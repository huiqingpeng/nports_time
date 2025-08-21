#include <vxWorks.h>
#include <stdio.h>
#include <sockLib.h>
#include <inetLib.h>
#include <taskLib.h>
#include <socket.h>
#include <stdlib.h>
#include <sysLib.h>
#include <logLib.h>
#include <errno.h>
#include <string.h>
#include "wdLib.h"
#include "in.h"
#include "ioLib.h"
#include <unistd.h>
#include <sys/socket.h>
#include <stdint.h>
#include <stddef.h>
#include <fcntl.h>
#include <tickLib.h>
#include "./inc/app_com.h"
#include "./inc/app_cmd.h"
#include "../hal/hal_axi16550.h"

const int bauderate_table[] = { 300, 600, 1200, 2400, 4800, 7200, 9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600, 150, 134, 110, 75, 50};
const unsigned int data_bit_table[] = { 5, 6, 7, 8 };

int socket_send_to_middle(int sock_fd, char *buf, int buf_len) 
{
	int i = 0;
	int ret = send(sock_fd, buf, buf_len, 0);
	if (ret < 0) {
		perror("send");
		return -1;
	}
	return 0;
}


int  init_usart(UART_Config_Params *uart_instance,int client_socket, char *buf, int buf_len, int channel) 
{
	int ret;

	unsigned char stop_bit;
	unsigned char data_bit;

	char pack_buf[5] = {0};

//	uart_buffer_init(channel);
	/*提取串口参数*/

	/*设置串口波特率*/
	int baud_rate = bauderate_table[(int)buf[2]];
	uart_instance->config.baud_rate = baud_rate;
	LOG_DEBUG("baud_rate: %d\n", uart_instance->config.baud_rate);

	/*data bit*/
	data_bit = ((int)buf[3])& 0x03;
	uart_instance->config.data_bit = data_bit_table[data_bit];
	LOG_DEBUG("data_bit: %d\n", uart_instance->config.data_bit);

	/*stop bit*/
	stop_bit = ((int)buf[3])& 0x04;
	if(stop_bit == 0)
	{
		uart_instance->config.stop_bit = USART_STOP_BIT_1;
		LOG_DEBUG("stop_bit: %d\n", uart_instance->config.stop_bit);
	}
	else
	{
		uart_instance->config.stop_bit = USART_STOP_BIT_2;
		LOG_DEBUG("stop_bit: %d\n", uart_instance->config.stop_bit);
	}

	/* 0b111000，用于提取第3 - 5位*/
	int last_mask = ((int)buf[3]) & 0x38;
	switch (last_mask) {
	case 0x00:
		LOG_DEBUG("Parity: None\n");
		uart_instance->config.parity = USART_PARITY_NONE;
		break;
	case 0x08:
		LOG_DEBUG("Parity: Even\n");
		uart_instance->config.parity = USART_PARITY_EVEN;
		break;
	case 0x10:
		LOG_DEBUG("Parity: Odd\n");
		uart_instance->config.parity = USART_PARITY_ODD;
		break;
	case 0x18:
		LOG_DEBUG("Parity: Mark\n");
		uart_instance->config.mark = USART_IOCTL_MARK;
		break;
	case 0x20:
		LOG_DEBUG("Parity: Space\n");
		uart_instance->config.space = USART_IOCTL_SPACE;
		break;
	default:
		LOG_ERROR("Unknown parity configuration:%02x \n",last_mask);
		break;
	}
	/*调用AXI_api设置串口相关寄存器*/
	axi165502CInit(uart_instance,channel);

	uart_instance->config.usart_mcr_dtr = (unsigned char)buf[4];

	uart_instance->config.usart_mcr_rts = (unsigned char)buf[5];

	/* 获取当前 MCR 寄存器值*/
	unsigned int mcr_reg = userAxiCfgRead(channel, AXI_16550_MCR);

	/*设置 DTR 位*/
	if (uart_instance->config.usart_mcr_dtr) {
		mcr_reg |= MCR_DTR;
	} else {
		mcr_reg &= ~MCR_DTR;
	}

	/* 设置 RTS 位*/
	if (uart_instance->config.usart_mcr_rts) {
		mcr_reg |= MCR_RTS;
	} else {
		mcr_reg &= ~MCR_RTS;
	}
	/* 写入更新后的 MCR 寄存器值*/
	//	userAxiCfgWrite(channel, AXI_16550_MCR, mcr_reg);

	uart_instance->config.usart_crtscts = (unsigned char)buf[6];

	/*
//	if(uart_instance->config.IX_on == (int)buf[7])
//	{
//		send_xon_xoff_char(channel, 1);
//	}
//	if(uart_instance->config.IX_off == (int)buf[8])
//	{
//		send_xon_xoff_char(channel, 0);
//	}
	 * 
	 * */

	//打包数据
	pack_buf[0] = buf[0];
	pack_buf[1] = 0x3;
	pack_buf[2] = 0x0;
	pack_buf[3] = 0x0;
	pack_buf[4] = 0x0; 
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, pack_buf, sizeof(pack_buf));
	if(ret < 0)
	{
		/*printf("send error\n");*/
		return -1;
	}

	return 0;

}


