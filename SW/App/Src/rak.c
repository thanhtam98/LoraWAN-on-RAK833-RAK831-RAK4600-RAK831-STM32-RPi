#include "rak.h"
#include "main.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>
#include "param.h"

/* Private variables -------------------*/
char rakCommandSendBuffer[RAK_MAX_SEND_LEN];
char commandRecvBuffer[RAK_MAX_RECV_LEN];
uint8_t commandRecvBufferIndex = 0;
uint8_t gotCommandRecvFlag = 0;
lr_packet_t lr_packet_recv;
enum {
	LR_NOT_RESPONE, LR_JOINED, LR_NOT_JOINED, LR_ERR, LR_BUSY
};
uint8_t isJoinedLoraWAN = 0;
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
	if ((base == 16) && (((uint8_t) val_) < 16)) {
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
			return LR_JOINED;
		}
		/*Todo: capture error code for deciding next command */
		if (commandRecvBuffer[0] == 'E') //ERROR
				{
			return LR_ERR;
		}

		/*	Clear buffer*/
		memset(commandRecvBuffer, 0, RAK_MAX_RECV_LEN);

	} else {

		return LR_NOT_RESPONE;
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

uint8_t rak_sendData(uint8_t port, char* data) {
	if (port > 63)
		return 0;  // the biggest port is 63
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+send=lora:");
	strcat(rakCommandSendBuffer, itoa_user(port, 10));
	strcat(rakCommandSendBuffer, ":");
	strcat(rakCommandSendBuffer, data);
	rak_send_raw(rakCommandSendBuffer);

}

uint8_t rak_getStatus(void) {
	char *pNetJoinStatus = NULL;
	memset(rakCommandSendBuffer, 0, RAK_MAX_RECV_LEN);
	strcat(rakCommandSendBuffer, "at+get_config=lora:status");
	return rak_send_raw(rakCommandSendBuffer);
	for (uint8_t u8tryPerSec = 0; u8tryPerSec < MAX_TIME_OUT; u8tryPerSec++) {
		osDelay(1000);
		if (gotCommandRecvFlag == 1) {
			break;
		}
	}
	if (gotCommandRecvFlag == 1) {
		gotCommandRecvFlag = 0;
//		Region: EU868
//		Send_interval: 600s
//		Auto send status: false.
//		Join_mode: ABP
//		DevAddr: 260125D7
//		AppsKey: 841986913ACD00BBC2BE2479D70F3228
//		NwksKey: 69AF20AEA26C01B243945A28C9172B42
//		Class: A
//		Joined Network:true => offset 9
//		IsConfirm: false
//		AdrEnable: true
//		EnableRepeaterSupport: false
		/* Process the rak at command*/
		pNetJoinStatus = strstr(rakCommandSendBuffer, "Network:");
		if (pNetJoinStatus != NULL)
		{

			/* Check true false status
			 * Simply only need check bit =)))
			 * */
			if(*(pNetJoinStatus +9 ) == 't')
			{
//				isJoinedLoraWAN = LR_JOINED;
				return LR_JOINED;
			}
			else {
//				isJoinedLoraWAN =LR_NOT_JOINED;
				return LR_NOT_JOINED;
			}
		}
		/* rak not responding*/
	}

}

/*Brief: command received processing
 *
 * **/
void rak_command_recv_process(void) {
	/*Packet support extraction  variale*/
	uint8_t buf[4];
	uint8_t* pColon;
	if (strcmp(rakCommandSendBuffer, "at+recv") == 0) {
		if ((strchr(rakCommandSendBuffer, '=') + 1) == '0') {
			/*This is ACK.*/
		} else {
			/*
			 * The downlink recieved at port 22 and the pay load is: 6e7474
			 * port,rssi,fnc,snr,payload
			 * Content:  at+recv=22,-54,9,3:6e7474{0D}{0A}*/
			if ((strchr(rakCommandSendBuffer, '=') + 3) != ',') {
				memset(buf, 0, 4);
				memcpy(buf, (strchr(rakCommandSendBuffer, '=') + 1), 2);
				lr_packet_recv.port = atoi(buf);
			} else {
				memset(buf, 0, 4);
				memcpy(buf, (strchr(rakCommandSendBuffer, '=') + 1), 1);
				lr_packet_recv.port = atoi(buf);
			}
			pColon = strchr(rakCommandSendBuffer, ':');
			if (*(pColon - 2) != ',') {
				memset(buf, 0, 4);
				memcpy(buf, (pColon - 2), 2);
				lr_packet_recv.len = atoi(buf);
			} else {
				memset(buf, 0, 4);
				memcpy(buf, (pColon - 1), 1);
				lr_packet_recv.len = atoi(buf);
			}

			for (uint8_t index = 0; index < lr_packet_recv.len; index++) {
				//
				memcpy(buf, (pColon + 1) + index * 2, 2);
				lr_packet_recv.pPayload[index] = strtol(buf, NULL, 16);
			}
			//memcpy(&lr_packet_recv.pPayload[0],(strchr(rakCommandSendBuffer, ':') + 1), strlen(strchr(rakCommandSendBuffer, ':') + 1
		}
	}

	/*ERROR code */
	if (strcmp(commandRecvBuffer, "ER") == 0) {

		if ((commandRecvBuffer[7] == '8') && (commandRecvBuffer[8] == '0')) {
			isJoinedLoraWAN = LR_BUSY;
		}
		if ((commandRecvBuffer[7] == '8') && (commandRecvBuffer[8] == '6')) {
			isJoinedLoraWAN = LR_NOT_JOINED;
		}
	}

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

	char * DevEui = "60C5A8FFFE000001";
	char * AppEui = "70B3D57EF00047C0";
	char * AppKey = "5D833B4696D5E01E2F8DC880E30BA5FE";
	char * pData =
			"5468656e20746869732073697465206973206d61646520666f7220796f752120557365206f75722073757065722068616e6479206f6e6c696e6520746f6f6c20746f206465636f6465206f7220656e636f646520796f757220646174612e";

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
	isJoinedLoraWAN = rak_join();
	uint8_t err;

	while (1) {
		/*Thread up*/

		osDelay(5000);

		err = rak_sendData(5, pData);
		DBG("Send data over LPWAN \r\n with code: %d", err);
		/*Thread down*/

		/*Handling*/
		isJoinedLoraWAN = rak_getStatus();
		if (isJoinedLoraWAN == LR_NOT_JOINED) {
			DBG("Re joining to LRWAN: ");
			osDelay(3000);
			isJoinedLoraWAN = rak_join();
			DBG("Re joining to LRWAN with code: %d \r\n", isJoinedLoraWAN);
		}
		if (isJoinedLoraWAN == LR_BUSY) {
			DBG("LRWAN is busy now, sleeping in 5s \r\n");
			osDelay(5000);
		}

		/*
		 * Receive downlink data and error code detecting
		 *
		 * **/

		if (gotCommandRecvFlag == 1) {
			rak_command_recv_process();
			gotCommandRecvFlag = 0;
			/*	Clear buffer*/
			memset(commandRecvBuffer, 0, RAK_MAX_RECV_LEN);
		}

	}
}

