/*
 * led.c
 *
 *  Created on: Sep 26, 2024
 *      Author: nidul
 */

#include "led.h"

void centerLED() {
	int speed = 90;

	LED1_ON;
	HAL_Delay(speed);
	;
	LED2_ON;
	HAL_Delay(speed);

	LED3_ON;
	HAL_Delay(speed);

	LED4_ON;
	HAL_Delay(speed);

	LED5_ON;
	HAL_Delay(speed);

	LED6_ON;
	HAL_Delay(speed);

	LED7_ON;
	HAL_Delay(speed);

	LED8_ON;
	HAL_Delay(speed);

	LED9_ON;
	HAL_Delay(speed);

	LED10_ON;
	HAL_Delay(speed);

	LED11_ON;
	HAL_Delay(speed);


	HAL_Delay(500);

	LED11_OFF;
	HAL_Delay(speed);

	LED10_OFF;
	HAL_Delay(speed);

	LED9_OFF;
	HAL_Delay(speed);

	LED8_OFF;
	HAL_Delay(speed);

	LED7_OFF;
	HAL_Delay(speed);

	LED6_OFF;
	HAL_Delay(speed);

	LED5_OFF;
	HAL_Delay(speed);

	LED4_OFF;
	HAL_Delay(speed);

	LED3_OFF;
	HAL_Delay(speed);

	LED2_OFF;
	HAL_Delay(speed);

	LED1_OFF;
	HAL_Delay(speed);

}
