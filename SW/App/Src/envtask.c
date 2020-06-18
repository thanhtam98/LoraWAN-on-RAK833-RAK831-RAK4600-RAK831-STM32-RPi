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

/* Shared variables ---------------------------------------------------------*/
//extern ADC_HandleTypeDef hadc1;

/* Start Implementation -----------------------------*/

void vEnvTask(void const *arg)
{
	uint32_t adcRead1;
	uint32_t adcRead2;
	uint32_t temperature;
	float vsense = 3.3/1023;
	float 	temp;
	HAL_ADC_Start(&hadc1);
	DHT11_DATA_TypeDef DHT_DATA;
	while(1)
	{
//		delay_us(1000000);

		HAL_ADC_Start(&hadc1);
		osDelay(1200);
		HAL_ADC_PollForConversion(&hadc1, 100);
		adcRead1 = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop (&hadc1);
		DHT11_ReadData(&DHT_DATA);
		uiMemSet(FUNC_READ_LIGH_ADR, adcRead1);
		uiMemSet(FUNC_READ_TEMP_ADR, DHT_DATA.temp_int);
		uiMemSet(FUNC_READ_HUMD_ADR, DHT_DATA.humi_int);

	}

}
void ControlTask(void const *arg)
{
	uint8_t temp;
	while(1)
	{
		temp = uiMemGet(FUNC_WRITE_SPEK_ADR);
	//	HAL_GPIO_WritePin(GPIO_SPEAKER_GPIO_Port, GPIO_SPEAKER_Pin, temp);
		osDelay(10);
	}
}
