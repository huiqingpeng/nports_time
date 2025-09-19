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
 * @brief 检查并接管来自ConnectionManager的新数据连接
 */
static void check_for_new_connections(void) {
	NewConnectionMsg msg;
	while (msgQReceive(g_data_conn_q, (char*) &msg, sizeof(msg), NO_WAIT)
			== sizeof(NewConnectionMsg)) {
		if (msg.type
				== CONN_TYPE_DATA&& msg.channel_index >= 0 && msg.channel_index < NUM_PORTS) {
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
				LOG_INFO(
						"NetScheduler: Ch %d accepted new client fd=%d. Total clients: %d\n",
						i, msg.client_fd, channel->data_net_info.num_clients);
			} else {
				LOG_ERROR(
						"NetScheduler: Ch %d client limit reached. Rejecting fd=%d\n",
						i, msg.client_fd);
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
static void run_net_recv(void) {
	unsigned char temp_buffer_net[2048]; // 为网络I/O使用独立的缓冲区
	int i, j;

	for (i = 0; i < NUM_PORTS; i++) {
		ChannelState* channel = &g_system_config.channels[i];

		// 从后往前遍历，方便在循环中安全地移除断开的连接
		for (j = channel->data_net_info.num_clients - 1; j >= 0; j--) {
			int fd = channel->data_net_info.client_fds[j];
			if (fd < 0)
				continue;

			int n = recv(fd, (char*) temp_buffer_net, sizeof(temp_buffer_net),
					0);

			if (n > 0) {
				// 将收到的数据写入该通道的“网络到串口”环形缓冲区 
				ring_buffer_queue_arr(&channel->buffer_net,
						(const char*) temp_buffer_net, n);
				channel->tx_net += n;
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
 * @brief 对所有活跃的数据通道执行非阻塞send
 * @details 从“串口到网络”的环形缓冲区读取数据，并发送给所有连接的客户端。
 */
static void run_net_send(void) {
	unsigned char temp_buffer_net[2048]; // 为网络I/O使用独立的缓冲区
	int i, j;

	for (i = 0; i < NUM_PORTS; i++) {
		ChannelState* channel = &g_system_config.channels[i];

		// 如果该通道没有客户端连接，或者缓冲区没数据，则跳过
		if (channel->data_net_info.num_clients == 0
				|| ring_buffer_is_empty(&channel->buffer_uart)) {
			continue;
		}

		// *** 从“串口到网络”的环形缓冲区读取所有可用数据 ***
		unsigned int bytes_to_send = ring_buffer_dequeue_arr(
				&channel->buffer_uart, (char*) temp_buffer_net,
				sizeof(temp_buffer_net));
		channel->rx_net += bytes_to_send;
		if (bytes_to_send > 0) {
			// 将数据“扇出”(Fan-out)到该通道的所有客户端
			for (j = channel->data_net_info.num_clients - 1; j >= 0; j--) {
				int fd = channel->data_net_info.client_fds[j];
				if (fd < 0)
					continue;

				int sent = send(fd, (char*) temp_buffer_net, bytes_to_send, 0);
				if (sent < 0) {
					if (errno != EWOULDBLOCK && errno != EAGAIN) {
						// 发送失败，说明此客户端可能已断开
						cleanup_data_connection(i, j);
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
	LOG_INFO("NetScheduler: Ch %d cleaned up client fd=%d.\n", channel_index,
			fd_to_close);

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
		channel->tx_net = 0;
		channel->rx_net = 0;
		channel->rx_count = 0;
		channel->tx_count = 0;
		LOG_INFO(
				"NetScheduler: Ch %d has no clients left. State -> LISTENING.\n",
				channel_index);
	}
	semGive(g_config_mutex);
}
