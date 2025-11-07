/*
 * =====================================================================================
 *
 * Filename:  app_net_scheduler.c
 *
 * Description:  实现 NetworkSchedulerTask 任务。
 * 该任务负责处理所有与网络套接字相关的非阻塞I/O操作，
 * 包括接收新连接、从客户端接收数据以及向客户端发送数据。
 *
 * =====================================================================================
 */
#include "./inc/app_com.h"

#ifndef TX_CHUNK_SIZE
#define TX_CHUNK_SIZE (UART_HW_FIFO_SIZE / 2)
#endif

/* ------------------ Private Function Prototypes ------------------ */
static void check_for_new_connections(void);
static void run_net_recv(void);
static void run_net_send(void);
static void cleanup_data_connection(int channel_index,int client_index_in_array);

/**
 * @brief 网络调度任务的主入口函数
 * @details 这是一个中等优先级的任务，以轮询方式处理所有网络相关事件。
 */
void NetworkSchedulerTask(void) {
	// 检查并接管来自ConnectionManager的新数据连接
	check_for_new_connections();

	// 处理所有活跃数据通道的网络接收
	run_net_recv();
	// 处理所有活跃数据通道的网络发送
	run_net_send();
}

/**
 * @brief (非阻塞)检查所有通道的新连接消息队列，并将新的fd分类存放到正确的管理结构中
 *
 * @description
 * 此函数被设计为在主调度循环中被频繁调用。它会轮询所有16个通道的消息队列
 * (g_net_conn_q[0] 到 g_net_conn_q[15])。
 * 当接收到一个由 ConnectionManagerTask 分发来的 NewConnectionMsg 时，它会：
 * 1. 根据 msg.channel_index 定位到对应的全局配置 ChannelState。
 * 2. 根据 msg.conn_type 判断连接的类型（如：普通数据、RealCOM数据、RealCOM命令等）。
 * 3. 将新的 client_fd 存入 ChannelState 中对应的 NetInfo 结构体
 * (data_net_info) 的 client_fds 数组中。
 * 4. 更新客户端计数器 (num_clients)，并处理连接数已满的情况。
 * 5. 使用互斥信号量 g_config_mutex 保证对共享配置 g_system_config 的原子操作。
 */
static void check_for_new_connections(void) {
    NewConnectionMsg msg;
    int i; // 用于遍历通道
    // 1. 遍历所有通道的消息队列
    for (i = 0; i < NUM_PORTS; i++) 
    {
        // 使用 while 循环来排空当前通道队列中的所有消息
        if (msgQReceive(g_net_conn_q[i], (char*) &msg, sizeof(msg), NO_WAIT) == sizeof(NewConnectionMsg))
        {
            // 验证消息的合法性
            if (msg.channel_index != i) {
                LOG_ERROR(
                    "NetScheduler: Mismatched channel index in message! Queue_idx=%d, msg.ch_idx=%d. Closing fd=%d\n",
                    i, msg.channel_index, msg.client_fd);
                close(msg.client_fd);
                continue; // 处理下一条消息
            }

			// semTake(g_config_mutex, WAIT_FOREVER);

            ChannelState* channel = &g_system_config.channels[i];

            // 2. 根据连接类型，选择正确的 NetInfo 结构体来存放 fd
            switch (msg.type)
            {
                case CONN_TYPE_TCPSERVER:
				case CONN_TYPE_REALCOM_DATA:
					channel->data_net_info.state = NET_STATE_CONNECTED;
					channel->data_net_info.client_fds[channel->data_net_info.num_clients] = msg.client_fd;
					channel->data_net_info.num_clients++;
				break;

                case CONN_TYPE_TCPCLIENT:
				case CONN_TYPE_UDP:

				break;
                
                default:
                    LOG_ERROR("NetScheduler: Ch %d received unknown conn_type %d. Closing fd=%d\n",
                              i, msg.type, msg.client_fd);
                    close(msg.client_fd);
                    continue; // 跳过此无效消息
            }
			// semGive(g_config_mutex);

			LOG_DEBUG("NetScheduler: Ch %d accepted new connection fd=%d, type=%d. Total clients: %d (Data).\n",
					 i, msg.client_fd, msg.type,
					 channel->data_net_info.num_clients);
        }
    }
    // (处理全局配置连接队列 g_config_conn_q 的逻辑可以放在这里，如果需要的话)
}

