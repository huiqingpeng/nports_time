#ifndef APP_DEV_H
#define APP_DEV_H

#include "app_com.h" // 包含基础类型定义

/* ------------------ Application-Specific Constants ------------------ */
#define NUM_PORTS               16      // 系统支持的串口/通道数量
#define MAX_CLIENTS_PER_CHANNEL 4 		// 每个通道最多允许4个客户端
#define RING_BUFFER_SIZE        (8 * 1024) // 8KB 环形缓冲区大小
#define MAX_CONFIG_CLIENTS      (NUM_PORTS * MAX_CLIENTS_PER_CHANNEL + 1) // 最大配置客户端数量

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

/* --- NEW: Sub-structures for better organization --- */

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
    unsigned int ip_address;
    unsigned int netmask;
    unsigned int gateway;
    unsigned char ip_config_mode; // 0=Static, 1=DHCP, etc.
    unsigned int dns_server1;
    unsigned int dns_server2;
    
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

    /* -- Serial Settings (0x04) -- */
    char alias[MAX_ALIAS_LEN+1];
    int baudrate;
    unsigned char data_bits;
    unsigned char stop_bits;
    unsigned char parity;
    unsigned char flow_ctrl;
    unsigned char fifo_enable;
    unsigned char interface_type;
    
    /* -- 串口控制参数 (来自旧协议，但监控协议仍在使用) -- */
    unsigned char space;
    unsigned char mark;
	unsigned char usart_mcr_dtr;
	unsigned char usart_mcr_rts;
	unsigned char usart_crtscts;
	unsigned char IX_on;
	unsigned char IX_off; //XonXoff

    /* -- Operating Settings -- */
    unsigned char op_mode;
	unsigned char tcp_alive_check_time_min;
	unsigned char max_connections;
    unsigned short local_tcp_port;
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

#endif /* APP_DEV_H */
