
#include "hal_com.h"

void sysAxiWriteLong(ULONG address, int32_t data)
{
    *(volatile int32_t *)address = data;
}

int32_t sysAxiReadLong(ULONG address)
{
    return *(volatile int32_t *)address;
}
