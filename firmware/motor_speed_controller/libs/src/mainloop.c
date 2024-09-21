/*
 * mainloop.c
 *
 *  Created on: Sep 18, 2024
 *      Author: nadil
 */

#include "mainloop.h"

float speed = 0.0;

void mainloop(){
	init();
	speed_set(-255);

	while (1)
	{
		speed = encoder_speed();
	}
}
