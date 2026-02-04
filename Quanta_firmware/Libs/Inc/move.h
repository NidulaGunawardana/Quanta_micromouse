/*
 * move.h
 *
 *  Created on: Sep 27, 2024
 *      Author: nadil
 */

#ifndef INC_MOVE_H_
#define INC_MOVE_H_

#include "main.h"
#include "motor.h"
#include "typedefs.h"
#include "encoder.h"
#include "L3GD20.h"
#include "parameters_.h"
#include "led.h"
#include "sensors.h"
#include <stdbool.h>

void turnToAngle(float angle);
//void turnToAngleEncoder(float angle);
float calculateDistance(uint32_t encoder_count);
void moveStraightForDistance(float target_distance);
void moveFirst_cell();
void alignAndMaintainDistance(float targetDistance);

int mstwoWalls();
int msleftWall();
int msrightWall();

extern bool F, L, R;

#endif /* INC_MOVE_H_ */
