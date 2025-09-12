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
#define MEDIUM_FREQ_INTERVAL     (10)          // 中频任务执行间隔 (20 * 100µs = 2ms)
#define LOW_FREQ_INTERVAL        (5*1000)     // 任务执行间隔 (1000ms)

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
/* ------------------ Global Variable Definitions ------------------ */


void printHex(const char *buffer, size_t size);

void printHex(const char *buffer, size_t size)
{
	// int i;
    // for (i = 0; i < size; ++i)
    // {
    //     printf("%02x ", (uint8_t)buffer[i]);
    // }
    // printf("\r\n");
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

		/* --- 100µs 高频任务 --- */
        run_high_frequency_tasks();
		/* --- 1ms 中频任务 --- */
		if ((minor_cycle_counter % MEDIUM_FREQ_INTERVAL) == 0) {
            static unsigned int count = 0;
            count++;

			run_medium_frequency_tasks();

            if(count % 2 == 0)
            {
                txled(0,0);
                rxled(0,0);
                Portled(0,0);
            }else{
                txled(0,1);
                rxled(0,1);
                Portled(0,1);
            }
		}

		// 更新周期计数器
		minor_cycle_counter++;
		if (minor_cycle_counter >= LOW_FREQ_INTERVAL) { // 假设100ms为一个主周期
			minor_cycle_counter = 0;
            run_low_frequency_tasks();
		}
	}
}


static void run_low_frequency_tasks(void) 
{
    LOG_ERROR("rx_count= %d, tx_count= %d",g_system_config.channels[0].rx_count,g_system_config.channels[0].tx_count);
    LOG_ERROR("rx_net  = %d, tx_net  = %d",g_system_config.channels[0].rx_net,g_system_config.channels[0].tx_net);
}
/**
 * @brief 执行所有高频（每个周期）任务
 * @details 负责在环形缓冲区和串口硬件FIFO之间高速交换数据。

 */
static unsigned char temp_buffer[2048]; // 使用一个较小的临时缓冲区进行数据交换
static void run_high_frequency_tasks(void)
{
    int i;

    uint32_t bytes_count = 0;

    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];

        // *** 状态检查: 只有打开的串口才进行I/O ***
        if (channel->uart_state == UART_STATE_OPENED) {
            
            // --- 数据方向: 串口 -> 网络环形缓冲区 ---
            // 从串口硬件非阻塞地读取数据
            axi16550Recv(i, temp_buffer, &bytes_count);
            if (bytes_count > 0) {
                // 将读取到的数据放入“串口到网络”的环形缓冲区
                LOG_DEBUG("RX:%d",bytes_count);
                printHex(temp_buffer, bytes_count);
                ring_buffer_queue_arr(&channel->buffer_uart, (const char*)temp_buffer, bytes_count);
                channel->rx_count += bytes_count;
            }

            // --- 数据方向: 网络环形缓冲区 -> 串口 ---
            // 检查“网络到串口”缓冲区中是否有数据
            if (!ring_buffer_is_empty(&channel->buffer_net)) 
            {

                // 检查串口硬件是否准备好接收数据
                // if (axi16550_TxReady(i)) {
                {
                    // 从环形缓冲区中取出数据

                    bytes_count = ring_buffer_dequeue_arr(&channel->buffer_net, (char*)temp_buffer, sizeof(temp_buffer));
                    channel->tx_count += bytes_count;
                    if (bytes_count > 0) {
                        // 将数据写入串口硬件
                        LOG_DEBUG("TX:%d",bytes_count);
                        printHex(temp_buffer, bytes_count);
                        axi16550SendNoWait(i, temp_buffer, bytes_count);
                    }
                }
            }
        }
    }
}

/**
 * @brief 执行所有中频（每1ms）任务
 */
static void run_medium_frequency_tasks(void) {
	check_for_new_connections();
	run_net_recv();
	run_net_send();
}

/**
 * @brief 检查并接管来自ConnectionManager的新数据连接
 */
static void check_for_new_connections(void) {
    NewConnectionMsg msg;
    while (msgQReceive(g_data_conn_q, (char*)&msg, sizeof(msg), NO_WAIT) == sizeof(NewConnectionMsg)) {
        if (msg.type == CONN_TYPE_DATA && msg.channel_index >= 0 && msg.channel_index < NUM_PORTS) {
            int i = msg.channel_index;
            ChannelState* channel = &g_system_config.channels[i];

            semTake(g_config_mutex, WAIT_FOREVER);
            if (channel->data_net_info.num_clients < MAX_CLIENTS_PER_CHANNEL) {
                int client_idx = channel->data_net_info.num_clients;
                channel->data_net_info.client_fds[client_idx] = msg.client_fd;
                
                if (channel->data_net_info.num_clients == 0) {
                    // 第一个客户端连接，状态从 LISTENING 变为 CONNECTED
                    channel->data_net_info.state = NET_STATE_CONNECTED;
                }
                channel->data_net_info.num_clients++;
                LOG_INFO("RT_Task: Ch %d accepted new client fd=%d. Total clients: %d\n", i, msg.client_fd, channel->data_net_info.num_clients);
            } else {
                LOG_ERROR("RT_Task: Ch %d client limit reached. Rejecting fd=%d\n", i, msg.client_fd);
                close(msg.client_fd);
            }
            semGive(g_config_mutex);

        } else {
            close(msg.client_fd);
        }
    }
}

/**
 * @brief 对所有活跃的数据通道执行非阻塞recv
 * @details 从TCP客户端接收数据，并放入“网络到串口”的环形缓冲区。
 */
