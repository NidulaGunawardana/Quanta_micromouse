/*
 * L3GD20.h
 *
 *  Created on: Sep 26, 2024
 *      Author: nadil
 */

#ifndef L3GD20_H_
#define L3GD20_H_

#include "led.h"
#include "typedefs.h"
#include <stdint.h>
#include "main.h"
#include "parameters_.h"
#include <math.h>

#define BUFFER_LENGTH ((u32)1000u)  // 1000u

extern float angle_z;
extern uint8_t gyro_identity;
extern float offset, noise;

// INITIALIZATION OF SPI COMMUNICATION AND CALIBRATION
void gyroInit(void);

// UPDATING ANGLE EVERY 2ms
int gyroUpdate(void);

// READING GYRO VALUE
int16_t readGyro(void);

// CALIBRATION IN THE BEGINNING
void gyroCalibration(void);

#endif /* L3GD20_H_ */
