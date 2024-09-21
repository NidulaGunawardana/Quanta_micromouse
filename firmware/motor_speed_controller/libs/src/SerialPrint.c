/*
 * SerialPrint.c
 *
 *  Created on: Sep 19, 2024
 *      Author: nadil
 */

#include "SerialPrint.h"

void print(const char* value) {
    char buffer[100]; // Adjust size based on your needs
    sprintf(buffer, "%s", value); // Use %s to format the string

    HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
}
