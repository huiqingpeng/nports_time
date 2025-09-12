#include <vxWorks.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <fcntl.h>
#include <tickLib.h>

#include "common.h"
#include "hal_axi16550.h"
#include "hal_com.h"

void userAxiCfgWrite(unsigned int channel, unsigned int offset, unsigned int data)
{
    sysAxiWriteLong(AXI_UART_BASE(channel) + offset, data);
}

unsigned int userAxiCfgRead(unsigned int channel, unsigned int offset)
{
    unsigned int data = 0;
    data = sysAxiReadLong(AXI_UART_BASE(channel) + offset);
    return data;
}

int axi16550Recv(unsigned int channel, uint8_t *buffer, uint32_t *len)
{
    *len = 0;
    /* Read data until there is no more data available */
    while (userAxiCfgRead(channel, AXI_16550_LSR) & LSR_TX_READY)
    {
        /* Read the data from the UART */
        buffer[(*len)++] = userAxiCfgRead(channel, AXI_16550_RBR);
    }
    if (buffer == NULL || *len == 0)
        return -1;
    return 0;
}

int axi16550_TxReady(unsigned int channel)
{
    if ((userAxiCfgRead(channel, AXI_16550_LSR) & LSR_THRE) == 0)
        return 0;  /* Not ready (THR or FIFO not empty) */
    else
        return 1;  /* Ready (THR or FIFO is empty) */
}

int axi16550SendNoWait(unsigned int channel, uint8_t *buffer, uint32_t len)
{
    int i = 0;
    if (buffer == NULL || len < 0)
    {
        return -1;
    }
    for (i = 0; i < len; i++)
    {
        userAxiCfgWrite(channel, AXI_16550_THR, buffer[i]);
    }
    return 0;
}

int axi16550Send(unsigned int channel, uint8_t *buffer, uint32_t len)
{
    int i = 0;
    if (buffer == NULL || len < 0)
    {
        return -1;
    }
    while (!axi16550_TxReady(channel));
    for (i = 0; i < len; i++)
    {
        userAxiCfgWrite(channel, AXI_16550_THR, buffer[i]);
    }
    return 0;
}

void axi16550BaudInit(unsigned int channel, unsigned int baud)
{
    unsigned int div;
    unsigned short dlm, dll;
    unsigned char reg;
    div = AXI_16550_CLK / 16 / baud;
    dlm = (div >> 8) & 0xFF;
    dll = div & 0xFF;
    reg = userAxiCfgRead(channel, AXI_16550_LCR);
    userAxiCfgWrite(channel, AXI_16550_LCR, reg | 0x80);
    userAxiCfgWrite(channel, AXI_16550_DLM, dlm);
    userAxiCfgWrite(channel, AXI_16550_DLL, dll);
    userAxiCfgWrite(channel, AXI_16550_LCR, reg);
}

void axi16550SendStartBreak(unsigned int channel)
{
    unsigned char lcr = userAxiCfgRead(channel, AXI_16550_LCR);
    lcr |= LCR_SBRK;
    userAxiCfgWrite(channel, AXI_16550_LCR, lcr);

    taskDelay(10); 
}

void axi16550SendStopBreak(unsigned int channel)
{
    unsigned char lcr = userAxiCfgRead(channel, AXI_16550_LCR);
    lcr &= ~LCR_SBRK;
    userAxiCfgWrite(channel, AXI_16550_LCR, lcr);
}

void send_xon_xoff_char(uint8_t channel, uint8_t is_xon)
{
    uint8_t control_char = is_xon ? XON_CHAR : XOFF_CHAR;
    while (!(userAxiCfgRead(channel, AXI_16550_LSR) & LSR_THRE_MASK));
    userAxiCfgWrite(channel, AXI_16550_THR, control_char);
}

void axi16550Init(unsigned int channel, unsigned int baud)
{
    unsigned int div;
    unsigned short dlm, dll;
    unsigned char reg;
    div = AXI_16550_CLK / 16 / baud;
    dlm = (div >> 8) & 0xFF;
    dll = div & 0xFF;
    reg = userAxiCfgRead(channel, AXI_16550_LCR);
    userAxiCfgWrite(channel, AXI_16550_LCR, reg | 0x80);
    userAxiCfgWrite(channel, AXI_16550_DLM, dlm); /* dlm */
    userAxiCfgWrite(channel, AXI_16550_DLL, dll); /* dll */
    userAxiCfgWrite(channel, AXI_16550_LCR, reg);
    userAxiCfgWrite(channel, AXI_16550_LCR, 0x03);
    userAxiCfgWrite(channel, AXI_16550_FCR, 0x87);
    userAxiCfgWrite(channel, AXI_16550_FCR, 0x81);
    userAxiCfgWrite(channel, AXI_16550_MCR, 0x00); /* 0x00  normal -> 0x10 loopback */
    userAxiCfgWrite(channel, AXI_16550_IER, 0x00);
}

void axi165502CInit(usart_info_t *uart_instance, int channel)
{
    unsigned int div;
    unsigned short dlm, dll;
    unsigned char reg, lcr = 0;

    switch (uart_instance->data_bit)
    {
        case 5:
            lcr |= 0x00;
            break;
        case 6:
            lcr |= 0x01;
            break;
        case 7:
            lcr |= 0x02;
            break;
        case 8:
            lcr |= 0x03;
            break;
    }
    if (uart_instance->stop_bit == 2) lcr |= 0x04;
    if (uart_instance->parity != 0)
    {
        lcr |= 0x08;
        if (uart_instance->parity == 2) lcr |= 0x10;
    }

    div = AXI_16550_CLK / 16 / uart_instance->baud_rate;
    dlm = (div >> 8) & 0xFF;
    dll = div & 0xFF;

    reg = userAxiCfgRead(channel, AXI_16550_LCR);
    userAxiCfgWrite(channel, AXI_16550_LCR, reg | 0x80);
    userAxiCfgWrite(channel, AXI_16550_DLM, dlm);
    userAxiCfgWrite(channel, AXI_16550_DLL, dll);
    userAxiCfgWrite(channel, AXI_16550_LCR, reg);
    userAxiCfgWrite(channel, AXI_16550_LCR, lcr);
    userAxiCfgWrite(channel, AXI_16550_FCR, 0x07);
    userAxiCfgWrite(channel, AXI_16550_MCR, 0x00);
    userAxiCfgWrite(channel, AXI_16550_IER, 0x00);
}

/* FIFO initialization function */
int axi16550FIFOInit(int port)
{
    userAxiCfgWrite(port, AXI_16550_FCR, 0x87);
    userAxiCfgWrite(port, AXI_16550_FCR, 0x81);
    return 0;
}


/* LED control functions */
void txled(int i, int action)
{
	if (i < 0 || i > 15) return;

	uint32_t reg_address = 0x130 + (i * 4);  
	uint32_t value = (action == 1) ? 1 : 0; 

	sysAxiWriteLong(PL_AXI_BASE + reg_address, value);
}

void rxled(int i, int action)
{
	if (i < 0 || i > 15) return;

	uint32_t reg_address = 0x230 + (i * 4);  
	uint32_t value = (action == 1) ? 1 : 0;  

	sysAxiWriteLong(PL_AXI_BASE + reg_address, value);
}

void Portled(int i, int action) {
	if (i < 0 || i > 15) return;

	uint32_t reg_address = 0x30 + (i * 4);  
	uint32_t value = (action == 1) ? 1 : 0;  

	sysAxiWriteLong(PL_AXI_BASE + reg_address, value);
}

