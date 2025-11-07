/*
 * =================================================================
 *
 * VxWorks MTD 环境变量读写库 (无文件系统依赖)
 * (V-Final 方案 - 共享环境 @ mtd2)
 *
 * 实现了 U-Boot fw_setenv 的核心功能:
 * 1. 知道 mtd2 (app_env) 的冗余扇区 (0x120000 和 0x130000)。
 * 2. 知道如何计算 U-Boot CRC32。
 * 3. 知道如何安全地在两个扇区之间交替写入。
 *
 * 【重要】:
 * 1. 必须提供 MTD/Flash 驱动的占位函数。
 * 2. CRC32 算法必须与 U-Boot (zlib) 匹配。
 * 3. 环境变量大小 (ENV_SIZE) 必须与 U-Boot (CONFIG_ENV_SIZE) 匹配。
 * =================================================================
 */

/* * 包含的头文件 (根据您的 VxWorks 环境)
 * 您需要 stdint.h (用于 uint32_t), string.h (用于 memcmp, memcpy, strlen)
 * 和 STATUS (OK/ERROR) 的定义。
 */
#include <vxWorks.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "./HAL/hal_log.h"


/* --- 1. MTD 驱动占位函数 (您必须实现) --- */
/*
 * 【警告】: 您必须使用您 VxWorks BSP 中
 * 真实的 MTD 驱动 API 替换这些函数。
 */

STATUS flash_data_read(uint32_t offset, void* data, uint32_t len)
{
    /* * 占位逻辑: (例如: `sysQspiRead(offset, data, len)`)
     * LOG_INFO("    (模拟) MTD 读取: 偏移量 0x%x, 大小 %u\n", offset, len,0,0,0,0);
     */
     
    /* 【警告】: 占位代码, 总是返回 OK */
    /* 您必须实现真实的读取 */
    if (offset < 0x02000000) {
        /* (模拟读取成功) */
        /* memset(data, 0xFF, len); */ /* 真实的 read 会填充 data */
        return OK;
    }
    return ERROR;
}

STATUS flash_data_write(uint32_t offset, const void* data, uint32_t len)
{
    /* * 占位逻辑: (例如: `sysQspiWrite(offset, data, len)`)
     * LOG_INFO("    (模拟) MTD 写入: 偏移量 0x%x, 大小 %u\n", offset, len,0,0,0,0);
     */
     
    /* 【警告】: 占位代码, 总是返回 OK */
    /* 您必须实现真实的写入 */
    if (offset < 0x02000000) {
        return OK;
    }
    return ERROR;
}

STATUS flash_data_erase(uint32_t offset, uint32_t len)
{
    /* * 占位逻辑: (例如: `sysQspiErase(offset, len)`)
     * LOG_INFO("    (模拟) MTD 擦除: 偏移量 0x%x, 大小 %u\n", offset, len,0,0,0,0);
     */
     
    /* 【警告】: 占位代码, 总是返回 OK */
    /* 您必须实现真实的擦除 */
    if (offset < 0x02000000) {
        return OK;
    }
    return ERROR;
}


/* --- 2. U-Boot CRC32 (zlib) 算法 --- */
/* (这与 update_client_v4.c 和 image_update.py 中的算法完全相同) */
static const uint32_t crc32_table[256] = {
    0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
    0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
    0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
    0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
    0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L,
    0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L,
    0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L,
    0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
    0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,
    0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL,
    0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L,
    0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
    0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L,
    0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL,
    0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL,
    0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
    0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL,
    0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L,
    0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L,
    0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
    0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,
    0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L,
    0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L,
    0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
    0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L,
    0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L,
    0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L,
    0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
    0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L,
    0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL,
    0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL,
    0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,
    0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,
    0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL,
    0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL,
    0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
    0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL,
    0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L,
    0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,
    0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
    0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL,
    0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L,
    0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L,
    0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
    0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,
    0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L,
    0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L,
    0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
    0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L,
    0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L,
    0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,
    0x2d02ef8dL
};

/*
 * U-Boot CRC32 计算函数
 * (与 U-Boot 源码 common/crc32.c 中的 crc32_no_comp 行为一致)
 */
uint32_t calculate_crc32(uint32_t crc_in, const void *buf, size_t len)
{
    const unsigned char *p = (const unsigned char *)buf;
    uint32_t crc = crc_in ^ 0xffffffffL;
    while (len--) {
        crc = crc32_table[(crc ^ *p++) & 0xff] ^ (crc >> 8);
    }
    return crc ^ 0xffffffffL;
}


/* --- 3. 环境变量配置 (V-Final 方案) --- */
/* (必须与 U-Boot menuconfig 和 Flash Map 严格匹配) */

