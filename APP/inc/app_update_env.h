#ifndef __APP_UPDATE_ENV_H__
#define __APP_UPDATE_ENV_H__

/* VxWorks 环境变量读写库头文件 */
/* 兼容 V-Final 方案 - 共享环境 @ mtd2 */

#include <vxWorks.h>
#include <stdint.h>

/* --- MTD 驱动函数声明 (需要实现) --- */

/**
 * @brief 从 Flash 读取数据
 * @param offset 偏移地址
 * @param data 数据缓冲区
 * @param len 数据长度
 * @return STATUS OK/ERROR
 */
STATUS flash_data_read(uint32_t offset, void* data, uint32_t len);

/**
 * @brief 向 Flash 写入数据
 * @param offset 偏移地址
 * @param data 数据缓冲区
 * @param len 数据长度
 * @return STATUS OK/ERROR
 */
STATUS flash_data_write(uint32_t offset, const void* data, uint32_t len);

/**
 * @brief 擦除 Flash 区域
 * @param offset 偏移地址
 * @param len 擦除长度
 * @return STATUS OK/ERROR
 */
STATUS flash_data_erase(uint32_t offset, uint32_t len);

/* --- CRC32 计算函数 --- */

/**
 * @brief 计算 U-Boot 兼容的 CRC32 校验和
 * @param crc_in 初始 CRC 值 (通常为0)
 * @param buf 数据缓冲区
 * @param len 数据长度
 * @return uint32_t CRC32 校验和
 */
uint32_t calculate_crc32(uint32_t crc_in, const void *buf, size_t len);

/* --- 环境变量操作接口 --- */

/**
 * @brief 查找并加载有效的环境变量扇区
 * @return STATUS OK/ERROR
 * @note 自动选择两个冗余扇区中较新的有效扇区
 */
STATUS app_fw_find_env(void);

/**
 * @brief 设置环境变量 (内存中修改)
 * @param name 变量名
 * @param value 变量值 (NULL 表示删除该变量)
 * @return STATUS OK/ERROR
 * @note 此函数只修改内存中的环境变量，需要调用 app_fw_save() 保存到 Flash
 */
STATUS app_fw_setenv(const char *name, const char *value);

/**
 * @brief 保存环境变量到 Flash
 * @return STATUS OK/ERROR
 * @note 使用冗余写入策略，递增标志位并写入非活动扇区
 */
STATUS app_fw_save(void);

/* --- 环境变量配置常量 --- */

#define ENV_OFFSET_A     0x120000  /* 扇区 A (CONFIG_ENV_OFFSET) */
#define ENV_OFFSET_B     0x130000  /* 扇区 B (CONFIG_ENV_OFFSET_REDUND) */
#define ENV_SECT_SIZE    0x10000   /* 64KB 扇区大小 (CONFIG_ENV_SIZE) */

#endif /* __APP_UPDATE_ENV_H__ */