int  usart_set_baudrate(UART_Config_Params *uart_instance,int client_socket, char *buf, int buf_len, int channel)
{
	int ret;
	unsigned int baud_rate;

	/*提取波特率:假设高位在前*/
	baud_rate = buf[2] << 24 | buf[3] << 16 | buf[4] << 8 | buf[5];
	uart_instance->config.baud_rate = baud_rate;

	LOG_DEBUG("baud_rate: %d\n", baud_rate);

	//调用AXI_api设置串口波特率
	//打包数据
	axi16550BaudInit(channel, uart_instance->config.baud_rate);

	char response[3] = {0};
	response[0] = buf[0];         
	response[1] = 'O';            
	response[2] = 'K';            
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, response, sizeof(response));
	if(ret < 0)
	{
		/*printf("send error\n");*/
		return -1;
	}

	return 0;
}


int usart_set_xon_xoff(int client_socket,int channel, char *buf, int buf_len)
{
	int ret;

	/*字符串比较VSTART和VSTOP从buf[2]开始*/
	if( (strcmp(&buf[2], "VSTART")) == 0)
	{
		/*调用AXI_api设置XonXoff*/
		/*		send_xon_xoff_char(channel, 1); // 发送 XON*/
	}
	else if( (strcmp(&buf[2], "VSTOP")) == 0)
	{
		/*		send_xon_xoff_char(channel, 0); // 发送 XOFF*/
	}

	/*返回数据给中间件*/
	char response[3] = {0};
	response[0] = buf[0];         
	response[1] = 'O';            
	response[2] = 'K';            
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, response, sizeof(response));
	if(ret < 0)
	{
		/*printf("send error\n");*/
		return -1;
	}

	return 0 ;
}


int usart_set_tx_fifo(int client_socket,int channel, char *buf, int buf_len)
{
	unsigned fifo_size;
	int ret;

	fifo_size = buf[2];
	/*
	//printf("fifo_size: %d\n", fifo_size);

	//调用AXI_api设置TX_FIFO

	// 根据 fifo_size 配置 16550 FCR 寄存器*/
	unsigned char fcr_value = FCR_FIFO_ENABLE;
	if (fifo_size == 1) {
		fcr_value |= FCR_TRIGGER_LEVEL_1;
	} else if (fifo_size == 16) {
		fcr_value |= FCR_TRIGGER_LEVEL_16;
	}
	//	userAxiCfgWrite(channel, AXI_16550_FCR, fcr_value);

	char response[3] = {0};
	response[0] = buf[0];         
	response[1] = 'O';            
	response[2] = 'K';            
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, response, sizeof(response));

	if(ret < 0)
	{
		/*printf("send error\n");*/
		return -1;
	}

	return 0 ;
}


int usart_set_line_control(int client_socket,int channel, char *buf, int buf_len)
{
	int ret;
	unsigned char dtr_val = buf[2];
	unsigned char rts_val = buf[3];

	/* 获取当前 MCR 寄存器值*/
	unsigned int mcr_reg = userAxiCfgRead(channel, AXI_16550_MCR);

	/* 设置 DTR 位*/
	if (dtr_val) {
		mcr_reg |= MCR_DTR;
	} else {
		mcr_reg &= ~MCR_DTR;
	}

	/* 设置 RTS 位*/
	if (rts_val) {
		mcr_reg |= MCR_RTS;
	} else {
		mcr_reg &= ~MCR_RTS;
	}

	/* 写入更新后的 MCR 寄存器值*/
	userAxiCfgWrite(channel, AXI_16550_MCR, mcr_reg);

	char response[3] = {0};
	response[0] = buf[0];         
	response[1] = 'O';            
	response[2] = 'K';            
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, response, sizeof(response));
	if(ret < 0)
	{
		return -1;
	}

	return 0 ;
}

