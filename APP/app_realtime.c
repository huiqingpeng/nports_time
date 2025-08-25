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
#define MEDIUM_FREQ_INTERVAL     (10)          // 中频任务执行间隔 (10 * 100µs = 1ms)

/* ------------------ Private Function Prototypes ------------------ */
static void high_precision_timer_isr(void *arg);
static int setup_high_precision_timer(void);

static void run_high_frequency_tasks(void);
static void run_medium_frequency_tasks(void);

static void check_for_new_connections(void);
static void run_net_recv(void);
static void run_net_send(void);
static void cleanup_data_connection(int channel_index,
		int client_index_in_array);

/* ------------------ Module-level static variables ------------------ */
static SEM_ID s_timer_sync_sem; // 用于定时器ISR与任务同步的二进制信号量

/* ------------------ Global Variable Definitions ------------------ */

static void high_precision_timer_isr(void *arg) {
	// ISR中唯一要做的事：释放信号量唤醒实时任务
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
			run_medium_frequency_tasks();
		}

		// 更新周期计数器
		minor_cycle_counter++;
		if (minor_cycle_counter >= 1000) { // 假设100ms为一个主周期
			minor_cycle_counter = 0;
		}
	}
}

/**
 * @brief 执行所有高频（每个周期）任务
 */
static void run_high_frequency_tasks(void) {
	int i;
	for (i = 0; i < NUM_PORTS; i++) {
		// TODO: 从串口硬件FIFO读取数据到 g_channel_states[i].buffer_uart

	}

	for (i = 0; i < NUM_PORTS; i++) {
		// TODO: 从 g_channel_states[i].buffer_net 读取数据写入到串口硬件FIFO
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
    while (msgQReceive(g_data_conn_q, (char*)&msg, sizeof(msg), NO_WAIT) == OK) {
        if (msg.type == CONN_TYPE_DATA && msg.channel_index >= 0 && msg.channel_index < NUM_PORTS) {
            int i = msg.channel_index;
            ChannelState* channel = &g_system_config.channels[i];

            semTake(g_config_mutex, WAIT_FOREVER);
            if (channel->data_net_info.num_clients < MAX_CLIENTS_PER_CHANNEL) {
                int client_idx = channel->data_net_info.num_clients;
                channel->data_net_info.client_fds[client_idx] = msg.client_fd;
                
                if (channel->data_net_info.num_clients == 0) {
                    /* --- STATE UPDATE --- */
                    // 第一个客户端连接，状态从 LISTENING 变为 CONNECTED
                    channel->data_net_info.state = NET_STATE_CONNECTED;
                }
                channel->data_net_info.num_clients++;
                
                printf("RT_Task: Ch %d accepted new client fd=%d. Total clients: %d\n", i, msg.client_fd, channel->data_net_info.num_clients);

            } else {
                fprintf(stderr, "RT_Task: Ch %d client limit reached. Rejecting fd=%d\n", i, msg.client_fd);
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
 */
static void run_net_recv(void) {
	unsigned char temp_buffer[2048];
	int i, j;
	for (i = 0; i < NUM_PORTS; i++) {
		// MODIFIED: Loop through all clients for this channel
		// 从后往前遍历，方便安全地移除断开的连接

		for (j = g_channel_states[i].num_data_clients - 1; j >= 0; j--) {
			int fd = g_channel_states[i].data_client_fds[j];
			if (fd < 0)
				continue;

			int n = recv(fd, (char*) temp_buffer, sizeof(temp_buffer), 0);
			if (n > 0) {
				// 将收到的数据写入该通道的公共网络缓冲区
//                ring_buffer_write_bytes(&g_channel_states[i].buffer_net, temp_buffer, n);
				temp_buffer[n] = '\0';
				LOG_INFO("[ch%d][%d] %d : %s \r\n", i, j, n, temp_buffer);
			} else if (n == 0) {
				cleanup_data_connection(i, j);
			} else {
				if (errno != EWOULDBLOCK && errno != EAGAIN) {
					cleanup_data_connection(i, j);
				}
			}
		}
	}
}

/**
 * @brief 对所有活跃的数据通道执行非阻塞send
 */
static void run_net_send(void) {
	unsigned char temp_buffer[2048];
	int i, j;
	temp_buffer[0] = '1';
	temp_buffer[1] = '\0';
	for (i = 0; i < NUM_PORTS; i++) {
		if (g_channel_states[i].num_data_clients == 0)
			continue;

		unsigned int bytes_to_send = 2;
// bytes_to_send= ring_buffer_bytes_used(&g_channel_states[i].buffer_uart);
		if (bytes_to_send == 0)
			continue;

		if (bytes_to_send > sizeof(temp_buffer)) {
			bytes_to_send = sizeof(temp_buffer);
		}

		// 从串口缓冲区读取数据
//        ring_buffer_read_bytes(&g_channel_states[i].buffer_uart, temp_buffer, bytes_to_send);

		// MODIFIED: "Fan-out" data to all clients for this channel
		for (j = g_channel_states[i].num_data_clients - 1; j >= 0; j--) {
			int fd = g_channel_states[i].data_client_fds[j];

			int sent = send(fd, (char*) temp_buffer, bytes_to_send, 0);
			if (sent < 0) {
				if (errno != EWOULDBLOCK && errno != EAGAIN) {
					cleanup_data_connection(i, j);
				}
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
    printf("RT_Task: Ch %d cleaned up client fd=%d.\n", channel_index, fd_to_close);

    int last_index = channel->data_net_info.num_clients - 1;
    if (client_index_in_array != last_index) {
        channel->data_net_info.client_fds[client_index_in_array] = channel->data_net_info.client_fds[last_index];
    }
    channel->data_net_info.client_fds[last_index] = -1;
    channel->data_net_info.num_clients--;

    if (channel->data_net_info.num_clients == 0) {
        /* --- STATE UPDATE --- */
        // 最后一个客户端断开，状态从 CONNECTED 变回 LISTENING
        channel->data_net_info.state = NET_STATE_LISTENING;
        printf("RT_Task: Ch %d has no clients left. State -> LISTENING.\n", channel_index);
        
        // 可选：当最后一个客户端断开时，才重置缓冲区
        // ring_buffer_init(&channel->buffer_net, channel->net_buffer_mem, RING_BUFFER_SIZE);
        // ring_buffer_init(&channel->buffer_uart, channel->uart_buffer_mem, RING_BUFFER_SIZE);
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
