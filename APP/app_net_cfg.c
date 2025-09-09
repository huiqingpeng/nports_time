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
#include "./inc/app_com.h"
#include "./inc/app_uart.h"

// 内部宏定义
#define INACTIVITY_TIMEOUT_SECONDS 30000 // 5分钟无活动则超时
#define MAX_COMMAND_LEN 1024
#define HEAD_ID_B1 0xA5
#define HEAD_ID_B2 0xA5
#define END_ID_B1 0x5A
#define END_ID_B2 0x5A
#define MIN_FRAME_SIZE 6 // Head(2) + Cmd(1) + Sub(1) + End(2)

// 内部会话管理结构体
typedef struct {
    int fd;
    ConnectionType type;
    int channel_index;
    time_t last_activity_time;
    // 接收缓冲区，用于处理不完整的TCP数据包
    unsigned char rx_buffer[MAX_COMMAND_LEN];
    int rx_bytes;
} ClientSession;

/* ------------------ Private Function Prototypes ------------------ */
static void cleanup_config_connection(int index);
static int handle_config_client(int index);
static void process_command_frame(int session_index, const unsigned char* frame, int len);

// --- 新封装的协议处理函数 ---
static void handle_global_setting_frame(int session_index, ClientSession* session);
static void handle_serial_port_command(ClientSession* session);


// Protocol Handlers
static void handle_overview_request(int session_index);
static void handle_basic_settings_request(int session_index, const unsigned char* frame, int len);
static void handle_network_settings_request(int session_index, const unsigned char* frame, int len);
static void handle_serial_settings_request(int session_index, const unsigned char* frame, int len);
static void handle_change_password_request(int session_index, const unsigned char* frame, int len);
static void handle_monitor_request(int session_index, const unsigned char* frame, int len);
static void handle_operating_settings_request(int session_index, const unsigned char* frame, int len);

static void send_response(int fd, const unsigned char* data, int len);
static void send_framed_ack(int fd, unsigned char cmd_id, unsigned char sub_id, int success);
static int pack_serial_settings(int channel_index, unsigned char* buffer);

static int set_single_port_mode(unsigned char port_index, unsigned char op_mode, const unsigned char* op_mode_data);
static int set_all_ports_mode(unsigned char op_mode, const unsigned char* op_mode_data);
static int validate_and_update_port_mode(ChannelState* channel, unsigned char op_mode, const unsigned char* op_mode_data);
static void handle_query_op_mode(int session_index, const unsigned char* frame);
static void handle_read_op_mode(int session_index, const unsigned char* frame);
static void handle_set_op_mode(int session_index, const unsigned char* frame);
static void send_op_mode_response(int fd, unsigned char cmd_id, unsigned char sub_id, const unsigned char* data, int data_len);

