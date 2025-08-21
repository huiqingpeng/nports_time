#include <vxWorks.h>
#include <stdio.h>
#include <intLib.h> /* 用于 intLock() 和 intUnlock() */
#include "hal_timer.h"

/* ---------------- API 从驱动导入 (不变) ---------------- */
/* 定义回调函数类型 */
typedef void (*TTC_CALLBACK)(void *arg);

/* 从定时器驱动中“导入”我们创建的API函数 */
extern STATUS ttc_init_timer(int unit, UINT32 hz, TTC_CALLBACK func, void *arg);
extern STATUS ttc_stop_timer(int unit);

/* ---------------- 新增：动态任务注册框架 ---------------- */

/* 全局变量，用于保存用户动态注册的任务函数及其参数 */
/* volatile 关键字确保编译器每次都从内存中读取，防止优化问题 */
static volatile APP_TASK_CALLBACK g_registered_func = NULL;
static volatile void * g_registered_arg = NULL;

/*
 * [核心] 中断分发器 (ISR Dispatcher)
 * 这个函数被注册给硬件定时器驱动，它在每次中断时被调用。
 * 它的工作就是去调用用户当前注册的动态任务。
 */
void isr_dispatcher(void *arg) {
	/* * 为了绝对安全，先将全局指针读到局部变量中。
	 * 这可以防止在 if 判断之后、函数调用之前，指针被其他任务修改为 NULL。
	 */
	APP_TASK_CALLBACK func_to_call = g_registered_func;

	if (func_to_call != NULL) {
		/* 执行用户注册的动态任务 */
		func_to_call((void *) g_registered_arg);
	}
}

/*
 * [API] 动态注册一个任务函数
 * func: 您希望在中断中执行的函数
 * arg:  传递给该函数的参数
 */
STATUS app_register_task(APP_TASK_CALLBACK func, void *arg) {
	int lock_key;

	if (func == NULL) {
		printf("ERROR: Task function to register cannot be NULL.\n");
		return ERROR;
	}

	/* * 关键安全点：关闭中断，以防止在修改指针时被ISR抢占 
	 * 这是一个原子操作块的开始
	 */
	lock_key = intLock();

	g_registered_arg = arg;
	g_registered_func = func; /* 最后设置函数指针，确保参数已准备好 */

	/* 恢复之前的中断状态 */
	intUnlock(lock_key);

	printf("OK: Application task has been registered.\n");
	return OK;
}

/*
 * [API] 注销当前注册的任务函数
 */
STATUS app_unregister_task(void) {
	int lock_key;

	lock_key = intLock();
	g_registered_func = NULL;
	g_registered_arg = NULL;
	intUnlock(lock_key);

	printf("OK: Application task has been unregistered.\n");
	return OK;
}

/* ---------------- 应用程序逻辑和示例 ---------------- */

/* 示例任务1：累加一个计数器 */
volatile int g_counter1 = 0;
void user_task_increment_counter(void *arg) {
	/* arg 就是传递进来的全局计数器的地址 */
	volatile int *counter_ptr = (volatile int *) arg;
	(*counter_ptr)++;
}

/* 示例任务2：简单打印 (仅用于低频调试！) */
void user_task_print_message(void *arg) {
	/* 警告：printf非常慢，只能在极低频率(如1Hz)的中断中使用！ */
	printf("Timer tick! Arg: %s\n", (char *) arg);
}

/* ---------------- 启动/停止/监视 函数 ---------------- */

/*
 * 启动函数
 * 它只负责启动底层的定时器，并设置好中断分发器。
 */
void app_start_hz(int unit, int hz) {
	printf("Attempting to start dispatcher on timer unit %d at %d Hz.\n", unit,
			hz);

	/* 注意：这里注册的是固定的 isr_dispatcher，而不是用户的具体任务 */
	ttc_init_timer(unit, hz, isr_dispatcher, NULL);
}

/*
 * 停止函数
 * 它会先注销动态任务，然后停止底层定时器。
 */
void app_stop(int unit) {
	app_unregister_task();
	ttc_stop_timer(unit);
}

/*
 * 辅助函数，用于查看计数器的值
 */
void app_show_count(void) {
	printf("Current counter1 value: %d\n", g_counter1);
}
