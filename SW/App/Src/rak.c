#include "rak.h"
#include "main.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>
#include "param.h"

/* Private variables -------------------*/
char rakCommandSendBuffer[RAK_MAX_RECV_LEN];
char commandRecvBuffer[RAK_MAX_RECV_LEN];
uint8_t commandRecvBufferIndex = 0;
uint8_t gotCommandRecvFlag = 0;

/* Start implementation --------------------*/

/*
 *
 *
 * */
/*Function*/
/**
 * @brief
 * @param
 * @retval None
 */
uint8_t* itoa_user(uint32_t val, uint8_t base) {
	static uint8_t buf[32] = { 0 };  // 32 bits
	int i = 30;
	uint32_t val_ = val;
	if (val == 0) {
		buf[i--] = '0';
//		if (base == 16) {
//			buf[i--] = '0';
//			return &buf[i + 1];
//		}
	}

	for (; val && i; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	if ((base == 16) && (((uint8_t)val_) < 16)) {
		buf[i--] = '0';
	}
//	if (base == 16)
//	{
//		buf[i] = '0';
//	}
	return &buf[i + 1];

}

uint8_t rak_send_raw(char *datahex) {
	char *EnterCMD = "\r\n";
	HAL_UART_Transmit(&RAK_huart, (uint8_t*) datahex, strlen(datahex), 1000);
	HAL_UART_Transmit(&RAK_huart, (uint8_t*) EnterCMD, 3, 100);
//	while(gotCommandRecvFlag != 0)
//	{
//		osDelay(200);
//	}
	/*Wait for the rak reponse*/
	for (uint8_t u8tryPerSec = 0; u8tryPerSec < MAX_TIME_OUT; u8tryPerSec++) {
		osDelay(1000);
		if (gotCommandRecvFlag == 1) {
			break;
		}
	}

	if (gotCommandRecvFlag == 1) {
		gotCommandRecvFlag = 0;
		/* Process the rak at command*/
		if (commandRecvBuffer[0] == 'O') // OK
				{
			return 1;
		}
		/*Todo: capture error code for deciding next command */
		if (commandRecvBuffer[0] == 'E') //ERROR
				{
			return 2;
		}

		/*	Clear buffer*/
		memset(commandRecvBuffer, 0, RAK_MAX_RECV_LEN);

	} else {

		return 0;
		/* rak not responding*/
	}
}

/*Brief:
 * @param: class Mode: Class A = 0; Class C = 2
 *
 *
 * */
uint8_t rak_setClass(uint8_t classMode) {
	if (classMode > 2)
		return 0;
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+set_config=lora:class:");
	strcat(rakCommandSendBuffer, itoa_user(classMode, 10));
	return rak_send_raw(rakCommandSendBuffer);
}

uint8_t rak_setRegion(uint8_t region) {
	if (region > 9) {
		return 0;
	}
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+set_config=lora:region:");
	switch (region) {
	case 0:

		strcat(rakCommandSendBuffer, "AS923");
		break;
	case 1:

		strcat(rakCommandSendBuffer, "AU915");
		break;
	case 2:

		strcat(rakCommandSendBuffer, "CN470");
		break;
	case 3:

		strcat(rakCommandSendBuffer, "CN779");
		break;
	case 4:

		strcat(rakCommandSendBuffer, "EU433");
		break;
	case 5:

		strcat(rakCommandSendBuffer, "EU868");
		break;
	case 6:

		strcat(rakCommandSendBuffer, "KR920");
		break;
	case 7:

		strcat(rakCommandSendBuffer, "IN865");
		break;
	case 8:

		strcat(rakCommandSendBuffer, "AU915");
		break;
	case 9:

		strcat(rakCommandSendBuffer, "AU915");
		break;
	}
	return rak_send_raw(rakCommandSendBuffer);

}

void rak_reset(void) {
	char *reset = "at+set_config=device:restart";
	char *EnterCMD = "\r\n";
	HAL_UART_Transmit(&RAK_huart, (uint8_t*) reset, strlen(reset), 1000);
	HAL_UART_Transmit(&RAK_huart, (uint8_t*) EnterCMD, 3, 100);
}

/*
 * mode = 0: LoraWAN Mode
 * mode = 1: Lora2P2 Mode
 *
 * */
uint8_t rak_setWorkingMode(uint8_t mode) {
	if (mode > 2)
		return 0;
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+set_config=lora:work_mode:");
	strcat(rakCommandSendBuffer, itoa_user(mode, 10));
	return rak_send_raw(rakCommandSendBuffer);
}

/*
 * Mode = 0: OTAA
 * Mode = 1: ABP
 *
 * */

uint8_t rak_setJoinMode(uint8_t mode) {
	if (mode > 2)
		return 0;
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+set_config=lora:join_mode:");
	strcat(rakCommandSendBuffer, itoa_user(mode, 10));
	return rak_send_raw(rakCommandSendBuffer);
}

uint8_t rak_join(void) {
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+join");
	rak_send_raw(rakCommandSendBuffer);

	for (uint8_t u8tryPerSec = 0; u8tryPerSec < MAX_TIME_OUT; u8tryPerSec++) {
		osDelay(1000);
		if (gotCommandRecvFlag == 1) {
			break;
		}
	}
	if (gotCommandRecvFlag == 1) {
		gotCommandRecvFlag = 0;
		/* Process the rak at command*/
		if (commandRecvBuffer[0] == 'O') // OK
				{
			return 1;
		}
		/*Todo: capture error code for deciding next command */
		if (commandRecvBuffer[0] == 'E') //ERROR
				{
			return 2;
		}

		/*	Clear buffer*/
		memset(commandRecvBuffer, 0, RAK_MAX_RECV_LEN);

	} else {

		return 0;
		/* rak not responding*/
	}

}

void rak_initOTAA(char *devEUI, char *appEUI, char *appKey) {

	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+set_config=lora:dev_eui:");
	strcat(rakCommandSendBuffer, devEUI);
	rak_send_raw(rakCommandSendBuffer);
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+set_config=lora:app_eui:");
	strcat(rakCommandSendBuffer, appEUI);
	rak_send_raw(rakCommandSendBuffer);
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "appKey+set_config=lora:app_key:");
	strcat(rakCommandSendBuffer, devEUI);
	rak_send_raw(rakCommandSendBuffer);

}
/*
 * Type = 0: unc
 * Type = 1: cfm
 *
 * */
