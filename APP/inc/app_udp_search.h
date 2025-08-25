#ifndef APP_UDP_SEARCH_H
#define APP_UDP_SEARCH_H

/**
 * @brief UDP 搜索与应答任务的主入口函数
 * @details 该任务监听特定的UDP端口上的广播包，并在收到合法的
 * 搜索请求后，单播回复设备的摘要信息。
 */
void UdpSearchTask(void);

#endif /* APP_UDP_SEARCH_H */
