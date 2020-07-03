/* Built-in C library includes ----------------------*/

#include <stdio.h>
#include <stdint.h>
#include "cmsis_os.h"
/* Platform includes --------------------------------*/
#include "main.h"
#include "sharedmem.h"
#include "envtask.h"
#include "dht.h"
#include  "adc.h"
#include "gpio.h"
#include "param.h"
#include "ds18b20.h"
#include "tim.h"
#include "timers.h"
/*Timer */
#define ENV_TIME_INTERVAL  10
osTimerId envTimerHandler;

/* Shared variables ---------------------------------------------------------*/
//extern ADC_HandleTypeDef hadc1;
io_port_t ioPort[IO_MAX_PORT];
uint8_t ubSequenceCompleted = RESET;
__IO uint16_t aADCxConvertedValues[2];
/* Start Implementation -----------------------------*/
/**/

void vPortRawRead(uint32_t *portData) {

	/* Port0 ------------*/
	portData[PORT0] = HAL_GPIO_ReadPin(SW_1_GPIO_Port, SW_1_Pin);
	/* Port1 ------------*/
	portData[PORT1] = HAL_GPIO_ReadPin(SW_2_GPIO_Port, SW_2_Pin);
	/* Port2 ------------*/
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);
	portData[PORT2] = HAL_ADC_GetValue(&hadc1);

	/* Port3 ------------*/

	HAL_ADC_PollForConversion(&hadc1, 100);
	portData[PORT3] = HAL_ADC_GetValue(&hadc1);

	HAL_ADC_Stop(&hadc1);
	/* Port4 ------------*/
//	portData[PORT4] = TIM3->CNT;
//	TIM3->CNT = 0;
	portData[PORT4] = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_3);
	htim3.Instance->CCR2 = 0;

	/* Port5----------------**/
	DBG("Raw data: %d %d %d %d %d", portData[PORT0], portData[PORT1],
			portData[PORT2], portData[PORT3], portData[PORT4]);
//	DHT11_DATA_TypeDef DHT_DATA;
//	DHT11_ReadData(&DHT_DATA);
//	portData[PORT5] = DHT_DATA.temp_int;

}
void vPortProcess(uint32_t *portData) {

	for (uint8_t portIndex = 0; portIndex < IO_MAX_PORT; portIndex++) {
		switch (ioPort[portIndex].profile) {
		case IO_SW_NC:
			uiMemSet(ioPort[portIndex].mbAdr,
					(portData[portIndex] == RESET) ? SET : RESET);
			break;
		case IO_SW_NO:
			uiMemSet(ioPort[portIndex].mbAdr,
					(portData[portIndex] == RESET) ? RESET : SET);
			break;
		case IO_PUL_PER_SEC:
			uiMemSet(ioPort[portIndex].mbAdr,
					(uint16_t) ((portData[portIndex] / ENV_TIME_INTERVAL) << 8)
							| 0x0000);
			break;
		case IO_PUL_PER_MIN:
			uiMemSet(ioPort[portIndex].mbAdr,
					(uint16_t) ((60 * portData[portIndex] / ENV_TIME_INTERVAL)
							<< 8) | 0x0000);
			break;
		case IO_PUL_PER_HOUR:
			uiMemSet(ioPort[portIndex].mbAdr,
					(uint16_t) ((60 * 60 * portData[portIndex]
							/ ENV_TIME_INTERVAL) << 8) | 0x0000);
			break;
		case IO_ADC_LIGHT:
			uiMemSet(ioPort[portIndex].mbAdr, (uint16_t) portData[portIndex]);

			break;
		case IO_ADC_TEMP:
			uiMemSet(ioPort[portIndex].mbAdr, (uint16_t) portData[portIndex]);
			break;
		case IO_ADC_HUMID:
			uiMemSet(ioPort[portIndex].mbAdr, (uint16_t) portData[portIndex]);
			break;
		case IO_ONEWIRE_DHT11:
			uiMemSet(ioPort[portIndex].mbAdr, (uint16_t) portData[portIndex]);

			break;
		case IO_ONEWIRE_DHT22:
			uiMemSet(ioPort[portIndex].mbAdr, (uint16_t) portData[portIndex]);

			break;
		case IO_ONWWIRE_DS18B20:
			uiMemSet(ioPort[portIndex].mbAdr, (uint16_t) portData[portIndex]);

			break;
		}

	}
}

void vEnvTimerCallback(void const *arg) {
	uint32_t *pxArg = (uint32_t) arg;
	vPortRawRead(pxArg);
	//vPortProcess(pxArg);

}
void vEnvTask(void const *arg) {
	/*
	 * Initial ports if configured
	 * **/

	if (PARAM[NODE_HAVE_PARAM_ADR] == 1) {
		for (uint8_t portIndex = 0; portIndex < IO_MAX_PORT; portIndex++) {
			ioPort[portIndex].profile = u_mem_get(NODE_IO_BASE + portIndex * 2);
			ioPort[portIndex].mbAdr = u_mem_get(
			NODE_IO_BASE + portIndex * 2 + 1);
		}
	} else {

		/*Us*/
	}

	uint32_t temperature;
//	DHT11_DATA_TypeDef DHT_DATA;
	uint32_t u32portRawData[IO_MAX_PORT];
	HAL_TIM_IC_Start(&htim3, TIM_CHANNEL_3);

//	if (HAL_ADC_Start_DMA(&hadc1, (uint32_t *) aADCxConvertedValues, 2)
//			!= HAL_OK) {
////		/* Start Error */
//		Error_Handler();
//	}

//	envTimerHandler = osTimerCreate(vEnvTimerCallback, osTimerPeriodic,
//			u32portRawData);
//	osTimerStart(envTimerHandler, ENV_TIME_INTERVAL * 1000);
	while (1) {
		vEnvTimerCallback(u32portRawData);
		osDelay(1000);
		/* */
//		vPortRawRead(u32portRawData);
//		delay_us(1000000);
//		HAL_ADC_Start(&hadc1);
//		osDelay(1200);
//		HAL_ADC_PollForConversion(&hadc1, 100);
//		adcRead1 = HAL_ADC_GetValue(&hadc1);
//		HAL_ADC_Stop (&hadc1);
//		DHT11_ReadData(&DHT_DATA);
////		uiMemSet(FUNC_READ_LIGH_ADR, adcRead1);
//		uiMemSet(FUNC_READ_TEMP_ADR, DHT_DATA.temp_int);
//		uiMemSet(FUNC_READ_HUMD_ADR, DHT_DATA.humi_int);
	}

}
void ControlTask(void const *arg) {
	uint8_t temp;
	while (1) {
		temp = uiMemGet(FUNC_WRITE_SPEK_ADR);
		//	HAL_GPIO_WritePin(GPIO_SPEAKER_GPIO_Port, GPIO_SPEAKER_Pin, temp);
		osDelay(10);
	}
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *AdcHandle) {
	/* Report to main program that ADC sequencer has reached its end */
	ubSequenceCompleted = SET;
}
