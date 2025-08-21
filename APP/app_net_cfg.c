/*
 * =====================================================================================
 *
 * Filename:  ConfigTaskManager.c
 *
 * Description:  实现 ConfigTaskManager 任务，包含完整的协议处理逻辑。
 *
 * =====================================================================================
 */
#include "./inc/app_com.h"
#include "./inc/app_cmd.h"
#include <time.h> // For inactivity timeout check
#include <stdlib.h> // For atoi, etc.
#include <arpa/inet.h> // For htonl, ntohl etc.

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
static void handle_serial_settings_request(int session_index, const unsigned char* frame, int len);
static void handle_operating_settings_request(int session_index, const unsigned char* frame, int len);
// TODO: 添加其他命令的处理函数原型
// static void handle_network_settings_request(...);
// static void handle_basic_settings_request(...);
// static void handle_monitor_request(...);
// static void handle_password_change_request(...);

static void send_response(int fd, const unsigned char* data, int len);
static void send_simple_ack(int fd, unsigned char cmd_id, unsigned char sub_id, int success);

/* ------------------ Module-level static variables ------------------ */
static ClientSession s_sessions[MAX_CONFIG_CLIENTS];
static int s_num_active_sessions = 0;

/* ------------------ Global Variable Definitions ------------------ */
TASK_ID g_config_task_manager_tid;
SEM_ID g_config_mutex; // Mutex defined here

/**
 * @brief ConfigTaskManager 的主入口函数
 */
void ConfigTaskManager(void)
{
    int i;
    printf("ConfigTaskManager: Starting...\n");

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
        	printf("g_config_conn_q \n");
            if (s_num_active_sessions < MAX_CONFIG_CLIENTS) {
                int new_index = s_num_active_sessions;
                s_sessions[new_index].fd = msg.client_fd;
                s_sessions[new_index].type = msg.type;
                s_sessions[new_index].channel_index = msg.channel_index;
                s_sessions[new_index].last_activity_time = time(NULL);
                s_sessions[new_index].rx_bytes = 0;
                s_num_active_sessions++;
                printf("ConfigTask: Accepted new config connection fd=%d\n", msg.client_fd);
            } else {
                fprintf(stderr, "ConfigTaskManager: Max config clients reached. Rejecting fd=%d\n", msg.client_fd);
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
                    printf("ConfigTaskManager: fd=%d timed out due to inactivity.\n", s_sessions[i].fd);
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
        case 0x01: // Overview
            handle_overview_request(session_index);
            break;
        case 0x04: // Serial Settings
            handle_serial_settings_request(session_index, frame, len);
            break;
        case 0x05: // Operating Settings
            handle_operating_settings_request(session_index, frame, len);
            break;
        // TODO: 添加其他命令的处理
        // case 0x02: handle_basic_settings_request(...); break;
        // case 0x03: handle_network_settings_request(...); break;
        // case 0x06: handle_monitor_request(...); break;
        // case 0x07: handle_password_change_request(...); break;
        default:
            printf("ConfigTask: Received unknown command ID 0x%02X\n", command_id);
            // 可以选择发送一个"未知命令"的错误响应
            break;
    }
}


/**
 * @brief 处理 0x01 - 概述信息请求
 */
static void handle_overview_request(int session_index) {
    unsigned char response[128];
    int offset = 4; // Start after header

    // TODO: 从系统获取真实数据
    const char* model_name = "FPGA Serial Server v1.2.3";
    unsigned char mac_addr[6] = {0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E};
    unsigned short serial_no = 12345;
    unsigned char fw_ver[3] = {1, 2, 3};
    unsigned char hw_ver[3] = {1, 0, 0};
    unsigned int uptime_sec = sysClkRateGet() > 0 ? tickGet() / sysClkRateGet() : 0;

    // Model Name (1 byte len + 39 bytes data, padded with 0)
    response[offset] = (unsigned char)strlen(model_name);
    strncpy((char*)&response[offset + 1], model_name, 39);
    offset += 40;
    // MAC Address (6 bytes)
    memcpy(&response[offset], mac_addr, 6);
    offset += 6;
    // Serial No. (2 bytes)
    *(unsigned short*)&response[offset] = htons(serial_no);
    offset += 2;
    // Firmware Version (3 bytes)
    memcpy(&response[offset], fw_ver, 3);
    offset += 3;
    // Hardware Version (3 bytes)
    memcpy(&response[offset], hw_ver, 3);
    offset += 3;
    // System Uptime (4 bytes: D, H, M, S)
    response[offset++] = (uptime_sec / 86400);
    response[offset++] = (uptime_sec % 86400) / 3600;
    response[offset++] = (uptime_sec % 3600) / 60;
    response[offset++] = (uptime_sec % 60);
    // LCM (1 byte)
    response[offset++] = 0x00; // No LCM

    // 填充帧头
    unsigned short len = offset - 4;
    response[0] = 0x01; // Command_ID
    response[1] = 0x01; // Sub_ID
    response[2] = (len >> 8) & 0xFF;
    response[3] = len & 0xFF;

    send_response(s_sessions[session_index].fd, response, offset);
}


