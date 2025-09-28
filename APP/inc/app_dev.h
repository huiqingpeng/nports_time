#ifndef APP_DEV_H
#define APP_DEV_H

#include "app_com.h" // 包含基础类型定义
#include "app_dev_cfg.h" // 包含基础类型定义

/* ------------------ Application-Specific Constants ------------------ */
#define NUM_PORTS               16      // 系统支持的串口/通道数量
#define MAX_CLIENTS_PER_CHANNEL 4 		// 每个通道最多允许4个客户端
#define RING_BUFFER_SIZE        (64 * 1024) // 64KB 环形缓冲区大小
#define MAX_CONFIG_CLIENTS      (NUM_PORTS * (MAX_CLIENTS_PER_CHANNEL+1) + 1) // 最大配置客户端数量

#define MAX_ALIAS_LEN               19
#define MAX_MODEL_NAME_LEN          39
#define MAX_SERVER_NAME_LEN         39
#define MAX_PASSWORD_LEN            14

/* ------------------ Global Configuration Structures ------------------ */
/**
 * @brief 描述物理串口硬件的状态机
 * @details 这个状态机追踪物理硬件的生命周期。
 */
typedef enum {
	UART_STATE_CLOSED,      // 初始状态。串口未被HAL层初始化或已关闭。
	UART_STATE_OPENED,      // 正常工作状态。串口已由HAL层成功打开并配置。
	UART_STATE_ERROR        // 异常状态。HAL层在尝试打开或配置串口时发生硬件错误。
							// 这是一个持久性故障，可能需要重启或干预才能恢复。
} UartPhysicalState;

/**
 * @brief 描述网络通道（数据和命令）的状态机
 * @details 这个状态机追踪每个网络服务（如数据端口950）的生命周期。
 */
typedef enum {
	NET_STATE_IDLE,         // 初始状态。任务尚未开始监听此端口。
	NET_STATE_LISTENING,    // 正常状态。监听Socket已成功创建并正在等待连接。此时没有活跃的客户端。
	NET_STATE_CONNECTED,    // 正常状态。至少有一个客户端已连接，正在进行数据交换。
	NET_STATE_ERROR         // 异常状态。创建监听Socket失败 (例如，端口被占用)。
							// 这是一个持久性故障，该通道的网络服务将不可用。
} NetworkChannelState;


/**
 * @brief 定义通道的接口模式
 */
typedef enum {
    INTERFACE_TYPE_RS232   = 0x00, // RS232 Mode
    INTERFACE_TYPE_RS422   = 0x01, // RS422 Mode
    INTERFACE_TYPE_RS485   = 0x02, // RS485 Mode
} Interface_Mode;

/**
 * @brief 定义通道的工作模式
 * @details 根据用户需求定义的操作模式枚举。
 */
typedef enum {
    OP_MODE_REAL_COM     = 0x01, // Real COM Mode
    OP_MODE_TCP_SERVER   = 0x03, // TCP Server Mode
    OP_MODE_TCP_CLIENT   = 0x04, // TCP Client Mode
    OP_MODE_UDP          = 0x05, // UDP Mode
    OP_MODE_DISABLED     = 0xFF  // Disabled Mode
} OperationMode;

/**
 * @brief 定义数据打包时的分隔符处理方式
 */
typedef enum {
    DELIMITER_PROCESS_NONE          = 0x01, // 不做任何处理 (Do Nothing)
    DELIMITER_PROCESS_APPEND_DELIM1 = 0x02, // 附加分隔符1 (Delimiter+1)
    DELIMITER_PROCESS_APPEND_DELIM2 = 0x03, // 附加分隔符2 (Delimiter+2)
    DELIMITER_PROCESS_STRIP         = 0x04  // 剥离分隔符 (Strip Delimiter)
} DelimiterProcess;


/**
 * @brief TCP远程目标端点定义
 * @details 包含目标IP、目标端口和本地源端口。
 */
typedef struct {
    unsigned int   destination_ip;           // 目标IP地址 (4 bytes)
    unsigned short destination_port;         // 目标端口 (2 bytes)
    unsigned short designated_local_port;    // 指定的本地源端口 (0表示自动分配) (2 bytes)
} TCP_Client_Mode_Settings;

