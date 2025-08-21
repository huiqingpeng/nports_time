/*
 * =====================================================================================
 *
 * Filename:  ConfigTaskManager.c
 *
 * Description:  实现 ConfigTaskManager 任务，包含完整的协议处理逻辑。
 *
 * =====================================================================================
 */
#include <time.h> // For inactivity timeout check
#include <stdlib.h> // For atoi, etc.
#include <arpa/inet.h> // For htonl, ntohl etc.
#include "./inc/app_com.h"
#include "./inc/app_uart.h"

// 内部宏定义
#define INACTIVITY_TIMEOUT_SECONDS 300 // 5分钟无活动则超时
#define MAX_COMMAND_LEN 1024

// 内部会话管理结构体
typedef struct {
    int fd;
    ConnectionType type;
    int channel_index;
    time_t last_activity_time;
    // 添加一个接收缓冲区来处理不完整的TCP数据包
    unsigned char rx_buffer[MAX_COMMAND_LEN];
    int rx_bytes;
} ClientSession;

/* ------------------ Private Function Prototypes ------------------ */
static void cleanup_config_connection(int index);
static int handle_config_client(int index);
static void process_command_frame(int session_index, const unsigned char* frame, int len);

// Protocol Handlers
static void handle_overview_request(int session_index);
static void handle_basic_settings_request(int session_index, const unsigned char* frame, int len);
static void handle_network_settings_request(int session_index, const unsigned char* frame, int len);
static void handle_serial_settings_request(int session_index, const unsigned char* frame, int len);
static void handle_change_password_request(int session_index, const unsigned char* frame, int len);

