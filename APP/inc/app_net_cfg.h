
/**
 * @brief 设置网络接口的IP地址、子网掩码和默认网关。
 *
 * @param interface_name 网络接口名称 (例如 "fei0").
 * @param ip_address 要设置的IP地址 (例如 "192.168.1.10").
 * @param netmask 要设置的子网掩码 (例如 "255.255.255.0").
 * @param gateway 要设置的默认网关 (例如 "192.168.1.1").
 * @return 0 表示成功, -1 表示失败.
 */
int net_cfg_set_network_settings(const char *interface_name, const char *ip_address, const char *netmask, const char *gateway);