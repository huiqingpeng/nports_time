/*
 * =====================================================================================
 *
 * Filename:  app_init.c
 *
 * Description:  应用程序的主入口和初始化函数。
 * 负责初始化全局资源（消息队列、互斥锁、状态变量），
 * 并创建所有应用程序任务。
 *
 * =====================================================================================
 */

#include "./inc/app_com.h"
#include "./inc/app_udp_search.h"
#include "./inc/app_net_cfg.h"
#include "./inc/app_net_scheduler.h"

/* ------------------ Task Configuration Constants ------------------ */
// 任务优先级 (数字越小，优先级越高)
#define REALTIME_SCHEDULER_PRIORITY   55
#define CONFIG_TASK_MANAGER_PRIORITY  60
#define CONN_MANAGER_PRIORITY         70
#define UDP_SEARCH_PRIORITY           75


// 任务栈大小
#define DEFAULT_STACK_SIZE            (32 * 1024) // 16KB

// 计算数据队列的最大容量
#define DATA_QUEUE_CAPACITY (NUM_PORTS * MAX_CLIENTS_PER_CHANNEL + 10) // 16 * 4 + 10 = 74
// 计算配置队列的最大容量
#define CONFIG_QUEUE_CAPACITY (DATA_QUEUE_CAPACITY)

#define MAX_MSG_IN_Q 24

MSG_Q_ID g_config_conn_q;
MSG_Q_ID g_net_conn_q[NUM_PORTS];
MSG_Q_ID g_serial_port_ctrl_q[NUM_PORTS];
/* ------------------ Global Variable Definitions ------------------ */
SEM_ID g_config_mutex;
TASK_ID g_conn_manager_tid;
TASK_ID g_realtime_scheduler_tid;
TASK_ID g_config_task_manager_tid;
TASK_ID g_udp_search_tid;
/**
 * @brief 应用程序的主入口函数
 * @details 在VxWorks启动脚本中，通常会调用这个函数来启动整个应用。
 */
void app_start(void) {
	int i,j;
	log_init(LOG_LEVEL_DEBUG);

	FPGA_Info_Read();
	LOG_ERROR("\n\n--- UART FIFO : %d ---\n", UART_HW_FIFO_SIZE/2);
	LOG_INFO("\n\n--- Application Starting ---\n");

	/* ------------------ 1. 初始化全局资源 ------------------ */
	LOG_INFO("Initializing global resources...\n");

	// 创建消息队列
	// 参数: maxMsgs, maxMsgLength, options
    for (i = 0; i < NUM_PORTS; i++) {
        g_net_conn_q[i] = msgQCreate(MAX_MSG_IN_Q, sizeof(NewConnectionMsg), MSG_Q_FIFO);
        if (g_net_conn_q[i] == NULL) {
            // 错误处理: 记录日志或停止系统
            LOG_ERROR("Failed to create message queue for channel %d\n", i);
        }
    }
	g_config_conn_q = msgQCreate(DATA_QUEUE_CAPACITY,sizeof(NewConnectionMsg), MSG_Q_FIFO);

	if (g_config_conn_q == NULL) {
		LOG_ERROR("FATAL: Failed to create message queues.\n");
		return;
	}
	LOG_INFO("Message queues created.\n");

	// 创建互斥锁
	// 使用 SEM_INVERSION_SAFE 防止优先级反转
	g_config_mutex = semMCreate(SEM_Q_PRIORITY | SEM_INVERSION_SAFE);
	if (g_config_mutex == NULL) {
		LOG_ERROR("FATAL: Failed to create config mutex.\n");
		return;
	}
	LOG_INFO("Configuration mutex created.\n");
	dev_config_init();

	dev_network_settings_apply("192.168.8.220", "255.255.255.0", "192.168.8.1",0);

	/* ------------------ 2. 初始化通道状态 ------------------ */
	LOG_INFO("Initializing channel states...\n");
	for (i = 0; i < NUM_PORTS; i++) {
		// *** 状态维护：明确设置所有通道的初始物理状态为关闭 ***
        g_system_config.channels[i].uart_state = UART_STATE_CLOSED;

		for(j=0;j<MAX_CLIENTS_PER_CHANNEL;j++)
		{
			g_system_config.channels[i].data_net_info.client_fds[j] = -1;	
		}
		// 初始化环形缓冲区
		ring_buffer_init(&g_system_config.channels[i].buffer_net,  g_system_config.channels[i].net_buffer_mem,  RING_BUFFER_SIZE);
		ring_buffer_init(&g_system_config.channels[i].buffer_uart, g_system_config.channels[i].uart_buffer_mem, RING_BUFFER_SIZE);
	}
	LOG_INFO("All %d channel states initialized.\n", NUM_PORTS);

	/* ------------------ 3. 创建应用程序任务 ------------------ */
	LOG_INFO("Spawning application tasks...\n");

	ConnectionManager_TaskStart();

	// 创建 ConfigTaskManager
	g_config_task_manager_tid = taskSpawn("tConfigManager",
	CONFIG_TASK_MANAGER_PRIORITY, 0, DEFAULT_STACK_SIZE,
			(FUNCPTR) ConfigTaskManager, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	// 创建 RealTimeSchedulerTask
    g_realtime_scheduler_tid = taskSpawn("tRealTimeScheduler",
                                         REALTIME_SCHEDULER_PRIORITY,
                                         0, DEFAULT_STACK_SIZE,
                                         (FUNCPTR)RealTimeSchedulerTask,
                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
   g_udp_search_tid = taskSpawn("tUdpSearch",
                                UDP_SEARCH_PRIORITY,
                                0, DEFAULT_STACK_SIZE,
                                (FUNCPTR)UdpSearchTask,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	if (g_conn_manager_tid == ERROR || g_config_task_manager_tid == ERROR
			|| g_realtime_scheduler_tid == ERROR || g_udp_search_tid == ERROR) {
		LOG_ERROR("FATAL: Failed to spawn one or more tasks.\n");
		// 此处可能需要清理已创建的资源
		return;
	}
	start_update_server();

	LOG_INFO("All tasks spawned successfully.\n");
	LOG_INFO("--- Application Initialization Complete ---\n\n");
}
