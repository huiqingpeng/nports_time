
#ifndef __APP_NET_CON_H__
#define __APP_NET_CON_H__

#include <vxWorks.h> // For STATUS type

/**
 * @file app_net_con.h
 * @brief 网络连接管理器模块公共接口
 *
 * 该模块提供了一个独立的任务 (ConnectionManagerTask)，负责：
 * 1. 根据系统配置，创建和管理所有网络套接字 (TCP Server/Client, UDP)。
 * 2. 监听TCP Server端口，接受新的客户端连接。
 * 3. 处理非阻塞的TCP Client连接过程。
 * 4. 将准备就绪的套接字文件描述符 (fd) 分发给对应的业务逻辑任务。
 * 5. 响应动态重配命令，安全地更新单个通道的网络模式。
 */

/**
 * @brief 启动网络连接管理器任务
 *
 * 创建并启动 ConnectionManagerTask。此函数应在系统初始化阶段，
 * 
 * 在所有消息队列创建完毕、业务逻辑任务启动之后调用。
 *
 * @return STATUS OK on success, ERROR on failure.
 */
STATUS ConnectionManager_TaskStart(void);

/**
 * @brief 向 ConnectionManagerTask 发送一个重新配置通道的命令
 *
 * 这是一个非阻塞、线程安全的函数，可以从任何其他任务（如配置管理任务）调用，
 * 以便动态更改某个串口的网络模式。
 *
 * @param channel_index 要重新配置的通道号 (0-15)
 * @return STATUS OK on success, ERROR if the command could not be sent.
 */
STATUS ConnectionManager_RequestReconfigure(int channel_index);


/**
 * @brief 通知 ConnectionManagerTask 一个TCP连接已关闭
 *
 * 当业务逻辑任务关闭一个由 ConnectionManager 分发下来的TCP套接字时，
 * 必须调用此函数来更新连接计数器。
 *
 * @param channel_index 连接所属的通道号 (0-15)
 * @return STATUS OK on success, ERROR if the notification could not be sent.
 */
STATUS ConnectionManager_NotifyConnectionClosed(int channel_index);

#endif // __APP_NET_CON_H__
