/* Built-in C library includes ----------------------*/

#include <stdio.h>
#include <stdint.h>
/* Platform includes --------------------------------*/

#include "main.h"
#include "cmsis_os.h"
#include "sharedmem.h"
#include "param.h"
#include "usart.h"
/* Modbus includes ---------------------------------*/
#include "mb.h"
#include "mbport.h"

extern osTimerId myTimer01Handle;
#define REG_INPUT_START 1000
#define REG_INPUT_NREGS 8

static USHORT usRegInputStart = REG_INPUT_START;
static USHORT usRegInputBuf[REG_INPUT_NREGS];

void vModBusTask(void const * argument) {
	/* ABCDEF */
	eMBErrorCode eStatus;
	if (PARAM[NODE_HAVE_PARAM_ADR] != 0) {
		eStatus = eMBInit(MB_RTU, PARAM[NODE_MB_ID_ADR], 3, 9600, MB_PAR_NONE);
	} else {
		eStatus = eMBInit(MB_RTU, 1, 3, 9600, MB_PAR_NONE);
	}

	eStatus = eMBEnable();
	__HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);
//  osTimerStart(myTimer01Handle, 1);
	while (1) {
		eMBPoll();
		osDelay(10);
	}
}

eMBErrorCode eMBRegInputCB(UCHAR * pucRegBuffer, USHORT usAddress,
		USHORT usNRegs) {
	eMBErrorCode eStatus = MB_ENOERR;
	int iRegIndex;

	if ((usAddress >= REG_INPUT_START)
			&& (usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS)) {
		iRegIndex = (int) (usAddress - usRegInputStart);
		while (usNRegs > 0) {
			*pucRegBuffer++ = (unsigned char) (usRegInputBuf[iRegIndex] >> 8);
			*pucRegBuffer++ = (unsigned char) (usRegInputBuf[iRegIndex] & 0xFF);
			iRegIndex++;
			usNRegs--;
		}

		//	HAL_GPIO_TogglePin(LD4_GPIO_Port, LD4_Pin);
	} else {
		// HAL_GPIO_TogglePin(LD5_GPIO_Port, LD5_Pin);
		eStatus = MB_ENOREG;
	}

	return eStatus;
}

eMBErrorCode eMBRegHoldingCB(UCHAR * pucRegBuffer, USHORT usAddress,
		USHORT usNRegs, eMBRegisterMode eMode) {
	eMBErrorCode eStatus = MB_ENOERR;
	USHORT iRegIndex;
	USHORT * pusRegHoldingBuf;
	USHORT REG_HOLDING_START;
	USHORT REG_HOLDING_NREGS;
	USHORT usRegHoldStart;


//   pusRegHoldingBuf = usSRegHoldBuf;
//   REG_HOLDING_START = S_REG_HOLDING_START;
//   REG_HOLDING_NREGS = S_REG_HOLDING_NREGS;
//   usRegHoldStart = usSRegHoldStart;
	DBG("\r\n MB callback function");
	usAddress--;
	if (usAddress < MEM_MAX_SIZE) {
		switch (eMode) {
		case MB_REG_READ:
			while (usNRegs > 0) {
				DBG("\r\n MB callback uiMemGet: adr: %d val: %d", usAddress,(uiMemGet(usAddress)));
				*pucRegBuffer++ = (UCHAR) (uiMemGet(usAddress) >> 8);
				*pucRegBuffer++ = (UCHAR) (uiMemGet(usAddress) & 0xFF);
				usAddress++;
				usNRegs--;

			}
			break;
		case MB_REG_WRITE:
			while (usNRegs > 0) {

				uiMemSet(usAddress, (uint16_t) ((*(pucRegBuffer))<<8)|*(pucRegBuffer + 1));
				DBG("\r\n MB callback uiMemSet: adr: %d val: %d", usAddress,
						*(pucRegBuffer + 1));
				usAddress++;
				usNRegs--;
			}

			break;
		}
	}

	return MB_ENOERR;
}

eMBErrorCode eMBRegCoilsCB(UCHAR * pucRegBuffer, USHORT usAddress,
		USHORT usNCoils, eMBRegisterMode eMode) {
	return MB_ENOREG;
}

eMBErrorCode eMBRegDiscreteCB(UCHAR * pucRegBuffer, USHORT usAddress,
		USHORT usNDiscrete) {
	return MB_ENOREG;
}
