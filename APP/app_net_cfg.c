/*
 * =====================================================================================
 *
 * Filename:  ConfigTaskManager.c
 *
 * Description:  实现 ConfigTaskManager 任务，包含完整的协议处理逻辑。
 *
 * =====================================================================================
 */
#include <time.h>      // For inactivity timeout check
#include <stdlib.h>    // For atoi, etc.
#include <arpa/inet.h> // For htonl, ntohl etc.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./inc/app_com.h"
#include "./inc/app_uart.h"
#include "./inc/app_net_proto.h"
#include "./inc/app_net.h"


// 内部宏定义
#define INACTIVITY_TIMEOUT_SECONDS 300 // 5分钟无活动则超时




/* ------------------ Private Function Prototypes ------------------ */
static void cleanup_config_connection(int index);
static int handle_config_client(int index);
static void process_command_frame(int session_index, const unsigned char* frame, int len);

/* ------------------ Module-level static variables ------------------ */
ClientSession s_sessions[MAX_CONFIG_CLIENTS];
static int s_num_active_sessions = 0;

/* ------------------ Global Variable Definitions ------------------ */
TASK_ID g_config_task_manager_tid;
SEM_ID g_config_mutex;
SystemConfiguration g_system_config; // 全局配置变量的实体定义

/**
 * @brief ConfigTaskManager 的主入口函数
 */
void ConfigTaskManager(void)
{
    int i;
    LOG_INFO("ConfigTaskManager: Starting...\n");

    // 初始化会话列表
    for (i = 0; i < MAX_CONFIG_CLIENTS; i++) {
        s_sessions[i].fd = -1;
        s_sessions[i].rx_bytes = 0;
    }

    while (1)
    {
        /* ------------------ 1. 检查并接管新连接 ------------------ */
        NewConnectionMsg msg;
        while (msgQReceive(g_config_conn_q, (char*)&msg, sizeof(msg), NO_WAIT) == sizeof(NewConnectionMsg))
        {
            if (s_num_active_sessions < MAX_CONFIG_CLIENTS) {
                int new_index = s_num_active_sessions;
                s_sessions[new_index].fd = msg.client_fd;
                s_sessions[new_index].type = msg.type;
                s_sessions[new_index].channel_index = msg.channel_index;
                s_sessions[new_index].last_activity_time = time(NULL);
                s_sessions[new_index].rx_bytes = 0;
                s_num_active_sessions++;
                LOG_DEBUG("ConfigTaskManager: Accepted new connection fd=%d, type=%d, channel_index=%d. Total sessions: %d\n",
                    msg.client_fd, msg.type, msg.channel_index, s_num_active_sessions);
                if (msg.type == CONN_TYPE_REALCOM_CMD && msg.channel_index >= 0) {
                    int i = msg.channel_index;
                    ChannelState* channel = &g_system_config.channels[i];

                    semTake(g_config_mutex, WAIT_FOREVER);
                    if (channel->cmd_net_info.num_clients < MAX_CLIENTS_PER_CHANNEL) {
                        int client_idx = channel->cmd_net_info.num_clients;
                        channel->cmd_net_info.client_fds[client_idx] = msg.client_fd;
                        
                        if (channel->cmd_net_info.num_clients == 0) {
                            // 第一个客户端连接，状态从 LISTENING 变为 CONNECTED
                            channel->cmd_net_info.state = NET_STATE_CONNECTED;
                        }
                        channel->cmd_net_info.num_clients++;
                        
                        LOG_INFO("ConfigTask: Ch %d accepted new CMD client fd=%d. Total CMD clients for this port: %d\n", i, msg.client_fd, channel->cmd_net_info.num_clients);

                    } else {
                        // 如果此通道的命令连接已满，则拒绝
                        LOG_ERROR("ConfigTask: Ch %d CMD client limit reached. Rejecting fd=%d\n", i, msg.client_fd);
                        close(msg.client_fd);
                        // 因为连接被拒绝，所以不将会话加入 s_sessions 列表
                        s_num_active_sessions--; 
                    }
                    semGive(g_config_mutex);
                }
                LOG_INFO("ConfigTask: Accepted new config connection fd=%d\n", msg.client_fd);
            } else {
                LOG_ERROR("ConfigTaskManager: Max config clients reached. Rejecting fd=%d\n", msg.client_fd);
                close(msg.client_fd);
            }
        }

        if (s_num_active_sessions == 0) {
            taskDelay(sysClkRateGet()); // 没有连接时，休眠1秒
            continue;
        }

        /* ------------------ 2. 构建select监听集合 ------------------ */
        fd_set read_fds;
        int max_fd = 0;
        FD_ZERO(&read_fds);
        for (i = 0; i < s_num_active_sessions; i++) {
            FD_SET(s_sessions[i].fd, &read_fds);
            if (s_sessions[i].fd > max_fd) {
                max_fd = s_sessions[i].fd;
            }
        }

        /* ------------------ 3. 阻塞等待事件 ------------------ */
        struct timeval timeout = { 5, 0 }; // 5秒超时
        int ret = select(max_fd + 1, &read_fds, NULL, NULL, &timeout);

        if (ret < 0) {
            if (errno == EINTR) continue;
            LOG_ERROR("ConfigTaskManager: select() error");
            taskDelay(sysClkRateGet());
            continue;
        }

        /* ------------------ 4. 处理就绪的连接和超时 ------------------ */
        time_t now = time(NULL);
        // 从后往前遍历，方便在循环中安全地移除断开的连接
        for (i = s_num_active_sessions - 1; i >= 0; i--) {
            int connection_alive = 1; // 1 for true
            if (FD_ISSET(s_sessions[i].fd, &read_fds)) {
                // 有数据可读
                s_sessions[i].last_activity_time = now;
                connection_alive = handle_config_client(i);
            } else if (ret == 0) {
                // select超时，检查此连接是否不活动超时
                if ((now - s_sessions[i].last_activity_time) > INACTIVITY_TIMEOUT_SECONDS) {
                    LOG_INFO("ConfigTaskManager: fd=%d timed out due to inactivity.\n", s_sessions[i].fd);
                    connection_alive = 0; // 0 for false
                }
            }

            if (connection_alive == 0) {
                cleanup_config_connection(i);
            }
        }
    }
}

