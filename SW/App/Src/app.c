/*
 * Brief: Default app folked from rtos default task
 *
 *
 *
 *
 * */

#include "app.h"
/**/
osThreadId modbusTaskHandle;
osThreadId loraTaskHandle;
osThreadId envTaskHandle;
osThreadId cmdTaskHandle;
//osMessageQId btnQueueHandle;

void vAppDefault(void) {

	/*Struct information*/
	iot_node_t iot_node_handle;

	/*Queue initialization**/
	osMessageQDef(btnQueue,1,sw_data_t);
	iot_node_handle.btnQueueHandle =  osMessageCreate(osMessageQ(btnQueue), NULL);
	osMessageQDef(ledQueue,1,led_control_t);
	iot_node_handle.ledQueueHandle = osMessageCreate(osMessageQ(ledQueue), NULL);
//	iot_node.envQueueHandle
	/*Task initialization*/

//	osThreadDef(loraTaskHandle, vRakTask, osPriorityNormal, 0, 256);
//	loraTaskHandle = osThreadCreate(osThread(loraTaskHandle), (void*)&iot_node_handle);
	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());
	osThreadDef(modbusTaskHandle, vModBusTask, osPriorityNormal, 0, 256);
	modbusTaskHandle = osThreadCreate(osThread(modbusTaskHandle), (void*)&iot_node_handle);
	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());
//	osThreadDef(envTaskHandle, vEnvTask, osPriorityNormal, 0, 512);
//	envTaskHandle = osThreadCreate(osThread(envTaskHandle), (void*)&iot_node_handle);
	osThreadDef(cmdTaskHandle, vCmdTask, osPriorityNormal, 0, 256);
	cmdTaskHandle = osThreadCreate(osThread(cmdTaskHandle), (void*)&iot_node_handle);
	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());

	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());

	osDelay(1000);
	DBG("\r\n MemFree: %d", xPortGetFreeHeapSize());

	char *p = "\r\n NTT";
	DHT11_DATA_TypeDef DHT_DATA;
	char send[30] = { 10, 20, 30, 40, 50, 60, 50, 45, 44, 43, 45, 22, 33, 44,
			88, 77, 55, 66, 66, 55, 88, 11, 55 };
	char recv[30];
//	__HAL_RCC_I2C1_FORCE_RESET();
//				HAL_Delay(1000);
//				__HAL_RCC_I2C1_RELEASE_RESET();
	float dtemp=0;
	while (1) {
		dtemp = f_ds18b20();
		DBG("\r\n Temp: %.2f \r\n",dtemp);
//		if (HAL_I2C_IsDeviceReady(&hi2c1, 0xA0, 2, 100)==HAL_OK)
//		{
//			DBG("EEPROM ready \r\n/");
//		}
//		else {
//
//			DBG("EEPROM not ready \r\n");
//		}
////		DBG("Write value %c \r\n",send);
//		while (HAL_I2C_Mem_Write(&hi2c1, (uint16_t) 0xa0, (uint16_t) 0x02,
//				I2C_MEMADD_SIZE_8BIT, (uint8_t*) send, 16, 1000) != HAL_OK) {
//			DBG("Write Error \r\n");
//			HAL_I2C_ClearBusyFlagErrata_2_14_7(&hi2c1);
////			MX_I2C1_Init();
//			osDelay(1000);
//		}
////
//		DBG("Write complete \r\n");
//		osDelay(1000);
//////		taskENTER_CRITICAL();
//		while (HAL_I2C_Mem_Read(&hi2c1, (uint16_t) 0xA0, (uint16_t) 0x2,
//				I2C_MEMADD_SIZE_8BIT, (uint8_t*) recv, (uint16_t) 16, 1000) != HAL_OK) {
//			DBG("Read Error \r\n");
//			osDelay(1000);
////			//NVIC_SystemReset();
//	}
////		taskEXIT_CRITICAL();
//		DBG("Read complete \r\n");
//		for (uint8_t i = 0; i < 20; i++) {
//			DBG("Read value %d %d  \r\n", i, recv[i]);
//		}
////		DBG("Read value %d %d %d \r\n",recv[0],recv[1],recv[2],recv[3],recv[4],recv[5]);
//	DBG("\r\n MemFree:%d", xPortGetFreeHeapSize());
	osDelay(1000);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	osDelay(1000);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);
	osDelay(1000);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
	osDelay(1000);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);

	}
}

