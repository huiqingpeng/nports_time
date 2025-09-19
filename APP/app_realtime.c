/*
 * =====================================================================================
 *
 * Filename:  RealTimeSchedulerTask.c
 *
 * Description:  实现 RealTimeSchedulerTask 任务。
 * 这是系统的硬实时核心，由高精度硬件定时器驱动，
 * 负责所有数据通路的高速、非阻塞I/O操作。
 *
 * =====================================================================================
 */
#include "./inc/app_com.h"
#include <timers.h>     // For POSIX timers if used as fallback, or custom timer driver header
#include <intLib.h>     // For intConnect()

/* ------------------ Task-Specific Constants ------------------ */
#define MEDIUM_FREQ_INTERVAL     (10)          // 中频任务执行间隔 (10 * 100µs = ms)
#define LOW_FREQ_INTERVAL        (5*1000)     // 任务执行间隔 (1000ms)

#define TX_CHUNK_SIZE (UART_HW_FIFO_SIZE / 2)

 // LED每次触发后点亮的持续时间（单位：中频任务周期，即50ms）
#define LED_ON_DURATION_TICKS    (50)      

/* ------------------ Private Function Prototypes ------------------ */
static void high_precision_timer_isr(void *arg);
static int setup_high_precision_timer(void);

static void run_high_frequency_tasks(void);
static void run_medium_frequency_tasks(void);
static void run_low_frequency_tasks(void);

static void check_for_new_connections(void);
static void run_net_recv(void);
static void run_net_send(void);
static void cleanup_data_connection(int channel_index,
		int client_index_in_array);

/* ------------------ Module-level static variables ------------------ */
static SEM_ID s_timer_sync_sem; // 用于定时器ISR与任务同步的二进制信号量
static volatile uint32_t timer_cnt = 0;

static uint32_t s_last_rx_count[NUM_PORTS] = {0};
static uint32_t s_last_tx_count[NUM_PORTS] = {0};
static uint8_t s_rx_led_timer[NUM_PORTS] = {0};
static uint8_t s_tx_led_timer[NUM_PORTS] = {0};
/* ------------------ Global Variable Definitions ------------------ */


void printHex(const char *buffer, size_t size);

void printHex(const char *buffer, size_t size)
{
	int i;
    for (i = 0; i < size; ++i)
    {
        printf("%02x ", (uint8_t)buffer[i]);
    }
    printf("\r\n");
}


static void high_precision_timer_isr(void *arg) {
	// ISR中唯一要做的事：释放信号量唤醒实时任务
	timer_cnt++;
	semGive(s_timer_sync_sem);
}

/**
 * @brief RealTimeSchedulerTask 的主入口函数
 */
void RealTimeSchedulerTask(void) {
    unsigned int minor_cycle_counter = 0;
	LOG_INFO("RealTimeSchedulerTask: Starting...\n");

	// 1. 创建用于同步的二进制信号量
	s_timer_sync_sem = semBCreate(SEM_Q_PRIORITY, SEM_EMPTY);
	if (s_timer_sync_sem == NULL) {
		LOG_ERROR(
				"FATAL: RealTimeSchedulerTask failed to create sync semaphore.\n");
		return;
	}

	// 2. 设置并启动高精度硬件定时器
	if (setup_high_precision_timer() != OK) {
		LOG_ERROR(
				"FATAL: RealTimeSchedulerTask failed to setup high-precision timer.\n");
		return;
	}
	LOG_INFO("RealTimeSchedulerTask: High-precision timer initialized.\n");

	/* ------------------ 主调度循环 ------------------ */
	while (1) {
		// 3. 等待下一个100µs定时器中断信号，任务在此阻塞，不消耗CPU
		semTake(s_timer_sync_sem, WAIT_FOREVER);
        minor_cycle_counter++;
		/* --- 100µs 高频任务 --- */
		run_high_frequency_tasks();
        if ((minor_cycle_counter % MEDIUM_FREQ_INTERVAL) == 0) {
            run_medium_frequency_tasks();
        }
        
		if (minor_cycle_counter >= LOW_FREQ_INTERVAL) { // 假设100ms为一个主周期
			minor_cycle_counter = 0;
            run_low_frequency_tasks();
		}
	}
}

/**
 * @brief 串口接收处理函数
 * @details 从所有活跃的串口硬件FIFO读取数据，并存入软件环形缓冲区。
 */
static unsigned char temp_buffer[2048];
static void handle_serial_rx(void)
{
    int i;
    uint32_t bytes_count = 0;

    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];

        // 智能轮询：只处理有客户端连接且串口已打开的通道
        if (channel->data_net_info.num_clients > 0 && channel->uart_state == UART_STATE_OPENED) 
        {
            // 从串口硬件非阻塞地读取FIFO中的所有数据
            axi16550Recv(i, temp_buffer, &bytes_count);
            if (bytes_count > 0) {
                // 检查软件缓冲区是否会溢出
                if ((ring_buffer_num_items(&channel->buffer_uart) + bytes_count) > RING_BUFFER_SIZE)
                {
                    // 缓冲区已满，此处应处理错误（例如增加一个丢包计数器）
                    // for production code, you might want to increment a drop counter here.
                    // channel->rx_dropped_count += bytes_count;
                } else {
                    // 将读取到的数据放入“串口到网络”的环形缓冲区
                    ring_buffer_queue_arr(&channel->buffer_uart, (const char*)temp_buffer, bytes_count);
                }
                channel->rx_count += bytes_count;
                // printf("RX:%d \r\n ",bytes_count);
                // printHex(temp_buffer, bytes_count);
            }
        }
    }
}

