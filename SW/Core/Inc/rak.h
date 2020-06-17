#ifndef __RAK_H__
#define __RAK_H__

#include "usart.h"

#define RAK_MAX_RECV_LEN 40
#define MAX_TIME_OUT     10   // second unit
/* UART for RAK communication */
#define RAK_huart huart1


void rak_recv_isr(void);
#endif