uint8_t rak_isConfirm(uint8_t type) {
	if (type > 1)
		return 0;
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+set_config=lora:confirm:");
	strcat(rakCommandSendBuffer, itoa_user(type, 10));
	return rak_send_raw(rakCommandSendBuffer);
}

/*Brief: Handle AT command received over serial interrupt
 *
 *
 * */
void rak_recv_isr(void) {
	uint8_t receivedChar;

	receivedChar = (uint8_t) ((RAK_huart).Instance->DR & (uint8_t) 0x00FF);
	if (receivedChar != 13) {

		commandRecvBuffer[commandRecvBufferIndex] = receivedChar;
		commandRecvBufferIndex++;
	}

	else {
		commandRecvBuffer[commandRecvBufferIndex] = 0;
		commandRecvBufferIndex = 0;
		gotCommandRecvFlag = 1;
	}
	if (commandRecvBufferIndex == RAK_MAX_RECV_LEN)
		commandRecvBufferIndex = 0;
//	HAL_UART_Transmit(&RAK_huart, &receivedChar, 1, 100);
}

void vRakTask(void const *arg) {
	uint8_t isLoraWAN = 0;

	char * DevEui = "60C5A8FFFE000001";
	char * AppEui = "70B3D57EF00047C0";
	char * AppKey = "5D833B4696D5E01E2F8DC880E30BA5FE";
	if (PARAM[NODE_HAVE_PARAM_ADR] == 1) {
		for (uint8_t idx = 0; idx < 8; idx++) {
			strcat(DevEui,
					itoa_user(u_mem_get(NODE_LRWAN_DEVEUI_ADR + idx), 16));
		}
		for (uint8_t idx = 0; idx < 16; idx++) {
			strcat(AppEui,
					itoa_user(u_mem_get(NODE_LRWAN_APPEUI_ADR + idx), 16));
		}
		for (uint8_t idx = 0; idx < 16; idx++) {
			strcat(AppKey,
					itoa_user(u_mem_get(NODE_LRWAN_APPKEY_ADR + idx), 16));
		}
		//printf("%d \r\n", u_mem_get(NODE_LRWAN_DEVEUI_ADR + idx));

	}
	/*Initial */
//rak_reset();
	osDelay(1000);
	rak_setClass(2);
	rak_setRegion(0);
	rak_setWorkingMode(0);
	rak_setJoinMode(0);
	rak_isConfirm(1);
	rak_initOTAA(DevEui, AppEui, AppKey);
	rak_join();
//	if(rak_setClass(0) == 0)
//
//	{
//		HAL_UART_Transmit(&huart1,p,6,100);
//	}
//	else
//	{
//		HAL_UART_Transmit(&huart1,n,6,100);
//	}

	while (1) {
		/*Thread up*/

		/*Thread down*/

	}
}