static void send_response(int fd, const unsigned char* data, int len);
static void send_simple_ack(int fd, unsigned char cmd_id, unsigned char sub_id, int port_num, int success);

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
        while (msgQReceive(g_config_conn_q, (char*)&msg, sizeof(msg), NO_WAIT) != ERROR)
        {
        	LOG_INFO("g_config_conn_q \n");
            if (s_num_active_sessions < MAX_CONFIG_CLIENTS) {
                int new_index = s_num_active_sessions;
                s_sessions[new_index].fd = msg.client_fd;
                s_sessions[new_index].type = msg.type;
                s_sessions[new_index].channel_index = msg.channel_index;
                s_sessions[new_index].last_activity_time = time(NULL);
                s_sessions[new_index].rx_bytes = 0;
                s_num_active_sessions++;
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
            perror("ConfigTaskManager: select() error");
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
 * @brief 处理数据接收，并尝试从字节流中解析出完整的命令帧
 * @return 1 表示连接存活, 0 表示连接断开
 */
static int handle_config_client(int index) {
    ClientSession* session = &s_sessions[index];
    
    // 尝试将新数据读入到会话的接收缓冲区末尾
    int n = recv(session->fd, (char*)session->rx_buffer + session->rx_bytes, 
                 MAX_COMMAND_LEN - session->rx_bytes, 0);

    if (n > 0) {
        session->rx_bytes += n;

        // TODO: 协议的帧结构需要明确。这里假设一个简单的帧结构:
        // [Command_ID (1 byte)][Sub_ID (1 byte)][Length (2 bytes)][Data...]
        // 您需要根据实际的协议文档来调整这里的帧解析逻辑。
        while (session->rx_bytes >= 4) { // 至少包含一个完整的帧头
            unsigned short frame_len = (session->rx_buffer[2] << 8) | session->rx_buffer[3];
            if (session->rx_bytes >= frame_len + 4) {
                // 我们有一个完整的帧
                process_command_frame(index, session->rx_buffer, frame_len + 4);
                
                // 从缓冲区中移除已处理的帧
                int remaining_bytes = session->rx_bytes - (frame_len + 4);
                if (remaining_bytes > 0) {
                    memmove(session->rx_buffer, session->rx_buffer + frame_len + 4, remaining_bytes);
                }
                session->rx_bytes = remaining_bytes;
            } else {
                break; // 数据包不完整，等待下一次recv
            }
        }
        return 1;
    } else if (n == 0) {
        return 0; // 对方正常关闭
    } else {
        return (errno == EWOULDBLOCK || errno == EAGAIN) ? 1 : 0;
    }
}

/**
 * @brief 主命令分发器
 */
static void process_command_frame(int session_index, const unsigned char* frame, int len) {
    unsigned char command_id = frame[0];
    switch (command_id) {
        case 0x01: handle_overview_request(session_index); break;
        case 0x02: handle_basic_settings_request(session_index, frame, len); break;
        case 0x03: handle_network_settings_request(session_index, frame, len); break;
        case 0x04: handle_serial_settings_request(session_index, frame, len); break;
        case 0x07: handle_change_password_request(session_index, frame, len); break;
        default:
            LOG_WARN("ConfigTask: Received unknown command ID 0x%02X\n", command_id);
            break;
    }
}


/**
 * @brief 处理 0x01 - 概述信息请求
 */
static void handle_overview_request(int session_index) {
    unsigned char response[128];
    int offset = 4;
    semTake(g_config_mutex, WAIT_FOREVER);
    // --- 临界区开始 ---
    response[offset] = (unsigned char)strlen(g_system_config.device.model_name);
    strncpy((char*)&response[offset + 1], g_system_config.device.model_name, MAX_MODEL_NAME_LEN);
    offset += (1 + MAX_MODEL_NAME_LEN);
    memcpy(&response[offset], g_system_config.device.mac_address, 6);
    offset += 6;
    *(unsigned short*)&response[offset] = htons(g_system_config.device.serial_no);
    offset += 2;
    memcpy(&response[offset], g_system_config.device.firmware_version, 3);
    offset += 3;
    // Hardware Version (3 bytes)
    memcpy(&response[offset], g_system_config.device.hardware_version, 3);
    offset += 3;
    // --- 临界区结束 ---
    semGive(g_config_mutex);
    
    unsigned int uptime_sec = sysClkRateGet() > 0 ? tickGet() / sysClkRateGet() : 0;
    response[offset++] = (uptime_sec / 86400);
    response[offset++] = (uptime_sec % 86400) / 3600;
    response[offset++] = (uptime_sec % 3600) / 60;
    response[offset++] = (uptime_sec % 60);
    response[offset++] = g_system_config.device.lcm_present;

    unsigned short len = offset - 4;
    response[0] = 0x01; response[1] = 0x01;
    response[2] = (len >> 8) & 0xFF; response[3] = len & 0xFF;
    send_response(s_sessions[session_index].fd, response, offset);
}

static void handle_basic_settings_request(int session_index, const unsigned char* frame, int len) {
    // TODO: 实现对 Basic Settings 的读/写操作
    // 记得使用互斥锁
    send_simple_ack(s_sessions[session_index].fd, frame[0], frame[1], 0, 1);
}

static void handle_network_settings_request(int session_index, const unsigned char* frame, int len) {
    // TODO: 实现对 Network Settings 的读/写操作
    // 记得使用互斥锁
    send_simple_ack(s_sessions[session_index].fd, frame[0], frame[1], 0, 1);
}

static void handle_serial_settings_request(int session_index, const unsigned char* frame, int len) {
    ClientSession* session = &s_sessions[session_index];
    if (session->type != CONN_TYPE_SET || session->channel_index < 0) {
        send_simple_ack(session->fd, frame[0], frame[1], 0, 0);
        return;
    }
    int channel = session->channel_index;
    unsigned char sub_id = frame[1];

    if (sub_id == 0x01) { // Read Request
        unsigned char response[128];
        int offset = 4;
        semTake(g_config_mutex, WAIT_FOREVER);
        ChannelState* ch_state = &g_system_config.channels[channel];
        response[offset++] = (unsigned char)(channel + 1);
        response[offset] = (unsigned char)strlen(ch_state->alias);
        strncpy((char*)&response[offset + 1], ch_state->alias, MAX_ALIAS_LEN);
        offset += (1 + MAX_ALIAS_LEN);
        *(unsigned int*)&response[offset] = htonl(ch_state->baudrate);
        offset += 4;
        response[offset++] = ch_state->data_bits;
        response[offset++] = ch_state->stop_bits;
        response[offset++] = ch_state->parity;
        response[offset++] = ch_state->fifo_enable;
        response[offset++] = ch_state->flow_ctrl;
        response[offset++] = ch_state->interface_type;
        semGive(g_config_mutex);
        
        unsigned short data_len = offset - 4;
        response[0] = 0x04; response[1] = 0x01;
        response[2] = (data_len >> 8) & 0xFF; response[3] = data_len & 0xFF;
        send_response(session->fd, response, offset);

    } else if (sub_id == 0x02) { // Write Request
        const unsigned char* data = frame + 4;
        semTake(g_config_mutex, WAIT_FOREVER);
        ChannelState* ch_state = &g_system_config.channels[channel];
        strncpy(ch_state->alias, (const char*)&data[2], data[1]);
        ch_state->alias[data[1]] = '\0';
        ch_state->baudrate = ntohl(*(unsigned int*)&data[22]);
        ch_state->data_bits = data[26];
        ch_state->stop_bits = data[27];
        ch_state->parity = data[28];
        ch_state->fifo_enable = data[29];
        ch_state->flow_ctrl = data[30];
        ch_state->interface_type = data[31];
        // TODO: 调用硬件驱动函数，实际应用新配置
        semGive(g_config_mutex);
        send_simple_ack(session->fd, frame[0], frame[1], channel + 1, 1);
    }
}

static void handle_change_password_request(int session_index, const unsigned char* frame, int len) {
    const unsigned char* data = frame + 4;
    char old_pass[MAX_PASSWORD_LEN + 1];
    char new_pass[MAX_PASSWORD_LEN + 1];
    int success = 0;

    strncpy(old_pass, (const char*)&data[1], data[0]);
    old_pass[data[0]] = '\0';
    
    const unsigned char* new_pass_data = data + 1 + MAX_PASSWORD_LEN;
    strncpy(new_pass, (const char*)&new_pass_data[1], new_pass_data[0]);
    new_pass[new_pass_data[0]] = '\0';

    semTake(g_config_mutex, WAIT_FOREVER);
    if (strcmp(old_pass, g_system_config.device.password) == 0) {
        strncpy(g_system_config.device.password, new_pass, MAX_PASSWORD_LEN);
        g_system_config.device.password[MAX_PASSWORD_LEN] = '\0';
        success = 1;
        // TODO: 将新密码持久化存储到Flash
    }
    semGive(g_config_mutex);
    
    send_simple_ack(s_sessions[session_index].fd, frame[0], frame[1], 0, success);
}

/**
 * @brief 统一的发送函数
 */
static void send_response(int fd, const unsigned char* data, int len) {
    send(fd, (char*)data, len, 0);
}

/**
 * @brief 发送一个简单的成功/失败响应
 */
static void send_simple_ack(int fd, unsigned char cmd_id, unsigned char sub_id, int port_num, int success) {
    unsigned char response[6];
    response[0] = cmd_id;
    response[1] = sub_id;
    response[2] = 0;
    response[3] = 2; // Length of data (port + status)
    response[4] = (unsigned char)port_num;
    response[5] = success ? 0x01 : 0x00;
    send_response(fd, response, sizeof(response));
}

static void cleanup_config_connection(int index) {
    if (index < 0 || index >= s_num_active_sessions) return;
    close(s_sessions[index].fd);
    int last_index = s_num_active_sessions - 1;
    if (index != last_index) {
        s_sessions[index] = s_sessions[last_index];
    }
    s_sessions[last_index].fd = -1;
    s_num_active_sessions--;
}
