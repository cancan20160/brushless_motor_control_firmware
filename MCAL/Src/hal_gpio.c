/*
 * hal_gpio.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */


#include "hal_gpio.h"
#include "gpio.h"

void hal_gpio_init(void) {
	MX_GPIO_Init();
}

uint8_t hal_gpio_read_hall_sensors(void) {
	uint8_t hall_state = 0U;
	hall_state |= HAL_GPIO_ReadPin(HALL_SENSOR_U_GPIO_Port, HALL_SENSOR_U_Pin) << 2;
	hall_state |= HAL_GPIO_ReadPin(HALL_SENSOR_V_GPIO_Port, HALL_SENSOR_V_Pin) << 1;
	hall_state |= HAL_GPIO_ReadPin(HALL_SENSOR_W_GPIO_Port, HALL_SENSOR_W_Pin) << 0;

	return hall_state & 0x07U;
}

bool hal_gpio_read_brake(void) {
	return HAL_GPIO_ReadPin(BRAKE_BUTTON_GPIO_Port, BRAKE_BUTTON_Pin);
}

bool hal_gpio_read_direction(void) {
	return HAL_GPIO_ReadPin(DIRECTION_BUTTON_GPIO_Port, DIRECTION_BUTTON_Pin);
}
