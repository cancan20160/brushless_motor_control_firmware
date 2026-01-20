/*
 * brake.c
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */


#include "brake.h"
#include "hal_gpio.h"

static bool brake_pressed;

void ecal_brake_init(void)
{
    brake_pressed = false;
}

void ecal_brake_update(void)
{
    brake_pressed = !hal_gpio_read_brake();
}

bool ecal_brake_is_pressed(void)
{
    return brake_pressed;
}
