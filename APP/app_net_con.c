/********************************************************************************
 * @file    app_net_con.c
 * @author  Gemini Architect & <Your Name>
 * @brief   网络连接管理器模块
 *
 * @description
 * 本模块实现了一个核心任务 ConnectionManagerTask，作为整个系统的“网络总机”。
 * 其主要职责包括：
 * - 启动时根据全局配置 g_system_config 初始化所有16个通道的网络服务。
 * - 统一监听所有 TCP Server 端口，并接受（accept）新的客户端连接。
 * - 在接受新连接前，检查并实施每个通道的最大连接数限制。
 * - 统一管理所有 TCP Client 的非阻塞连接（connect）过程。
 * - 将所有准备就绪（已连接或已绑定）的 socket 文件描述符 (fd) 通过消息队列
 * 准确地分发给对应的上层业务任务（如 RealTimeSchedulerTask）。
 * - 监听一个控制消息队列，以支持对任意通道进行动态的网络模式切换，并处理
 * 来自业务任务的连接关闭通知。
 *
 * @design_principles
 * - **单一职责**: 本任务只负责连接的“建立”、“分发”与“计数”，不参与任何业务数据的收发。
 * - **模块化**: 复杂的逻辑被分解为一系列职责清晰的 static 辅助函数。
 * - **事件驱动**: 采用 select() 模型，高效地处理网络事件和控制命令。
 * - **配置驱动**: 所有网络行为均由全局 g_system_config 结构驱动。
 ********************************************************************************/

#include <vxWorks.h>
#include <taskLib.h>
#include <msgQLib.h>
#include <sockLib.h>
#include <inetLib.h>
#include <selectLib.h>
#include <fcntl.h>
#include <errnoLib.h>
#include <string.h>
#include <stdio.h>

#include "./inc/app_net_con.h" // 模块自身的公共头文件
#include "./inc/app_com.h"     // 包含 SystemConfiguration, NewConnectionMsg 等核心结构

/* ================================================================================
 * 宏定义与内部数据结构
 * ================================================================================ */

// 任务配置
#define MANAGER_TASK_NAME       "tNetConnMgr"
#define MANAGER_TASK_PRIORITY   70
#define MANAGER_TASK_STACK_SIZE 8192 // 为网络操作提供充足的栈空间
#define MANAGER_CTRL_MSG_Q_SIZE 20   // 控制消息队列深度，以应对突发命令

// 内部使用的 "监听Socket映射表"，用于通过 listen_fd 快速反查其来源信息
typedef struct {
    int             listen_fd;
    int             channel_index;
    ConnectionType  conn_type;
    BOOL            is_in_use;
} ListenerMap;

// 内部使用的 "待连接TCP Client列表"，用于跟踪非阻塞 connect 的状态
typedef struct {
    int             socket_fd;
    int             channel_index;
    ConnectionType  conn_type;
    BOOL            is_in_use;
} PendingConnection;

#define MAX_LISTENERS           (16 * 2 + 1) // 16串口*2(RealCom)+1全局配置
#define MAX_PENDING_CONNECTIONS (16 * 8)     // 16串口*8(TCP Client)

/* ================================================================================
 * 模块级静态变量
 * ================================================================================ */

static int      g_manager_task_id = 0;
static MSG_Q_ID g_manager_ctrl_q  = NULL; // 接收控制命令的消息队列

// 内部状态管理表
static ListenerMap       g_listener_map[MAX_LISTENERS];
static PendingConnection g_pending_connections[MAX_PENDING_CONNECTIONS];
static int               g_active_tcp_connections[NUM_PORTS]; // 跟踪每个通道的活跃TCP连接数

// --- 外部依赖 ---
extern SystemConfiguration g_system_config;
extern MSG_Q_ID g_net_conn_q[NUM_PORTS];
extern MSG_Q_ID g_serial_port_ctrl_q[NUM_PORTS];

/* ================================================================================
 * 内部辅助函数声明
 * ================================================================================ */

static void ConnectionManagerTask(void);
static void process_control_messages(void);
static void process_network_events(fd_set* p_readfds, fd_set* p_writefds);
static void setup_channel(int channel_index);
static void teardown_channel(int channel_index);
static void handle_new_connections(fd_set* p_readfds);
static void handle_pending_connections(fd_set* p_writefds);
static int  create_tcp_listener(int port);
static void add_to_listener_map(int fd, int ch_index, ConnectionType type);
static void add_to_pending_list(int fd, int ch_index, ConnectionType type);
static void remove_from_pending_list(int fd);


/* ================================================================================
 * 公共接口函数实现
 * ================================================================================ */

