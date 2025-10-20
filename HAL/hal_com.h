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
#include "hal_log.h"

#define UART_HW_FIFO_SIZE               (256)



void sysAxiWriteLong(ULONG address, int32_t data);
int32_t sysAxiReadLong(ULONG address);


#endif /* COMMON_H_ */
