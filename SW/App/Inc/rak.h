#ifndef __RAK_H__
#define __RAK_H__

#include "usart.h"

#define RAK_MAX_RECV_LEN 40
#define MAX_TIME_OUT     10   // second unit
/* UART for RAK communication */
#define RAK_huart huart1

uint8_t rak_send_raw(char *datahex);
uint8_t rak_setClass(uint8_t classMode);
uint8_t rak_setRegion(uint8_t region);
void rak_reset(void);
uint8_t rak_setWorkingMode(uint8_t mode);
uint8_t rak_setJoinMode(uint8_t mode);
uint8_t rak_join(void) ;
void rak_initOTAA(char *devEUI, char *appEUI, char *appKey);
uint8_t rak_isConfirm(uint8_t type);


void rak_recv_isr(void);

void vRakTask(void const *arg);

#endif
