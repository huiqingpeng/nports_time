#ifndef APP_DEV_CFG_H
#define APP_DEV_CFG_H

/*
 * =====================================================================================
 *
 * Filename:  app_dev_cfg.h
 *
 * Description:  此文件集中定义了所有通道操作模式的默认配置参数。
 * 通过宏定义，可以方便地调整和维护不同模式下的默认值。
 *
 * =====================================================================================
 */
 
#include "app_com.h" // 引入 OP_MODE_*, DELIMITER_PROCESS_NONE 等枚举类型

//--------------------------------------------------------------------------------------
#define NET_NUM 2
//--- Real COM Mode 默认配置参数 ---
#define DEFAULT_COM_BAUDRATE                115200
#define DEFAULT_COM_INTERFACE_TYPE          INTERFACE_TYPE_RS232               

//--------------------------------------------------------------------------------------

/** @brief 默认的操作模式 (Real COM)。 */
#define DEFAULT_COM_OP_MODE              OP_MODE_REAL_COM
/** @brief TCP 连接保活探测时间 (单位：分钟)。 */
#define DEFAULT_REAL_COM_TCP_ALIVE_CHECK_MIN  7
/** @brief 允许的最大TCP连接数。 */
#define DEFAULT_REAL_COM_MAX_CONNECTIONS      8
/** @brief 是否忽略造成网络拥塞的IP (0: No)。 */
#define DEFAULT_REAL_COM_IGNORE_JAMMED_IP     0
/** @brief 是否允许驱动程序通过特殊指令控制设备 (0: No)。 */
#define DEFAULT_REAL_COM_ALLOW_DRIVER_CONTROL 0
/** @brief 打包长度 (字节, 0表示禁用)。 */
#define DEFAULT_REAL_COM_PACKING_LENGTH       0
/** @brief 第一个分隔符。 */
#define DEFAULT_REAL_COM_DELIMITER1           0x00
/** @brief 第二个分隔符。 */
#define DEFAULT_REAL_COM_DELIMITER2           0x00
/** @brief 分隔符处理方式。 */
#define DEFAULT_REAL_COM_DELIMITER_PROCESS    DELIMITER_PROCESS_NONE
/** @brief 强制发送时间 (毫秒, 0表示禁用)。 */
#define DEFAULT_REAL_COM_FORCE_TRANSMIT_TIME  0

//--------------------------------------------------------------------------------------
//--- TCP Server Mode 默认配置参数 ---
//--------------------------------------------------------------------------------------

/** @brief 默认的操作模式 (TCP Server)。 */
#define DEFAULT_TCPSERVER_OP_MODE              OP_MODE_TCP_SERVER
/** @brief TCP 连接保活探测时间 (单位：分钟)。 */
#define DEFAULT_TCPSERVER_TCP_ALIVE_CHECK_MIN  7
/** @brief 连接不活动超时时间 (毫秒, 0表示禁用)。 */
#define DEFAULT_TCPSERVER_INACTIVITY_TIME_MS   0
/** @brief 允许的最大TCP连接数。 */
#define DEFAULT_TCPSERVER_MAX_CONNECTIONS      1
/** @brief 是否忽略造成网络拥塞的IP (0: No)。 */
#define DEFAULT_TCPSERVER_IGNORE_JAMMED_IP     0
/** @brief 是否允许驱动程序通过特殊指令控制设备 (0: No)。 */
#define DEFAULT_TCPSERVER_ALLOW_DRIVER_CONTROL 0
/** @brief 打包长度 (字节, 0表示禁用)。 */
#define DEFAULT_TCPSERVER_PACKING_LENGTH       0
/** @brief 第一个分隔符。 */
#define DEFAULT_TCPSERVER_DELIMITER1           0x00
/** @brief 第二个分隔符。 */
#define DEFAULT_TCPSERVER_DELIMITER2           0x00
/** @brief 分隔符处理方式。 */
#define DEFAULT_TCPSERVER_DELIMITER_PROCESS    DELIMITER_PROCESS_NONE
/** @brief 强制发送时间 (毫秒, 0表示禁用)。 */
#define DEFAULT_TCPSERVER_FORCE_TRANSMIT_TIME  0
/** @brief 本地监听的数据端口。 */
#define DEFAULT_TCPSERVER_LOCAL_TCP_PORT       4001
/** @brief 本地监听的命令端口。 */
#define DEFAULT_TCPSERVER_COMMAND_PORT         966
/** @brief 本地监听的命令端口。 */
#define DEFAULT_TCPSERVER_DATA_PORT            950

//--------------------------------------------------------------------------------------
//--- TCP Client Mode 默认配置参数 ---
//--------------------------------------------------------------------------------------

