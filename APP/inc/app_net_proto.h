
#ifndef APP_NET_PROTO_H
#define APP_NET_PROTO_H

// 帧格式常量定义
#define HEAD_ID_B1 0xA5
#define HEAD_ID_B2 0xA5
#define END_ID_B1 0x5A
#define END_ID_B2 0x5A
#define MIN_FRAME_SIZE 6 // Head(2) + Cmd(1) + Sub(1) + End(2)

// 主命令ID定义
typedef enum {
    CMD_OVERVIEW = 0x01,
    CMD_BASIC_SETTINGS = 0x02,
    CMD_NETWORK_SETTINGS = 0x03,
    CMD_SERIAL_SETTINGS = 0x04,
    CMD_OPERATING_SETTINGS = 0x05,
    CMD_MONITOR = 0x06,
    CMD_ADMIN = 0x07
} ProtocolCmdId;

// 查询类型
typedef enum {
    QUERY_SINGLE = 0x01,
    QUERY_ALL = 0xFF
} QueryType;


// 基础协议操作
int pack_frame(unsigned char* buffer, unsigned char cmd_id, 
               unsigned char sub_id, const unsigned char* data, int data_len);
int unpack_frame(const unsigned char* buffer, int len,
                 unsigned char* cmd_id, unsigned char* sub_id, 
                 unsigned char** data, int* data_len);

// 具体命令处理函数
void handle_overview_request(int session_index);
void handle_basic_settings_request(int session_index, const unsigned char* frame, int len);
void handle_network_settings_request(int session_index, const unsigned char* frame, int len);
void handle_serial_settings_request(int session_index, const unsigned char* frame, int len);
void handle_operating_settings_request(int session_index, const unsigned char* frame, int len);
void handle_monitor_request(int session_index, const unsigned char* frame, int len);
void handle_change_password_request(int session_index, const unsigned char* frame, int len);
#endif