/**
 * @brief 串口发送处理函数
 * @details 从软件环形缓冲区取出数据，并写入所有活跃的串口硬件FIFO。
 */
unsigned char data_chunk[TX_CHUNK_SIZE];
static void handle_serial_tx(void)
{
    int i;
    uint32_t bytes_count;

    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];

        // 智能轮询：只处理有客户端连接且串口已打开的通道
        if (channel->data_net_info.num_clients > 0 && channel->uart_state == UART_STATE_OPENED) 
        {
            // 检查“网络到串口”缓冲区中是否有数据
            if (!ring_buffer_is_empty(&channel->buffer_net)) 
            {
                // 检查串口硬件是否准备好接收数据
                //if (axi16550_TxReady(i)) 
                {
                    // 从环形缓冲区中取出数据
                    bytes_count = ring_buffer_dequeue_arr(&channel->buffer_net, (char*)temp_buffer, TX_CHUNK_SIZE);
                    // printf("TX:%d \r\n ",bytes_count);
                    // printHex(temp_buffer, bytes_count);
                    if (bytes_count > 0) {
                        // 将数据写入串口硬件
                        int j;
                        for (j = 0; j < bytes_count; j++)
                        {
                            // 等待，直到硬件发送FIFO有可用空间 (LSR_THRE位被置位)
                            // 这是一个忙等待循环，确保以最快速度响应
                            while (!axi16550_TxReady(i))
                            {
                                // 在等待期间可以考虑放弃CPU，但这会降低极限吞吐率
                                // 对于硬实时测试，可以不加taskDelay
                                // taskDelay(0); 
                            }
                            
                            // 向发送保持寄存器(THR)写入一个字节
                            // FIFO会自动处理后续字节的移入
                            userAxiCfgWrite(i, 0x1000, temp_buffer[j]);
                        }
                        channel->tx_count += bytes_count;
                    }
                }
            }
        }
    }
}


/**
 * @brief 执行所有高频（每个周期）任务
 * @details 负责在环形缓冲区和串口硬件FIFO之间高速交换数据。
 * 拆分为接收和发送两个独立循环，以提高逻辑清晰度。
 */
static void run_high_frequency_tasks(void)
{
    static int call_count = 0;
    call_count++;
    // 1. 统一处理所有端口的接收
    //if(call_count % 2 == 0)
    {
        handle_serial_rx();
    }


    // 2. 统一处理所有端口的发送
    {
        handle_serial_tx();
    }

}


/**
 * @brief 新增：处理所有通道的LED闪烁逻辑
 * @details 基于可重入单稳态触发器模型。
 * 检测到数据活动时，重置计时器；计时器大于0则点亮LED。
 */
static void handle_led_blinking(void)
{
    int i;
    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];

        // --- 处理 RX LED ---
        // 1. 检测数据接收活动
        if (channel->rx_count > s_last_rx_count[i]) {
            s_rx_led_timer[i] = LED_ON_DURATION_TICKS; // 重置点亮计时器
            s_last_rx_count[i] = channel->rx_count;   // 更新上次的计数值
        }

        // 2. 根据计时器更新LED状态
        if (s_rx_led_timer[i] > 0) {
            rxled(i, 1); // 点亮 RX LED
            s_rx_led_timer[i]--; // 计时器递减LOG_LEVEL_DEBUG
        } else {
            rxled(i, 0); // 关闭 RX LED
        }

        // --- 处理 TX LED ---
        // 1. 检测数据发送活动
        if (channel->tx_count > s_last_tx_count[i]) {
            s_tx_led_timer[i] = LED_ON_DURATION_TICKS; // 重置点亮计时器
            s_last_tx_count[i] = channel->tx_count;   // 更新上次的计数值
        }

        // 2. 根据计时器更新LED状态
        if (s_tx_led_timer[i] > 0) {
            txled(i, 1); // 点亮 TX LED
            s_tx_led_timer[i]--; // 计时器递减
        } else {
            txled(i, 0); // 关闭 TX LED
        }
    }
}

/**
 * @brief 执行所有中频（每1ms）任务
 */
static void run_medium_frequency_tasks(void) {
    NetworkSchedulerTask();
    handle_led_blinking();
}


static void run_low_frequency_tasks(void) 
{
    int i;
    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];

        // 只处理有客户端连接且串口已打开的通道
        if (channel->data_net_info.num_clients > 0 && channel->uart_state == UART_STATE_OPENED) 
        {
            LOG_INFO("[%d]:rx_count= %d, tx_count= %d", i, channel->rx_count, channel->tx_count);
            LOG_INFO("[%d]:rx_net  = %d, tx_net  = %d", i, channel->rx_net,   channel->tx_net);
        }
    }
}


/**
 * @brief 设置并启动高精度硬件定时器
 */
static int setup_high_precision_timer(void) {
	int ret = 0;
	app_start_hz(1, 10000);
	app_register_task(high_precision_timer_isr, NULL);
	ret = OK;
	return ret;
}


void app_realtime_print(void)
{
	LOG_INFO("timer_cnt:%d \r\n",timer_cnt);
}
