#ifndef APP_NET_H
#define APP_NET_H

#include "app_com.h" 

#define MAX_COMMAND_LEN 1024
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

extern ClientSession s_sessions[];
#endif