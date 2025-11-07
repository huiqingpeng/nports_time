#ifndef FIRMWARE_HEADER_H
#define FIRMWARE_HEADER_H

#include <stdint.h> // 使用标准整数类型

// (点 1) Magic Number
// 使用 'UPDT' 对应的 ASCII 码 (0x55 0x50 0x44 0x54) 作为魔术字。
#define FW_PACKAGE_MAGIC 0x55504454 

// Header 总大小
#define FW_PACKAGE_HEADER_SIZE 128

// 版本字符串固定长度
#define FW_VERSION_STRING_LEN 32

/**
 * @brief 固件包文件头结构体 (128 字节)
 * * @note 这个结构体被设计为在 x86/ARM (小端序) 平台上直接从文件映射。
 * 使用 __attribute__((packed)) 确保没有编译器填充。
 */
typedef struct __attribute__((packed)) {
    
    // ---------------------------------
    // 偏移量 0: Magic 和 Header CRC
    // ---------------------------------
    uint32_t magic_number;  // 必须等于 FW_PACKAGE_MAGIC
    uint32_t header_crc32;  // 偏移量 8 到 127 的 CRC32

    // ---------------------------------
    // 偏移量 8: 版本信息 (点 0)
    // ---------------------------------
    char pkg_version[FW_VERSION_STRING_LEN];
    char bit_version[FW_VERSION_STRING_LEN];
    char app_version[FW_VERSION_STRING_LEN];

    // ---------------------------------
    // 偏移量 104: 时间戳 (点 0)
    // ---------------------------------
    uint32_t timestamp;     // Unix 时间戳

    // ---------------------------------
    // 偏移量 108: Bitstream 描述 (点 2, 3)
    // ---------------------------------
    uint32_t bit_length;    // Bitstream 字节长度
    uint32_t bit_crc32;     // Bitstream CRC32

    // ---------------------------------
    // 偏移量 116: Application 描述 (点 2, 3)
    // ---------------------------------
    uint32_t app_length;    // Application 字节长度
    uint32_t app_crc32;     // Application CRC32

    // ---------------------------------
    // 偏移量 124: 保留
    // ---------------------------------
    char reserved[4];

} fw_package_header_t;

/**
 * @brief 检查 Header 结构体大小是否正确
 *
 * (这是一个编译时断言，如果大小不匹配，编译会失败)
 */
typedef int static_assert_header_size_check[
    (sizeof(fw_package_header_t) == FW_PACKAGE_HEADER_SIZE) ? 1 : -1
];


#endif // FIRMWARE_HEADER_H