/* 共享环境 (app_env) 分区 (mtd2) */
#define ENV_OFFSET_A     0x120000  /* 扇区 A (U-Boot 的 CONFIG_ENV_OFFSET) */
#define ENV_OFFSET_B     0x130000  /* 扇区 B (U-Boot 的 CONFIG_ENV_OFFSET_REDUND) */
#define ENV_SECT_SIZE    0x10000   /* 64KB (U-Boot 的 CONFIG_ENV_SIZE 和 SECT_SIZE) */

/* U-Boot 环境变量头部 (5 字节) */
typedef struct {
    uint32_t crc;   /* 4字节 CRC32 (数据的校验和) */
    uint8_t  flags; /* 1字节 标志位 (1 = active, 0 = obsolete) */
    char     data[ENV_SECT_SIZE - sizeof(uint32_t) - sizeof(uint8_t)]; /* 剩余的数据 */
} env_sector_t;

/*
 * 【修正】: 移除静态全局指针, 修复编译器错误。
 * 我们只保留静态缓冲区。
 */

/* 整个扇区(64KB)的内存缓冲区 */
static char env_buffer[ENV_SECT_SIZE];

/* * 内存中最新的 env_data 是否有效的标志
 * 0 = 未初始化, 1 = 已加载
 */
static int env_is_loaded = 0; 
/* 内存中最新环境的标志位 (来自 FLASH) */
static uint8_t env_active_flag = 0; 

/* 内部辅助函数 */
static STATUS app_fw_validate_env(env_sector_t *env_sect);
static STATUS app_fw_write_env(uint8_t new_flag);


/*
 * app_fw_find_env()
 * 功能:
 * 1. 读取 mtd2 的两个冗余扇区 (A 和 B)。
 * 2. 比较它们的 'flags' (标志位) 和 CRC。
 * 3. 找到最新的、有效的扇区。
 * 4. 将其内容加载到内存中的 'env_buffer'。
 * 5. 设置 'env_is_loaded = 1'。
 */
STATUS app_fw_find_env(void)
{
    /* 【修正】: 指针现在是局部变量 */
    env_sector_t *env_a = (env_sector_t *)env_buffer;
    env_sector_t *env_b = NULL; /* 我们需要第二个缓冲区来比较 */
    
    char env_buffer_b[ENV_SECT_SIZE]; /* 临时的第二个缓冲区 */
    env_b = (env_sector_t *)env_buffer_b;

    STATUS status_a = ERROR;
    STATUS status_b = ERROR;
    uint8_t flag_a = 0;
    uint8_t flag_b = 0;
    
    env_is_loaded = 0; /* 重置状态 */

    /* 1. 读取扇区 A (0x120000) */
    if (flash_data_read(ENV_OFFSET_A, env_a, ENV_SECT_SIZE) != OK) {
        LOG_INFO("vx_env_lib: MTD 读取 0x%x 失败\n", ENV_OFFSET_A,0,0,0,0,0);
        return ERROR;
    }
    
    /* 2. 读取扇区 B (0x130000) */
    if (flash_data_read(ENV_OFFSET_B, env_b, ENV_SECT_SIZE) != OK) {
        LOG_INFO("vx_env_lib: MTD 读取 0x%x 失败\n", ENV_OFFSET_B,0,0,0,0,0);
        return ERROR;
    }

    /* 3. 校验扇区 A */
    if (app_fw_validate_env(env_a) == OK) {
        status_a = OK;
        flag_a = env_a->flags;
    }

    /* 4. 校验扇区 B */
    if (app_fw_validate_env(env_b) == OK) {
        status_b = OK;
        flag_b = env_b->flags;
    }

    /* 5. 比较标志位 (flags), 决定哪个是"活动"的 */
    if (status_a == OK && status_b == OK) {
        /* A 和 B 都有效, 比较 flags */
        if (flag_a > flag_b) {
            env_active_flag = flag_a;
            env_is_loaded = 1;
            /* env_a 已在 env_buffer 中, 无需操作 */
            return OK;
        } else {
            env_active_flag = flag_b;
            env_is_loaded = 1;
            /* B 是最新的, 把它复制到主 env_buffer */
            memcpy(env_buffer, env_buffer_b, ENV_SECT_SIZE);
            return OK;
        }
    } 
    else if (status_a == OK) {
        /* 只有 A 有效 */
        env_active_flag = flag_a;
        env_is_loaded = 1;
        /* env_a 已在 env_buffer 中 */
        return OK;
    }
    else if (status_b == OK) {
        /* 只有 B 有效 */
        env_active_flag = flag_b;
        env_is_loaded = 1;
        /* B 是最新的, 把它复制到主 env_buffer */
        memcpy(env_buffer, env_buffer_b, ENV_SECT_SIZE);
        return OK;
    }
    else {
        /* 两个扇区都已损坏或为空 */
        LOG_INFO("vx_env_lib: 警告: 两个环境扇区均无效或为空。\n", 0,0,0,0,0,0);
        LOG_INFO("vx_env_lib: 将使用空白环境。\n", 0,0,0,0,0,0);
        
        /* 创建一个空白环境 */
        memset(env_buffer, 0, ENV_SECT_SIZE);
        /* 【修正】: 获取局部指针 */
        env_sector_t *env_hdr = (env_sector_t *)env_buffer;
        char *env_dat = (char *)env_hdr->data;
        
        env_hdr->flags = 1; /* 第一个标志位 */
        env_dat[0] = '\0';  /* 空数据区 */
        env_dat[1] = '\0';  /* 确保双 null 结尾 */
        
        env_active_flag = 1;
        env_is_loaded = 1;
        
        /* 我们不需要在这里计算CRC, 因为 setenv/save 会做 */
        return OK;
    }
}