/* ------------------ Module-level static variables ------------------ */
static ClientSession s_sessions[MAX_CONFIG_CLIENTS];
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
                if (msg.type == CONN_TYPE_SET && msg.channel_index >= 0) {
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
 * @brief 处理单个串口配置指令 (CONN_TYPE_SET)
 * @details 直接将接收到的数据缓冲区传递给 app_uart.c 中的 handle_command。
 */
static void handle_serial_port_command(ClientSession* session) {
    
    ChannelState* p_channel_state = &g_system_config.channels[session->channel_index];

    handle_command(p_channel_state, session->fd, (char*)session->rx_buffer, session->rx_bytes, session->channel_index);
    
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
        
        if (session->type == CONN_TYPE_SET) {
            LOG_DEBUG("CONN_TYPE_SET");
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
 * @brief 主命令分发器 (仅用于全局配置指令)
 */
static void process_command_frame(int session_index, const unsigned char* frame, int len) { 
	
    unsigned char command_id = frame[2];
    switch (command_id) {
        case 0x01: handle_overview_request(session_index); break;
        case 0x02: handle_basic_settings_request(session_index, frame, len); break;
        case 0x03: handle_network_settings_request(session_index, frame, len); break;
        case 0x04: handle_serial_settings_request(session_index, frame, len); break;
        case 0x05: handle_operating_settings_request(session_index, frame, len); break;
        case 0x06: handle_monitor_request(session_index, frame, len); break;
        case 0x07: handle_change_password_request(session_index, frame, len); break;
        default:
            LOG_WARN("ConfigTask: Received unknown command ID 0x%02X\n", command_id);
            break;
    }
}

/**
 * @brief 发送一个带协议帧的简单ACK响应
 * @param fd      客户端socket
 * @param cmd_id  主命令ID
 * @param sub_id  子命令ID
 * @param success 成功(1)或失败(0)
 */
static void send_framed_ack(int fd, unsigned char cmd_id, unsigned char sub_id, int success)
{
    unsigned char response[7];
    int offset = 0;

    // 帧头
    response[offset++] = 0xA5;
    response[offset++] = 0xA5;

    // 功能码
    response[offset++] = cmd_id;
    response[offset++] = sub_id;

    // 数据 (ACK)
    response[offset++] = success ? 0x01 : 0x00;

    // 帧尾
    response[offset++] = 0x5A;
    response[offset++] = 0x5A;

    send_response(fd, response, offset);
}

/**
 * @brief 处理 0x01 - 概述信息请求 (新协议)
 * @details 根据新的帧协议规范 (Head ID + Data + End ID)，
 * 构建并发送包含设备概述信息的响应包。
 */
static void handle_overview_request(int session_index)
{
    // 响应包缓冲区，256字节足够存放所有信息
    unsigned char response[256]; 
    int offset = 0;
    size_t model_name_len;

    // --- 1. 填充帧头 (Head ID: 0xA5A5) ---
    response[offset++] = 0xA5;
    response[offset++] = 0xA5;

    // --- 2. 填充功能码 (Command_ID: 0x01, Sub_ID: 0x01) ---
    response[offset++] = 0x01; // Command_ID for Overview
    response[offset++] = 0x01; // Sub_ID for Read/Response

    // --- 3. 填充数据负载 (Data Payload) ---
    semTake(g_config_mutex, WAIT_FOREVER);
    
    // 3.1 Model Name (1 byte length + N bytes data)
    model_name_len = strlen(g_system_config.device.model_name);
    if (model_name_len > MAX_MODEL_NAME_LEN) {
        model_name_len = MAX_MODEL_NAME_LEN;
    }
    response[offset++] = (unsigned char)model_name_len;
    memcpy(&response[offset], g_system_config.device.model_name, MAX_MODEL_NAME_LEN);
    offset += MAX_MODEL_NAME_LEN;
    LOG_DEBUG("  [SENDING] Model Name: %s", g_system_config.device.model_name);

    // 3.2 MAC Address (6 bytes)
    memcpy(&response[offset], g_system_config.device.mac_address, 6);
    offset += 6;
    LOG_DEBUG("  [SENDING] MAC Address: %02X:%02X:%02X:%02X:%02X:%02X",
              g_system_config.device.mac_address[0], g_system_config.device.mac_address[1],
              g_system_config.device.mac_address[2], g_system_config.device.mac_address[3],
              g_system_config.device.mac_address[4], g_system_config.device.mac_address[5]);

    // 3.3 Serial No (2 bytes, network byte order)
    *(unsigned short*)&response[offset] = htons(g_system_config.device.serial_no);
    offset += 2;
    LOG_DEBUG("  [SENDING] Serial No: %u", g_system_config.device.serial_no);

    // 3.4 Firmware Version (3 bytes)
    memcpy(&response[offset], g_system_config.device.firmware_version, 3);
    offset += 3;
    LOG_DEBUG("  [SENDING] Firmware Version: %d.%d.%d", 
              g_system_config.device.firmware_version[0], g_system_config.device.firmware_version[1], 
              g_system_config.device.firmware_version[2]);

    // 3.5 Hardware Version (3 bytes)
    memcpy(&response[offset], g_system_config.device.hardware_version, 3);
    offset += 3;
    LOG_DEBUG("  [SENDING] Hardware Version: %d.%d.%d", 
              g_system_config.device.hardware_version[0], g_system_config.device.hardware_version[1], 
              g_system_config.device.hardware_version[2]);
    
    // 3.7 LCM (1 byte)
    response[offset++] = g_system_config.device.lcm_present;
    LOG_DEBUG("  [SENDING] LCM Present: %d", g_system_config.device.lcm_present);

    semGive(g_config_mutex);

    // 3.6 System Uptime (4 bytes)
    unsigned int uptime_sec = (sysClkRateGet() > 0) ? (tickGet() / sysClkRateGet()) : 0;
    response[offset++] = (unsigned char)(uptime_sec / 86400);        // byte1: Days
    response[offset++] = (unsigned char)((uptime_sec % 86400) / 3600); // byte2: Hours
    response[offset++] = (unsigned char)((uptime_sec % 3600) / 60);  // byte3: Minutes
    response[offset++] = (unsigned char)(uptime_sec % 60);           // byte4: Seconds
    LOG_DEBUG("  [SENDING] Uptime: %u seconds", uptime_sec);

    // --- 4. 填充帧尾 (End ID: 0x5A5A) ---
    response[offset++] = 0x5A;
    response[offset++] = 0x5A;

    // --- 5. 发送完整的响应包 ---
    // 'offset' 此时包含了整个数据包的长度
    send_response(s_sessions[session_index].fd, response, offset);
    
    LOG_INFO("ConfigTask: Sent Overview response (New Protocol). Total length: %d bytes.", offset);
}

/**
 * @brief 处理 0x02 - 基础设置请求 
 * @details 根据 Sub_ID 将请求分发给参数读取或参数写入的处理逻辑。
 */
static void handle_basic_settings_request(int session_index, const unsigned char* frame, int len)
{
    // 帧结构: [A5 A5] [CmdID] [SubID] [Data...] [5A 5A]
    unsigned char sub_id = frame[3]; 

    LOG_INFO("ConfigTask: Handling Basic Settings Request (0x02), Sub ID: 0x%02X...", sub_id);

    switch (sub_id) {
        case 0x00: // 参数读取 (设备 -> 上位机) 
            {
                unsigned char response[256];
                int offset = 0;
                size_t server_name_len;
                unsigned int time_server_ip_net_order; // 使用网络字节序的临时变量
                struct in_addr addr;

                // --- 1. 填充帧头和功能码 ---
                response[offset++] = 0xA5; response[offset++] = 0xA5; // Head ID
                response[offset++] = 0x02; response[offset++] = 0x00; // Command & Sub ID

                // --- 2. 填充数据负载 ---
                semTake(g_config_mutex, WAIT_FOREVER);
                
                // Server name (1 + 39 bytes)
                server_name_len = strlen(g_system_config.device.server_name);
                if (server_name_len > MAX_SERVER_NAME_LEN) server_name_len = MAX_SERVER_NAME_LEN;
                response[offset++] = (unsigned char)server_name_len;
                memcpy(&response[offset], g_system_config.device.server_name, MAX_SERVER_NAME_LEN);
                offset += MAX_SERVER_NAME_LEN;
                LOG_DEBUG("  [SENDING] len : %d Server Name: %s", server_name_len, g_system_config.device.server_name);

                // Time zone, Local time, Time server
                response[offset++] = g_system_config.device.time_zone;
                memcpy(&response[offset], g_system_config.device.local_time, 6);
                offset += 6;
                time_server_ip_net_order = htonl(g_system_config.device.time_server);
                memcpy(&response[offset], &time_server_ip_net_order, 4);
                offset += 4;
                addr.s_addr = time_server_ip_net_order;
                LOG_DEBUG("  [SENDING] Time Zone: %d", g_system_config.device.time_zone);
                LOG_DEBUG("  [SENDING] Local Time: %02d-%02d-%02d %02d:%02d:%02d", g_system_config.device.local_time[0], g_system_config.device.local_time[1], g_system_config.device.local_time[2], g_system_config.device.local_time[3], g_system_config.device.local_time[4], g_system_config.device.local_time[5]);
                LOG_DEBUG("  [SENDING] Time Server IP: %s", inet_ntoa(addr));

                // Settings (Web, Telnet, LCM, Reset)
                response[offset++] = g_system_config.device.web_console_enabled;
                response[offset++] = g_system_config.device.telnet_console_enabled;
                response[offset++] = g_system_config.device.lcm_password_protected;
                response[offset++] = g_system_config.device.reset_button_protected;
                LOG_DEBUG("  [SENDING] Web Console Enabled: %d", g_system_config.device.web_console_enabled);
                LOG_DEBUG("  [SENDING] Telnet Console Enabled: %d", g_system_config.device.telnet_console_enabled);
                LOG_DEBUG("  [SENDING] LCM Password Protected: %d", g_system_config.device.lcm_password_protected);
                LOG_DEBUG("  [SENDING] Reset Button Protected: %d", g_system_config.device.reset_button_protected);
                
                semGive(g_config_mutex);

                // --- 3. 填充帧尾 ---
                response[offset++] = 0x5A; response[offset++] = 0x5A; // End ID

                // --- 4. 发送响应包 ---
                send_response(s_sessions[session_index].fd, response, offset);
            }
            break;

        case 0x01: // Basic Settings (上位机 -> 设备), 现在包含所有基础设置
            {
                const unsigned char* data = frame + 4; // 数据部分从第4个字节之后开始
                unsigned char server_name_len = data[0];
                char received_server_name[MAX_SERVER_NAME_LEN + 1];
                struct in_addr addr;

                // 长度校验
                if (server_name_len > MAX_SERVER_NAME_LEN) {
                    LOG_ERROR("ConfigTask: Received invalid server name length (%d).", server_name_len);
                    send_framed_ack(s_sessions[session_index].fd, 0x02, 0x01, 0); // 0表示失败
                    return;
                }
                
                // 根据协议，Server name字段是固定的 1+39 字节，后续数据指针应基于此偏移
                const unsigned char* time_data = data + 1 + MAX_SERVER_NAME_LEN;

                // 打印接收到的信息
                strncpy(received_server_name, (const char*)&data[1], server_name_len);
                received_server_name[server_name_len] = '\0';
                LOG_DEBUG("  [RECEIVED] Server Name: %s", received_server_name);
                LOG_DEBUG("  [RECEIVED] Time Zone: %d", time_data[0]);
                LOG_DEBUG("  [RECEIVED] Local Time: %02d-%02d-%02d %02d:%02d:%02d", time_data[1], time_data[2], time_data[3], time_data[4], time_data[5], time_data[6]);
                memcpy(&addr.s_addr, &time_data[7], 4);
                LOG_DEBUG("  [RECEIVED] Time Server IP: %s", inet_ntoa(addr));

                // 根据合并后的协议，继续解析后续的开关量设置
                const unsigned char* settings_data = time_data + 11; // Time zone(1) + Local time(6) + Time server(4) = 11 bytes
                
                semTake(g_config_mutex, WAIT_FOREVER);
                
                // 更新 Server name
                memset(g_system_config.device.server_name, 0, sizeof(g_system_config.device.server_name));
                strncpy(g_system_config.device.server_name, (const char*)&data[1], server_name_len);
                
                // 更新时间相关设置
                g_system_config.device.time_zone = time_data[0];
                memcpy(g_system_config.device.local_time, &time_data[1], 6);
                memcpy(&g_system_config.device.time_server, &time_data[7], 4);
                g_system_config.device.time_server = ntohl(g_system_config.device.time_server);

                // 更新开关量设置
                g_system_config.device.web_console_enabled    = settings_data[0];
                g_system_config.device.telnet_console_enabled = settings_data[1];
                g_system_config.device.lcm_password_protected = settings_data[2];
                g_system_config.device.reset_button_protected = settings_data[3];

                LOG_DEBUG("  [RECEIVED] Web Console Enabled: %d", settings_data[0]);
                LOG_DEBUG("  [RECEIVED] Telnet Console Enabled: %d", settings_data[1]);
                LOG_DEBUG("  [RECEIVED] LCM Password Protected: %d", settings_data[2]);
                LOG_DEBUG("  [RECEIVED] Reset Button Protected: %d", settings_data[3]);

                semGive(g_config_mutex);
                
                // TODO: 在这里可以添加实际设置系统时间的代码
                
                LOG_INFO("ConfigTask: Updated all Basic Settings.");
                send_framed_ack(s_sessions[session_index].fd, 0x02, 0x01, 1); // 1表示成功
            }
            break;

        default:
            LOG_WARN("ConfigTask: Received unknown Sub_ID 0x%02X for Basic Settings.", sub_id);
            send_framed_ack(s_sessions[session_index].fd, 0x02, sub_id, 0); // 失败
            break;
    }
}

/**
 * @brief 处理 0x03 - 网络设置请求
 * @details 根据 Sub_ID 将请求分发给参数读取或写入的处理逻辑。
 */
static void handle_network_settings_request(int session_index, const unsigned char* frame, int len)
{
    // 帧结构: [A5 A5] [CmdID] [SubID] [Data...] [5A 5A]
    unsigned char sub_id = frame[3];
    struct in_addr addr; // 用于IP地址转换

    LOG_INFO("ConfigTask: Handling Network Settings Request (0x03), Sub ID: 0x%02X...", sub_id);

    switch (sub_id) {
        case 0x00: // 参数读取 (设备 -> 上位机)
            {
                unsigned char response[256];
                int offset = 0;
                unsigned int temp_ip;
                unsigned short temp_port;

                // --- 1. 填充帧头和功能码 ---
                response[offset++] = 0xA5; response[offset++] = 0xA5; // Head ID
                response[offset++] = 0x03; response[offset++] = 0x00; // Command & Sub ID

                // --- 2. 填充数据负载 ---
                semTake(g_config_mutex, WAIT_FOREVER);
                
                // IP, Netmask, Gateway (4+4+4 bytes)
                temp_ip = htonl(g_system_config.device.ip_address);
                memcpy(&response[offset], &temp_ip, 4);
                offset += 4;
                addr.s_addr = temp_ip;
                LOG_DEBUG("  [SENDING] IP Address: %s", inet_ntoa(addr));

                temp_ip = htonl(g_system_config.device.netmask);
                memcpy(&response[offset], &temp_ip, 4);
                offset += 4;
                addr.s_addr = temp_ip;
                LOG_DEBUG("  [SENDING] Netmask: %s", inet_ntoa(addr));

                temp_ip = htonl(g_system_config.device.gateway);
                memcpy(&response[offset], &temp_ip, 4);
                offset += 4;
                addr.s_addr = temp_ip;
                LOG_DEBUG("  [SENDING] Gateway: %s", inet_ntoa(addr));

                // IP configuration (1 byte)
                response[offset++] = g_system_config.device.ip_config_mode;
                LOG_DEBUG("  [SENDING] IP Config Mode: %s", (g_system_config.device.ip_config_mode == 1) ? "DHCP" : "Static");

                // DNS servers (4+4 bytes)
                temp_ip = htonl(g_system_config.device.dns_server1);
                memcpy(&response[offset], &temp_ip, 4);
                offset += 4;
                addr.s_addr = temp_ip;
                LOG_DEBUG("  [SENDING] DNS Server 1: %s", inet_ntoa(addr));

                temp_ip = htonl(g_system_config.device.dns_server2);
                memcpy(&response[offset], &temp_ip, 4);
                offset += 4;
                addr.s_addr = temp_ip;
                LOG_DEBUG("  [SENDING] DNS Server 2: %s", inet_ntoa(addr));

                // SNMP (1 byte)
                response[offset++] = g_system_config.device.snmp_enabled;
                LOG_DEBUG("  [SENDING] SNMP Enabled: %d", g_system_config.device.snmp_enabled);

                // Auto report IP, port, period (4+2+2 bytes)
                temp_ip = htonl(g_system_config.device.auto_report_ip);
                memcpy(&response[offset], &temp_ip, 4);
                offset += 4;
                addr.s_addr = temp_ip;
                LOG_DEBUG("  [SENDING] Auto Report IP: %s", inet_ntoa(addr));
                
                temp_port = htons(g_system_config.device.auto_report_udp_port);
                memcpy(&response[offset], &temp_port, 2);
                offset += 2;
                LOG_DEBUG("  [SENDING] Auto Report UDP Port: %d", g_system_config.device.auto_report_udp_port);

                temp_port = htons(g_system_config.device.auto_report_period);
                memcpy(&response[offset], &temp_port, 2);
                offset += 2;
                LOG_DEBUG("  [SENDING] Auto Report Period: %d", g_system_config.device.auto_report_period);

                semGive(g_config_mutex);

                // --- 3. 填充帧尾 ---
                response[offset++] = 0x5A; response[offset++] = 0x5A; // End ID

                // --- 4. 发送响应包 ---
                send_response(s_sessions[session_index].fd, response, offset);
            }
            break;

        case 0x01: // 写入所有网络设置 (上位机 -> 设备)
            {
                const unsigned char* data = frame + 4;
                int offset = 0;
		
		// 打印接收到的信息
                addr.s_addr = *(unsigned int*)&data[0];
                LOG_DEBUG("  [RECEIVED] IP Address: %s", inet_ntoa(addr));
                addr.s_addr = *(unsigned int*)&data[4];
                LOG_DEBUG("  [RECEIVED] Netmask: %s", inet_ntoa(addr));
                addr.s_addr = *(unsigned int*)&data[8];
                LOG_DEBUG("  [RECEIVED] Gateway: %s", inet_ntoa(addr));
                LOG_DEBUG("  [RECEIVED] IP Config Mode: %s", (data[12] == 1) ? "DHCP" : "Static");
                addr.s_addr = *(unsigned int*)&data[13];
                LOG_DEBUG("  [RECEIVED] DNS Server 1: %s", inet_ntoa(addr));
                addr.s_addr = *(unsigned int*)&data[17];
                LOG_DEBUG("  [RECEIVED] DNS Server 2: %s", inet_ntoa(addr));

                semTake(g_config_mutex, WAIT_FOREVER);

                // 1. 解析并更新 IP, Netmask, Gateway
                memcpy(&g_system_config.device.ip_address, &data[offset], 4);
                g_system_config.device.ip_address = ntohl(g_system_config.device.ip_address);
                offset += 4;

                memcpy(&g_system_config.device.netmask, &data[offset], 4);
                g_system_config.device.netmask = ntohl(g_system_config.device.netmask);
                offset += 4;
                
                memcpy(&g_system_config.device.gateway, &data[offset], 4);
                g_system_config.device.gateway = ntohl(g_system_config.device.gateway);
                offset += 4;

                // 2. 解析并更新 IP Config Mode
                g_system_config.device.ip_config_mode = data[offset++];

                // 3. 解析并更新 DNS Servers
                memcpy(&g_system_config.device.dns_server1, &data[offset], 4);
                g_system_config.device.dns_server1 = ntohl(g_system_config.device.dns_server1);
                offset += 4;

                memcpy(&g_system_config.device.dns_server2, &data[offset], 4);
                g_system_config.device.dns_server2 = ntohl(g_system_config.device.dns_server2);
                offset += 4;

                // 4. 解析并更新 SNMP
                g_system_config.device.snmp_enabled = data[offset++];
		        LOG_DEBUG("  [RECEIVED] SNMP Enabled: %d",g_system_config.device.snmp_enabled);

                // 5. 解析并更新 Auto Report 设置
                memcpy(&g_system_config.device.auto_report_ip, &data[offset], 4);
                g_system_config.device.auto_report_ip = ntohl(g_system_config.device.auto_report_ip);
                offset += 4;
                
                memcpy(&g_system_config.device.auto_report_udp_port, &data[offset], 2);
                g_system_config.device.auto_report_udp_port = ntohs(g_system_config.device.auto_report_udp_port);
                offset += 2;

                memcpy(&g_system_config.device.auto_report_period, &data[offset], 2);
                g_system_config.device.auto_report_period = ntohs(g_system_config.device.auto_report_period);
                offset += 2;

                semGive(g_config_mutex);
                
                // TODO: 在此调用实际应用网络配置的函数 (e.g., ifconfig)
		
//	    	    LOG_DEBUG("  [RECEIVED] Auto Report IP: %s", inet_ntoa(g_system_config.device.auto_report_ip));
                LOG_DEBUG("  [RECEIVED] Auto Report UDP Port: %d", g_system_config.device.auto_report_udp_port);
                LOG_DEBUG("  [RECEIVED] Auto Report Period: %d", g_system_config.device.auto_report_period);
                
                LOG_INFO("ConfigTask: Updated all Network Settings.");
                send_framed_ack(s_sessions[session_index].fd, 0x03, 0x01, 1); // 成功
            }
            break;

        default:
            LOG_WARN("ConfigTask: Received unknown Sub_ID 0x%02X for Network Settings.", sub_id);
            send_framed_ack(s_sessions[session_index].fd, 0x03, sub_id, 0); // 失败
            break;
    }
}

/**
 * @brief 将单个串口通道的配置打包到缓冲区
 * @param channel_index 要打包的通道索引 (0-15)
 * @param buffer        目标缓冲区
 * @return int          打包的数据长度
 */
static int pack_serial_settings(int channel_index, unsigned char* buffer)
{
    int offset = 0;
    size_t alias_len;
    unsigned int temp_baud;
    ChannelState* ch = &g_system_config.channels[channel_index];

    LOG_DEBUG("  [PACKING] Port %d Settings:", channel_index + 1);
    LOG_DEBUG("    - Alias: %s", ch->alias);
    LOG_DEBUG("    - Baudrate: %d", ch->baudrate);
    LOG_DEBUG("    - DataBits: %d, StopBits: %d, Parity: %d", ch->data_bits, ch->stop_bits, ch->parity);
    LOG_DEBUG("    - FIFO: %d, FlowCtrl: %d, Interface: %d", ch->fifo_enable, ch->flow_ctrl, ch->interface_type);


    // 1. Port Index (1-based)
    buffer[offset++] = (unsigned char)(channel_index + 1);

    // 2. Alias (1 byte length + N bytes data)
    alias_len = strlen(ch->alias);
    if (alias_len > MAX_ALIAS_LEN) alias_len = MAX_ALIAS_LEN;
    buffer[offset++] = (unsigned char)alias_len;
    memcpy(&buffer[offset], ch->alias, MAX_ALIAS_LEN);
    offset += MAX_ALIAS_LEN;

    // 3. Baud rate (4 bytes, network byte order)
    temp_baud = htonl(ch->baudrate);
    memcpy(&buffer[offset], &temp_baud, 4);
    offset += 4;

    // 4. Data bits, Stop bits, Parity, FIFO, Flow ctrl, Interface
    buffer[offset++] = ch->data_bits;
    buffer[offset++] = ch->stop_bits;
    buffer[offset++] = ch->parity;
    buffer[offset++] = ch->fifo_enable;
    buffer[offset++] = ch->flow_ctrl;
    buffer[offset++] = ch->interface_type;
    
    return offset;
}

/**
 * @brief 处理 0x04 - 串口设置请求
 * @details 根据 Sub_ID 将请求分发给参数读取或写入的处理逻辑。
 */
static void handle_serial_settings_request(int session_index, const unsigned char* frame, int len)
{
    // 帧结构: [A5 A5] [CmdID] [SubID] [Data...] [5A 5A]
    unsigned char sub_id = frame[3]; 

    LOG_INFO("ConfigTask: Handling Serial Settings Request (0x04), Sub ID: 0x%02X...", sub_id);


    switch (sub_id) {
        case 0x00: // 读取所有串口设置
            {
                // 预估最大长度: 4(head) + 1(count) + 16 * (1+1+19+4+1+1+1+1+1+1) (ports) + 2(end) approx 500 bytes
                unsigned char response[1024]; 
                int offset = 0;
                int i;

                LOG_DEBUG("  Action: Read All Serial Settings.");

                // --- 1. 填充帧头和功能码 ---
                response[offset++] = 0xA5; response[offset++] = 0xA5; // Head ID
                response[offset++] = 0x04; response[offset++] = 0x00; // Command & Sub ID

                // --- 2. 填充数据负载 ---
                response[offset++] = NUM_PORTS; // 串口数量
                LOG_DEBUG("  [SENDING] Total Port Count: %d", NUM_PORTS);

                semTake(g_config_mutex, WAIT_FOREVER);
                for (i = 0; i < NUM_PORTS; i++) {
                    offset += pack_serial_settings(i, &response[offset]);
                }
                semGive(g_config_mutex);

                // --- 3. 填充帧尾 ---
                response[offset++] = 0x5A; response[offset++] = 0x5A; // End ID

                // --- 4. 发送响应包 ---
                send_response(s_sessions[session_index].fd, response, offset);
            }
            break;


        case 0x01: // 读取单个串口设置
            {
                const unsigned char* data = frame + 4;
                unsigned char port_index = data[0]; // 1-based index

                LOG_DEBUG("  Action: Read Single Serial Port Setting.");
                LOG_DEBUG("  [RECEIVED] Port Index: %d", port_index);

                if (port_index < 1 || port_index > NUM_PORTS) {
                    LOG_ERROR("ConfigTask: Invalid port index %d for read.", port_index);
                    return; // 无效请求，不回复
                }
                int channel_index = port_index - 1; // 0-based index

                unsigned char response[256];
                int offset = 0;

                response[offset++] = 0xA5; response[offset++] = 0xA5;
                response[offset++] = 0x04; response[offset++] = 0x01;
                
                semTake(g_config_mutex, WAIT_FOREVER);
                offset += pack_serial_settings(channel_index, &response[offset]);
                semGive(g_config_mutex);

                response[offset++] = 0x5A; response[offset++] = 0x5A;

                send_response(s_sessions[session_index].fd, response, offset);
            }
            break;

        case 0x02: // 写入单个串口设置
            {
                const unsigned char* data = frame + 4;
                int data_offset = 0;
                unsigned char port_index = data[data_offset++];
                
                LOG_DEBUG("  Action: Write Single Serial Port Setting.");
                LOG_DEBUG("  [RECEIVED] Target Port Index: %d", port_index);

                if (port_index < 1 || port_index > NUM_PORTS) {
                    LOG_ERROR("ConfigTask: Invalid port index %d for write.", port_index);
                    send_framed_ack(s_sessions[session_index].fd, 0x04, 0x02, 0); // 失败
                    return;
                }
                int channel_index = port_index - 1;

                semTake(g_config_mutex, WAIT_FOREVER);
                ChannelState* ch = &g_system_config.channels[channel_index];

                // Alias
                unsigned char alias_len = data[data_offset++];
                if (alias_len > MAX_ALIAS_LEN) alias_len = MAX_ALIAS_LEN; // 长度保护
                
                memset(ch->alias, 0, sizeof(ch->alias));
                strncpy(ch->alias, (const char*)&data[data_offset], alias_len);
                LOG_DEBUG("    - Alias: %s", ch->alias);
                
                data_offset += MAX_ALIAS_LEN;

                // Baud, Data bits, etc.
                unsigned int received_baud;
                memcpy(&received_baud, &data[data_offset], 4);
                ch->baudrate = ntohl(received_baud);
                LOG_DEBUG("    - Baudrate: %d", ch->baudrate);
                data_offset += 4;

                ch->data_bits = data[data_offset++];
                ch->stop_bits = data[data_offset++];
                ch->parity = data[data_offset++];
                ch->fifo_enable = data[data_offset++];
                ch->flow_ctrl = data[data_offset++];
                ch->interface_type = data[data_offset++];
                LOG_DEBUG("    - DataBits: %d, StopBits: %d, Parity: %d", ch->data_bits, ch->stop_bits, ch->parity);
                LOG_DEBUG("    - FIFO: %d, FlowCtrl: %d, Interface: %d", ch->fifo_enable, ch->flow_ctrl, ch->interface_type);
                
                semGive(g_config_mutex);

                // TODO: 在此调用实际应用串口硬件配置的函数
                // e.g., apply_serial_config_to_hw(channel_index);

                LOG_INFO("ConfigTask: Updated Serial Settings for Port %d.", port_index);
                send_framed_ack(s_sessions[session_index].fd, 0x04, 0x02, 1); // 成功
            }
            break;
            
        default:
            LOG_WARN("ConfigTask: Received unknown Sub_ID 0x%02X for Serial Settings.", sub_id);
            send_framed_ack(s_sessions[session_index].fd, 0x04, sub_id, 0); // 失败
            break; 
    }
}

static int pack_operating_mode_params(const ChannelState* channel, unsigned char* buffer)
{
    int i,offset = 0;
    
    switch(channel->op_mode) {
        case OP_MODE_REAL_COM:
            buffer[offset++] = channel->tcp_alive_check_time_min;
            buffer[offset++] = channel->max_connections;
            buffer[offset++] = channel->ignore_jammed_ip;
            buffer[offset++] = channel->allow_driver_control;
            *(unsigned short*)&buffer[offset] = htons(channel->packing_settings.packing_length);
            offset += 2;
            buffer[offset++] = channel->packing_settings.delimiter1;
            buffer[offset++] = channel->packing_settings.delimiter2;
            buffer[offset++] = channel->packing_settings.delimiter_process;
            *(unsigned short*)&buffer[offset] = htons(channel->packing_settings.force_transmit_time_ms);
            offset += 2;
            break;

        case OP_MODE_TCP_SERVER:
            buffer[offset++] = channel->tcp_alive_check_time_min;
            *(unsigned short*)&buffer[offset] = htons(channel->inactivity_time_ms);
            offset += 2;
            buffer[offset++] = channel->max_connections;
            buffer[offset++] = channel->ignore_jammed_ip;
            buffer[offset++] = channel->allow_driver_control;
            *(unsigned short*)&buffer[offset] = htons(channel->packing_settings.packing_length);
            offset += 2;
            buffer[offset++] = channel->packing_settings.delimiter1;
            buffer[offset++] = channel->packing_settings.delimiter2;
            buffer[offset++] = channel->packing_settings.delimiter_process;
            *(unsigned short*)&buffer[offset] = htons(channel->packing_settings.force_transmit_time_ms);
            offset += 2;
            *(unsigned short*)&buffer[offset] = htons(channel->local_tcp_port);
            offset += 2;
            *(unsigned short*)&buffer[offset] = htons(channel->command_port);
            offset += 2;
            break;
            
        case OP_MODE_TCP_CLIENT:
            buffer[offset++] = channel->tcp_alive_check_time_min;
            // Inactivity time
            *(unsigned short*)&buffer[offset] = htons(channel->inactivity_time_ms);
            offset += 2;
            
            // Ignore jammed IP
            buffer[offset++] = channel->ignore_jammed_ip;
            
            // Packing settings
            *(unsigned short*)&buffer[offset] = htons(channel->packing_settings.packing_length);
            offset += 2;
            buffer[offset++] = channel->packing_settings.delimiter1;
            buffer[offset++] = channel->packing_settings.delimiter2;
            buffer[offset++] = channel->packing_settings.delimiter_process;
            *(unsigned short*)&buffer[offset] = htons(channel->packing_settings.force_transmit_time_ms);
            offset += 2;
            
            // Destination settings (4 sets)
            for(i = 0; i < 4; i++) {
                // IP (4 bytes) + Port (2 bytes) = 6 bytes per destination
                unsigned int ip = htonl(channel->tcp_destinations[i].destination_ip);
                memcpy(&buffer[offset], &ip, 4);
                offset += 4;
                *(unsigned short*)&buffer[offset] = htons(channel->tcp_destinations[i].destination_port);
                offset += 2;
            }
            
            // Designated local ports (4 sets)
            for(i = 0; i < 4; i++) {
                *(unsigned short*)&buffer[offset] = htons(channel->tcp_destinations[i].designated_local_port);
                offset += 2;
            }
            
            // Connection control
            buffer[offset++] = channel->connection_control;
            break;
            
        case OP_MODE_UDP:
            // Packing settings
            *(unsigned short*)&buffer[offset] = htons(channel->packing_settings.packing_length);
            offset += 2;
            buffer[offset++] = channel->packing_settings.delimiter1;
            buffer[offset++] = channel->packing_settings.delimiter2;
            buffer[offset++] = channel->packing_settings.delimiter_process;
            *(unsigned short*)&buffer[offset] = htons(channel->packing_settings.force_transmit_time_ms);
            offset += 2;
            
            // UDP destination settings (4 sets)
            for(i = 0; i < 4; i++) {
                // Begin IP (4) + End IP (4) + Port (2) = 10 bytes per destination
                unsigned int begin_ip = htonl(channel->udp_destinations[i].begin_ip);
                unsigned int end_ip = htonl(channel->udp_destinations[i].end_ip);
                memcpy(&buffer[offset], &begin_ip, 4);
                offset += 4;
                memcpy(&buffer[offset], &end_ip, 4);
                offset += 4;
                *(unsigned short*)&buffer[offset] = htons(channel->udp_destinations[i].port);
                offset += 2;
            }
            
            // Local listen port
            *(unsigned short*)&buffer[offset] = htons(channel->local_udp_listen_port);
            offset += 2;
            break;
            
        case OP_MODE_DISABLED:
            // No parameters needed for disabled mode
            break;
    }
    
    return offset;
}

/**
 * @brief 处理操作模式相关请求的主函数
 */
static void handle_operating_settings_request(int session_index, const unsigned char* frame, int len)
{
    unsigned char sub_id = frame[3];
    
    LOG_DEBUG("ConfigTask: Handling Operating Settings Request (0x05), Sub ID: 0x%02X, len: %d", 
             sub_id, len);

    switch(sub_id) {
        case 0x00:  // 查询串口操作模式
            handle_query_op_mode(session_index, frame);
            break;

        case 0x01:  // 读取串口操作模式
            handle_read_op_mode(session_index, frame);
            break;

        case 0x02:  // 设置串口操作模式
            handle_set_op_mode(session_index, frame);
            break;

        default:
            LOG_WARN("Unknown operating settings sub command: 0x%02X", sub_id);
            break;
    }
}

/**
 * @brief 处理查询操作模式请求(0x00)
 */
static void handle_query_op_mode(int session_index, const unsigned char* frame)
{
    unsigned char response[1024];
    int i, offset = 0;
    unsigned char query_type = frame[4];
    
    // 帧头
    response[offset++] = 0xA5;
    response[offset++] = 0xA5;
    response[offset++] = 0x05;    // command id
    response[offset++] = 0x00;    // sub id
    
    semTake(g_config_mutex, WAIT_FOREVER);
    
    if(query_type == 0xFF) {  // 查询所有端口
        response[offset++] = query_type;
        response[offset++] = NUM_PORTS;
        
        for(i = 0; i < NUM_PORTS; i++) {
            const ChannelState* channel = &g_system_config.channels[i];
            response[offset++] = i + 1;  // 端口序号(从1开始)
            response[offset++] = channel->op_mode;
            offset += pack_operating_mode_params(channel, &response[offset]);
        }
    }
    else if(query_type == 0x01) {  // 查询单个端口
        unsigned char port_index = frame[5];
        if(port_index < 1 || port_index > NUM_PORTS) {
            LOG_WARN("Invalid port index: %d", port_index);
            semGive(g_config_mutex);
            return;
        }
        
        response[offset++] = query_type;
        response[offset++] = 1;  // 只返回1个端口
        
        const ChannelState* channel = &g_system_config.channels[port_index - 1];
        response[offset++] = port_index;
        response[offset++] = channel->op_mode;
        offset += pack_operating_mode_params(channel, &response[offset]);
    }
    
    semGive(g_config_mutex);

    // 发送响应
    send_op_mode_response(s_sessions[session_index].fd, 0x05, 0x00, response, offset);
}

/**
 * @brief 处理读取操作模式请求(0x01)
 */
static void handle_read_op_mode(int session_index, const unsigned char* frame)
{
    unsigned char response[1024];
    int offset = 0;
    unsigned char port_index = frame[4];
    unsigned char op_mode = frame[5];

    LOG_DEBUG("Reading port %d operation mode: 0x%02X", port_index, op_mode);
    
    if(port_index < 1 || port_index > NUM_PORTS) {
        LOG_WARN("Invalid port index: %d", port_index);
        return;
    }

    // 构造响应
    response[offset++] = 0xA5;
    response[offset++] = 0xA5;
    response[offset++] = 0x05;    // command id
    response[offset++] = 0x01;    // sub id
    response[offset++] = port_index;
    response[offset++] = op_mode;

    semTake(g_config_mutex, WAIT_FOREVER);
    offset += pack_operating_mode_params(&g_system_config.channels[port_index - 1], 
                                       &response[offset]);
    semGive(g_config_mutex);

    // 发送响应
    send_op_mode_response(s_sessions[session_index].fd, 0x05, 0x01, response, offset);
}

/**
 * @brief 处理设置操作模式请求(0x02)
 */
static void handle_set_op_mode(int session_index, const unsigned char* frame)
{
    unsigned char response[1024];
    int offset = 0;
    unsigned char query_type = frame[4];
    unsigned char op_mode = frame[5];
    int success = 0;

    LOG_DEBUG("Setting operation mode: query_type=0x%02X, op_mode=0x%02X", 
             query_type, op_mode);

    if(query_type == 0x01) {  // 设置单个端口
        unsigned char port_index = frame[6];
        success = set_single_port_mode(port_index, op_mode, &frame[7]);
    }
    else if(query_type == 0xFF) {  // 设置所有端口
        const unsigned char* op_mode_data = &frame[6];
        success = set_all_ports_mode(op_mode, op_mode_data);
    }
    else {
        LOG_WARN("Unknown query type: 0x%02X", query_type);
    }

    // 构造响应
    response[offset++] = 0xA5;
    response[offset++] = 0xA5;
    response[offset++] = 0x05;    // command id
    response[offset++] = 0x02;    // sub id
    response[offset++] = query_type;
    response[offset++] = success ? 0x01 : 0x02;

    // 发送响应
    send_op_mode_response(s_sessions[session_index].fd, 0x05, 0x02, response, offset);
}

/**
 * @brief 发送操作模式响应的通用函数
 */
static void send_op_mode_response(int fd, unsigned char cmd_id, unsigned char sub_id, 
                                const unsigned char* data, int data_len)
{
    unsigned char response[1024];
    int total_len = data_len + 2;  // +2 for end bytes
    
    // 复制数据
    memcpy(response, data, data_len);
    
    // 添加帧尾
    response[data_len] = 0x5A;
    response[data_len + 1] = 0x5A;
    
    // 发送响应
    send_response(fd, response, total_len);
}
/**
 * @brief 设置单个端口的操作模式
 * @param port_index 端口索引(1-based)
 * @param op_mode 操作模式
 * @param op_mode_data 模式参数数据
 * @return 1表示成功，0表示失败
 */
static int set_single_port_mode(unsigned char port_index, unsigned char op_mode, 
                              const unsigned char* op_mode_data)
{
    int success = 0;

    if(port_index < 1 || port_index > NUM_PORTS) {
        LOG_WARN("Invalid port index: %d", port_index);
        return 0;
    }

    semTake(g_config_mutex, WAIT_FOREVER);
    
    ChannelState* channel = &g_system_config.channels[port_index - 1];
    success = validate_and_update_port_mode(channel, op_mode, op_mode_data);
    
    semGive(g_config_mutex);

    LOG_INFO("Set port %d operation mode to 0x%02X: %s", 
             port_index, op_mode, success ? "Success" : "Failed");

    return success;
}

/**
 * @brief 设置所有端口的操作模式
 * @param op_mode 操作模式
 * @param op_mode_data 模式参数数据
 * @return 1表示成功，0表示失败
 */
static int set_all_ports_mode(unsigned char op_mode, const unsigned char* op_mode_data)
{
    int i, success = 1;

    semTake(g_config_mutex, WAIT_FOREVER);
    
    for(i = 0; i < NUM_PORTS; i++) {
        ChannelState* channel = &g_system_config.channels[i];
        if(!validate_and_update_port_mode(channel, op_mode, op_mode_data)) {
            success = 0;
            LOG_WARN("Failed to set port %d operation mode", i + 1);
            break;
        }
    }
    
    semGive(g_config_mutex);

    LOG_INFO("Set all ports operation mode to 0x%02X: %s", 
             op_mode, success ? "Success" : "Failed");

    return success;
}

/**
 * @brief 验证并更新端口的操作模式参数
 * @param channel 通道状态指针
 * @param op_mode 操作模式
 * @param op_mode_data 模式参数数据
 * @return 1表示成功，0表示失败
 */
static int validate_and_update_port_mode(ChannelState* channel, unsigned char op_mode, 
                                       const unsigned char* op_mode_data)
{
    int i, offset = 0;
    
    // 保存旧的操作模式，以便在设置失败时恢复
    unsigned char old_op_mode = channel->op_mode;
    channel->op_mode = op_mode;

    switch(op_mode) {
        case OP_MODE_REAL_COM:
            channel->tcp_alive_check_time_min = op_mode_data[offset++];
            channel->max_connections = op_mode_data[offset++];
            channel->ignore_jammed_ip = op_mode_data[offset++];
            channel->allow_driver_control = op_mode_data[offset++];
            channel->packing_settings.packing_length = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            channel->packing_settings.delimiter1 = op_mode_data[offset++];
            channel->packing_settings.delimiter2 = op_mode_data[offset++];
            channel->packing_settings.delimiter_process = op_mode_data[offset++];
            channel->packing_settings.force_transmit_time_ms = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            break;

        case OP_MODE_TCP_SERVER:
            channel->tcp_alive_check_time_min = op_mode_data[offset++];
            channel->inactivity_time_ms = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            channel->max_connections = op_mode_data[offset++];
            channel->ignore_jammed_ip = op_mode_data[offset++];
            channel->allow_driver_control = op_mode_data[offset++];
            channel->packing_settings.packing_length = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            channel->packing_settings.delimiter1 = op_mode_data[offset++];
            channel->packing_settings.delimiter2 = op_mode_data[offset++];
            channel->packing_settings.delimiter_process = op_mode_data[offset++];
            channel->packing_settings.force_transmit_time_ms = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            channel->local_tcp_port = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            channel->command_port = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            break;
            
        case OP_MODE_TCP_CLIENT:
            channel->tcp_alive_check_time_min = op_mode_data[offset++];
            channel->inactivity_time_ms = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            channel->ignore_jammed_ip = op_mode_data[offset++];
            channel->packing_settings.packing_length = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            channel->packing_settings.delimiter1 = op_mode_data[offset++];
            channel->packing_settings.delimiter2 = op_mode_data[offset++];
            channel->packing_settings.delimiter_process = op_mode_data[offset++];
            channel->packing_settings.force_transmit_time_ms = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            
            // 4组目标地址设置
            for(i = 0; i < 4; i++) {
                // IP (4 bytes) + Port (2 bytes) = 6 bytes per destination
                channel->tcp_destinations[i].destination_ip = ntohl(*(unsigned int*)&op_mode_data[offset]);
                offset += 4;
                channel->tcp_destinations[i].destination_port = ntohs(*(unsigned short*)&op_mode_data[offset]);
                offset += 2;
            }
            
            // 4组本地端口
            for(i = 0; i < 4; i++) {
                channel->tcp_destinations[i].designated_local_port = ntohs(*(unsigned short*)&op_mode_data[offset]);
                offset += 2;
            }
            
            channel->connection_control = op_mode_data[offset++];
            break;
            
        case OP_MODE_UDP:
            channel->packing_settings.packing_length = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            channel->packing_settings.delimiter1 = op_mode_data[offset++];
            channel->packing_settings.delimiter2 = op_mode_data[offset++];
            channel->packing_settings.delimiter_process = op_mode_data[offset++];
            channel->packing_settings.force_transmit_time_ms = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            
            // 4组UDP目标地址范围设置
            for(i = 0; i < 4; i++) {
                // Begin IP (4) + End IP (4) + Port (2) = 10 bytes per destination
                channel->udp_destinations[i].begin_ip = ntohl(*(unsigned int*)&op_mode_data[offset]);
                offset += 4;
                channel->udp_destinations[i].end_ip = ntohl(*(unsigned int*)&op_mode_data[offset]);
                offset += 4;
                channel->udp_destinations[i].port = ntohs(*(unsigned short*)&op_mode_data[offset]);
                offset += 2;
            }
            
            channel->local_udp_listen_port = ntohs(*(unsigned short*)&op_mode_data[offset]);
            offset += 2;
            break;
            
        case OP_MODE_DISABLED:
            // 禁用模式不需要额外参数
            break;

        default:
            LOG_WARN("Unknown operation mode: 0x%02X", op_mode);
            channel->op_mode = old_op_mode;  // 恢复旧的操作模式
            return 0;
    }

    return 1;
}

/**
 * @brief 处理 0x06 - 监控请求 (新协议分发器)
 * @details 根据 Sub_ID 将请求分发给不同的监控数据读取逻辑。
 */
static void handle_monitor_request(int session_index, const unsigned char* frame, int len)
{
    // 帧结构: [A5 A5] [CmdID] [SubID] [Data...] [5A 5A]
    unsigned char sub_id = frame[3]; 
    struct in_addr addr; // 用于IP地址转换

    LOG_INFO("ConfigTask: Handling Monitor Request (0x06), Sub ID: 0x%02X...", sub_id);


    switch (sub_id) {
        case 0x01: // 读取 Monitor Line
            {
                const unsigned char* data = frame + 4;
                unsigned char port_count = NUM_PORTS; // 第一个字节是端口数量
                int i;

                LOG_DEBUG("  Action: Read Monitor Line.");
                LOG_DEBUG("  [RECEIVED] Requested Port Count: %d", port_count);


                if (port_count == 0 || port_count > NUM_PORTS) {
                     LOG_ERROR("ConfigTask: Invalid port count %d for Monitor Line.", port_count);
                     return; // 无效请求，不回复
                }

                unsigned char response[1024];
                int offset = 0;

                // --- 1. 填充帧头和功能码 ---
                response[offset++] = 0xA5; response[offset++] = 0xA5;
                response[offset++] = 0x06; response[offset++] = 0x01;

                // --- 2. 填充数据负载 ---
                response[offset++] = port_count; // 回复请求的端口数量

                semTake(g_config_mutex, WAIT_FOREVER);
                for (i = 0; i < port_count; i++) {
                    unsigned char port_index = data[1 + i]; // 1-based index
                    if (port_index >= 1 && port_index <= NUM_PORTS) {
                        int channel_index = port_index - 1;
                        ChannelState* ch = &g_system_config.channels[channel_index];
                        unsigned int temp_ip;

                        LOG_DEBUG("  [SENDING] Port %d Monitor Line Data:", port_index);

                        response[offset++] = port_index;
                        response[offset++] = (unsigned char)ch->op_mode;
                        LOG_DEBUG("    - Op Mode: %d", ch->op_mode);
                        
                        temp_ip = htonl(ch->op_mode_ip1);
                        memcpy(&response[offset], &temp_ip, 4); offset += 4;
                        addr.s_addr = temp_ip;
                        LOG_DEBUG("    - IP 1: %s", inet_ntoa(addr));

                        temp_ip = htonl(ch->op_mode_ip2);
                        memcpy(&response[offset], &temp_ip, 4); offset += 4;
                        addr.s_addr = temp_ip;
                        LOG_DEBUG("    - IP 2: %s", inet_ntoa(addr));
                        
                        temp_ip = htonl(ch->op_mode_ip3);
                        memcpy(&response[offset], &temp_ip, 4); offset += 4;
                        addr.s_addr = temp_ip;
                        LOG_DEBUG("    - IP 3: %s", inet_ntoa(addr));

                        temp_ip = htonl(ch->op_mode_ip4);
                        memcpy(&response[offset], &temp_ip, 4); offset += 4;
                        addr.s_addr = temp_ip;
                        LOG_DEBUG("    - IP 4: %s", inet_ntoa(addr));
                    }
                }
                semGive(g_config_mutex);

                // --- 3. 填充帧尾 ---
                response[offset++] = 0x5A; response[offset++] = 0x5A;

                // --- 4. 发送响应包 ---
                send_response(s_sessions[session_index].fd, response, offset);
            }
            break;

        case 0x02: // 读取 Monitor Async
            {
                const unsigned char* data = frame + 4;
                unsigned char port_count = NUM_PORTS;
                int i;

                LOG_DEBUG("  Action: Read Monitor Async.");
                LOG_DEBUG("  [RECEIVED] Requested Port Count: %d", port_count);

                if (port_count == 0 || port_count > NUM_PORTS) {
                     LOG_ERROR("ConfigTask: Invalid port count %d for Monitor Async.", port_count);
                     return;
                }

                unsigned char response[1024];
                int offset = 0;
                
                response[offset++] = 0xA5; response[offset++] = 0xA5;
                response[offset++] = 0x06; response[offset++] = 0x02;
                response[offset++] = port_count; // 回复请求的端口数量

                semTake(g_config_mutex, WAIT_FOREVER);
                for (i = 0; i < port_count; i++) {
                    unsigned char port_index = data[1 + i]; // 1-based index
                    if (port_index >= 1 && port_index <= NUM_PORTS) {
                        int channel_index = port_index - 1;
                        ChannelState* ch = &g_system_config.channels[channel_index];
                        unsigned int temp_32;
                        unsigned long long temp_64;
                        
                        LOG_DEBUG("  [SENDING] Port %d Monitor Async Data:", port_index);

                        response[offset++] = port_index;

                        temp_32 = htonl(ch->tx_count);
                        memcpy(&response[offset], &temp_32, 4); offset += 4;
                        LOG_DEBUG("    - TX Count: %u", ch->tx_count);

                        temp_32 = htonl(ch->rx_count);
                        memcpy(&response[offset], &temp_32, 4); offset += 4;
                        LOG_DEBUG("    - RX Count: %u", ch->rx_count);
                        
                        // 注意: VxWorks可能没有htobe64, 需要手动转换
                         
                        temp_64 = ch->tx_total_count;
                        response[offset++] = (temp_64 >> 56) & 0xFF; response[offset++] = (temp_64 >> 48) & 0xFF;
                        response[offset++] = (temp_64 >> 40) & 0xFF; response[offset++] = (temp_64 >> 32) & 0xFF;
                        response[offset++] = (temp_64 >> 24) & 0xFF; response[offset++] = (temp_64 >> 16) & 0xFF;

                        response[offset++] = (temp_64 >> 8) & 0xFF;  response[offset++] = temp_64 & 0xFF;
                        LOG_DEBUG("    - TX Total Count: %llu", ch->tx_total_count);

                        temp_64 = ch->rx_total_count;
                        response[offset++] = (temp_64 >> 56) & 0xFF; response[offset++] = (temp_64 >> 48) & 0xFF;
                        response[offset++] = (temp_64 >> 40) & 0xFF; response[offset++] = (temp_64 >> 32) & 0xFF;
                        response[offset++] = (temp_64 >> 24) & 0xFF; response[offset++] = (temp_64 >> 16) & 0xFF;
                        response[offset++] = (temp_64 >> 8) & 0xFF;  response[offset++] = temp_64 & 0xFF;
                        LOG_DEBUG("    - RX Total Count: %llu", ch->rx_total_count);

                        response[offset++] = ch->dsr_status;
                        response[offset++] = ch->cts_status;
                        response[offset++] = ch->dcd_status;
                        LOG_DEBUG("    - DSR: %d, CTS: %d, DCD: %d", ch->dsr_status, ch->cts_status, ch->dcd_status);
                    }
                }
                semGive(g_config_mutex);

                response[offset++] = 0x5A; response[offset++] = 0x5A;
                send_response(s_sessions[session_index].fd, response, offset);
                LOG_INFO("ConfigTask: Sent Monitor Async response for %d ports.", port_count);
            }
            break;
            
        case 0x03: // 读取 Monitor Async-Settings
            {
                const unsigned char* data = frame + 4;
                unsigned char port_count = NUM_PORTS;
                int i;

                LOG_DEBUG("  Action: Read Monitor Async Settings.");
                LOG_DEBUG("  [RECEIVED] Requested Port Count: %d", port_count);

                if (port_count == 0 || port_count > NUM_PORTS) {
                     LOG_ERROR("ConfigTask: Invalid port count %d for Monitor Settings.", port_count);
                     return;
                }

                unsigned char response[1024];
                int offset = 0;
                
                response[offset++] = 0xA5; response[offset++] = 0xA5;
                response[offset++] = 0x06; response[offset++] = 0x03;
                response[offset++] = port_count; // 回复请求的端口数量
                
                semTake(g_config_mutex, WAIT_FOREVER);
                for (i = 0; i < port_count; i++) {
                    unsigned char port_index = data[1 + i]; // 1-based index
                    if (port_index >= 1 && port_index <= NUM_PORTS) {
                        int channel_index = port_index - 1;
                        ChannelState* ch = &g_system_config.channels[channel_index];
                        unsigned int temp_baud;

                        LOG_DEBUG("  [SENDING] Port %d Monitor Async Settings:", port_index);

                        response[offset++] = port_index;

                        temp_baud = htonl(ch->baudrate);
                        memcpy(&response[offset], &temp_baud, 4); offset += 4;
                        LOG_DEBUG("    - Baudrate: %d", ch->baudrate);
                        
                        response[offset++] = ch->data_bits;
                        response[offset++] = ch->stop_bits;
                        response[offset++] = ch->parity;
                        LOG_DEBUG("    - DataBits: %d, StopBits: %d, Parity: %d", ch->data_bits, ch->stop_bits, ch->parity);

                        response[offset++] = ch->fifo_enable;
                        response[offset++] = ch->usart_crtscts; // RTS/CTS
                        response[offset++] = ch->IX_on;         // XON/XOFF
                        response[offset++] = ch->usart_mcr_dtr; // DTR/DSR
                        LOG_DEBUG("    - FIFO: %d, RTS/CTS: %d, XON/XOFF: %d, DTR/DSR: %d", ch->fifo_enable, ch->usart_crtscts, ch->IX_on, ch->usart_mcr_dtr);
                    }
                }
                semGive(g_config_mutex);

                response[offset++] = 0x5A; response[offset++] = 0x5A;
                send_response(s_sessions[session_index].fd, response, offset);
            }
            break;

        default:
            LOG_WARN("ConfigTask: Received unknown Sub_ID 0x%02X for Monitor.", sub_id);
            // 此协议没有ACK，所以未知子命令不回复
            break;
    }
}


/**
 * @brief 处理 0x07 - 管理功能请求 (登录、改密、重启等)
 * @details 根据 Sub_ID 将请求分发给不同的处理函数。
 */
static void handle_change_password_request(int session_index, const unsigned char* frame, int len)
{
    // 帧结构: [A5 A5] [CmdID] [SubID] [Data...] [5A 5A]
    unsigned char sub_id = frame[3]; 

    LOG_INFO("ConfigTask: Handling Admin Functions Request (0x07), Sub ID: 0x%02X...", sub_id);

    switch (sub_id) {
        case 0x00: // Login (登录)
            {
                const unsigned char* data = frame + 4;
                
                // --- 解析 User ---
                unsigned char user_len = data[0];
                char user_recv[MAX_PASSWORD_LEN + 1];
                
                // --- 解析 Password ---
                // 指针偏移应使用固定的字段长度 (1 + MAX_PASSWORD_LEN)
                const unsigned char* pass_data = data + 1 + MAX_PASSWORD_LEN;
                unsigned char pass_len = pass_data[0];
                char pass_recv[MAX_PASSWORD_LEN + 1];

                int login_ok = 0;
                
                LOG_DEBUG("  Action: Login attempt.");

                // 长度校验
                if (user_len <= MAX_PASSWORD_LEN && pass_len <= MAX_PASSWORD_LEN) {
                    // 提取接收到的用户名和密码
                    strncpy(user_recv, (const char*)&data[1], user_len);
                    user_recv[user_len] = '\0';
                    strncpy(pass_recv, (const char*)&pass_data[1], pass_len);
                    pass_recv[pass_len] = '\0';

                    // 调试信息
                    LOG_DEBUG("  [RECEIVED] Username: '%s'", user_recv);
                    LOG_DEBUG("  [RECEIVED] Password: '%s'", pass_recv);

                    semTake(g_config_mutex, WAIT_FOREVER);
                    // 比较用户名和密码
                    if (strcmp(user_recv, g_system_config.device.user_name) == 0 &&
                        strcmp(pass_recv, g_system_config.device.password) == 0) {
                        login_ok = 1; // 验证成功
                    }
                    semGive(g_config_mutex);
                }
                
                LOG_INFO("ConfigTask: Login attempt with user '%s'. Success: %d", user_recv, login_ok);
                send_framed_ack(s_sessions[session_index].fd, 0x07, 0x00, login_ok);
            }
            break;

        case 0x01: // Change password (修改密码)
            {
                const unsigned char* data = frame + 4;
                int success = 0;

                LOG_DEBUG("  Action: Change password attempt.");

                // 1. 解析旧密码
                unsigned char old_pass_len = data[0];
                char old_pass_recv[MAX_PASSWORD_LEN + 1];
                // 使用固定的字段长度 (1 + MAX_PASSWORD_LEN)
                const unsigned char* new_pass_data = data + 1 + MAX_PASSWORD_LEN;

                // 2. 解析新密码
                unsigned char new_pass_len = new_pass_data[0];
                char new_pass_recv[MAX_PASSWORD_LEN + 1];
                // 使用固定的字段长度 (1 + MAX_PASSWORD_LEN)
                const unsigned char* retype_pass_data = new_pass_data + 1 + MAX_PASSWORD_LEN;
                
                // 3. 解析重复输入的新密码
                unsigned char retype_pass_len = retype_pass_data[0];
                char retype_pass_recv[MAX_PASSWORD_LEN + 1];

                // 长度校验
                if (old_pass_len <= MAX_PASSWORD_LEN && new_pass_len <= MAX_PASSWORD_LEN && retype_pass_len <= MAX_PASSWORD_LEN) {
                    strncpy(old_pass_recv, (const char*)&data[1], old_pass_len);
                    old_pass_recv[old_pass_len] = '\0';
                    
                    strncpy(new_pass_recv, (const char*)&new_pass_data[1], new_pass_len);
                    new_pass_recv[new_pass_len] = '\0';

                    strncpy(retype_pass_recv, (const char*)&retype_pass_data[1], retype_pass_len);
                    retype_pass_recv[retype_pass_len] = '\0';
                    
                    LOG_DEBUG("  [RECEIVED] Old password: '%s' (len: %d)", old_pass_recv, old_pass_len);
                    LOG_DEBUG("  [RECEIVED] New password: '%s' (len: %d)", new_pass_recv, new_pass_len);
                    LOG_DEBUG("  [RECEIVED] Retyped new password: '%s' (len: %d)", retype_pass_recv, retype_pass_len);


                    // 逻辑校验
                    if (new_pass_len > 0 && strcmp(new_pass_recv, retype_pass_recv) == 0) {
                        semTake(g_config_mutex, WAIT_FOREVER);
                        // 校验旧密码是否正确
                        if (strcmp(old_pass_recv, g_system_config.device.password) == 0) {
                            // 更新密码
                            strncpy(g_system_config.device.password, new_pass_recv, MAX_PASSWORD_LEN);
                            g_system_config.device.password[MAX_PASSWORD_LEN] = '\0'; // 确保字符串结束
                            success = 1;
                            LOG_DEBUG("    - Old password matched. Password will be updated.");
                            // TODO: 调用 dev_config_save() 将新密码持久化到Flash
                        } else {
                            LOG_WARN("    - Old password did not match. Password change failed.");
                        }
                        semGive(g_config_mutex);
                    } else {
                        LOG_WARN("    - New passwords do not match or are empty. Password change failed.");
                    }
                }
                
                LOG_INFO("ConfigTask: Change password attempt. Success: %d", success);
                send_framed_ack(s_sessions[session_index].fd, 0x07, 0x01, success);
            }
            break;

        case 0x02: // Load Factory Default (恢复出厂设置)
            {
                LOG_INFO("  Action: Load Factory Defaults.");
                dev_config_load_defaults();
                // 恢复出厂设置后，通常需要保存
                dev_config_save();
                // 此操作通常不回复ACK，因为设备可能直接重启
                // 如果需要回复，可以在重启前发送
                // send_framed_ack(s_sessions[session_index].fd, 0x07, 0x02, 1);
            }
            break;

        case 0x03: // Save/Restart (重启)
            {
                LOG_INFO("  Action: Save and Restart.");
                dev_config_save();
                // 此操作通常不回复ACK，因为设备将立即重启
                dev_reboot(); 
            }
            break;

        default:
            LOG_WARN("ConfigTask: Received unknown Sub_ID 0x%02X for Admin functions.", sub_id);
            send_framed_ack(s_sessions[session_index].fd, 0x07, sub_id, 0); // 失败
            break;
    }
}


/**
 * @brief 统一的发送函数
 */
static void send_response(int fd, const unsigned char* data, int len) {
    send(fd, (char*)data, len, 0);
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
    if (session->type == CONN_TYPE_SET && session->channel_index >= 0) {
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
            
            // *** 关键状态维护：检查数据通道是否也已没有客户端 ***
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