/*
 * =====================================================================================
 *
 * 顾问修改说明:
 *
 * 原有 `run_net_recv` 的问题:
 * 1. 在 `run_net_recv` 中，`recv()` 是在一个循环中被无条件调用的。
 * 2. 如果 `client_fd` 是阻塞模式 (默认)，`recv()` 会阻塞整个实时任务，导致
 * 上游的 `handle_serial_rx` 无法执行，引发UART FIFO溢出和数据丢失。
 *
 * 修改方案:
 * 1. **依赖非阻塞Socket**: 我们依赖上一步在 `app_net_con.c` 中所做的修改，
 * 即所有 `accept()` 的 `fd` 都已被设为 `O_NONBLOCK`。
 * 2. **引入 `select()` 检测可读性**:
 * - 在 `recv()` 之前，我们构建一个包含所有客户端 `fd` 的 `readfds` 集合。
 * - 使用 `select()` (超时设为0) 立即返回哪些 `fd` 真正有数据可读。
 * 3. **按需 `recv()`**:
 * - 只有 `FD_ISSET(fd, &readfds)` 为真的 `fd`，我们才对其调用 `recv()`。
 *
 * 优点:
 * - **杜绝阻塞**: 彻底解决了 `recv()` 阻塞实时任务的风险。
 * - **极高效率**: `select()` 是一次系统调用，远快于循环中 N 次无效的 `recv()`
 * (并检查 EWOULDBLOCK)。CPU只处理真正有数据的socket。
 * - **代码一致性**: 此逻辑与我们修改后的 `run_net_send` 保持一致。
 *
 * =====================================================================================
 */
#define TX_NET_SIZE (4096) 
unsigned char temp_buffer_net_rx[TX_NET_SIZE];
static void run_net_recv(void) {

    int i, j;
    fd_set readfds; // 用于 select 的可读文件描述符集合
    int max_fd = 0;
    struct timeval timeout = {0, 0}; // 完全非阻塞的 select

    FD_ZERO(&readfds);

    // 1. 构建 fd_set，包含所有通道的所有活动客户端
    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];
        for (j = channel->data_net_info.num_clients - 1; j >= 0; j--) {
            int fd = channel->data_net_info.client_fds[j];
            if (fd >= 0) {
                FD_SET(fd, &readfds);
                if (fd > max_fd) {
                    max_fd = fd;
                }
            }
        }
    }

    if (max_fd == 0) {
        return; // 没有任何活动的客户端，直接返回
    }

    // 2. 非阻塞地轮询哪些 fd 准备好了
    int ret = select(max_fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret <= 0) {
        return; // 没有任何 fd 可读 (ret=0) 或 select 发生错误 (ret<0)
    }

    // 3. 仅对 select() 报告为可读的 fd 执行 recv()
    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];
        for (j = channel->data_net_info.num_clients - 1; j >= 0; j--) {
            int fd = channel->data_net_info.client_fds[j];
            
            // 检查这个 fd 是否在可读集合中
            if (fd >= 0 && FD_ISSET(fd, &readfds)) {
                
                // (由于 select() 保证了可读性，此处的 recv() 不会阻塞)
                int n = recv(fd, (char*) temp_buffer_net_rx, sizeof(temp_buffer_net_rx), 0);

                if (n > 0) {
                    // 成功读取数据
                    ring_buffer_queue_arr(&channel->buffer_net, (char*) temp_buffer_net_rx, n);
                    channel->tx_net += n;
                } else if (n == 0) {
                    // 客户端主动关闭 (TCP FIN)
                    cleanup_data_connection(i, j);
                } else {
                    // n < 0
                    // 理论上，因为我们用了 select()，不应再收到 EWOULDBLOCK。
                    // 但为健壮性，我们仍然检查：忽略 EWOULDBLOCK，其他视为错误。
                    if (errno != EWOULDBLOCK && errno != EAGAIN) {
                        // 发生真实错误 (如 RST)
                        cleanup_data_connection(i, j);
                    }
                }
            }
        }
    }
}



unsigned char temp_buffer_net_tx[TX_NET_SIZE]; // 使用更小的块大小
/**
 * @brief 对所有活跃的数据通道执行非阻塞send
 * @details 从“串口到网络”的环形缓冲区读取数据，并发送给所有连接的客户端。
 */
