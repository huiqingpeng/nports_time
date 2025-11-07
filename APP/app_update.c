/*
 * =================================================================
 * firmware_server_task_v2.c
 *
 * VxWorks 6.9 固件更新 TCP 服务器 (V-Final 方案)
 *
 * 特性:
 * 1. 接收一个完整的 "update.pkg" 固件包。
 * 2. 在 RAM 中对固件包执行完整的5项校验。
 * 3. 【新】使用 "双向应答" 协议:
 * - 校验通过后, 发送 STATUS_OK_TO_PROCEED
 * - FLASH 写入完成后, 发送 STATUS_WRITE_COMPLETE
 * - 发生任何错误, 发送 STATUS_ERROR
 * 4. 【新】不依赖文件系统, 而是:
 * - #include "vx_env_lib.c"
 * - 调用 app_fw_setenv() 和 app_fw_save() 来安全地
 * 更新 mtd2 (app_env) 中的冗余环境变量。
 * =================================================================
 */

/* VxWorks 核心头文件 */
#include <vxWorks.h>
#include <taskLib.h>     /* 用于 taskSpawn */
#include <sockLib.h>     /* 用于套接字 API */
#include <inetLib.h>     /* 用于 inet_addr */
#include <ioLib.h>       /* 用于 close */
#include <logLib.h>      /* 用于 LOG_INFO */
#include <stdio.h>
#include <stdlib.h>      /* 用于 malloc, free */
#include <string.h>      /* 用于 memcpy, memset */
#include <unistd.h>      /* (VxWorks 6.9 可能需要) */

/* --- 1. 包含共享的定义 --- */
#include "./HAL/hal_log.h"
/* 固件包结构体 (magic, crc, versions...) */
#include "./inc/app_update_header.h"

/* TCP 协议应答码 (STATUS_OK_TO_PROCEED...) */
#include "./inc/app_update_protocol.h"

#include "./inc/app_com.h"

#include "./inc/app_update_env.h"


/* --- 2. 服务器配置 --- */
#define SERVER_PORT 19001
#define SERVER_TASK_PRIORITY 100
#define SERVER_STACK_SIZE 32768
#define MAX_CLIENT_QUEUE 1

/*
 * 固件包最大允许大小 (例如 20MB)
 * (防止恶意客户端耗尽 RAM)
 */
#define MAX_PACKAGE_SIZE (20 * 1024 * 1024)

/* 任务 ID */
static int serverTaskId = 0;

/* --- 3. 函数原型 --- */
void update_server_main(void);
STATUS handle_client(int client_sock);
STATUS process_firmware_package(int client_sock, char *buffer, long size);

/* 【修正】: 函数原型现在需要 header 指针 */
STATUS write_firmware_to_flash(
    const fw_package_header_t *header,
    const char *bit_data,
    const char *app_data
);


/*
 * =================================================================
 * 任务启动函数 (从 VxWorks Shell 调用)
 * =================================================================
 */
