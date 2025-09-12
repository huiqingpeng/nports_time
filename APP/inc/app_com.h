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
#include "app_dev.h"

/* 网络端口定义 */
#define TCP_DATA_PORT_START     950    // 数据通道起始端口 (950-965)
#define TCP_SET_PORT_START      966    // 串口配置通道起始端口 (966-981)
#define TCP_SETTING_PORT        4000   // 全局设备配置端口

#define BUFFERCOM_SIZE_RX  (65536*2)
#define BUFFERCOM_SIZE_TX  (65536*2)

// 发送配置相关常量
#define MIN_BAUDRATE        50      // 最小波特率
#define MAX_BAUDRATE        1000000 // 最大波特率

#define BITS_PER_CHAR      10      // 1起始位+8数据位+1停止位
#define MIN_PACKET_SIZE    4       // 最小包大小(字节)
#define MAX_PACKET_SIZE    (256)    // 最大包大小(字节)

#define TIMER_TICK_US     100     // 定时器tick为100微秒
#define US_TO_MS          1000    // 微秒转毫秒


#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#endif


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


/* ------------------ Global Variable Declarations (extern) ------------------ */
/*
 * 在.c文件中定义的全局变量，在此处用extern声明，以便其他文件可以访问。
 */
// 消息队列ID
extern MSG_Q_ID g_data_conn_q;
extern MSG_Q_ID g_config_conn_q;

// 互斥锁ID
extern SEM_ID g_config_mutex;

// 主状态数组：包含所有16个通道的状态
extern SystemConfiguration g_system_config;

extern void ConnectionManagerTask(void);
extern void ConfigTaskManager(void);
extern void RealTimeSchedulerTask(void);

#endif /* APP_COMMON_H */
