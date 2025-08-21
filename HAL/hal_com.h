#ifndef __HAL_COMMON_H_
#define __HAL_COMMON_H_

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
#include <selectLib.h>
#include <tickLib.h>
#include <msgQLib.h>
#include <netinet/in.h>


#define VESION_H 1
#define VESION_M 0
#define VESION_L 0

#define UART_HW_FIFO_SIZE               (4096)

#define BACKLOG   8
#define LED_ON  1
#define LED_OFF 0

/* 日志等级控制宏（可用编译器 -D 传入） */
#define LOG_LEVEL_ERROR	0
#define LOG_LEVEL_INNFO	1
#define LOG_LEVEL_DEBUG	2

#ifndef LOG_LEVEL
#define LOG_LEVEL  LOG_LEVEL_INNFO   // 0: ERROR only, 1: +INFO, 2: +DEBUG
#endif

/* 始终输出 */
#define LOG_ERROR(fmt, ...) \
    do { \
        printf("[ERROR]:%d: " fmt "\n", __LINE__, ##__VA_ARGS__); \
    } while (0)

#if LOG_LEVEL >= 1
#define LOG_INFO(fmt, ...) \
    do { \
        printf("[INFO ]:%d: " fmt "\n", __LINE__, ##__VA_ARGS__); \
    } while (0)
#else
#define LOG_INFO(fmt, ...) do {} while (0)
#endif

#if LOG_LEVEL >= 2
#define LOG_DEBUG(fmt, ...) \
    do { \
        printf("[DEBUG]:%d: " fmt "\n", __LINE__, ##__VA_ARGS__); \
    } while (0)
#else
#define LOG_DEBUG(fmt, ...) do {} while (0)
#endif

/* State enumeration for TCP connections */
typedef enum
{
	STATE_INIT = 0,
	STATE_TCP_OPEN,
	STATE_TCP_CONN,
	STATE_TCP_CLOSE,
	STATE_TCP_WAIT,
	STATE_RW_DATA,
	STATE_MAX
} sock_state_enum;

extern const char *STATE_NAMES[];

/* LED status tracking */
typedef struct
{
	uint16_t tx_count;
	uint16_t rx_count;
	uint16_t sample_tick_cnt_tx;
	uint16_t sample_tick_cnt_rx;
	uint16_t sample_period_ticks_tx;
	uint16_t sample_period_ticks_rx;
	uint8_t tx_led_state;   // 0=灭,1=亮
	uint8_t rx_led_state;   // 0=灭,1=亮
} uart_led_stat_t;

/* UART parameters */
typedef struct usart_params1
{
	unsigned int  baud_rate;
	unsigned char data_bit;
	unsigned char stop_bit;
	unsigned char parity;
	unsigned char mark;
	unsigned char space;
	unsigned char usart_mcr_dtr;
	unsigned char usart_mcr_rts;
	unsigned char usart_crtscts;
	unsigned char IX_on;
	unsigned char IX_off; //XonXoff
} usart_params1_t;

extern const int portdata_array[];
extern const int portcmd_array[]; 

void sysAxiWriteLong(ULONG address, int32_t data);
int32_t sysAxiReadLong(ULONG address);


#endif /* COMMON_H_ */