STATUS start_update_server(void)
{
    if (serverTaskId != 0) {
        LOG_INFO("[!] 固件更新服务器任务已在运行 (ID: %d)\n", serverTaskId, 0,0,0,0,0);
        return ERROR;
    }

    /* 启动主服务器任务 */
    serverTaskId = taskSpawn("tFwUpdateSrv",
                             SERVER_TASK_PRIORITY,
                             0, /* 默认选项 */
                             SERVER_STACK_SIZE,
                             (FUNCPTR)update_server_main,
                             0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    if (serverTaskId == ERROR) {
        LOG_INFO("[X] 致命错误: 无法启动 tFwUpdateSrv 任务\n", 0,0,0,0,0,0);
        serverTaskId = 0;
        return ERROR;
    }

    LOG_INFO("[+] 固件更新服务器已在端口 %d 上启动 (任务 ID: %d)\n", SERVER_PORT, serverTaskId, 0,0,0,0);
    return OK;
}

/*
 * =================================================================
 * 主服务器任务 (循环)
 * =================================================================
 */
void update_server_main(void)
{
    int server_sock, client_sock;
    struct sockaddr_in serv_addr, client_addr;
    int client_addr_len = sizeof(client_addr);

    /* 1. 创建服务器套接字 */
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == ERROR) {
        LOG_INFO("tFwUpdateSrv: [X] Socket 创建失败\n", 0,0,0,0,0,0);
        serverTaskId = 0;
        return;
    }

    /* 2. 绑定地址 */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == ERROR) {
        LOG_INFO("tFwUpdateSrv: [X] 绑定端口 %d 失败\n", SERVER_PORT, 0,0,0,0,0);
        close(server_sock);
        serverTaskId = 0;
        return;
    }

    /* 3. 监听连接 */
    if (listen(server_sock, MAX_CLIENT_QUEUE) == ERROR) {
        LOG_INFO("tFwUpdateSrv: [X] 监听失败\n", 0,0,0,0,0,0);
        close(server_sock);
        serverTaskId = 0;
        return;
    }

    /* 4. 接受客户端循环 */
    LOG_INFO("tFwUpdateSrv: [*] 等待客户端连接...\n", 0,0,0,0,0,0);
    
    while (1)
    {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        
        if (client_sock == ERROR) {
            LOG_INFO("tFwUpdateSrv: [!] Accept 失败, 正在退出...\n", 0,0,0,0,0,0);
            /* (在真实系统中, 这里可能不应该退出, 而是继续循环) */
            break; 
        }

        LOG_INFO("tFwUpdateSrv: [+] 客户端 %s 已连接\n", (int)inet_ntoa(client_addr.sin_addr), 0,0,0,0,0);

        /* 5. 处理这个客户端 (阻塞) */
        if (handle_client(client_sock) == ERROR) {
            LOG_INFO("tFwUpdateSrv: [!] 客户端处理失败或断开连接\n", 0,0,0,0,0,0);
        }

        close(client_sock);
        LOG_INFO("tFwUpdateSrv: [*] 客户端已断开, 等待下一个...\n", 0,0,0,0,0,0);
    }

    /* 6. 清理 */
    close(server_sock);
    serverTaskId = 0;
    LOG_INFO("tFwUpdateSrv: [*] 服务器任务正在关闭。\n", 0,0,0,0,0,0);
}


/*
 * =================================================================
 * 客户端处理 (接收文件)
 * =================================================================
 */
STATUS handle_client(int client_sock)
{
    uint32_t net_size;
    uint32_t file_size;
    char *file_buffer = NULL;
    int bytes_read = 0;
    int total_bytes_read = 0;

    /* 1. 接收 4 字节的文件总长度 (网络字节序) */
    bytes_read = recv(client_sock, (char *)&net_size, sizeof(net_size), 0);
    if (bytes_read != sizeof(net_size)) {
        LOG_INFO("handle_client: [X] 接收文件大小失败 (读取 %d 字节)\n", bytes_read, 0,0,0,0,0);
        return ERROR;
    }
    file_size = ntohl(net_size); /* 转换为 主机 字节序 */

    /* 2. 安全检查: 检查文件大小是否过大 */
    if (file_size == 0 || file_size > MAX_PACKAGE_SIZE) {
        LOG_INFO("handle_client: [X] 文件大小无效或过大 (Size: %u)\n", file_size, 0,0,0,0,0);
        send_status(client_sock, STATUS_ERROR); /* (V4) 发送错误 */
        return ERROR;
    }

    LOG_INFO("handle_client: [*] 收到文件大小: %u 字节\n", file_size, 0,0,0,0,0);

    /* 3. 分配 RAM 缓冲区 (关键) */
    file_buffer = (char *)malloc(file_size);
    if (file_buffer == NULL) {
        LOG_INFO("handle_client: [X] 致命错误: Malloc 失败 (无法分配 %u 字节)\n", file_size, 0,0,0,0,0);
        send_status(client_sock, STATUS_ERROR); /* (V4) 发送错误 */
        return ERROR;
    }

    /* 4. 循环接收, 直到收满 'file_size' 字节 */
    LOG_INFO("handle_client: [*] 正在接收文件...\n", 0,0,0,0,0,0);
    while (total_bytes_read < file_size)
    {
        bytes_read = recv(client_sock, 
                          file_buffer + total_bytes_read, /* 写入缓冲区的正确位置 */
                          file_size - total_bytes_read,   /* 还需要多少字节 */
                          0);
        
        if (bytes_read <= 0) {
            /* 客户端提前断开连接 */
            LOG_INFO("handle_client: [X] 接收中断 (在 %d 字节处)\n", total_bytes_read, 0,0,0,0,0);
            free(file_buffer);
            /* (V4) 不需要发送错误, 因为连接已断 */
            return ERROR;
        }
        total_bytes_read += bytes_read;
    }

    LOG_INFO("handle_client: [+] 文件接收完毕 (%d 字节)\n", total_bytes_read, 0,0,0,0,0);

    /* 5. 【关键】处理这个缓冲区中的文件 (校验、擦写、发送应答) */
    if (process_firmware_package(client_sock, file_buffer, file_size) != OK) {
        LOG_INFO("handle_client: [X] 固件处理失败。\n", 0,0,0,0,0,0);
        /* (process_firmware_package 已经发送了 STATUS_ERROR) */
        free(file_buffer);
        return ERROR;
    }

    /* 6. 清理 */
    free(file_buffer);
    LOG_INFO("handle_client: [+] 固件更新流程成功。\n", 0,0,0,0,0,0);
    return OK;
}


