#ifndef __HAL_AXI_16550_H_
#define __HAL_AXI_16550_H_

#include <vxWorks.h>
#include <stdint.h>
#include "hal_com.h"

/* Base addresses and register offsets */
#define AXI_UART_BASE(n)         (0x41200000 + 0x2000 * n) /* 基地址 */
#define AXI_16550_INT            (84)
#define AXI_16550_CLK            (29491200)
#define AXI_16550_CLK1           (32000000)
#define AXI_16550_RBR            (0x1000)
#define AXI_16550_THR            (0x1000)
#define AXI_16550_IER            (0x1004)
#define AXI_16550_IIR            (0x1008)
#define AXI_16550_FCR            (0x1008)
#define AXI_16550_LCR            (0x100C)
#define AXI_16550_MCR            (0x1010)
#define AXI_16550_LSR            (0x1014)
#define AXI_16550_MSR            (0x1018)
#define AXI_16550_SCR            (0x101C)
#define AXI_16550_DLL            (0x1000)
#define AXI_16550_DLM            (0x1004)
#define BRAM_KZ                  (0x00000004)

/* Control bit definitions */
#define LCR_SBRK                  0x40  /* BREAK 信号控制位 */
#define LSR_TX_READY              0x01  /* Data Ready */
#define LSR_TX_BUFFER_EMPTY       (1<<6) /* Transmit reg empty */
#define LSR_THER                  (1<<5)

/* Line Status Register (LSR) bits */
#define LSR_DR                    0x01  /* Data Ready */
#define LSR_OE                    0x02  /* Overrun Error */
#define LSR_PE                    0x04  /* Parity Error */
#define LSR_FE                    0x08  /* Framing Error */
#define LSR_BI                    0x10  /* Break Interrupt */
#define LSR_THRE                  0x20  /* Transmitter Holding Register Empty (FIFO has space) */
#define LSR_TEMT                  0x40  /* Transmitter Empty (FIFO and shift register empty) */

/* XON/XOFF control characters */
#define XON_CHAR                  0x11  /* XON 字符（DC1）*/
#define XOFF_CHAR                 0x13  /* XOFF 字符（DC3）*/
#define LSR_THRE_MASK             0x20  /* 发送保持寄存器为空标志位 */



/* Function declarations */
void userAxiCfgWrite(unsigned int channel, unsigned int offset, unsigned int data);
unsigned int userAxiCfgRead(unsigned int channel, unsigned int offset);
int axi16550Recv(unsigned int channel, uint8_t *buffer, uint32_t *len);
int axi16550_TxReady(unsigned int channel);
int axi16550SendNoWait(unsigned int channel, uint8_t *buffer, uint32_t len);
int axi16550Send(unsigned int channel, uint8_t *buffer, uint32_t len);
void axi16550BaudInit(unsigned int channel, unsigned int baud);
void axi16550SendStartBreak(unsigned int channel);
void axi16550SendStopBreak(unsigned int channel);
void send_xon_xoff_char(uint8_t channel, uint8_t is_xon);
void axi16550Init(unsigned int channel, unsigned int baud);
void axi165502CInit(usart_params1_t *uart_instance, int channel);

#endif /* AXI_16550_H_ */