static unsigned char temp_buffer_net_recv[8192];
static void run_net_recv(void) {

    int i, j;

    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];
        
        // 从后往前遍历，方便在循环中安全地移除断开的连接
        for (j = channel->data_net_info.num_clients - 1; j >= 0; j--) {
            int fd = channel->data_net_info.client_fds[j];
            if (fd < 0) continue;

            if(channel->uart_state != UART_STATE_OPENED) {
                // 如果串口未打开 不接收数据
                continue;
            }

            int n = recv(fd, (char*)temp_buffer_net_recv, sizeof(temp_buffer_net_recv), 0);
            if (n > 0) {
                // 将收到的数据写入该通道的“网络到串口”环形缓冲区 ***
                LOG_INFO("net RX:%d",n);
                ring_buffer_queue_arr(&channel->buffer_net, (const char*)temp_buffer_net_recv, n);
                channel->rx_net += n;
            } else if (n == 0) {
                // 客户端正常关闭连接
                cleanup_data_connection(i, j);
            } else { // n < 0
                // 检查是否是真正的错误，而不是暂无数据
                if (errno != EWOULDBLOCK && errno != EAGAIN) {
                    // 客户端异常断开
                    cleanup_data_connection(i, j);
                }
            }
        }
    }
}

/**
 * @brief 网络数据发送任务
 */
static void run_net_send(void)
{
    static uint32_t last_send_ticks[NUM_PORTS] = {0};
    unsigned char temp_buffer[MAX_PACKET_SIZE*10];
    int i, j;
    
    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];
        
        // 跳过未连接的通道
        if (channel->data_net_info.num_clients == 0) {
            continue;
        }

        // 检查缓冲区中的可用数据
        unsigned int available_bytes = ring_buffer_num_items(&channel->buffer_uart);
        if (available_bytes == 0) {
            continue;
        }

        // 使用timer_cnt计算精确的时间间隔(转换为毫秒)
        uint32_t current_ticks = timer_cnt;
        uint32_t elapsed_ticks = current_ticks - last_send_ticks[i];
        uint32_t elapsed_ms = (elapsed_ticks * TIMER_TICK_US) / US_TO_MS;

        // 判断是否应该发送数据
        unsigned int should_send = 1;
        
        // 1. 达到打包长度
        // if (available_bytes >= channel->net_send_cfg.packet_size) {
        //     LOG_DEBUG("Channel %d: Ready to send %d bytes (packet size: %d)", i, available_bytes, channel->net_send_cfg.packet_size);
        //     should_send = 1;
        // }
        // // 2. 达到发送间隔且有数据
        // else if (elapsed_ms >= channel->net_send_cfg.send_interval_ms && available_bytes > 0) {
        //     LOG_DEBUG("Channel %d: Sending %d bytes after interval %dms", i, available_bytes, elapsed_ms);
        //     should_send = 1;
        // }

        if (should_send) {
            // 读取数据
            unsigned int bytes_to_send = (available_bytes < channel->net_send_cfg.packet_size) ? 
                                       available_bytes : channel->net_send_cfg.packet_size;
            bytes_to_send = ring_buffer_dequeue_arr(&channel->buffer_uart, 
                                                  (char*)temp_buffer, 
                                                  bytes_to_send);

            if (bytes_to_send > 0) {
                // 发送给所有客户端
                for (j = channel->data_net_info.num_clients - 1; j >= 0; j--) {
                    int fd = channel->data_net_info.client_fds[j];
                    if (fd < 0) continue;
                    LOG_INFO("net TX:%d",bytes_to_send);
                    channel->tx_net += bytes_to_send;
                    int sent = send(fd, (char*)temp_buffer, bytes_to_send, 0);

                    if (sent < 0 && errno != EWOULDBLOCK && errno != EAGAIN) {
                        cleanup_data_connection(i, j);
                    }
                }
                
                // 更新发送时间戳
                last_send_ticks[i] = current_ticks;
            }
        }
    }
}

/**
 * @brief 清理一个已断开的数据连接
 */
static void cleanup_data_connection(int channel_index, int client_index_in_array) {
    semTake(g_config_mutex, WAIT_FOREVER);
    ChannelState* channel = &g_system_config.channels[channel_index];
    if (client_index_in_array < 0 || client_index_in_array >= channel->data_net_info.num_clients) {
        semGive(g_config_mutex);
        return;
    }

    int fd_to_close = channel->data_net_info.client_fds[client_index_in_array];
    close(fd_to_close);
    LOG_INFO("RT_Task: Ch %d cleaned up client fd=%d.\n", channel_index, fd_to_close);

    int last_index = channel->data_net_info.num_clients - 1;
    if (client_index_in_array != last_index) {
        channel->data_net_info.client_fds[client_index_in_array] = channel->data_net_info.client_fds[last_index];
    }
    channel->data_net_info.client_fds[last_index] = -1;
    channel->data_net_info.num_clients--;

    if (channel->data_net_info.num_clients == 0) {
        // 最后一个客户端断开，状态从 CONNECTED 变回 LISTENING
        channel->data_net_info.state = NET_STATE_LISTENING;
        LOG_INFO("RT_Task: Ch %d has no clients left. State -> LISTENING.\n", channel_index);
        
        // *** 状态维护：检查是否所有网络连接都已断开 ***
        if (channel->cmd_net_info.num_clients == 0) {
            channel->uart_state = UART_STATE_CLOSED;
            LOG_INFO("RT_Task: All network clients for Ch %d disconnected. UART physical state -> CLOSED.\n", channel_index);
        }
    }
    semGive(g_config_mutex);
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