/**
 * @brief 处理 0x04 - 串口设置读/写请求
 */
static void handle_serial_settings_request(int session_index, const unsigned char* frame, int len) {
    ClientSession* session = &s_sessions[session_index];
    if (session->type != CONN_TYPE_SET || session->channel_index < 0) {
        send_simple_ack(session->fd, frame[0], frame[1], 0);
        return;
    }
    int channel = session->channel_index;
    unsigned char sub_id = frame[1];

    if (sub_id == 0x01) { // Read Request
        unsigned char response[128];
        int offset = 4;
        semTake(g_config_mutex, WAIT_FOREVER);
        // --- 临界区开始 ---
        response[offset++] = (unsigned char)(channel + 1);
        response[offset] = (unsigned char)strlen(g_channel_states[channel].alias);
        strncpy((char*)&response[offset + 1], g_channel_states[channel].alias, 19);
        offset += 20;
        *(unsigned int*)&response[offset] = htonl(g_channel_states[channel].baudrate);
        offset += 4;
        response[offset++] = g_channel_states[channel].data_bits;
        response[offset++] = g_channel_states[channel].stop_bits;
        response[offset++] = g_channel_states[channel].parity;
        response[offset++] = g_channel_states[channel].fifo_enable;
        response[offset++] = g_channel_states[channel].flow_ctrl;
        response[offset++] = g_channel_states[channel].interface_type;
        // --- 临界区结束 ---
        semGive(g_config_mutex);
        
        unsigned short data_len = offset - 4;
        response[0] = 0x04; response[1] = 0x01;
        response[2] = (data_len >> 8) & 0xFF; response[3] = data_len & 0xFF;
        send_response(session->fd, response, offset);

    } else if (sub_id == 0x02) { // Write Request
        const unsigned char* data = frame + 4;
        semTake(g_config_mutex, WAIT_FOREVER);
        // --- 临界区开始 ---
        // data[0] is port, we already have it from channel_index
        strncpy(g_channel_states[channel].alias, (const char*)&data[2], data[1]);
        g_channel_states[channel].alias[data[1]] = '\0';
        g_channel_states[channel].baudrate = ntohl(*(unsigned int*)&data[22]);
        g_channel_states[channel].data_bits = data[26];
        g_channel_states[channel].stop_bits = data[27];
        g_channel_states[channel].parity = data[28];
        g_channel_states[channel].fifo_enable = data[29];
        g_channel_states[channel].flow_ctrl = data[30];
        g_channel_states[channel].interface_type = data[31];
        // TODO: 调用硬件驱动函数，实际应用新配置
        // reconfigure_uart_hardware(channel);
        // --- 临界区结束 ---
        semGive(g_config_mutex);
        send_simple_ack(session->fd, frame[0], frame[1], 1);
    }
}


/**
 * @brief 处理 0x05 - 操作模式设置请求
 */
static void handle_operating_settings_request(int session_index, const unsigned char* frame, int len) {
    // TODO: 实现与 handle_serial_settings_request 类似的读/写逻辑
    // 记得使用互斥锁保护对 g_channel_states 的访问
    send_simple_ack(s_sessions[session_index].fd, frame[0], frame[1], 1);
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
static void send_simple_ack(int fd, unsigned char cmd_id, unsigned char sub_id, int success) {
    unsigned char response[6];
    response[0] = cmd_id;
    response[1] = sub_id;
    response[2] = 0; // Length high byte
    response[3] = 2; // Length low byte (2 bytes of data)
    response[4] = 0; // TODO: Should be the port number, need to get it
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
