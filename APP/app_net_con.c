#include "./inc/app_com.h"
#include <netinet/tcp.h>

#define LISTEN_BACKLOG 128*2 // 从 5 增加到 128


/* ------------------ Private Function Prototypes ------------------ */
static int setup_listening_socket(int port);
static void set_socket_non_blocking(int sock_fd);
static void set_tcp_keepalive(int sock_fd, int keepidle, int keepintl,
		int keepcnt);

/* ------------------ Port Mapping Table ------------------ */
static PortMapping g_port_mappings[NUM_PORTS] = {
    { 0,  950, 966, -1, -1 }, { 1,  951, 967, -1, -1 },
    { 2,  952, 968, -1, -1 }, { 3,  953, 969, -1, -1 },
    { 4,  954, 970, -1, -1 }, { 5,  955, 971, -1, -1 },
    { 6,  956, 972, -1, -1 }, { 7,  957, 973, -1, -1 },
    { 8,  958, 974, -1, -1 }, { 9,  959, 975, -1, -1 },
    { 10, 960, 976, -1, -1 }, { 11, 961, 977, -1, -1 },
    { 12, 962, 978, -1, -1 }, { 13, 963, 979, -1, -1 },
    { 14, 964, 980, -1, -1 }, { 15, 965, 981, -1, -1 }
};

static int g_setting_listen_fd = -1;


/* ------------------ Global Variable Definitions ------------------ */
// 在此文件中定义全局变量的实体
TASK_ID g_conn_manager_tid;


void ConnectionManagerTask(void)
{
    int i;
    LOG_INFO("ConnectionManagerTask: Starting...\n");

    /* ------------------ 1. 使用映射表初始化所有监听端口 ------------------ */
    for (i = 0; i < NUM_PORTS; i++) {
        g_port_mappings[i].data_listen_fd = setup_listening_socket(g_port_mappings[i].data_port);
        if (g_port_mappings[i].data_listen_fd < 0) {
            LOG_ERROR("FATAL: Failed to create data socket for channel %d on port %d\n", i, g_port_mappings[i].data_port);
            return;
        }

        g_port_mappings[i].set_listen_fd = setup_listening_socket(g_port_mappings[i].set_port);
        if (g_port_mappings[i].set_listen_fd < 0) {
            LOG_ERROR("FATAL: Failed to create set socket for channel %d on port %d\n", i, g_port_mappings[i].set_port);
            return;
        }
    }

    g_setting_listen_fd = setup_listening_socket(TCP_SETTING_PORT);
    if (g_setting_listen_fd < 0) {
        LOG_ERROR("FATAL: Failed to create global setting socket on port %d\n", TCP_SETTING_PORT);
        return;
    }

    LOG_INFO("ConnectionManagerTask: All %d listening sockets are ready.\n", (NUM_PORTS * 2) + 1);

    /* ------------------ 2. 主循环，使用 select 等待连接 ------------------ */
    while (1)
    {
        fd_set read_fds;
        int max_fd = 0;

        FD_ZERO(&read_fds);

        // 将所有监听socket加入fd_set
        for (i = 0; i < NUM_PORTS; i++) {
            FD_SET(g_port_mappings[i].data_listen_fd, &read_fds);
            if (g_port_mappings[i].data_listen_fd > max_fd) max_fd = g_port_mappings[i].data_listen_fd;

            FD_SET(g_port_mappings[i].set_listen_fd, &read_fds);
            if (g_port_mappings[i].set_listen_fd > max_fd) max_fd = g_port_mappings[i].set_listen_fd;
        }
        FD_SET(g_setting_listen_fd, &read_fds);
        if (g_setting_listen_fd > max_fd) max_fd = g_setting_listen_fd;

        struct timeval timeout = { 1, 0 };
        int ret = select(max_fd + 1, &read_fds, NULL, NULL, &timeout);

        if (ret <= 0) {
            if (ret < 0 && errno != EINTR) {
                perror("ConnectionManagerTask: select() error");
                taskDelay(sysClkRateGet());
            }
            continue; // 超时或被信号中断，继续下一次循环
        }

        /* ------------------ 3. 处理就绪的连接 ------------------ */
        // 遍历映射表，检查哪个fd就绪
        for (i = 0; i < NUM_PORTS; i++) {
            // 检查数据通道
            if (FD_ISSET(g_port_mappings[i].data_listen_fd, &read_fds)) {
                int client_fd = accept(g_port_mappings[i].data_listen_fd, NULL, NULL);
                if (client_fd >= 0) {
                    NewConnectionMsg msg;
                    msg.type = CONN_TYPE_DATA;
                    msg.channel_index = g_port_mappings[i].channel_index;
                    msg.client_fd = client_fd;
                    set_socket_non_blocking(client_fd);
                    set_tcp_keepalive(client_fd, 60, 5, 3);
                    LOG_INFO("[%d ]CONN_TYPE_DATA:[%d]\r\n",i,msg.channel_index);
                    if (msgQSend(g_data_conn_q, (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL) != OK) {
                        printf(stderr, "CRITICAL: Data queue full! Dropping connection for channel %d.\n", i);
                        close(client_fd);
                    }
                }
            }

            // 检查串口配置通道
            if (FD_ISSET(g_port_mappings[i].set_listen_fd, &read_fds)) {
                int client_fd = accept(g_port_mappings[i].set_listen_fd, NULL, NULL);
                if (client_fd >= 0) {
                    NewConnectionMsg msg;
                    msg.type = CONN_TYPE_SET;
                    msg.channel_index = g_port_mappings[i].channel_index;
                    msg.client_fd = client_fd;
                    set_socket_non_blocking(client_fd);
                    LOG_INFO("[%d ]CONN_TYPE_SET:[%d]\r\n",i,msg.channel_index);
                    if (msgQSend(g_config_conn_q, (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL) != OK) {
                        LOG_ERROR("CRITICAL: Config queue full! Dropping connection for channel %d.\n", i);
                        close(client_fd);
                    }
                }
            }
        }

        // 检查全局配置通道
        if (FD_ISSET(g_setting_listen_fd, &read_fds)) {
            int client_fd = accept(g_setting_listen_fd, NULL, NULL);
            if (client_fd >= 0) {
                NewConnectionMsg msg;
                    msg.type = CONN_TYPE_SETTING;
                    msg.channel_index = g_port_mappings[i].channel_index;
                    msg.client_fd = client_fd;
                set_socket_non_blocking(client_fd);
                
                if (msgQSend(g_config_conn_q, (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL) != OK) {
                    LOG_ERROR("CRITICAL: Config queue full! Dropping global setting connection.\n");
                    close(client_fd);
                }
            }
        }
    } // end while(1)
}

/**
 * @brief 创建并配置一个监听TCP socket的辅助函数
 *
 * @param port 要监听的端口号
 * @return int 成功则返回socket文件描述符，失败则返回-1
 */
static int setup_listening_socket(int port) {
	int sock_fd;
	struct sockaddr_in server_addr;
	int optval = 1;

	// 1. 创建socket
	if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket() failed");
		return -1;
	}

	// 2. 设置SO_REUSEADDR选项，允许服务器快速重启
	if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (char *) &optval,
			sizeof(optval)) < 0) {
		perror("setsockopt(SO_REUSEADDR) failed");
		close(sock_fd);
		return -1;
	}

	// 3. 准备服务器地址结构体
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 监听所有网络接口
	server_addr.sin_port = htons(port);

	// 4. 绑定地址
	if (bind(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr))
			< 0) {
		perror("bind() failed");
		close(sock_fd);
		return -1;
	}

	// 5. 开始监听
	if (listen(sock_fd, LISTEN_BACKLOG) < 0) {
		perror("listen() failed");
		close(sock_fd);
		return -1;
	}

	LOG_INFO("Successfully created listening socket on port %d, fd=%d\n", port,
			sock_fd);
	return sock_fd;
}

