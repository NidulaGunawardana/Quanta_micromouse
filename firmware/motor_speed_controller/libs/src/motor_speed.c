/*
 * motor_speed.c
 *
 *  Created on: Sep 18, 2024
 *      Author: nadil
 */

#include "motor_speed.h"

#include <stdlib.h>

char buffer[50];  // Buffer to store the string to be transmitted
const int enc_res = 65535;

void init(){
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
	__HAL_RCC_GPIOA_CLK_ENABLE();
}

void speed_set(int speed){

	if (abs(speed)>255){
		speed = 255*(speed/abs(speed)); // Set the speed to the maximum value with the relevant sign
	}

	if (speed>0){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); // IN1 = 1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // IN2 = 0
	}
	else{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); // IN1 = 0
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); // IN2 = 1
	}

	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, speed);
}

int get_encoder_reading(){
	int encoder_value = __HAL_TIM_GET_COUNTER(&htim3);
	return encoder_value;
}

float encoder_speed() {
    uint16_t start_count = get_encoder_reading();
    uint32_t start_time = HAL_GetTick();

    uint32_t time_taken = 0;
    uint32_t current_time = 0;
    uint16_t current_count = 0;

    while (1) {
        current_count = get_encoder_reading();  // Update the current count

        // Handle potential encoder count wrap-around
        if (abs(current_count - start_count) > enc_res/2) {
            continue;  // Skip if the count difference is invalid
        }

        if (abs(current_count - start_count) >= 100) {  // Check if count difference threshold is met
            current_time = HAL_GetTick();  // Record the time when count threshold is reached
            time_taken = current_time - start_time;  // Calculate the time taken in milliseconds
            break;  // Exit the loop
        }
    }

    // Ensure time_taken is not zero to avoid division by zero
    if (time_taken == 0) {
        return 0.0f;  // Return zero speed if no time has elapsed
    }

    // Calculate speed in counts per second
    float speed = ((float)(current_count - start_count)) / ((float)time_taken/ 1000.0);

    speed = speed/810.0; // Revolutions per second

    return speed;
}

