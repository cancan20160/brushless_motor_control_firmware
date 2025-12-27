/*
 * direction.c
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */


#include "direction.h"
#include "hal_gpio.h"

static direction_t current_direction;

void direction_init(void)
{
    current_direction = DIRECTION_FORWARD;
}

void direction_update(void)
{
    if (hal_gpio_read_direction()) {
        current_direction = DIRECTION_FORWARD;
    } else {
        current_direction = DIRECTION_REVERSE;
    }
}

direction_t direction_get(void)
{
    return current_direction;
}

bool direction_is_forward(void)
{
    return (current_direction == DIRECTION_FORWARD);
}
