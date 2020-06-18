/*
 * Brief: Default app folked from rtos default task
 *
 *
 *
 *
 * */
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "gpio.h"
#include "app.h"
#include "dht.h"
#include "rak.h"
#include "mbtask.h"
#include "envtask.h"
/**/
osThreadId modbusTaskHandle;
osThreadId loraTaskHandle;
osThreadId envTaskHandle;

void vAppDefault(void) {

	/*Task initialization*/

//	osThreadDef(modbusTaskHandle, vModBusTask, osPriorityNormal, 0, 128);
//	modbusTaskHandle = osThreadCreate(osThread(modbusTaskHandle), NULL);
	osThreadDef(loraTaskHandle, vRakTask, osPriorityNormal, 0, 128);
	loraTaskHandle = osThreadCreate(osThread(loraTaskHandle), NULL);
//	osThreadDef(envTaskHandle, vEnvTask, osPriorityNormal, 0, 128);
//	envTaskHandle = osThreadCreate(osThread(envTaskHandle), NULL);

	char *p= "\r\n NTT";
	while (1) {
		//HAL_UART_Transmit(&huart1,p,6,100);
		osDelay(5000);
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
//		osDelay(1000);
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
//		osDelay(1000);
	}
}

