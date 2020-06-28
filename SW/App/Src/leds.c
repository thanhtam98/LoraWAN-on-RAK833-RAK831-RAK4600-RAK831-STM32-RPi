#include "leds.h"
#include "main.h"
#include "cmsis_os.h"
#include "app.h"



void v_led_controller(uint8_t led_num, uint8_t led_state)
{
/*--Add mapping array if the led total is more than 4*/

	switch (led_num)
	{
	case 0:
		HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, (FlagStatus)led_state);
		break;
	case 1:
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, (FlagStatus)led_state);
		break;
	case 2:
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, (FlagStatus)led_state);
		break;
	case 3:
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, (FlagStatus)led_state);
		break;
	default:
		HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_3_Pin|LED_2_Pin|LED_1_Pin|LED_0_Pin, (FlagStatus)led_state);

	}
}


/*
 * Brief: Callback function for led execution
 *
 * **/
void v_led_process_callback(const void *arg)
{

	while(10);
}



vLedTask(const void *arg)
{
	/* Global struct mapping */
	iot_node_t *px_iot_node_handle = (iot_node_t*) arg;

	/*
	 * Create led instance and set default values
	 * */
	led_control_update led_control_update[LED_MAX_NUM];
	for(uint8_t led_index =0; led_index < LED_MAX_NUM; led_index++)
	{
		led_control_update[led_index].is_update = NONE;
		led_control_update[led_index].led_control.led_num = led_index;
		led_control_update[led_index].led_control.led_freq = 0;
		led_control_update[led_index].led_control.led_state = LED_OFF;
		led_control_update[led_index].led_control.led_timeout = 0;
	}
	/*HW init*/

	/*SW timmer init*/
	osTimerDef(ledTimer,v_led_process_callback);
	osTimerId ledTimerHandle = osTimerCreate(osTimer(ledTimer), osTimerPeriodic, (void*)led_control_update);
	osTimerStart(ledTimerHandle, LED_UPDATE_INTERVAL_MS);

	while (1){

		/* Take the queue */

		/* Update to callback*/
	}
}