/**
 * @brief 处理单个串口配置指令
 * @details 直接将接收到的数据缓冲区传递给 app_uart.c 中的 handle_command。
 */
static void handle_serial_port_command(ClientSession* session) {
    
    ChannelState* p_channel = &g_system_config.channels[session->channel_index];
    handle_command(p_channel, session->fd, (char*)session->rx_buffer, session->rx_bytes, session->channel_index);
    // 处理完后清空缓冲区，准备接收下一条指令
    session->rx_bytes = 0;
}

/**
 * @brief 处理全局设备配置指令 (CONN_TYPE_SETTING)
 * @details 从字节流中解析出带 A5A5 帧头帧尾的完整协议帧，并交给 process_command_frame 处理。
 */
static void handle_global_setting_frame(int session_index, ClientSession* session) {
    while (session->rx_bytes >= MIN_FRAME_SIZE) {
        int frame_start = -1, frame_end = -1, i;

         // 1. 寻找帧头 (0xA5A5)
        for (i = 0; i <= session->rx_bytes - 2; i++) {
            if (session->rx_buffer[i] == HEAD_ID_B1 && session->rx_buffer[i+1] == HEAD_ID_B2) {
                frame_start = i;
                break;
            }
        }

        if (frame_start == -1) {
            // 缓冲区中没有帧头，所有数据都可能是无效的，但为了安全，只丢弃部分
            // 这样可以防止因丢失一个字节而丢弃整个缓冲区
            session->rx_bytes = 0;
            break;
        }

        // 如果帧头不在缓冲区开头，丢弃之前的所有垃圾数据
        if (frame_start > 0) {
            memmove(session->rx_buffer, session->rx_buffer + frame_start, session->rx_bytes - frame_start);
            session->rx_bytes -= frame_start;
        }

        // 2. 在找到帧头后，寻找帧尾 (0x5A5A)
        // 帧尾至少在帧头后4个字节 (Cmd+Sub+End)
        if (session->rx_bytes >= MIN_FRAME_SIZE) {
            for (i = MIN_FRAME_SIZE - 2; i <= session->rx_bytes - 2; i++) {
                if (session->rx_buffer[i] == END_ID_B1 && session->rx_buffer[i+1] == END_ID_B2) {
                    frame_end = i;
                    break;
                }
            }
        }

        if (frame_end != -1) {
            // 找到了一个完整的帧
            int frame_len = frame_end + 2;
            process_command_frame(session_index, session->rx_buffer, frame_len);
            // 从缓冲区中移除已处理的帧
            memmove(session->rx_buffer, session->rx_buffer + frame_len, session->rx_bytes - frame_len);
            session->rx_bytes -= frame_len;
        } else {
            break;
        }
    }
}


