/*
 * =====================================================================================
 *
 * Filename:  app_udp_search.c
 *
 * Description:  实现 UDP 搜索与应答任务，用于设备发现。
 *
 * =====================================================================================
 */

#include "./inc/app_com.h"


/* ------------------ Task-Specific Constants ------------------ */
#define UDP_SEARCH_PORT         48899 // 行业中常用的设备搜索端口
#define UDP_SEARCH_REQUEST_MSG  "SEARCH_DEVICE_WQ" // 上位机发送的搜索字符串
#define MAX_UDP_PACKET_SIZE     1024

// 准备回复内容
static  char response_msg[MAX_UDP_PACKET_SIZE];
/* ------------------ Global Variable Definitions ------------------ */

void UdpSearchTask(void)
{
    int sock_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[MAX_UDP_PACKET_SIZE];
    int optval = 1; // 用于 setsockopt 的选项值

    LOG_INFO("UdpSearchTask: Starting...");

    // 1. 创建 UDP socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        LOG_FATAL("UdpSearchTask: socket() failed: %s", strerror(errno));
        return;
    }
    
    // *** 设置SO_BROADCAST选项以允许接收广播 ***
    if (setsockopt(sock_fd, SOL_SOCKET, SO_BROADCAST, (char *)&optval, sizeof(optval)) < 0) {
        LOG_FATAL("UdpSearchTask: setsockopt(SO_BROADCAST) failed: %s", strerror(errno));
        close(sock_fd);
        return;
    }

    // 2. 准备服务器地址
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 监听所有网络接口
    server_addr.sin_port = htons(UDP_SEARCH_PORT);

    // 3. 绑定端口
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        LOG_FATAL("UdpSearchTask: bind() failed on port %d: %s", UDP_SEARCH_PORT, strerror(errno));
        close(sock_fd);
        return;
    }
    
    LOG_INFO("UdpSearchTask: Listening for broadcasts on UDP port %d", UDP_SEARCH_PORT);

    /* ------------------ 主循环，等待广播包 ------------------ */
    while (1)
    {
        // 4. 阻塞式地等待接收数据包。recvfrom 会填充发送方的地址信息
        int n = 0;
        n = recvfrom(sock_fd, buffer, MAX_UDP_PACKET_SIZE - 1, 0,
                         (struct sockaddr *)&client_addr, &client_addr_len);
        if (n > 0) {
            buffer[n] = '\0';

            // 5. 校验收到的消息是否是合法的搜索请求
            if (strncmp(buffer, UDP_SEARCH_REQUEST_MSG, strlen(UDP_SEARCH_REQUEST_MSG)) == 0) {
                
                char client_ip_str[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &client_addr.sin_addr, client_ip_str, sizeof(client_ip_str));
                LOG_INFO("UdpSearchTask: Received search request from %s", client_ip_str);

                
                // 以线程安全的方式读取全局配置
                semTake(g_config_mutex, WAIT_FOREVER);
                
                // --- 临界区开始 ---
                
                // 准备IP地址字符串
                char ip_str[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &g_system_config.device.ip_address, ip_str, sizeof(ip_str));

                // 格式化响应消息，使用分号';'作为分隔符
                snprintf(response_msg, sizeof(response_msg),
                         "%s;%02X:%02X:%02X:%02X:%02X:%02X;%hu;%d.%d.%d;%d.%d.%d;%s",
                         g_system_config.device.model_name,
                         g_system_config.device.mac_address[0], g_system_config.device.mac_address[1],
                         g_system_config.device.mac_address[2], g_system_config.device.mac_address[3],
                         g_system_config.device.mac_address[4], g_system_config.device.mac_address[5],
                         g_system_config.device.serial_no,
                         g_system_config.device.firmware_version[0], g_system_config.device.firmware_version[1], g_system_config.device.firmware_version[2],
                         g_system_config.device.hardware_version[0], g_system_config.device.hardware_version[1], g_system_config.device.hardware_version[2],
                         ip_str);
                
                // --- 临界区结束 ---
                semGive(g_config_mutex);

                // 7. 将回复单播发送回请求方
                sendto(sock_fd, response_msg, strlen(response_msg), 0,
                       (struct sockaddr *)&client_addr, client_addr_len);
            }
        }
    }
}