/**
 * @brief UDP远程目标端点定义
 * @details 包含目标IP、目标端口和本地源端口。
 */
typedef struct {
    unsigned int   begin_ip;           // 起始IP地址
    unsigned int   end_ip;             // 结束IP地址
    unsigned short port;               // 目标端口
} UDP_Mode_Settings;

/**
 * @brief 数据打包配置
 * @details 适用于所有网络转发模式 (Real COM, TCP Server/Client, UDP)
 */
typedef struct {
    unsigned short packing_length;           // 打包长度 (0-1024 bytes)
    unsigned short force_transmit_time_ms;   // 强制发送超时时间 (0-65535 ms)
    unsigned char  delimiter1;               // 分隔符1 (0x00-0xFF)
    unsigned char  delimiter2;               // 分隔符2 (0x00-0xFF)
    DelimiterProcess delimiter_process;      // 分隔符处理方式
} DataPackingSettings;


/**
 * @brief 描述数据通道的网络状态和连接信息
 */
typedef struct {
	NetworkChannelState state;
	int client_fds[MAX_CLIENTS_PER_CHANNEL];
	int num_clients;
} DataChannelInfo;

/**
 * @brief 描述命令通道的网络状态和连接信息
 */
typedef struct {
	NetworkChannelState state;
	int client_fds[MAX_CLIENTS_PER_CHANNEL];
	int num_clients;
} CmdChannelInfo;

/**
 * @brief 描述命令通道的网络状态和连接信息
 */
typedef struct {
	NetworkChannelState state;
	int client_fd;
	int num_clients;
} LocalChannelInfo;

/**
 * @brief 全局设备配置结构体
 */
typedef struct {
    /* -- Overview (0x01) -- */
    char model_name[MAX_MODEL_NAME_LEN+1];
    unsigned char mac_address[6];
    unsigned short serial_no;
    unsigned char firmware_version[3];
    unsigned char hardware_version[3];
    unsigned char lcm_present;

    /* -- Basic Settings (0x02) -- */
    char server_name[MAX_SERVER_NAME_LEN+1];
    unsigned char web_console_enabled;
    unsigned char telnet_console_enabled;
    unsigned char lcm_password_protected;
    unsigned char reset_button_protected;
    
    /* -- Time Settings (from 0x02) -- */
    unsigned char time_zone;
    unsigned char local_time[6]; // Year, Month, Day, Hour, Minute, Second
    unsigned int  time_server;   // Time Server IP Address

    /* -- Network Settings (0x03) -- */
    unsigned int ip_address[NET_NUM];
    unsigned int netmask[NET_NUM];
    unsigned int gateway[NET_NUM];
    unsigned char ip_config_mode; // 0=Static, 1=DHCP, etc.
    unsigned int dns_server1[NET_NUM];
    unsigned int dns_server2[NET_NUM];
    
    /* -- SNMP and IP Report Settings (from 0x03) -- */
    unsigned char  snmp_enabled;
    unsigned int   auto_report_ip;
    unsigned short auto_report_udp_port;
    unsigned short auto_report_period;

    /* -- Login/Admin Settings (0x07) -- */
    char user_name[MAX_PASSWORD_LEN+1];
    char password[MAX_PASSWORD_LEN+1];

} DeviceSettings;

/**
 * @brief 每个通道（串口）的状态和数据结构
 */
