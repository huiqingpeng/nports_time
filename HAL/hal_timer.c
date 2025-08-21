#include <vxWorks.h>
#include <stdio.h>
#include <intLib.h> /* ���� intLock() �� intUnlock() */
#include "hal_timer.h"

/* ---------------- API ���������� (����) ---------------- */
/* ����ص��������� */
typedef void (*TTC_CALLBACK)(void *arg);

/* �Ӷ�ʱ�������С����롱���Ǵ�����API���� */
extern STATUS ttc_init_timer(int unit, UINT32 hz, TTC_CALLBACK func, void *arg);
extern STATUS ttc_stop_timer(int unit);

/* ---------------- ��������̬����ע���� ---------------- */

/* ȫ�ֱ��������ڱ����û���̬ע���������������� */
/* volatile �ؼ���ȷ��������ÿ�ζ����ڴ��ж�ȡ����ֹ�Ż����� */
static volatile APP_TASK_CALLBACK g_registered_func = NULL;
static volatile void * g_registered_arg = NULL;

/*
 * [����] �жϷַ��� (ISR Dispatcher)
 * ���������ע���Ӳ����ʱ������������ÿ���ж�ʱ�����á�
 * ���Ĺ�������ȥ�����û���ǰע��Ķ�̬����
 */
void isr_dispatcher(void *arg) {
	/* * Ϊ�˾��԰�ȫ���Ƚ�ȫ��ָ������ֲ������С�
	 * ����Է�ֹ�� if �ж�֮�󡢺�������֮ǰ��ָ�뱻���������޸�Ϊ NULL��
	 */
	APP_TASK_CALLBACK func_to_call = g_registered_func;

	if (func_to_call != NULL) {
		/* ִ���û�ע��Ķ�̬���� */
		func_to_call((void *) g_registered_arg);
	}
}

/*
 * [API] ��̬ע��һ��������
 * func: ��ϣ�����ж���ִ�еĺ���
 * arg:  ���ݸ��ú����Ĳ���
 */
STATUS app_register_task(APP_TASK_CALLBACK func, void *arg) {
	int lock_key;

	if (func == NULL) {
		printf("ERROR: Task function to register cannot be NULL.\n");
		return ERROR;
	}

	/* * �ؼ���ȫ�㣺�ر��жϣ��Է�ֹ���޸�ָ��ʱ��ISR��ռ 
	 * ����һ��ԭ�Ӳ�����Ŀ�ʼ
	 */
	lock_key = intLock();

	g_registered_arg = arg;
	g_registered_func = func; /* ������ú���ָ�룬ȷ��������׼���� */

	/* �ָ�֮ǰ���ж�״̬ */
	intUnlock(lock_key);

	printf("OK: Application task has been registered.\n");
	return OK;
}

/*
 * [API] ע����ǰע���������
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

/* ---------------- Ӧ�ó����߼���ʾ�� ---------------- */

/* ʾ������1���ۼ�һ�������� */
volatile int g_counter1 = 0;
void user_task_increment_counter(void *arg) {
	/* arg ���Ǵ��ݽ�����ȫ�ּ������ĵ�ַ */
	volatile int *counter_ptr = (volatile int *) arg;
	(*counter_ptr)++;
}

/* ʾ������2���򵥴�ӡ (�����ڵ�Ƶ���ԣ�) */
void user_task_print_message(void *arg) {
	/* ���棺printf�ǳ�����ֻ���ڼ���Ƶ��(��1Hz)���ж���ʹ�ã� */
	printf("Timer tick! Arg: %s\n", (char *) arg);
}

/* ---------------- ����/ֹͣ/���� ���� ---------------- */

/*
 * ��������
 * ��ֻ���������ײ�Ķ�ʱ���������ú��жϷַ�����
 */
void app_start_hz(int unit, int hz) {
	printf("Attempting to start dispatcher on timer unit %d at %d Hz.\n", unit,
			hz);

	/* ע�⣺����ע����ǹ̶��� isr_dispatcher���������û��ľ������� */
	ttc_init_timer(unit, hz, isr_dispatcher, NULL);
}

/*
 * ֹͣ����
 * ������ע����̬����Ȼ��ֹͣ�ײ㶨ʱ����
 */
void app_stop(int unit) {
	app_unregister_task();
	ttc_stop_timer(unit);
}

/*
 * �������������ڲ鿴��������ֵ
 */
void app_show_count(void) {
	printf("Current counter1 value: %d\n", g_counter1);
}
