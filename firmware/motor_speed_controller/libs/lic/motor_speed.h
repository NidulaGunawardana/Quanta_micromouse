/*
 * motor_speed.h
 *
 *  Created on: Sep 18, 2024
 *      Author: nadil
 */

#ifndef MOTOR_SPEED_H_
#define MOTOR_SPEED_H_

#include "main.h"
#include <stdlib.h>

void init();
void speed_set(int speed);
int get_encoder_reading();
float encoder_speed();
void print(const char* value);

#endif /* MOTOR_SPEED_H_ */
