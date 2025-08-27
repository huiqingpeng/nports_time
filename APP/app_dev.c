/*
 * =====================================================================================
 *
 * Filename:  app_dev.c
 *
 * Description:  实现设备配置管理功能，包括加载、保存和恢复出厂设置。
 *
 * =====================================================================================
 */
#include "./inc/app_com.h" // For g_system_config definition

/* ------------------ Global Variable Definition ------------------ */

// 全局配置变量的实体定义
SystemConfiguration g_system_config;

/* ------------------ Private Function Prototypes ------------------ */
static int read_config_from_flash(SystemConfiguration* config);
static int write_config_to_flash(const SystemConfiguration* config);
static const char* uart_state_to_string(UartPhysicalState state);
static const char* net_state_to_string(NetworkChannelState state);

/* ------------------ Public API Implementations ------------------ */

/**
 * @brief 打印当前系统所有配置信息和运行时状态以供调试
 * @details 依次打印全局设备设置和每个通道的详细配置与状态。
 * 为保证打印数据的一致性，函数会获取配置互斥锁。
 */
void dev_config_print(void) 
{
	int i;
	char ip_str[INET_ADDRSTRLEN];
	char netmask_str[INET_ADDRSTRLEN];
	char gateway_str[INET_ADDRSTRLEN];

	LOG_INFO("\n");
	LOG_INFO("============================================================");
	LOG_INFO("=========  Current System Configuration & Status   =========");
	LOG_INFO("============================================================");

	// 获取互斥锁，以线程安全的方式读取全局配置
	if (semTake(g_config_mutex, WAIT_FOREVER) == OK) 
    {
		// --- 进入临界区 ---

		/* --- 打印全局设备设置 --- */
		DeviceSettings* dev = &g_system_config.device;
		LOG_INFO("[Device Settings]");
		LOG_INFO("  - Model Name: %s", dev->model_name);
		LOG_INFO("  - Server Name: %s", dev->server_name);
		LOG_INFO("  - MAC Address: %02X:%02X:%02X:%02X:%02X:%02X",
				dev->mac_address[0], dev->mac_address[1], dev->mac_address[2],
				dev->mac_address[3], dev->mac_address[4], dev->mac_address[5]);
		LOG_INFO("  - Serial No: %u", dev->serial_no);
		LOG_INFO("  - Firmware Version: %d.%d.%d", dev->firmware_version[0],
				dev->firmware_version[1], dev->firmware_version[2]);
		LOG_INFO("  - Hardware Version: %d.%d.%d", dev->hardware_version[0],
				dev->hardware_version[1], dev->hardware_version[2]);
		LOG_INFO("  - Password: %s", dev->password);

		// 转换IP地址为字符串进行打印
		inet_ntop(AF_INET, &dev->ip_address, ip_str, sizeof(ip_str));
		inet_ntop(AF_INET, &dev->netmask, netmask_str, sizeof(netmask_str));
		inet_ntop(AF_INET, &dev->gateway, gateway_str, sizeof(gateway_str));

		LOG_INFO("  - IP Config Mode: %s",
				(dev->ip_config_mode == 1) ? "DHCP" : "Static");
		LOG_INFO("  - IP Address: %s", ip_str);
		LOG_INFO("  - Netmask: %s", netmask_str);
		LOG_INFO("  - Gateway: %s", gateway_str);
		LOG_INFO(
				"------------------------------------------------------------");

		/* --- 循环打印每个通道的设置和状态 --- */
		for (i = 0; i < NUM_PORTS; i++) {
			ChannelState* ch = &g_system_config.channels[i];
			LOG_INFO("[Channel %d Settings & Status]", i + 1);

			// 打印配置参数
			LOG_INFO("  [Config]");
			LOG_INFO("    - Alias: %s", ch->alias);
			LOG_INFO(
					"    - Baudrate: %d, DataBits: %d, StopBits: %d, Parity: %d",
					ch->baudrate, ch->data_bits, ch->stop_bits, ch->parity);

			// 打印运行时状态
			LOG_INFO("  [Runtime Status]");
			LOG_INFO("    - UART Physical State: %s",
					uart_state_to_string(ch->uart_state));
			LOG_INFO("    - Data Channel: State=%s, Clients=%d/%d",
					net_state_to_string(ch->data_net_info.state),
					ch->data_net_info.num_clients, MAX_CLIENTS_PER_CHANNEL);
			LOG_INFO("    - Command Channel: State=%s, Clients=%d/%d",
					net_state_to_string(ch->cmd_net_info.state),
					ch->cmd_net_info.num_clients, MAX_CLIENTS_PER_CHANNEL);

			LOG_INFO(
					"------------------------------------------------------------");
		}

		// --- 退出临界区 ---
		semGive(g_config_mutex);
	} else {
		LOG_ERROR("FATAL: Could not take config mutex to print configuration.");
	}
	LOG_INFO("============================================================");
	LOG_INFO("\n");
}

int dev_config_init(void) {
	LOG_INFO("Initializing device configuration...\n");
	if (read_config_from_flash(&g_system_config) == OK) {
		LOG_INFO("Configuration successfully loaded from flash.\n");
		return OK;
	} else {
		LOG_INFO(
				"WARN: Failed to load configuration from flash. Loading factory defaults.\n");
		dev_config_load_defaults();
		// 尝试将出厂设置保存一次
		if (dev_config_save() != OK) {
			LOG_ERROR(
					"ERROR: Failed to save initial default configuration to flash.\n");
		}
		return ERROR; // 返回错误，表示启动时未找到有效配置
	}
}

