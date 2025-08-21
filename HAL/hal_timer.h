#ifndef HAL_TIMER_H
#define HAL_TIMER_H

#include <vxWorks.h>

#ifdef __cplusplus
extern "C" {
#endif


/* 定义用户动态注册的任务函数的类型 */
typedef void (*APP_TASK_CALLBACK)(void *arg);

#ifdef __cplusplus
}
#endif

#endif /* HAL_TIMER_H */
