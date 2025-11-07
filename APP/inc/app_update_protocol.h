/*
 * =================================================================
 * update_protocol.h
 *
 * 定义了固件更新TCP协议的应答码。
 * (由上位机和下位机共享)
 * =================================================================
 */

#ifndef UPDATE_PROTOCOL_H
#define UPDATE_PROTOCOL_H

#include <stdint.h>

/*
 * 协议状态码 (32位整数, 网络字节序)
 *
 * 【警告】: 0x00000000 不是一个有效的状态码 (保留)
 */

/*
 * 由服务器发送 -> 客户端接收
 * 含义: "我已收到文件, 并且所有 CRC/Magic 校验均通过。"
 * "我现在即将开始擦写 FLASH。"
 */
#define STATUS_OK_TO_PROCEED 0x00000001

/*
 * 由服务器发送 -> 客户端接收
 * 含义: "FLASH 擦写已完成, 环境变量已设置。"
 * "更新流程圆满成功。"
 */
#define STATUS_WRITE_COMPLETE 0x00000002

/*
 * 由服务器发送 -> 客户端接收
 * 含义: "发生了错误。"
 * "(例如: Malloc失败, CRC校验失败, FLASH写入失败)"
 */
#define STATUS_ERROR 0xFFFFFFFF


/*
 * 辅助函数: 发送一个状态码
 */
static int send_status(int sock, uint32_t status_code)
{
    uint32_t net_status = htonl(status_code); /* 转换为主机->网络字节序 */
    if (send(sock, (const char*)&net_status, sizeof(net_status), 0) != sizeof(net_status)) {
        /* 发送失败 (客户端可能已断开) */
        return -1;
    }
    return 0;
}

/*
 * 辅助函数: 接收一个状态码
 */
static uint32_t recv_status(int sock)
{
    uint32_t net_status = 0;
    int bytes_read = recv(sock, (char*)&net_status, sizeof(net_status), 0);
    
    if (bytes_read != sizeof(net_status)) {
        /* 接收失败 (服务器已断开或超时) */
        return 0; /* 返回 0 (无效状态码) */
    }
    return ntohl(net_status); /* 转换网络->主机字节序 */
}


#endif /* UPDATE_PROTOCOL_H */
