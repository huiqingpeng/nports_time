#ifndef __APP_COM_H_
#define __APP_COM_H_

/*
 * =====================================================================================
 *
 * Filename:  app_com.h
 *
 * Description:  VxWorks 串口-网络转发应用通用头文件
 * 定义了所有任务共享的常量、数据结构和全局变量声明。
 *
 * =====================================================================================
 */

/* ------------------ VxWorks and Standard C Includes ------------------ */
#include <vxWorks.h>
#include <taskLib.h>
#include <semLib.h>
#include <msgQLib.h>
#include <sysLib.h>
#include <ioLib.h>
#include <sockLib.h>
#include <inetLib.h>
#include <stdio.h>
#include <string.h>
#include "./HAL/hal_com.h"
#include "./HAL/hal_log.h"
#include "./HAL/hal_ringbuffer.h"

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

/* 网络端口定义 */
#define TCP_DATA_PORT_START     950    // 数据通道起始端口 (950-965)
#define TCP_SET_PORT_START      966    // 串口配置通道起始端口 (966-981)
#define TCP_SETTING_PORT        4000   // 全局设备配置端口

#define BUFFERCOM_SIZE_RX  (65536*2)
#define BUFFERCOM_SIZE_TX  (65536*2)



/* ------------------ Enumerations and Type Definitions ------------------ */


/**
 * @brief 定义网络连接的类型，用于ConnectionManager分发
 */
typedef enum {
    CONN_TYPE_DATA,    // 数据通道
    CONN_TYPE_SET,     // 单个串口配置通道
    CONN_TYPE_SETTING  // 全局设备配置通道
} ConnectionType;

/**
 * @brief 定义单个通道的端口映射关系
 */
typedef struct {
    int channel_index;      // 串口通道号
    int data_port;          // 对应的数据端口
    int set_port;           // 对应的配置端口

    /* ---- 以下字段在运行时填充 ---- */
    int data_listen_fd;     // 数据端口的监听socket fd
    int set_listen_fd;      // 配置端口的监听socket fd
} PortMapping;

/**
 * @brief 用于在任务间传递新连接信息的消息结构体
 */
typedef struct {
    ConnectionType type;          // 连接的类型
    int            channel_index; // 通道索引 (0-15)，对于全局配置为-1
    int            client_fd;     // 新建立的socket文件描述符
} NewConnectionMsg;

/**
 * @brief 每个通道（串口）的状态和数据结构
 */
typedef struct {
    /* -- Serial Settings -- */
    char alias[MAX_ALIAS_LEN];
    /* -- 配置参数 -- */
    int baudrate;
    int data_bits;
    int stop_bits;
    int parity;
    int flow_ctrl;
    int fifo_enable;
    int interface_type;

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

/* Main configuration structure */
typedef struct
{
	usart_params1_t config;

	int server_fdcmd;

	/* sock */
	int sock_cmd;
	int sock_data;
	uint16_t sock_cmd_port;
	uint16_t sock_data_port;

	/* client fd*/
	int cmd_client_fd;
	int data_client_fd;
	uint64_t cmd_count;
	uint64_t data_count;

	/* cmd state */
	uint8_t sock_cmd_state;
	uint8_t sock_data_state;

	/* buffer */
	char tx_buffer[BUFFERCOM_SIZE_TX];
	char rx_buffer[BUFFERCOM_SIZE_RX];
	ring_buffer_t data_tx;
	ring_buffer_t data_rx;

	/* heartbeat */
	unsigned int last_send_tick; 
	BOOL is_active;           

	/* tx chunk limit */
	int tx_buffer_limit; 

	uint64_t last_activity_time;
	uint8_t pause_send; /* 加入待后续优化 */
} UART_Config_Params;

/**
 * @brief 全局设备配置结构体
 */
typedef struct {
    /* -- Overview -- */
    char model_name[MAX_MODEL_NAME_LEN + 1];
    unsigned char mac_address[6];
    unsigned short serial_no;
    unsigned char firmware_version[3];
    unsigned char hardware_version[3];
    unsigned char lcm_present;

    /* -- Basic Settings -- */
    char server_name[MAX_SERVER_NAME_LEN + 1];
    char password[MAX_PASSWORD_LEN + 1];
    // TODO: 添加时区、时间服务器等字段
    unsigned char web_console_enabled;
    unsigned char telnet_console_enabled;
    unsigned char lcm_password_protected;
    unsigned char reset_button_protected;

    /* -- Network Settings -- */
    unsigned int ip_address;
    unsigned int netmask;
    unsigned int gateway;
    unsigned char ip_config_mode; // 0=Static, 1=DHCP, etc.
    unsigned int dns_server1;
    unsigned int dns_server2;
    
    // TODO: 添加SNMP和IP上报相关字段

} DeviceSettings;


/**
 * @brief 包含整个系统所有配置的顶层结构体
 */
typedef struct {
    DeviceSettings device;
    ChannelState channels[NUM_PORTS];
} SystemConfiguration;



/* ------------------ Global Variable Declarations (extern) ------------------ */
/*
 * 在.c文件中定义的全局变量，在此处用extern声明，以便其他文件可以访问。
 */

// 任务ID
extern TASK_ID g_conn_manager_tid;
extern TASK_ID g_realtime_scheduler_tid;
extern TASK_ID g_config_task_manager_tid;

// 消息队列ID
extern MSG_Q_ID g_data_conn_q;
extern MSG_Q_ID g_config_conn_q;

// 互斥锁ID
//extern SEM_ID g_config_mutex;

// 主状态数组：包含所有16个通道的状态
extern ChannelState g_channel_states[NUM_PORTS];
extern SystemConfiguration g_system_config;

extern void ConnectionManagerTask(void);
extern void ConfigTaskManager(void);
extern void RealTimeSchedulerTask(void);

#endif /* APP_COMMON_H */
