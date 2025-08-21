#ifndef APP_DEV_H
#define APP_DEV_H

#include "app_com.h" // 包含基础类型定义

/* ------------------ Application-Specific Constants ------------------ */
#define NUM_PORTS               16      // 系统支持的串口/通道数量
#define MAX_CLIENTS_PER_CHANNEL 4 		// 每个通道最多允许4个客户端
#define RING_BUFFER_SIZE        (8 * 1024) // 8KB 环形缓冲区大小
#define MAX_CONFIG_CLIENTS      (NUM_PORTS + 1) // 最大配置客户端数量

#define MAX_ALIAS_LEN               19
#define MAX_MODEL_NAME_LEN          39
#define MAX_SERVER_NAME_LEN         39
#define MAX_PASSWORD_LEN            14
#define MAX_SNMP_COMMUNITY_LEN      32 // 假设长度


/* ------------------ Global Configuration Structures ------------------ */

/**
 * @brief 全局设备配置结构体
 */
typedef struct {
    /* -- Overview (0x01) -- */
    char model_name[MAX_MODEL_NAME_LEN + 1];
    unsigned char mac_address[6];
    unsigned short serial_no;
    unsigned char firmware_version[3];
    unsigned char hardware_version[3];
    unsigned char lcm_present;

    /* -- Basic Settings (0x02) -- */
    char server_name[MAX_SERVER_NAME_LEN + 1];
    char password[MAX_PASSWORD_LEN + 1];
    unsigned char web_console_enabled;
    unsigned char telnet_console_enabled;
    unsigned char lcm_password_protected;
    unsigned char reset_button_protected;
    // TODO: 添加时区、时间服务器等字段

    /* -- Network Settings (0x03) -- */
    unsigned int ip_address;
    unsigned int netmask;
    unsigned int gateway;
    unsigned char ip_config_mode; // 0=Static, 1=DHCP, etc.
    unsigned int dns_server1;
    unsigned int dns_server2;
    // TODO: 添加SNMP和IP上报相关字段

} DeviceSettings;


/**
 * @brief 每个通道（串口）的状态和数据结构
 */
typedef struct {
    /* -- Serial Settings -- */
    char alias[MAX_ALIAS_LEN];
    /* -- 配置参数 -- */
    int baudrate;
    unsigned char data_bits;
    unsigned char stop_bits;
    unsigned char parity;
    unsigned char flow_ctrl;
	unsigned char space;
    unsigned char mark;
	unsigned char usart_mcr_dtr;
	unsigned char usart_mcr_rts;
	unsigned char usart_crtscts;
	unsigned char IX_on;
	unsigned char IX_off; //XonXoff

    unsigned char fifo_enable;
    unsigned char interface_type;


    /* -- Operating Settings -- */
    unsigned char op_mode;
    unsigned char tcp_alive_check_time_min;
    unsigned char max_connections;
    unsigned short local_tcp_port;

    /* -- 实时数据缓冲区 -- */
    ring_buffer_t buffer_net;      // 网络 -> 串口 的数据缓冲区
    ring_buffer_t buffer_uart;     // 串口 -> 网络 的数据缓冲区
    
    /* -- 缓冲区物理内存 -- */
    unsigned char net_buffer_mem[RING_BUFFER_SIZE];
    unsigned char uart_buffer_mem[RING_BUFFER_SIZE];

    /* -- 运行时状态 -- */
    int data_client_fds[MAX_CLIENTS_PER_CHANNEL];
    int num_data_clients;

} ChannelState;


/**
 * @brief 包含整个系统所有配置的顶层结构体
 */
typedef struct {
    DeviceSettings device;
    ChannelState channels[NUM_PORTS];
} SystemConfiguration;


/* ------------------ Global Variable Declaration (extern) ------------------ */

// 单一的全局配置变量
extern SystemConfiguration g_system_config;


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


#endif /* APP_DEV_H */