void vAppConfiguration(void) {

while (1) {

};
/* Reset system to apply */
u_mem_set(NODE_HAVE_PARAM_ADR, 1);

NVIC_SystemReset();
}
//void vHwI2cResetManual(void)
//{
//
//}
void HAL_GPIO_WRITE_ODR(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
/* Check the parameters */
assert_param(IS_GPIO_PIN(GPIO_Pin));

GPIOx->ODR |= GPIO_Pin;
}
void HAL_I2C_ClearBusyFlagErrata_2_14_7(I2C_HandleTypeDef *hi2c) {

static uint8_t resetTried = 0;
if (resetTried == 1) {
	return;
}
uint32_t SDA_PIN = GPIO_PIN_9;
uint32_t SCL_PIN = GPIO_PIN_8;
GPIO_InitTypeDef GPIO_InitStruct;

// 1
__HAL_I2C_DISABLE(hi2c);

// 2
GPIO_InitStruct.Pin = SDA_PIN | SCL_PIN;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
GPIO_InitStruct.Pull = GPIO_NOPULL;
GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

HAL_GPIO_WRITE_ODR(GPIOB, SDA_PIN);
HAL_GPIO_WRITE_ODR(GPIOB, SCL_PIN);

// 3
GPIO_PinState pinState;
if (HAL_GPIO_ReadPin(GPIOB, SDA_PIN) == GPIO_PIN_RESET) {
	for (;;) {
	}
}
if (HAL_GPIO_ReadPin(GPIOB, SCL_PIN) == GPIO_PIN_RESET) {
	for (;;) {
	}
}

// 4
GPIO_InitStruct.Pin = SDA_PIN;
HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

HAL_GPIO_TogglePin(GPIOB, SDA_PIN);

// 5
if (HAL_GPIO_ReadPin(GPIOB, SDA_PIN) == GPIO_PIN_SET) {
	for (;;) {
	}
}

// 6
GPIO_InitStruct.Pin = SCL_PIN;
HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

HAL_GPIO_TogglePin(GPIOB, SCL_PIN);

// 7
if (HAL_GPIO_ReadPin(GPIOB, SCL_PIN) == GPIO_PIN_SET) {
	for (;;) {
	}
}

// 8
GPIO_InitStruct.Pin = SDA_PIN;
HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

HAL_GPIO_WRITE_ODR(GPIOB, SDA_PIN);

// 9
if (HAL_GPIO_ReadPin(GPIOB, SDA_PIN) == GPIO_PIN_RESET) {
	for (;;) {
	}
}

// 10
GPIO_InitStruct.Pin = SCL_PIN;
HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

HAL_GPIO_WRITE_ODR(GPIOB, SCL_PIN);

// 11
if (HAL_GPIO_ReadPin(GPIOB, SCL_PIN) == GPIO_PIN_RESET) {
	for (;;) {
	}
}

// 12
GPIO_InitStruct.Pin = SDA_PIN | SCL_PIN;
GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
//    GPIO_InitStruct.Alternate = NUCLEO_I2C_EXPBD_SCL_SDA_AF;
HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

// 13
hi2c->Instance->CR1 |= I2C_CR1_SWRST;

// 14
hi2c->Instance->CR1 ^= I2C_CR1_SWRST;

// 15
__HAL_I2C_ENABLE(hi2c);

resetTried = 1;
}