/**
 * @brief 将指定的socket文件描述符设置为非阻塞模式
 *
 * @param sock_fd 要设置的socket fd
 */
static void set_socket_non_blocking(int sock_fd) {
	int on = 1;

	// FIONBIO: File I/O Non-Blocking I/O
	// 这是在VxWorks中设置非阻塞模式最常用、最可靠的方法。
	if (ioctl(sock_fd, FIONBIO, (int) &on) < 0) {
		perror("ioctl(FIONBIO) failed");
		// 在实际应用中，这里可能需要更详细的错误日志
	}
}

/**
 * @brief 为指定的TCP socket启用并配置Keep-Alive机制
 *
 * @param sock_fd 要设置的socket fd
 * @param keepidle 空闲多长时间后开始发送第一个探测包（秒）
 * @param keepintl 探测包之间的时间间隔（秒）
 * @param keepcnt 发送多少个探测包后仍无响应，则认为连接已断开
 */
static void set_tcp_keepalive(int sock_fd, int keepidle, int keepintl,
		int keepcnt) {
	int optval = 1;

	// 1. 启用 SO_KEEPALIVE 选项
	if (setsockopt(sock_fd, SOL_SOCKET, SO_KEEPALIVE, (char *) &optval,
			sizeof(optval)) < 0) {
		perror("setsockopt(SO_KEEPALIVE) failed");
		return; // 如果基础选项失败，后续设置无意义
	}

	// 2. 设置 TCP_KEEPIDLE: 空闲多长时间后开始探测
	if (setsockopt(sock_fd, IPPROTO_TCP, TCP_KEEPIDLE, (char *) &keepidle,
			sizeof(keepidle)) < 0) {
		perror("setsockopt(TCP_KEEPIDLE) failed");
	}

	// 3. 设置 TCP_KEEPINTVL: 探测间隔
	if (setsockopt(sock_fd, IPPROTO_TCP, TCP_KEEPINTVL, (char *) &keepintl,
			sizeof(keepintl)) < 0) {
		perror("setsockopt(TCP_KEEPINTVL) failed");
	}

	// 4. 设置 TCP_KEEPCNT: 探测次数
	if (setsockopt(sock_fd, IPPROTO_TCP, TCP_KEEPCNT, (char *) &keepcnt,
			sizeof(keepcnt)) < 0) {
		perror("setsockopt(TCP_KEEPCNT) failed");
	}
}