/*
 * app_fw_validate_env(env_sect)
 * 内部函数: 检查内存中的扇区 CRC 是否正确
 */
static STATUS app_fw_validate_env(env_sector_t *env_sect)
{
    uint32_t crc_calc;
    
    /* 计算数据区的 CRC */
    crc_calc = calculate_crc32(0, env_sect->data, (ENV_SECT_SIZE - 5));
    
    if (crc_calc == env_sect->crc) {
        return OK; /* 校验通过 */
    }
    
    return ERROR; /* 校验失败 */
}


/*
 * app_fw_setenv(name, value)
 * 功能:
 * 1. 在内存 (env_buffer) 中修改、添加或删除一个变量。
 * 2. 【重要】: 此函数不写入 FLASH。
 */
STATUS app_fw_setenv(const char *name, const char *value)
{
    char *in_ptr, *out_ptr;
    char *old_env_data;
    int name_len, value_len;
    int found = 0;
    
    /* 【修正】: 获取局部指针 */
    env_sector_t *env_hdr = (env_sector_t *)env_buffer;
    char *env_dat = (char *)env_hdr->data;

    /* 1. 确保环境已加载到内存 */
    if (!env_is_loaded) {
        if (app_fw_find_env() != OK) {
            LOG_INFO("vx_env_lib: setenv 失败, 无法加载环境。\n", 0,0,0,0,0,0);
            return ERROR;
        }
    }

    /* 2. 分配一个临时缓冲区来构建新的环境 */
    old_env_data = (char *)malloc(ENV_SECT_SIZE - 5);
    if (old_env_data == NULL) {
        LOG_INFO("vx_env_lib: setenv 失败, malloc 失败。\n", 0,0,0,0,0,0);
        return ERROR;
    }
    
    /* 复制当前 env_data 到临时区 */
    memcpy(old_env_data, env_dat, (ENV_SECT_SIZE - 5));

    /* 3. 准备遍历 (in_ptr) 和写入 (out_ptr) */
    in_ptr = old_env_data;
    out_ptr = env_dat; /* 直接写回主缓冲区 */
    name_len = strlen(name);
    
    /* 4. 遍历旧环境 (in_ptr), 构建新环境 (out_ptr) */
    while (*in_ptr != '\0') {
        char *entry = in_ptr;
        int entry_len = strlen(entry);

        /* 检查这个条目是否是我们正在寻找的? */
        if (strncmp(entry, name, name_len) == 0 && entry[entry_len] == '=') {
            /* 找到了! (例如 name == "ver_select") */
            found = 1;
            
            /* 如果 value 不为 NULL, 我们替换它 */
            if (value != NULL && *value != '\0') {
                value_len = strlen(value);
                /* 检查空间是否足够 */
                if ((out_ptr - env_dat) + name_len + 1 + value_len + 2 > (ENV_SECT_SIZE - 5)) {
                    LOG_INFO("vx_env_lib: setenv 失败, 环境变量空间不足!\n", 0,0,0,0,0,0);
                    free(old_env_data);
                    return ERROR;
                }
                /* 写入 "name=value\0" */
                memcpy(out_ptr, name, name_len);
                out_ptr[name_len] = '=';
                memcpy(out_ptr + name_len + 1, value, value_len);
                out_ptr += (name_len + 1 + value_len + 1);
            }
            /* 如果 value 是 NULL, 我们就"删除"它 (即, 什么都不复制) */
            
        } else {
            /* 这不是我们要找的变量, 原样复制 */
            /* 检查空间 */
            if ((out_ptr - env_dat) + entry_len + 2 > (ENV_SECT_SIZE - 5)) {
                LOG_INFO("vx_env_lib: setenv 失败, 环境变量空间不足 (复制时)!\n", 0,0,0,0,0,0);
                free(old_env_data);
                return ERROR;
            }
            /* 复制 "name=value\0" */
            memcpy(out_ptr, entry, entry_len + 1);
            out_ptr += (entry_len + 1);
        }
        
        /* 跳到下一个条目 */
        in_ptr += (entry_len + 1);
    }
    
    /* 5. 如果这是一个新变量 (没找到) 并且 value 不是 NULL */
    if (!found && value != NULL && *value != '\0') {
        value_len = strlen(value);
        /* 检查空间 */
        if ((out_ptr - env_dat) + name_len + 1 + value_len + 2 > (ENV_SECT_SIZE - 5)) {
            LOG_INFO("vx_env_lib: setenv 失败, 环境变量空间不足 (添加时)!\n", 0,0,0,0,0,0);
            free(old_env_data);
            return ERROR;
        }
        /* 写入 "name=value\0" */
        memcpy(out_ptr, name, name_len);
        out_ptr[name_len] = '=';
        memcpy(out_ptr + name_len + 1, value, value_len);
        out_ptr += (name_len + 1 + value_len + 1);
    }

    /* 6. 添加最终的双 null 结尾 */
    *out_ptr = '\0';
    
    /* 7. 释放临时缓冲区 */
    free(old_env_data);
    
    /* * 此时, env_buffer (env_dat) 已被修改。
     * 但 FLASH 尚未被写入。
     * CRC 和 Flag 也是旧的。
     * app_fw_save() 必须被调用来提交更改。
     */
    return OK;
}


