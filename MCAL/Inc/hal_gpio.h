/*
 * hal_gpio.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */

#ifndef INC_HAL_GPIO_H_
#define INC_HAL_GPIO_H_

#include <stdint.h>
#include <stdbool.h>

void hal_gpio_init(void);

uint8_t hal_gpio_read_hall_sensors(void);

bool hal_gpio_read_brake(void);

bool hal_gpio_read_direction(void);

#endif /* INC_HAL_GPIO_H_ */
