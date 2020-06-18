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
#include "sharedmem.h"
/**/
osThreadId modbusTaskHandle;
osThreadId loraTaskHandle;
osThreadId envTaskHandle;

void vAppDefault(void) {

	/*Task initialization*/

	osThreadDef(loraTaskHandle, vRakTask, osPriorityNormal, 0, 128);
	loraTaskHandle = osThreadCreate(osThread(loraTaskHandle), NULL);
	printf("\r\n MemFree: %d", xPortGetFreeHeapSize());

	osThreadDef(modbusTaskHandle, vModBusTask, osPriorityNormal, 0, 256);
	modbusTaskHandle = osThreadCreate(osThread(modbusTaskHandle), NULL);
	printf("\r\n MemFree: %d", xPortGetFreeHeapSize());

	osThreadDef(envTaskHandle, vEnvTask, osPriorityNormal, 0, 512);
	envTaskHandle = osThreadCreate(osThread(envTaskHandle), NULL);

	printf("\r\n MemFree: %d", xPortGetFreeHeapSize());

	osDelay(1000);
	printf("\r\n MemFree: %d", xPortGetFreeHeapSize());

	char *p = "\r\n NTT";
	DHT11_DATA_TypeDef DHT_DATA;
	while (1) {
		printf("\r\nMemFree:%d", xPortGetFreeHeapSize());
		osDelay(1000);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	}
}

