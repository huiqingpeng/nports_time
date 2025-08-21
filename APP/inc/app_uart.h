#ifndef __APP_NET_H_
#define __APP_NET_H_

#include <vxWorks.h>
#include <stdint.h>
#include "app_com.h"

/* ASPP Command Definitions */
#define     ASPP_CMD_PORT_INIT          (0x2c)  /*初始化串口*/
#define     ASPP_CMD_NOTIFY             (0x26)  /*向中间件通知设备状态改变*/
#define     ASPP_CMD_SETBAUD            (0x17)  /*设置串口波特率*/
#define     ASPP_CMD_XONXOFF            (0x18)  /*XonXoff*/
#define     ASPP_CMD_TX_FIFO            (0x30)  /*TX_FIFO*/
#define     ASPP_CMD_LINECTRL           (0x12)  /*LINECTRL*/
#define     ASPP_CMD_SETXON             (0x33)  /*SETXON*/
#define     ASPP_CMD_SETXOFF            (0x34)  /*SETXOFF*/
#define     ASPP_CMD_START_BREAK        (0x21)  /*START_BREAK*/
#define     ASPP_CMD_STOP_BREAK         (0x22)  /*STOP_BREAK*/
#define     ASPP_CMD_POLLING            (0x27)  /*POLLING*/
#define     ASPP_CMD_ALIVE              (0x28)  /*ALIVE*/
#define     ASPP_CMD_WAIT_OQUEUE        (0x2f)  /*WAIT_OQUEUE*/
#define     ASPP_CMD_FLUSH              (0x14)  /*FLUSH */

/* Notification flags */
#define ASPP_NOTIFY_PARITY      0x01
#define ASPP_NOTIFY_FRAMING     0x02
#define ASPP_NOTIFY_HW_OVERRUN  0x04
#define ASPP_NOTIFY_SW_OVERRUN  0x08
#define ASPP_NOTIFY_BREAK       0x10
#define ASPP_NOTIFY_MSR_CHG     0x20

/* UART MSR flags */
#define UART_MSR_CTS  0x10
#define UART_MSR_DSR  0x20
#define UART_MSR_DCD  0x80

/* USART control definitions */
#define USART_STOP_BIT_2   0x02
#define USART_STOP_BIT_1   0x01

#define USART_PARITY_NONE  0x00
#define USART_PARITY_EVEN  0x02
#define USART_PARITY_ODD   0x01
#define USART_IOCTL_MARK   0x01
#define USART_IOCTL_SPACE  0x01

#define LINE_CONTROL_UART_MCR_DTR 0
#define LINE_CONTROL_UART_MCR_RTS 1

/* FIFO control */
#define FCR_TRIGGER_LEVEL_1  0x00
#define FCR_TRIGGER_LEVEL_16 0x03
#define FCR_FIFO_ENABLE      0x01
#define MCR_DTR              0x01
#define MCR_RTS              0x02

/* Function prototypes */
int socket_send_to_middle(int sock_fd, char *buf, int buf_len);
int init_usart(ChannelState *uart_instance, int client_socket, char *buf,int buf_len, int channel);
int usart_set_baudrate(ChannelState *uart_instance, int client_socket,char *buf, int buf_len, int channel);
void handle_command(ChannelState *uart_instance, int client_socket,char *buf, int buf_len, int channel);

int usart_set_xon_xoff(int client_socket, int channel, char *buf, int buf_len);
int usart_set_tx_fifo(int client_socket, int channel, char *buf, int buf_len);
int usart_set_line_control(int client_socket, int channel, char *buf, int buf_len);
int usart_set_xon(int client_socket, int channel, char *buf, int buf_len);
int usart_set_xoff(int client_socket, int channel, char *buf, int buf_len);
int usart_set_start_break(int client_socket, int channel, char *buf, int buf_len);
int usart_set_stop_break(int client_socket, int channel, char *buf, int buf_len);
int usart_report_queue(int client_socket, char *buf, int buf_len);
int usart_close(int client_socket, char *buf, int buf_len);

void uart_task(unsigned int channel);
void send_xon_xoff_char(uint8_t channel, uint8_t is_xon);
void heartbeat_send_task();

extern const int bauderate_table[];
extern const unsigned int data_bit_table[];

#endif /* NET_CMD_H */