STATUS ConnectionManager_TaskStart(void) {
    if (g_manager_task_id != 0) {
        LOG_ERROR(stderr, "ConnectionManager: Task is already running.\n");
        return ERROR;
    }

    g_manager_ctrl_q = msgQCreate(MANAGER_CTRL_MSG_Q_SIZE, sizeof(ManagerCtrlMsg), MSG_Q_FIFO);
    if (g_manager_ctrl_q == NULL) {
        LOG_ERROR("ConnectionManager: Failed to create control message queue");
        return ERROR;
    }
    
    g_manager_task_id = taskSpawn(MANAGER_TASK_NAME, MANAGER_TASK_PRIORITY, 0,
                                  MANAGER_TASK_STACK_SIZE, (FUNCPTR)ConnectionManagerTask,
                                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    if (g_manager_task_id == ERROR) {
        perror("ConnectionManager: Failed to spawn task");
        msgQDelete(g_manager_ctrl_q);
        g_manager_ctrl_q = NULL;
        return ERROR;
    }
    
    LOG_INFO("Connection Manager Task started successfully.\n");
    return OK;
}

STATUS ConnectionManager_RequestReconfigure(int channel_index) {
    if (channel_index < 0 || channel_index >= NUM_PORTS) return ERROR;
    if (g_manager_ctrl_q == NULL) return ERROR;
    
    ManagerCtrlMsg msg;
    msg.cmd_type = CTRL_CMD_RECONFIGURE_CHANNEL;
    msg.channel_index = channel_index;
    return msgQSend(g_manager_ctrl_q, (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL);
}

STATUS ConnectionManager_NotifyConnectionClosed(int channel_index) {
    if (channel_index < 0 || channel_index >= NUM_PORTS) return ERROR;
    if (g_manager_ctrl_q == NULL) return ERROR;
    
    ManagerCtrlMsg msg;
    msg.cmd_type = CTRL_CMD_CONNECTION_CLOSED;
    msg.channel_index = channel_index;
    return msgQSend(g_manager_ctrl_q, (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL);
}

/* ================================================================================
 * 任务主函数
 * ================================================================================ */

static void ConnectionManagerTask(void) {
    int i;
    LOG_INFO("Connection Manager Task entering main loop.\n");

    // --- 1. 初始化 ---
    memset(g_listener_map, 0, sizeof(g_listener_map));
    memset(g_pending_connections, 0, sizeof(g_pending_connections));
    memset(g_active_tcp_connections, 0, sizeof(g_active_tcp_connections));
    
    for (i = 0; i < NUM_PORTS; i++) {
        setup_channel(i);
    }
    
    // --- 2. 主循环 ---
    while (1) {
        fd_set readfds, writefds;
        int max_fd = 0;
        struct timeval timeout = {0, 200 * 1000}; // 200ms

        FD_ZERO(&readfds);
        FD_ZERO(&writefds);
        
        for (i = 0; i < MAX_LISTENERS; i++) {
            if (g_listener_map[i].is_in_use) {
                FD_SET(g_listener_map[i].listen_fd, &readfds);
                if (g_listener_map[i].listen_fd > max_fd) max_fd = g_listener_map[i].listen_fd;
            }
        }
        for ( i = 0; i < MAX_PENDING_CONNECTIONS; i++) {
            if (g_pending_connections[i].is_in_use) {
                FD_SET(g_pending_connections[i].socket_fd, &writefds);
                if (g_pending_connections[i].socket_fd > max_fd) max_fd = g_pending_connections[i].socket_fd;
            }
        }
        
        process_control_messages();
        
        int ret = select(max_fd + 1, &readfds, &writefds, NULL, &timeout);
        
        if (ret > 0) {
            process_network_events(&readfds, &writefds);
        } else if (ret < 0) {
            perror("ConnectionManager: select() error");
            taskDelay(sysClkRateGet());
        }
    }
}

/* ================================================================================
 * 内部辅助函数实现
 * ================================================================================ */

static void process_control_messages(void) {
    ManagerCtrlMsg msg;
    if (msgQReceive(g_manager_ctrl_q, (char*)&msg, sizeof(msg), NO_WAIT) == OK) {
        switch (msg.cmd_type) {
            case CTRL_CMD_RECONFIGURE_CHANNEL:
                LOG_DEBUG("Received reconfigure command for channel %d.\n", msg.channel_index);
                teardown_channel(msg.channel_index);
                setup_channel(msg.channel_index);
                break;
            case CTRL_CMD_CONNECTION_CLOSED:
                if (g_active_tcp_connections[msg.channel_index] > 0) {
                    g_active_tcp_connections[msg.channel_index]--;
                }
                break;
        }
    }
}

static void process_network_events(fd_set* p_readfds, fd_set* p_writefds) {
    handle_new_connections(p_readfds);
    // @todo pendig untested
    handle_pending_connections(p_writefds);
}

static void handle_new_connections(fd_set* p_readfds) {\
	int i;
    for ( i = 0; i < MAX_LISTENERS; i++) {
        if (g_listener_map[i].is_in_use && FD_ISSET(g_listener_map[i].listen_fd, p_readfds)) {
            
            int channel_index = g_listener_map[i].channel_index;
            UINT8 max_connections = g_system_config.channels[channel_index].max_connections;

            if (g_active_tcp_connections[channel_index] >= max_connections) {
                LOG_DEBUG("Max connection limit (%d) reached for channel %d. Rejecting.\n", max_connections, channel_index);
                int temp_fd = accept(g_listener_map[i].listen_fd, NULL, NULL);
                if (temp_fd >= 0) close(temp_fd);
                continue;
            }

            struct sockaddr_in client_addr;
            int addr_len = sizeof(client_addr);
            int client_fd = accept(g_listener_map[i].listen_fd, (struct sockaddr*)&client_addr, &addr_len);
            
            if (client_fd >= 0) {
                g_active_tcp_connections[channel_index]++;
                LOG_DEBUG("Accepted fd=%d for channel %d from %s. Active count: %d\n", 
                       client_fd, channel_index, inet_ntoa(client_addr.sin_addr), g_active_tcp_connections[channel_index]);
                       
                NewConnectionMsg msg;
                msg.client_fd = client_fd;
                msg.channel_index = channel_index;
                msg.type = g_listener_map[i].conn_type;
                if (msgQSend(g_net_conn_q[msg.channel_index], (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL) != OK) {
                    LOG_ERROR("Failed to dispatch fd=%d. Closing and decrementing count.\n", client_fd);
                    close(client_fd);
                    g_active_tcp_connections[channel_index]--;
                }
            } else {
                 perror("accept() failed");
            }
        }
    }
}

static void handle_pending_connections(fd_set* p_writefds) {
	int i;
    PendingConnection temp_pending[MAX_PENDING_CONNECTIONS];
    memcpy(temp_pending, g_pending_connections, sizeof(temp_pending));

    for ( i = 0; i < MAX_PENDING_CONNECTIONS; i++) {
        if (temp_pending[i].is_in_use && FD_ISSET(temp_pending[i].socket_fd, p_writefds)) {
            int err = 0, len = sizeof(err), fd = temp_pending[i].socket_fd;
            remove_from_pending_list(fd);
            
            if (getsockopt(fd, SOL_SOCKET, SO_ERROR, (char*)&err, &len) == 0 && err == 0) {
                LOG_DEBUG("TCP Client (fd=%d) connected for channel %d.\n", fd, temp_pending[i].channel_index);
                NewConnectionMsg msg;
                msg.client_fd = fd;
                msg.channel_index = temp_pending[i].channel_index;
                msg.type = temp_pending[i].conn_type;
                    
                if (msgQSend(g_net_conn_q[msg.channel_index], (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL) != OK) {
                     LOG_ERROR("Failed to dispatch connected fd=%d. Closing.\n", fd);
                     close(fd);
                }
            } else {
                LOG_ERROR("TCP Client (fd=%d) failed for channel %d: %s\n", fd, temp_pending[i].channel_index, strerror(err));
                close(fd);
            }
        }
    }
}

static void teardown_channel(int channel_index) {
	int i;
    PortTaskCtrlMsg msg = {PORT_TASK_CTRL_CMD_CLOSE_ALL_FDS};
    msgQSend(g_serial_port_ctrl_q[channel_index], (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL);
    
    for ( i = 0; i < MAX_LISTENERS; i++) {
        if (g_listener_map[i].is_in_use && g_listener_map[i].channel_index == channel_index) {
            close(g_listener_map[i].listen_fd);
            g_listener_map[i].is_in_use = FALSE;
        }
    }
    for ( i = 0; i < MAX_PENDING_CONNECTIONS; i++) {
        if (g_pending_connections[i].is_in_use && g_pending_connections[i].channel_index == channel_index) {
            close(g_pending_connections[i].socket_fd);
            g_pending_connections[i].is_in_use = FALSE;
        }
    }
    g_active_tcp_connections[channel_index] = 0;
    LOG_DEBUG("Network resources for channel %d torn down.\n", channel_index);
}

static void setup_channel(int channel_index) {
    ChannelState* cfg = &g_system_config.channels[channel_index];

    switch (cfg->op_mode) {
        case OP_MODE_REAL_COM: 
        {
            int data_fd = create_tcp_listener(cfg->data_port);
            if (data_fd >= 0) add_to_listener_map(data_fd, channel_index, CONN_TYPE_REALCOM_DATA);
            
            if (cfg->command_port > 0) {
                 int cmd_fd = create_tcp_listener(cfg->command_port);
                 if (cmd_fd >= 0) add_to_listener_map(cmd_fd, channel_index, CONN_TYPE_REALCOM_CMD);
            }
            break;
        }
        case OP_MODE_TCP_SERVER:
        {
            int data_fd = create_tcp_listener(cfg->local_tcp_port);
            if (data_fd >= 0) add_to_listener_map(data_fd, channel_index, CONN_TYPE_TCPSERVER);
            
            if (cfg->command_port > 0) {
                 int cmd_fd = create_tcp_listener(cfg->command_port);
                 if (cmd_fd >= 0) add_to_listener_map(cmd_fd, channel_index, CONN_TYPE_REALCOM_CMD);
            }
            break;
        }
        case OP_MODE_TCP_CLIENT: {
        	int j;
            for (j = 0; j < 4; j++) {
                if (cfg->tcp_destinations[j].destination_ip == 0 || cfg->tcp_destinations[j].destination_port == 0) continue;
                
                int client_fd = socket(AF_INET, SOCK_STREAM, 0);
                if (client_fd < 0) continue;
                
                fcntl(client_fd, F_SETFL, O_NONBLOCK);
                
                struct sockaddr_in server_addr = {0};
                server_addr.sin_family = AF_INET;
                server_addr.sin_port = htons(cfg->tcp_destinations[j].destination_port);
                server_addr.sin_addr.s_addr = cfg->tcp_destinations[j].destination_ip;
                
                if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
                    if (errno == EINPROGRESS) {
                        add_to_pending_list(client_fd, channel_index, CONN_TYPE_TCPCLIENT);
                    } else {
                        perror("connect() error");
                        close(client_fd);
                    }
                } else {
                     NewConnectionMsg msg;
                     msg.client_fd = client_fd;
                     msg.channel_index = channel_index;
                     msg.type = CONN_TYPE_TCPCLIENT;
                     msgQSend(g_net_conn_q[channel_index], (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL);
                }
            }
            break;
        }
        case OP_MODE_UDP: {
            int udp_fd = socket(AF_INET, SOCK_DGRAM, 0);
            if (udp_fd < 0) break;
            
            struct sockaddr_in addr = {0};
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = htonl(INADDR_ANY);
            addr.sin_port = htons(cfg->udp_destinations[0].port);
            
            if (bind(udp_fd, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
                NewConnectionMsg msg;
                msg.client_fd = udp_fd;
                msg.channel_index = channel_index;
                msg.type = CONN_TYPE_UDP;
                msgQSend(g_net_conn_q[channel_index], (char*)&msg, sizeof(msg), NO_WAIT, MSG_PRI_NORMAL);
            } else {
                perror("UDP bind failed");
                close(udp_fd);
            }
            break;
        }
        default: break;
    }
    LOG_DEBUG("Network resources for channel %d set up for mode %d.\n", channel_index, cfg->op_mode);
}

static int create_tcp_listener(int port) {
    if (port == 0) return ERROR;
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) { perror("socket()"); return ERROR; }
    
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int opt = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));

    if (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind()"); close(listen_fd); return ERROR;
    }
    if (listen(listen_fd, 8) < 0) {
        perror("listen()"); close(listen_fd); return ERROR;
    }
    return listen_fd;
}

static void add_to_listener_map(int fd, int ch_index, ConnectionType type) {
	int i;
    for ( i = 0; i < MAX_LISTENERS; i++) {
        if (!g_listener_map[i].is_in_use) {
            g_listener_map[i].listen_fd = fd;
            g_listener_map[i].channel_index = ch_index;
            g_listener_map[i].conn_type = type;
            g_listener_map[i].is_in_use = TRUE;
            return;
        }
    }
    LOG_ERROR("Listener map is full! Cannot add fd %d.\n", fd);
}

static void add_to_pending_list(int fd, int ch_index, ConnectionType type) {\
	int i;
    for ( i = 0; i < MAX_PENDING_CONNECTIONS; i++) {
        if (!g_pending_connections[i].is_in_use) {
            g_listener_map[i].listen_fd = fd;
            g_listener_map[i].channel_index = ch_index;
            g_listener_map[i].conn_type = type;
            g_listener_map[i].is_in_use = TRUE;
            return;
        }
    }
    LOG_ERROR("Pending connections list is full! Cannot add fd %d.\n", fd);
}

static void remove_from_pending_list(int fd) {
	int i;
    for ( i = 0; i < MAX_PENDING_CONNECTIONS; i++) {
        if (g_pending_connections[i].is_in_use && g_pending_connections[i].socket_fd == fd) {
            g_pending_connections[i].is_in_use = FALSE;
            return;
        }
    }
}
