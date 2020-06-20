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
#include "main.h"
#include "gpio.h"
#include "app.h"
#include "dht.h"
#include "rak.h"
#include "mbtask.h"
#include "envtask.h"
#include "sharedmem.h"
#include "param.h"
#include "i2c.h"
#include "command.h"
/**/
osThreadId modbusTaskHandle;
osThreadId loraTaskHandle;
osThreadId envTaskHandle;
osThreadId cmdTaskHandle;

void vAppDefault(void) {

	/*Task initialization*/

	osThreadDef(loraTaskHandle, vRakTask, osPriorityNormal, 0, 128);
	loraTaskHandle = osThreadCreate(osThread(loraTaskHandle), NULL);
	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());

	osThreadDef(modbusTaskHandle, vModBusTask, osPriorityNormal, 0, 256);
	modbusTaskHandle = osThreadCreate(osThread(modbusTaskHandle), NULL);
	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());

	osThreadDef(envTaskHandle, vEnvTask, osPriorityNormal, 0, 512);
	envTaskHandle = osThreadCreate(osThread(envTaskHandle), NULL);

	osThreadDef(cmdTaskHandle, vCmdTask, osPriorityNormal, 0, 256);
	cmdTaskHandle = osThreadCreate(osThread(cmdTaskHandle), NULL);
	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());

	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());

	osDelay(1000);
	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());

	char *p = "\r\n NTT";
	DHT11_DATA_TypeDef DHT_DATA;
	char send[30] = { 10, 20, 30, 40, 50, 60, 50, 45, 44, 43, 45, 22, 33, 44,
			88, 77, 55, 66, 66, 55, 88, 11, 55 };
	char recv[30];
	while (1) {
//		DBG("Write value %c \r\n",send);
//		while (HAL_I2C_Mem_Write(&hi2c1, (uint16_t) 0xa0, (uint16_t) 0x00,
//				I2C_MEMADD_SIZE_8BIT,(uint8_t*) send, 10, 1000) != HAL_OK) {
//			DBG("Write Error \r\n");
//			MX_I2C1_Init();
//			osDelay(1000);
//		}
//
//		DBG("Write complete \r\n");
//		osDelay(1000);
////		taskENTER_CRITICAL();
//		while (HAL_I2C_Mem_Read(&hi2c1, (uint16_t) 0xA0, (uint16_t) 0x2,
//				I2C_MEMADD_SIZE_8BIT, (uint8_t*) recv, (uint16_t)10, 1000)
//				!= HAL_OK) {
//			DBG("Read Error \r\n");
//			osDelay(1000);
//			//NVIC_SystemReset();
//		}
////		taskEXIT_CRITICAL();
//		DBG("Read complete \r\n");
//		for (uint8_t i = 0; i < 20; i++ )
//		{
//			DBG("Read value %d %d  \r\n",i,recv[i]);
//		}
////		DBG("Read value %d %d %d \r\n",recv[0],recv[1],recv[2],recv[3],recv[4],recv[5]);
		DBG("\r\nMemFree:%d", xPortGetFreeHeapSize());
		osDelay(1000);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	}
}

void vAppConfiguration(void) {

	while (1) {

	};
	/* Reset system to apply */
	u_mem_set(NODE_HAVE_PARAM_ADR, 1);

	NVIC_SystemReset();
}