/*
 * =================================================================
 * 固件包处理 (校验、写入)
 * =================================================================
 */
STATUS process_firmware_package(int client_sock, char *buffer, long size)
{
    fw_package_header_t *header = NULL;
    const char *bit_data = NULL;
    const char *app_data = NULL;
    uint32_t header_crc_calc, bit_crc_calc, app_crc_calc;
    uint32_t expected_total_size;

    /* 1. 结构体映射 (Casting) */
    if (size < sizeof(fw_package_header_t)) {
        LOG_INFO("process_pkg: [X] 错误: 文件大小 (%ld) 小于头部大小 (%d)\n", size, (int)sizeof(fw_package_header_t), 0,0,0,0);
        send_status(client_sock, STATUS_ERROR);
        return ERROR;
    }
    header = (fw_package_header_t *)buffer;

    /* 2. 【校验 #1: Magic Number】 */
    if (header->magic_number != FW_PACKAGE_MAGIC) {
        LOG_INFO("process_pkg: [X] 致命错误: Magic Number 不匹配! (Expected: 0x%X, Got: 0x%X)\n", FW_PACKAGE_MAGIC, header->magic_number, 0,0,0,0);
        send_status(client_sock, STATUS_ERROR);
        return ERROR;
    }
    LOG_INFO("process_pkg: [*] 校验 1/5: Magic Number OK (0x%X)\n", header->magic_number, 0,0,0,0,0);

    /* 3. 【校验 #2: Header CRC】 */
    /* (从偏移量 8 (pkg_version) 开始, 到头部末尾) */
    const void *header_data_ptr = (const void *)header + 8;
    size_t header_data_len = FW_PACKAGE_HEADER_SIZE - 8;
    header_crc_calc = calculate_crc32(0, header_data_ptr, header_data_len);

    if (header_crc_calc != header->header_crc32) {
        LOG_INFO("process_pkg: [X] 致命错误: Header CRC 校验失败! (Expected: 0x%X, Got: 0x%X)\n", header->header_crc32, header_crc_calc, 0,0,0,0);
        send_status(client_sock, STATUS_ERROR);
        return ERROR;
    }
    LOG_INFO("process_pkg: [*] 校验 2/5: Header CRC OK (0x%X)\n", header->header_crc32, 0,0,0,0,0);

    /* 4. 【校验 #3: 总大小】 */
    expected_total_size = FW_PACKAGE_HEADER_SIZE + header->bit_length + header->app_length;
    if (size != expected_total_size) {
        LOG_INFO("process_pkg: [X] 致命错误: 文件总大小不匹配! (Expected: %u, Got: %ld)\n", expected_total_size, size, 0,0,0,0);
        send_status(client_sock, STATUS_ERROR);
        return ERROR;
    }
    LOG_INFO("process_pkg: [*] 校验 3/5: 总大小 OK (%u 字节)\n", (unsigned int)size, 0,0,0,0,0);

    /* 5. 定位数据 */
    bit_data = buffer + FW_PACKAGE_HEADER_SIZE;
    app_data = bit_data + header->bit_length;

    /* 6. 【校验 #4: Bitstream CRC】 */
    LOG_INFO("process_pkg: [*] 正在校验 Bitstream (%u 字节)...\n", header->bit_length, 0,0,0,0,0);
    bit_crc_calc = calculate_crc32(0, bit_data, header->bit_length);
    if (bit_crc_calc != header->bit_crc32) {
        LOG_INFO("process_pkg: [X] 致命错误: Bitstream CRC 校验失败! (Expected: 0x%X, Got: 0x%X)\n", header->bit_crc32, bit_crc_calc, 0,0,0,0);
        send_status(client_sock, STATUS_ERROR);
        return ERROR;
    }
    LOG_INFO("process_pkg: [*] 校验 4/5: Bitstream CRC OK (0x%X)\n", header->bit_crc32, 0,0,0,0,0);

    /* 7. 【校验 #5: Application CRC】 */
    LOG_INFO("process_pkg: [*] 正在校验 Application (%u 字节)...\n", header->app_length, 0,0,0,0,0);
    app_crc_calc = calculate_crc32(0, app_data, header->app_length);
    
    /* 【修正】: 修正拼写错误 app_crc2 -> app_crc32 */
    if (app_crc_calc != header->app_crc32) {
        LOG_INFO("process_pkg: [X] 致命错误: Application CRC 校验失败! (Expected: 0x%X, Got: 0x%X)\n", header->app_crc32, app_crc_calc, 0,0,0,0);
        send_status(client_sock, STATUS_ERROR);
        return ERROR;
    }
    LOG_INFO("process_pkg: [*] 校验 5/5: Application CRC OK (0x%X)\n", header->app_crc32, 0,0,0,0,0);
    
    LOG_INFO("process_pkg: [+] 所有校验通过! 准备写入 FLASH。\n", 0,0,0,0,0,0);

    /* 8. 【(V4) 发送应答 #1: 校验 OK】 */
    if (send_status(client_sock, STATUS_OK_TO_PROCEED) != 0) {
        LOG_INFO("process_pkg: [!] 发送 OK_TO_PROCEED 失败 (客户端可能已断开)\n", 0,0,0,0,0,0);
        return ERROR; /* 停止, 不写入 FLASH */
    }

    /* 9. 【关键】执行 FLASH 擦写 (慢速操作) */
    /* (我们传入 header 指针, 以便 write 函数可以访问大小信息) */
    if (write_firmware_to_flash(header, bit_data, app_data) != OK) {
        LOG_INFO("process_pkg: [X] 致命错误: 写入 FLASH 失败!\n", 0,0,0,0,0,0);
        send_status(client_sock, STATUS_ERROR);
        return ERROR;
    }
    
    /* 10. 【(V4) 发送应答 #2: 写入完成】 */
    LOG_INFO("process_pkg: [*] 写入 FLASH 成功, 正在发送最终确认...\n", 0,0,0,0,0,0);
    if (send_status(client_sock, STATUS_WRITE_COMPLETE) != 0) {
        LOG_INFO("process_pkg: [!] 发送 WRITE_COMPLETE 失败 (客户端可能已断开)\n", 0,0,0,0,0,0);
        /* * 此时已写入成功, 即使发送失败也返回 OK
         * (因为客户端只是没收到通知, 但更新已完成)
         */
    }
    
    return OK;
}