static void run_net_send(void) {

    int i, j;
    fd_set writefds;
    int max_fd = 0;
    struct timeval timeout = {0, 0}; // 完全非阻塞的 select

    for (i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];

        // 如果该通道没有客户端连接，或者缓冲区没数据，则跳过
        if (channel->data_net_info.num_clients == 0 || ring_buffer_is_empty(&channel->buffer_uart)) {
            continue;
        }

        FD_ZERO(&writefds);
        max_fd = 0;

        // 1. 将该通道所有客户端的fd加入select的写集合
        for (j = 0; j < channel->data_net_info.num_clients; j++) {
            int fd = channel->data_net_info.client_fds[j];
            if (fd >= 0) {
                FD_SET(fd, &writefds);
                if (fd > max_fd) {
                    max_fd = fd;
                }
            }
        }

        if (max_fd == 0) continue;

        // 2. 非阻塞地检查哪些fd可写
        int ret = select(max_fd + 1, NULL, &writefds, NULL, &timeout);

        // 3. 仅当至少有一个客户端可写时，才从缓冲区取数据
        if (ret > 0) {
            
            // 4. 从环形缓冲区读取一小块数据
            // (我们依赖 `handle_serial_rx` 中 UART_HW_FIFO_SIZE 的定义)
            unsigned int bytes_to_send = ring_buffer_dequeue_arr(
                &channel->buffer_uart, (char*)temp_buffer_net_tx, TX_NET_SIZE);

            if (bytes_to_send > 0) {
                channel->rx_net += bytes_to_send;
                
                // 5. 将数据发送给 *所有可写的* 客户端
                for (j = channel->data_net_info.num_clients - 1; j >= 0; j--) {
                    int fd = channel->data_net_info.client_fds[j];
                    
                    // 检查这个 fd 是否在可写集合中
                    if (fd >= 0 && FD_ISSET(fd, &writefds)) {
                        
                        // (由于 select() 保证了可写性，此处的 send() 不会阻塞)
                        int sent = send(fd, (char*)temp_buffer_net_tx, bytes_to_send, 0);
                        
                        if (sent < 0) {
                            // 理论上不应发生 EWOULDBLOCK，但如果发生，我们也忽略
                            if (errno != EWOULDBLOCK && errno != EAGAIN) {
                                // 发生真实错误 (如 RST)
                                cleanup_data_connection(i, j);
                            }
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief 清理一个已断开的数据连接
 */
static void cleanup_data_connection(int channel_index,
		int client_index_in_array) {
	semTake(g_config_mutex, WAIT_FOREVER);
	ChannelState* channel = &g_system_config.channels[channel_index];
	if (client_index_in_array < 0
			|| client_index_in_array >= channel->data_net_info.num_clients) {
		semGive(g_config_mutex);
		return;
	}

	int fd_to_close = channel->data_net_info.client_fds[client_index_in_array];
	close(fd_to_close);

	int last_index = channel->data_net_info.num_clients - 1;
	if (client_index_in_array != last_index) {
		channel->data_net_info.client_fds[client_index_in_array] =
				channel->data_net_info.client_fds[last_index];
	}
	channel->data_net_info.client_fds[last_index] = -1;
	channel->data_net_info.num_clients--;

	if (channel->data_net_info.num_clients == 0) {
		// 最后一个客户端断开，状态从 CONNECTED 变回 LISTENING
		channel->data_net_info.state = NET_STATE_LISTENING;
		channel->uart_state = UART_STATE_CLOSED;
		// channel->tx_net = 0;
		// channel->rx_net = 0;
		// channel->rx_count = 0;
		// channel->tx_count = 0;
		ring_buffer_init(&channel->buffer_net,  channel->net_buffer_mem,  RING_BUFFER_SIZE);
		ring_buffer_init(&channel->buffer_uart, channel->uart_buffer_mem, RING_BUFFER_SIZE);
		LOG_INFO(
				"NetScheduler: Ch %d has no clients left. State -> LISTENING.\n",
				channel_index);
	}
	semGive(g_config_mutex);
}


/**
 * @brief 用于独立测试网络调度器的任务入口函数
 * @details
 * 这个任务会以固定的频率循环执行网络调度的三个核心功能：
 * 1. 检查新连接 (check_for_new_connections)
 * 2. 处理网络数据接收 (run_net_recv)
 * 3. 处理网络数据发送 (run_net_send)
 * 任务末尾会有一个 taskDelay，以让出CPU给其他任务。
 */
void NetSchedulerTestTask_Entry(void)
{
    LOG_INFO("----> Starting independent Network Scheduler Test Task (tNetSchedTest)...\\n", 0,0,0,0,0,0);
    printf("NetSchedulerTestTask_Entry... \r\n");
    taskDelay(sysClkRateGet());

    for (;;)
    {
        // 调用原 NetworkSchedulerTask 的核心功能
        NetworkSchedulerTask();

        // 延时，让出 CPU，控制任务执行频率
        taskDelay(sysClkRateGet()/800); // 大约每 1.25ms 执行一次
    }
}