/** @brief 默认的操作模式 (TCP Client)。 */
#define DEFAULT_TCPCLIENT_OP_MODE              OP_MODE_TCP_CLIENT
/** @brief TCP 连接保活探测时间 (单位：分钟)。 */
#define DEFAULT_TCPCLIENT_TCP_ALIVE_CHECK_MIN  7
/** @brief 连接不活动超时时间 (毫秒, 0表示禁用)。 */
#define DEFAULT_TCPCLIENT_INACTIVITY_TIME_MS   0
/** @brief 是否忽略造成网络拥塞的IP (0: No)。 */
#define DEFAULT_TCPCLIENT_IGNORE_JAMMED_IP     0
/** @brief 打包长度 (字节, 0表示禁用)。 */
#define DEFAULT_TCPCLIENT_PACKING_LENGTH       0
/** @brief 第一个分隔符。 */
#define DEFAULT_TCPCLIENT_DELIMITER1           0x00
/** @brief 第二个分隔符。 */
#define DEFAULT_TCPCLIENT_DELIMITER2           0x00
/** @brief 分隔符处理方式。 */
#define DEFAULT_TCPCLIENT_DELIMITER_PROCESS    DELIMITER_PROCESS_NONE
/** @brief 强制发送时间 (毫秒, 0表示禁用)。 */
#define DEFAULT_TCPCLIENT_FORCE_TRANSMIT_TIME  0
/** @brief 目标IP地址1 (0.0.0.0)。 */
#define DEFAULT_TCPCLIENT_DEST_IP1             0
/** @brief 目标端口1。 */
#define DEFAULT_TCPCLIENT_DEST_PORT1           4001
/** @brief 目标IP地址2 (0.0.0.0)。 */
#define DEFAULT_TCPCLIENT_DEST_IP2             0
/** @brief 目标端口2。 */
#define DEFAULT_TCPCLIENT_DEST_PORT2           4001
/** @brief 目标IP地址3 (0.0.0.0)。 */
#define DEFAULT_TCPCLIENT_DEST_IP3             0
/** @brief 目标端口3。 */
#define DEFAULT_TCPCLIENT_DEST_PORT3           4001
/** @brief 目标IP地址4 (0.0.0.0)。 */
#define DEFAULT_TCPCLIENT_DEST_IP4             0
/** @brief 目标端口4。 */
#define DEFAULT_TCPCLIENT_DEST_PORT4           4001
/** @brief 指定本地端口1。 */
#define DEFAULT_TCPCLIENT_LOCAL_PORT1          5011
/** @brief 指定本地端口2。 */
#define DEFAULT_TCPCLIENT_LOCAL_PORT2          5012
/** @brief 指定本地端口3。 */
#define DEFAULT_TCPCLIENT_LOCAL_PORT3          5013
/** @brief 指定本地端口4。 */
#define DEFAULT_TCPCLIENT_LOCAL_PORT4          5014
/** @brief 连接控制 (0: Startup/None)。 */
#define DEFAULT_TCPCLIENT_CONNECTION_CONTROL   0

//--------------------------------------------------------------------------------------
//--- UDP Mode 默认配置参数 ---
//--------------------------------------------------------------------------------------

/** @brief 默认的操作模式 (UDP)。 */
#define DEFAULT_UDP_OP_MODE                    OP_MODE_UDP
/** @brief 打包长度 (字节, 0表示禁用)。 */
#define DEFAULT_UDP_PACKING_LENGTH             0
/** @brief 第一个分隔符。 */
#define DEFAULT_UDP_DELIMITER1                 0x00
/** @brief 第二个分隔符。 */
#define DEFAULT_UDP_DELIMITER2                 0x00
/** @brief 分隔符处理方式。 */
#define DEFAULT_UDP_DELIMITER_PROCESS          DELIMITER_PROCESS_NONE
/** @brief 强制发送时间 (毫秒, 0表示禁用)。 */
#define DEFAULT_UDP_FORCE_TRANSMIT_TIME        0
/** @brief 目标起始IP地址1 (0.0.0.0)。 */
#define DEFAULT_UDP_DEST_BEGIN_IP1             0
/** @brief 目标结束IP地址1 (0.0.0.0)。 */
#define DEFAULT_UDP_DEST_END_IP1               0
/** @brief 目标端口1。 */
#define DEFAULT_UDP_DEST_PORT1                 4001
/** @brief 目标起始IP地址2 (0.0.0.0)。 */
#define DEFAULT_UDP_DEST_BEGIN_IP2             0
/** @brief 目标结束IP地址2 (0.0.0.0)。 */
#define DEFAULT_UDP_DEST_END_IP2               0
/** @brief 目标端口2。 */
#define DEFAULT_UDP_DEST_PORT2                 4001
/** @brief 目标起始IP地址3 (0.0.0.0)。 */
#define DEFAULT_UDP_DEST_BEGIN_IP3             0
/** @brief 目标结束IP地址3 (0.0.0.0)。 */
#define DEFAULT_UDP_DEST_END_IP3               0
/** @brief 目标端口3。 */
#define DEFAULT_UDP_DEST_PORT3                 4001
/** @brief 目标起始IP地址4 (0.0.0.0)。 */
#define DEFAULT_UDP_DEST_BEGIN_IP4             0
/** @brief 目标结束IP地址4 (0.0.0.0)。 */
#define DEFAULT_UDP_DEST_END_IP4               0
/** @brief 目标端口4。 */
#define DEFAULT_UDP_DEST_PORT4                 4001
/** @brief 本地监听端口。 */
#define DEFAULT_UDP_LOCAL_LISTEN_PORT          4001


#endif /* APP_DEV_CFG_H */