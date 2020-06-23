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
	HAL_ADC_PollForConversion(&hadc1, 1);
	if (ubSequenceCompleted != RESET) {
		ubSequenceCompleted = RESET;

		portData[PORT2] = aADCxConvertedValues[0];


		/* Port3 ------------*/
		portData[PORT3] = aADCxConvertedValues[1];

	}

	/* Port4 ------------*/
	portData[PORT4] = TIM3 -> CNT;





}
void vPortProcess(uint32_t *portData)
{

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
	DHT11_DATA_TypeDef DHT_DATA;
	uint32_t u32portRawData[IO_MAX_PORT];
	if (HAL_ADC_Start_DMA(&hadc1, (uint32_t *) aADCxConvertedValues, 2)
			!= HAL_OK) {
		/* Start Error */
		Error_Handler();
	}

	while (1) {
		vPortRawRead(u32portRawData);


//		delay_us(1000000);

//		HAL_ADC_Start(&hadc1);
		osDelay(1200);
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