/*
 * =================================================================
 * FLASH 写入逻辑 (V-Final 方案)
 * =================================================================
 */
STATUS write_firmware_to_flash(
    const fw_package_header_t *header,
    const char *bit_data,
    const char *app_data)
{
    /*
     * 【V-Final 方案】:
     * 我们假设正在从 A 区启动, 目标是更新 B 区。
     * mtd5 (boot_b) @ 0xB40000 (大小 5MB)
     * mtd6 (app_b)  @ 0x1040000 (大小 5MB)
     * mtd2 (app_env) @ 0x120000 (共享环境)
     */
     
    /* --- 步骤 1: 写入 Bitstream B (mtd5) --- */
    LOG_INFO("write_flash: [1/4] 擦除 boot_b (mtd5 @ 0xB40000)...\n", 0,0,0,0,0,0);
    if (flash_data_erase(0xB40000, 0x500000) != OK) {
        LOG_INFO("write_flash: [X] 擦除 mtd5 失败!\n", 0,0,0,0,0,0);
        return ERROR;
    }
    
    LOG_INFO("write_flash: [1/4] 正在写入 %u 字节到 boot_b (mtd5)...\n", header->bit_length, 0,0,0,0,0);
    if (flash_data_write(0xB40000, bit_data, header->bit_length) != OK) {
        LOG_INFO("write_flash: [X] 写入 mtd5 失败!\n", 0,0,0,0,0,0);
        return ERROR;
    }

    /* --- 步骤 2: 写入 Application B (mtd6) --- */
    LOG_INFO("write_flash: [2/4] 擦除 app_b (mtd6 @ 0x1040000)...\n", 0,0,0,0,0,0);
    if (flash_data_erase(0x1040000, 0x500000) != OK) {
        LOG_INFO("write_flash: [X] 擦除 mtd6 失败!\n", 0,0,0,0,0,0);
        return ERROR;
    }
    
    LOG_INFO("write_flash: [2/4] 正在写入 %u 字节到 app_b (mtd6)...\n", header->app_length, 0,0,0,0,0);
    if (flash_data_write(0x1040000, app_data, header->app_length) != OK) {
        LOG_INFO("write_flash: [X] 写入 mtd6 失败!\n", 0,0,0,0,0,0);
        return ERROR;
    }

    /* --- 步骤 3: 【关键】调用 "无FS" 库来设置 mtd2 --- */
    
    /* * 3.1: 加载 mtd2 (app_env) 的当前状态到内存
     * (app_fw_find_env 会自动处理 CRC 和冗余)
     */
    LOG_INFO("write_flash: [3/4] 正在加载 mtd2 (app_env)...\n", 0,0,0,0,0,0);
    if (app_fw_find_env() != OK) {
        LOG_INFO("write_flash: [X] 无法加载环境变量 (mtd2)!\n", 0,0,0,0,0,0);
        return ERROR;
    }
    
    /* * 3.2: 在内存中设置B区的大小
     * (这些变量将被 Golden U-Boot 的 bootcmd 读取)
     */
    char size_str[12]; /* 用于整数到字符串的转换 */
    
    sprintf(size_str, "%u", header->bit_length);
    app_fw_setenv("fpga_size_b", size_str);
    
    sprintf(size_str, "%u", header->app_length);
    app_fw_setenv("app_size_b", size_str);
    
    /* * 3.3: 在内存中设置安全计数器和标志位
     * (Golden U-Boot 将读取这些来触发切换)
     */
    app_fw_setenv("boot_count", "3");
    app_fw_setenv("ver_select", "b");

    /* * 3.4: 【原子写入】将所有更改提交到 mtd2
     * (app_fw_save 会自动重算 CRC, 并在冗余扇区中写入)
     */
    LOG_INFO("write_flash: [4/4] 正在保存环境变量 (mtd2) 以切换到 B...\n", 0,0,0,0,0,0);
    if (app_fw_save() != OK) {
        LOG_INFO("write_flash: [X] 无法保存环境变量 (mtd2)!\n", 0,0,0,0,0,0);
        return ERROR;
    }

    LOG_INFO("write_flash: [+] FLASH 更新成功。\n", 0,0,0,0,0,0);
    return OK;
}