typedef struct {
    /* -- 运行时状态 -- */
	UartPhysicalState   uart_state;       
    DataChannelInfo     data_net_info;
    CmdChannelInfo      cmd_net_info;
    LocalChannelInfo    local_net_info;
    /* -- Serial Settings (0x04) -- */
    char alias[MAX_ALIAS_LEN+1];
    OperationMode  op_mode;

    /* -- 串口物理参数 -- */
    int baudrate;
    unsigned char data_bits;
    unsigned char stop_bits;
    unsigned char parity;
    unsigned char flow_ctrl;
    unsigned char fifo_enable;
    unsigned char interface_type;
    
    /* -- 串口控制参数 -- */
    unsigned char space;
    unsigned char mark;
	unsigned char usart_mcr_dtr;
	unsigned char usart_mcr_rts;
	unsigned char usart_crtscts;
	unsigned char IX_on;
	unsigned char IX_off; //XonXoff

    struct {
        int send_interval_ms;    // 发送时间间隔
        int packet_size;         // 发送包大小
    } net_send_cfg;


    DataPackingSettings packing_settings;

    /* --- 2. TCP/UDP 连接控制参数 (适用于 TCP Server/Client, UDP) --- */
    unsigned char  tcp_alive_check_time_min; // TCP keep-alive (0-99 min)
    unsigned short inactivity_time_ms;       // Inactivity timeout (0-65535 ms)
    unsigned char  ignore_jammed_ip;         // Ignore jammed IP (0: No, 1: Yes)
 /* --- 3. 模式特定配置 --- */
    
    // a) TCP Server / Real COM 模式特定参数
    unsigned char  allow_driver_control;     // 允许驱动控制 (仅 Real COM/TCP Server)
    unsigned char  max_connections;          // 最大连接数 (仅 Real COM/TCP Server)
    unsigned short local_tcp_port;           // 本地监听端口 (TCP Server/Real COM)
    unsigned short command_port;           // 本地监听端口 (TCP Server/Real COM)
    unsigned short data_port;
    unsigned short connection_control;     // 连接控制 (仅 TCP Client Mode)

    // b) TCP Client / UDP 模式特定参数
    UDP_Mode_Settings udp_destinations[4];  // udp 模式目标端点列表
    TCP_Client_Mode_Settings tcp_destinations[4];  // tcp 模式标端点列表
    unsigned short local_udp_listen_port;    // UDP模式下的本地监听端口

    /* -- Operating Settings -- */
    unsigned int op_mode_ip1;
    unsigned int op_mode_ip2;
    unsigned int op_mode_ip3;
    unsigned int op_mode_ip4;

    /* -- 实时数据缓冲区 -- */
    ring_buffer_t buffer_net;
    ring_buffer_t buffer_uart;
    unsigned char net_buffer_mem[RING_BUFFER_SIZE];
    unsigned char uart_buffer_mem[RING_BUFFER_SIZE];

    /* -- 运行时监控统计 (0x06) -- */
    unsigned int tx_count;
    unsigned int rx_count;
    unsigned int tx_net;
    unsigned int rx_net;
    unsigned long long tx_total_count;
    unsigned long long rx_total_count;
    unsigned char dsr_status;
    unsigned char cts_status;
    unsigned char dcd_status;
} ChannelState;

/**
 * @brief 包含整个系统所有配置的顶层结构体
 */
typedef struct {
	DeviceSettings device;
	ChannelState channels[NUM_PORTS];
} SystemConfiguration;

/* ------------------ Global Variable Declaration (extern) ------------------ */

/* ------------------ Public API Functions ------------------ */

/**
 * @brief 初始化设备配置模块
 * @details 从持久化存储（如Flash）中加载配置。如果加载失败，则加载出厂默认设置。
 * @return int OK on success, ERROR on failure.
 */
int dev_config_init(void);

/**
 * @brief 将当前系统配置保存到持久化存储
 * @return int OK on success, ERROR on failure.
 */
int dev_config_save(void);

/**
 * @brief 加载出厂默认配置到 g_system_config
 * @details 这只会修改内存中的配置，不会自动保存。
 */
void dev_config_load_defaults(void);

/**
 * @brief 重启设备
 */
void dev_reboot(void);

/**
 * @brief 打印当前系统所有配置信息以供调试
 */
void dev_config_print(void);

/**
 * @brief 应用新的网络配置，更新全局配置结构体，并将其保存到Flash。
 *
 * @param ip_str 新的IP地址字符串 (e.g., "192.168.1.10")。
 * @param netmask_str 新的子网掩码字符串 (e.g., "255.255.255.0")。
 * @param gateway_str 新的网关字符串 (e.g., "192.168.1.1")。
 * @return int OK 成功, ERROR 失败。
 */
int dev_network_settings_apply(const char *ip_str, const char *netmask_str, const char *gateway_str, const char index);

#endif /* APP_DEV_H */