/**
 * @brief 接收数据并根据连接类型分发到不同的处理函数
 * @return 1 表示连接存活, 0 表示连接断开
 */
static int handle_config_client(int index) {
    ClientSession* session = &s_sessions[index];
    
    int n = recv(session->fd, (char*)session->rx_buffer + session->rx_bytes, 
                 MAX_COMMAND_LEN - session->rx_bytes, 0);
  
    if (n > 0) {
        session->rx_bytes += n;
       if (session->type == CONN_TYPE_REALCOM_CMD) {
            handle_serial_port_command(session);
        } else if (session->type == CONN_TYPE_SETTING) {
            LOG_DEBUG("CONN_TYPE_SETTING");
            handle_global_setting_frame(index, session);
        }
        return 1;
    } else if (n == 0) {
        return 0;
    } else {
        return (errno == EWOULDBLOCK || errno == EAGAIN) ? 1 : 0;
    }
}


/**
 * @brief 用于全局配置指令
 */
static void process_command_frame(int session_index, const unsigned char* frame, int len)
{
    unsigned char cmd_id = frame[2];
    switch (cmd_id) {
        case CMD_OVERVIEW: 
            handle_overview_request(session_index); 
            break;
        case CMD_BASIC_SETTINGS:
            handle_basic_settings_request(session_index, frame, len);
            break;
        case CMD_NETWORK_SETTINGS:
            handle_network_settings_request(session_index, frame, len);
            break;
        case CMD_SERIAL_SETTINGS:
            handle_serial_settings_request(session_index, frame, len);
            break;
        case CMD_OPERATING_SETTINGS:
            handle_operating_settings_request(session_index, frame, len);
            break;
        case CMD_MONITOR:
            handle_monitor_request(session_index, frame, len);
            break;
        case CMD_ADMIN:
            handle_change_password_request(session_index, frame, len);
            break;
        default:
            LOG_WARN("Unknown command ID: 0x%02X", cmd_id);
            break;
    }
}

/**
 * @brief 清理一个已断开的配置连接 (全局或单个串口)
 * @details 关闭socket，从会话列表中移除，并根据情况更新通道状态。
 * 特别是，当一个通道的所有网络连接（数据和命令）都断开时，
 * 它会将该通道的物理串口状态（uart_state）更新为 CLOSED。
 * * @param index 要清理的会话在 s_sessions 数组中的索引
 */
