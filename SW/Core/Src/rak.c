#include "rak.h"
#include "main.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>
/* Private variables -------------------*/
int8_t commandSendBuffer[RAK_MAX_RECV_LEN];
uint8_t commandRecvBuffer[RAK_MAX_RECV_LEN];
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
	if (val == 0)
		buf[i--] = '0';
	for (; val && i; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];

	return &buf[i + 1];
}

uint8_t rak_send_raw(char *datahex) {
	char *EnterCMD = "\r\n>";
	HAL_UART_Transmit(&RAK_huart, (uint8_t*) datahex, sizeof(datahex), 1000);
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

uint8_t rak_setClass(uint8_t classMode) {
	if (classMode > 2)
		return 0;
	memset(commandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(commandSendBuffer, "at+set_config=lora:class:");
	strcat(commandSendBuffer, itoa_user(classMode, 10));
	return rak_send_raw(commandSendBuffer);
}

uint8_t rak_setRegion(uint8_t region) {
	if (region > 9) {
		return 0;
	}
	memset(commandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(commandSendBuffer, "at+set_config=lora:region:");
	switch (region) {
	case 0:

		strcat(commandSendBuffer, "AS923");
		break;
	case 1:

		strcat(commandSendBuffer, "AU915");
		break;
	case 2:

		strcat(commandSendBuffer, "CN470");
		break;
	case 3:

		strcat(commandSendBuffer, "CN779");
		break;
	case 4:

		strcat(commandSendBuffer, "EU433");
		break;
	case 5:

		strcat(commandSendBuffer, "EU868");
		break;
	case 6:

		strcat(commandSendBuffer, "KR920");
		break;
	case 7:

		strcat(commandSendBuffer, "IN865");
		break;
	case 8:

		strcat(commandSendBuffer, "AU915");
		break;
	case 9:

		strcat(commandSendBuffer, "AU915");
		break;
	}
	return rak_send_raw(commandSendBuffer);

}

void rak_reset(void)
{
	char *reset = "at+set_config=device:restart";
	char *EnterCMD = "\r\n>";
	HAL_UART_Transmit(&RAK_huart, (uint8_t*) reset, strlen(reset), 1000);
	HAL_UART_Transmit(&RAK_huart, (uint8_t*) EnterCMD, 3, 100);
}

uint8_t rak_setWorkingMode(void)

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
}
