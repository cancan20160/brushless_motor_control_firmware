/*
 * direction.c
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */


#include "direction.h"
#include "hal_gpio.h"

static direction_t current_direction;

void ecal_direction_init(void)
{
    current_direction = DIRECTION_FORWARD;
}

void ecal_direction_update(void)
{
    if (hal_gpio_read_direction()) {
        current_direction = DIRECTION_FORWARD;
    } else {
        current_direction = DIRECTION_REVERSE;
    }
}

direction_t ecal_direction_get(void)
{
    return current_direction;
}

bool ecal_direction_is_forward(void)
{
    return (current_direction == DIRECTION_FORWARD);
}