static void cleanup_config_connection(int index) 
{
	int i=0;
    if (index < 0 || index >= s_num_active_sessions) {
        LOG_WARN("cleanup_config_connection: Invalid index %d.", index);
        return;
    }

    ClientSession* session = &s_sessions[index];
    int fd_to_close = session->fd;

    // --- 步骤 1: 如果是特定通道的命令连接，则更新其状态 ---
    if (session->type == CONN_TYPE_REALCOM_CMD && session->channel_index >= 0) {
        int channel_index = session->channel_index;
        
        semTake(g_config_mutex, WAIT_FOREVER);
        ChannelState* channel = &g_system_config.channels[channel_index];
        
        // 在该通道的客户端数组中查找并移除 fd
        int client_found = 0;
        for (i = 0; i < channel->cmd_net_info.num_clients; i++) {
            if (channel->cmd_net_info.client_fds[i] == fd_to_close) {
                // 找到了，用最后一个元素覆盖当前位置，然后缩减数组大小
                int last_client_index = channel->cmd_net_info.num_clients - 1;
                channel->cmd_net_info.client_fds[i] = channel->cmd_net_info.client_fds[last_client_index];
                channel->cmd_net_info.client_fds[last_client_index] = -1; // 清理
                channel->cmd_net_info.num_clients--;
                client_found = 1;
                break;
            }
        }

        // 如果这是最后一个命令客户端，更新网络状态
        if (client_found && channel->cmd_net_info.num_clients == 0) {
            channel->cmd_net_info.state = NET_STATE_LISTENING;
            LOG_INFO("ConfigTask: Ch %d has no CMD clients left. State -> LISTENING.\n", channel_index);
            
            // *** 检查数据通道是否也已没有客户端 ***
            if (channel->data_net_info.num_clients == 0) {
                channel->uart_state = UART_STATE_CLOSED;
                LOG_INFO("ConfigTask: All network clients for Ch %d disconnected. UART physical state -> CLOSED.\n", channel_index);
            }
        }
        semGive(g_config_mutex);
    }

    // --- 步骤 2: 关闭 socket 文件描述符 ---
    close(fd_to_close);
    LOG_INFO("ConfigTask: Cleaned up client fd=%d.\n", fd_to_close);

    // --- 步骤 3: 从全局会话数组 s_sessions 中移除 ---
    // 通过将最后一个元素移动到当前位置来高效地删除，避免移动整个数组
    int last_index = s_num_active_sessions - 1;
    if (index != last_index) {
        s_sessions[index] = s_sessions[last_index];
    }
    // 清理最后一个元素的数据
    s_sessions[last_index].fd = -1;
    s_sessions[last_index].type = 0;
    s_sessions[last_index].channel_index = -1;
    s_num_active_sessions--;
}


/**
 * @brief 设置网络接口的IP地址、子网掩码和默认网关。
 *
 * @param interface_name 网络接口名称 (例如 "fei0").
 * @param ip_address 要设置的IP地址 (例如 "192.168.1.10").
 * @param netmask 要设置的子网掩码 (例如 "255.255.255.0").
 * @param gateway 要设置的默认网关 (例如 "192.168.1.1").
 * @return 0 表示成功, -1 表示失败.
 */
int net_cfg_set_network_settings(const char *interface_name, const char *ip_address, const char *netmask, const char *gateway)
{
    char command_buffer[128];

    /******************************************************************/
    /* 1. 使用 ifconfig 设置 IP 地址和子网掩码                          */
    /******************************************************************/
    // 构造 ifconfig 命令: "interface ip_address netmask xxx.xxx.xxx.xxx"
    snprintf(command_buffer, sizeof(command_buffer), "%s %s netmask %s", interface_name, ip_address, netmask);

    printf("Executing ifconfig command: '%s'\n", command_buffer);
    if (ifconfig(command_buffer) != 0) // 假设成功返回 0
    {
        perror("ifconfig failed");
        return -1;
    }
    printf("Successfully set IP address and netmask.\n");


    /******************************************************************/
    /* 2. 使用 routec 添加默认网关                                    */
    /******************************************************************/
    // 构造 routec 命令: "add default gateway_ip"
    // 根据 routec 文档, "default" 是默认路由的目标地址
    snprintf(command_buffer, sizeof(command_buffer), "add default %s", gateway);

    printf("Executing routec command: '%s'\n", command_buffer);
    if (routec(command_buffer) != 0) // 假设成功返回 0
    {
        perror("routec failed to set default gateway");
        return -1;
    }
    printf("Successfully set default gateway.\n");

    return 0;
}