int usart_set_xon(int client_socket,int channel, char *buf, int buf_len)
{
	int ret;
	/*	send_xon_xoff_char(channel, 1);*/
	char response[3] = {0};
	response[0] = buf[0];         
	response[1] = 'O';            
	response[2] = 'K';            
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, response, sizeof(response));

	if(ret < 0)
	{
		return -1;
	}

	return 0 ;
}

int usart_set_xoff(int client_socket,int channel, char *buf, int buf_len)
{
	int ret;
	/*	send_xon_xoff_char(channel, 0);*/
	char response[3] = {0};
	response[0] = buf[0];         
	response[1] = 'O';            
	response[2] = 'K';            
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, response, sizeof(response));

	if(ret < 0)
	{
		return -1;
	}

	return 0 ;
}


int usart_set_start_break(int client_socket,int channel, char *buf, int buf_len)
{
	axi16550SendStartBreak(channel);
	int ret;
	char response[3] = {0};
	response[0] = buf[0];         
	response[1] = 'O';            
	response[2] = 'K';            
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, response, sizeof(response));

	if(ret < 0)
	{
		return -1;
	}
	return 0 ;

}

int usart_set_stop_break(int client_socket,int channel, char *buf, int buf_len)
{
	int ret;
	axi16550SendStopBreak(channel);
	char response[3] = {0};
	response[0] = buf[0];         
	response[1] = 'O';            
	response[2] = 'K';            
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, response, sizeof(response));

	if(ret < 0)
	{
		return -1;
	}
	return 0 ;

}

int usart_report_queue(int client_socket, char *buf, int buf_len)
{
	int ret;

	char pack_buf[4];

	/*打包数据*/
	pack_buf[0] = buf[0];
	pack_buf[1] = 0x02;
	pack_buf[2] = 0x00;
	pack_buf[3] = 0x00;

	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, pack_buf, sizeof(pack_buf));
	if(ret < 0)
	{
		return -1;
	}
	return 0 ;

}

int usart_close(int client_socket, char *buf, int buf_len)
{
	int ret;

	char response[3] = {0};
	response[0] = buf[0];         
	response[1] = 'O';            
	response[2] = 'K';            
	/*返回数据给中间件*/
	ret = socket_send_to_middle(client_socket, response, sizeof(response));

	if(ret < 0)
	{
		return -1;
	}
	return 0 ;
}

void handle_command(UART_Config_Params *uart_instance,int client_socket, char *buf, int buf_len, int channel) 
{
	/*解析数据*/
	unsigned char cmd = buf[0];
	unsigned char data_len = buf[1];

	switch(cmd)
	{
	case ASPP_CMD_PORT_INIT:
	{
		init_usart(uart_instance,client_socket, buf, data_len, channel);
		break;
	}
	case ASPP_CMD_NOTIFY:
	{

		break;
	}
	case ASPP_CMD_SETBAUD:
	{
		usart_set_baudrate(uart_instance,client_socket, buf, data_len, channel);
		break;
	}

	case ASPP_CMD_XONXOFF:
	{
		usart_set_xon_xoff(client_socket, channel, buf, data_len);
		break;
	}

	case ASPP_CMD_TX_FIFO:
	{
		usart_set_tx_fifo(client_socket, channel, buf, data_len);
		break;
	}

	case ASPP_CMD_LINECTRL:
	{
		usart_set_line_control(client_socket, channel, buf, data_len);
		break;
	}

	case ASPP_CMD_SETXON:
	{
		usart_set_xon(client_socket, channel, buf, data_len);
		break;
	}

	case ASPP_CMD_SETXOFF:
	{
		usart_set_xoff(client_socket, channel, buf, data_len);
		break;
	}

	case ASPP_CMD_START_BREAK:
	{
		usart_set_start_break(client_socket, channel, buf, data_len);
		break;
	}

	case ASPP_CMD_STOP_BREAK:
	{   
		usart_set_stop_break(client_socket, channel, buf, data_len);
		break;
	}

	case ASPP_CMD_ALIVE:
	{
		/*		usart_report_hearbeat(client_socket, buf, data_len);*/
		break;
	}

	case ASPP_CMD_WAIT_OQUEUE:
	{
		usart_report_queue(client_socket, buf, data_len);
		break;
	}

	case ASPP_CMD_FLUSH:
	{
		usart_close(client_socket, buf, data_len);
		break;
	}


	default:
	{
		LOG_ERROR("Unknown command: %d\n", cmd);
		break;
	}

	}
}