/*
 * app_fw_save()
 * 功能:
 * 1. 找到非活动扇区。
 * 2. 重新计算内存中 env_buffer 的 CRC。
 * 3. 递增 flag。
 * 4. 将包含新 CRC 和新 flag 的 env_buffer 写入非活动扇区。
 */
STATUS app_fw_save(void)
{
    uint8_t new_flag;
    
    if (!env_is_loaded) {
        LOG_INFO("vx_env_lib: save 失败, 环境未加载。\n", 0,0,0,0,0,0);
        return ERROR;
    }

    /* * U-Boot 的标志位是一个循环计数器 (1, 2, 3, ... 255, 1, 2...)
     * 它通过递增来使新扇区变为"活动"。
     */
    if (env_active_flag == 0xFF) {
        new_flag = 1;
    } else {
        new_flag = env_active_flag + 1;
    }
    
    /* 提交写入 */
    if (app_fw_write_env(new_flag) != OK) {
        LOG_INFO("vx_env_lib: save 失败, 写入 FLASH 失败。\n", 0,0,0,0,0,0);
        return ERROR;
    }
    
    /* 更新内存中的活动标志 */
    env_active_flag = new_flag;
    
    return OK;
}


/*
 * app_fw_write_env(new_flag)
 * 内部函数: 实际执行 FLASH 擦写操作
 */
static STATUS app_fw_write_env(uint8_t new_flag)
{
    uint32_t write_offset;
    
    /* 【修正】: 获取局部指针 */
    env_sector_t *env_hdr = (env_sector_t *)env_buffer;
    char *env_dat = (char *)env_hdr->data;

    /* 1. 决定写入哪个扇区 (非活动扇区) */
    if (env_active_flag % 2 == 1) {
        /* 当前活动的是 A (0x120000, flag 1, 3, 5...), 写入 B (0x130000) */
        write_offset = ENV_OFFSET_B;
    } else {
        /* 当前活动的是 B (0x130000, flag 2, 4, 6...), 写入 A (0x120000) */
        write_offset = ENV_OFFSET_A;
    }

    /* 2. 准备新的 env_buffer (在内存中) */
    
    /* a. 更新 flag */
    env_hdr->flags = new_flag;
    
    /* b. 【关键】重新计算 CRC! */
    /* (大小是整个数据区, 减去头部) */
    env_hdr->crc = calculate_crc32(0, env_dat, (ENV_SECT_SIZE - 5));

    /* 3. 【关键】擦除非活动扇区 */
    if (flash_data_erase(write_offset, ENV_SECT_SIZE) != OK) {
        LOG_INFO("vx_env_lib: MTD 擦除 0x%x 失败!\n", write_offset,0,0,0,0,0);
        return ERROR;
    }

    /* 4. 【关键】写入包含新 CRC 和新 flag 的完整扇区 */
    if (flash_data_write(write_offset, env_buffer, ENV_SECT_SIZE) != OK) {
        LOG_INFO("vx_env_lib: MTD 写入 0x%x 失败!\n", write_offset,0,0,0,0,0);
        return ERROR;
    }

    return OK;
}