int dev_config_save(void) {
	int status;
	LOG_INFO("Attempting to save configuration to flash...\n");

	// 在写入Flash前，先获取互斥锁，确保配置数据是完整的
	if (semTake(g_config_mutex, WAIT_FOREVER) == OK) {
		status = write_config_to_flash(&g_system_config);
		semGive(g_config_mutex);
	} else {
		LOG_ERROR(
				"FATAL: Could not take config mutex to save configuration.\n");
		return ERROR;
	}

	if (status == OK) {
		LOG_INFO("Configuration saved successfully.\n");
	} else {
		LOG_ERROR("ERROR: Failed to write configuration to flash.\n");
	}
	return status;
}

void dev_config_load_defaults(void) 
{
	LOG_INFO("Loading factory default settings...\n");

	// 获取互斥锁，以线程安全的方式修改全局配置
	if (semTake(g_config_mutex, WAIT_FOREVER) == OK) {
		int i = 0;
		// --- 进入临界区 ---

		// 清空整个结构体
		memset(&g_system_config, 0, sizeof(SystemConfiguration));

		/* --- 加载全局设备默认设置 --- */
		DeviceSettings* dev = &g_system_config.device;
		strncpy(dev->model_name, "WQ-NPORTS-16", MAX_MODEL_NAME_LEN);
		// TODO: 从硬件读取真实的MAC地址
		unsigned char default_mac[6] = { 0x00, 0x0E, 0xC6, 0x01, 0x02, 0x03 };
		memcpy(dev->mac_address, default_mac, 6);
		dev->serial_no = 10001;
		dev->firmware_version[0] = 1;
		dev->firmware_version[1] = 2;
		dev->firmware_version[2] = 3;
		dev->hardware_version[0] = 1;
		dev->hardware_version[1] = 0;
		dev->hardware_version[2] = 0;
		strncpy(dev->server_name, "SerialServer_Default", MAX_SERVER_NAME_LEN);
		strncpy(dev->password, "admin", MAX_PASSWORD_LEN);
		dev->ip_config_mode = 1; // DHCP
		dev->ip_address = inet_addr("192.168.8.4");
		dev->netmask = inet_addr("255.255.255.0");
		dev->gateway = inet_addr("192.168.8.1");

		/* --- 加载每个通道的默认设置 --- */
		for (i = 0; i < NUM_PORTS; i++) {
			ChannelState* ch = &g_system_config.channels[i];
			snprintf(ch->alias, MAX_ALIAS_LEN, "Port %d", i + 1);
			ch->baudrate = 9600;
			ch->data_bits = 8;
			ch->stop_bits = 1;
			ch->parity = 0; // None
			ch->flow_ctrl = 0; // None
			ch->op_mode = 3; // TCP Server Mode
			ch->max_connections = 4;
			// ... 其他通道默认值 ...
		}

		// --- 退出临界区 ---
		semGive(g_config_mutex);
	} else {
		LOG_ERROR("FATAL: Could not take config mutex to load defaults.\n");
	}
}

void dev_reboot(void) 
{
	LOG_INFO("System rebooting...\n");
	// TODO: 调用BSP或硬件驱动提供的系统重启函数
	// Example: sysReboot();
}

/* ------------------ Private HAL Functions (Stubs) ------------------ */

/**
 * @brief 从Flash读取配置 (硬件相关)
 * @details TODO: 实现具体的Flash读取逻辑。
 * 可能需要处理CRC校验、数据版本控制等。
 */
static int read_config_from_flash(SystemConfiguration* config) 
{
	LOG_INFO("TODO: Implement read_config_from_flash()\n");
	// 1. 打开Flash设备
	// 2. 读取数据块到一个临时缓冲区
	// 3. (可选) 校验数据的CRC或Magic Number
	// 4. 如果校验成功，memcpy到config指针
	// 5. 关闭Flash设备
	// 6. 返回 OK 或 ERROR
	return ERROR; // 默认返回错误，以便首次启动时加载出厂设置
}

/**
 * @brief 将配置写入Flash (硬件相关)
 * @details TODO: 实现具体的Flash写入逻辑。
 * 通常包括擦除扇区、写入数据、可能还有回读校验。
 */
static int write_config_to_flash(const SystemConfiguration* config) 
{
	LOG_INFO("TODO: Implement write_config_to_flash()\n");
	// 1. 打开Flash设备
	// 2. (可选) 计算配置数据的CRC
	// 3. 擦除目标Flash扇区
	// 4. 将config指针指向的数据写入Flash
	// 5. (可选) 回读数据并校验
	// 6. 关闭Flash设备
	// 7. 返回 OK 或 ERROR
	return OK; // 暂时返回成功
}

/* ------------------ Helper Functions for Printing States ------------------ */

/**
 * @brief 将 UartPhysicalState 枚举转换为字符串
 */
static const char* uart_state_to_string(UartPhysicalState state) 
{
	switch (state) {
	case UART_STATE_CLOSED:
		return "CLOSED";
	case UART_STATE_OPENED:
		return "OPENED";
	case UART_STATE_ERROR:
		return "ERROR";
	default:
		return "UNKNOWN";
	}
}

/**
 * @brief 将 NetworkChannelState 枚举转换为字符串
 */
static const char* net_state_to_string(NetworkChannelState state) 
{
	switch (state) {
	case NET_STATE_IDLE:
		return "IDLE";
	case NET_STATE_LISTENING:
		return "LISTENING";
	case NET_STATE_CONNECTED:
		return "CONNECTED";
	case NET_STATE_ERROR:
		return "ERROR";
	default:
		return "UNKNOWN";
	}
}

