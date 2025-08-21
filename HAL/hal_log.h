#ifndef HAL_LOG_H
#define HAL_LOG_H

#include <vxWorks.h>
#include <stdio.h>
#include <stdarg.h> // For va_list, va_start, va_end

/* ------------------ Log Level Definition ------------------ */
typedef enum {
    LOG_LEVEL_DEBUG,    // 调试信息
    LOG_LEVEL_INFO,     // 普通信息
    LOG_LEVEL_WARN,     // 警告信息
    LOG_LEVEL_ERROR,    // 错误信息
    LOG_LEVEL_FATAL     // 致命错误信息
} LogLevel;

/* ------------------ Public API Functions ------------------ */

/**
 * @brief 初始化日志系统
 * @details 创建日志任务和消息队列，应在系统启动早期调用。
 *
 * @param initial_level 初始的日志记录级别。低于此级别的日志将被忽略。
 * @return int OK on success, ERROR on failure.
 */
int log_init(LogLevel initial_level);

/**
 * @brief 设置日志系统的记录级别
 * @details 可以在运行时动态调整，以控制日志的详细程度。
 *
 * @param level 新的日志记录级别。
 */
void log_set_level(LogLevel level);

/**
 * @brief 获取当前日志系统的记录级别
 *
 * @return LogLevel 当前的日志级别。
 */
LogLevel log_get_level(void);

/**
 * @brief 核心日志记录函数 (不建议直接调用，请使用下面的宏)
 *
 * @param level 日志级别
 * @param file 源代码文件名 (__FILE__)
 * @param line 源代码行号 (__LINE__)
 * @param format 格式化字符串 (printf-style)
 * @param ... 可变参数
 */
void log_printf(LogLevel level, const char* file, int line, const char* format, ...);


/* ------------------ Public API Macros (推荐使用) ------------------ */
// 使用宏可以自动填充文件名和行号，并能在编译时移除低级别的日志调用以优化性能。

#define LOG_DEBUG(...)    log_printf(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_INFO(...)     log_printf(LOG_LEVEL_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define LOG_WARN(...)     log_printf(LOG_LEVEL_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define LOG_ERROR(...)    log_printf(LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_FATAL(...)    log_printf(LOG_LEVEL_FATAL, __FILE__, __LINE__, __VA_ARGS__)


#endif /* HAL_LOG_H */
