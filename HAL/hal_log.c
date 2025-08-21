/*
 * =====================================================================================
 *
 * Filename:  hal_log.c
 *
 * Description:  实现一个异步、带缓冲、分级别的日志系统。
 *
 * =====================================================================================
 */

#include "hal_log.h"
#include <taskLib.h>
#include <msgQLib.h>
#include <sysLib.h>
#include <string.h>
#include <time.h>

/* ------------------ Internal Constants ------------------ */
#define LOG_TASK_PRIORITY   250  // 日志任务使用非常低的优先级
#define LOG_TASK_STACK_SIZE 8192 // 8KB 栈大小
#define LOG_QUEUE_MAX_MSGS  100  // 日志消息队列容量
#define MAX_LOG_MSG_LEN     512  // 每条日志消息的最大长度

/* ------------------ Internal Data Structures ------------------ */
typedef struct {
    char msg_body[MAX_LOG_MSG_LEN];
} LogMessage;

/* ------------------ Module-level static variables ------------------ */
static TASK_ID  s_log_task_tid;
static MSG_Q_ID s_log_msg_q;
static LogLevel s_current_log_level = LOG_LEVEL_INFO; // 默认级别

/* ------------------ Private Function Prototypes ------------------ */
static void LogTask(void);

/* ------------------ Public API Implementations ------------------ */

int log_init(LogLevel initial_level)
{
    s_current_log_level = initial_level;

    // 1. 创建日志消息队列
    s_log_msg_q = msgQCreate(LOG_QUEUE_MAX_MSGS, sizeof(LogMessage), MSG_Q_FIFO);
    if (s_log_msg_q == NULL) {
        printf("FATAL: Failed to create log message queue.\n");
        return ERROR;
    }

    // 2. 创建日志任务
    s_log_task_tid = taskSpawn("tLogTask",
                               LOG_TASK_PRIORITY,
                               0, LOG_TASK_STACK_SIZE,
                               (FUNCPTR)LogTask,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
    if (s_log_task_tid == ERROR) {
        printf("FATAL: Failed to spawn log task.\n");
        msgQDelete(s_log_msg_q);
        return ERROR;
    }

    printf("Logging system initialized. Level: %d\n", s_current_log_level);
    return OK;
}

void log_set_level(LogLevel level)
{
    s_current_log_level = level;
}

LogLevel log_get_level(void)
{
    return s_current_log_level;
}

void log_printf(LogLevel level, const char* file, int line, const char* format, ...)
{
    // 如果消息级别低于当前系统设置的级别，则直接忽略，提高性能
    if (level < s_current_log_level) {
        return;
    }

    // 如果消息队列未初始化，则直接打印到控制台（用于早期调试）
    if (s_log_msg_q == NULL) {
        printf("LOG_Q_NULL: ");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\n");
        return;
    }

    LogMessage log_msg;
    char temp_buf[MAX_LOG_MSG_LEN];
    va_list args;
    
    // 格式化消息内容
    va_start(args, format);
    vsnprintf(temp_buf, sizeof(temp_buf), format, args);
    va_end(args);

    // 准备完整的日志消息（包含时间戳、级别、文件名和行号）
    // TODO: 获取更精确的时间戳
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    snprintf(log_msg.msg_body, MAX_LOG_MSG_LEN,
             "[%02d:%02d:%02d] [%s] [%s:%d] %s",
             t->tm_hour, t->tm_min, t->tm_sec,
             (level == LOG_LEVEL_DEBUG) ? "DBG" :
             (level == LOG_LEVEL_INFO)  ? "INF" :
             (level == LOG_LEVEL_WARN)  ? "WRN" :
             (level == LOG_LEVEL_ERROR) ? "ERR" : "FTL",
             file, line, temp_buf);

    // 以非阻塞方式发送到消息队列，如果队列满了，则丢弃日志（确保不阻塞调用者）
    msgQSend(s_log_msg_q, (char*)&log_msg, sizeof(log_msg), NO_WAIT, MSG_PRI_NORMAL);
}


/* ------------------ Private Task Implementation ------------------ */

/**
 * @brief 日志后台任务
 * @details 这是一个低优先级的任务，它的唯一工作就是从消息队列中
 * 取出格式化好的日志消息，并将其打印到控制台。
 */
static void LogTask(void)
{
    LogMessage received_msg;

    printf("LogTask: Starting...\n");

    while (1)
    {
        // 阻塞式地等待新的日志消息
        if (msgQReceive(s_log_msg_q, (char*)&received_msg, sizeof(received_msg), WAIT_FOREVER) != ERROR)
        {
            // TODO: 这里是实际的日志输出点。
            // 目前是打印到标准输出，未来可以修改为写入文件、发送到网络等。
            printf("%s\n", received_msg.msg_body);
        }
    }
}
