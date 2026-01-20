/*
 * hall_sensor.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */


#include "hall_sensor_driver.h"
#include "hal_gpio.h"
#include "hal_timer.h"

#define POLE_PAIRS 9
#define INVALID_SECTOR 0

static const hall_sector_t hall_lookup_table[8] = {
    HALL_SECTOR_UNKNOWN,  // 0b000
    HALL_SECTOR_4,        // 0b001
    HALL_SECTOR_2,        // 0b010
    HALL_SECTOR_3,        // 0b011
    HALL_SECTOR_6,        // 0b100
    HALL_SECTOR_5,        // 0b101
    HALL_SECTOR_1,        // 0b110
    HALL_SECTOR_UNKNOWN   // 0b111
};

static hall_sector_t current_sector;
static uint8_t raw_hall_state;
static uint32_t capture_value;
static uint32_t speed_rpm;

void ecal_hall_sensor_init(void)
{
    current_sector = HALL_SECTOR_UNKNOWN;
    raw_hall_state = 0;
    capture_value = 0;
    speed_rpm = 0;
}

void ecal_hall_sensor_update(void)
{
    raw_hall_state = hal_gpio_read_hall_sensors();
    current_sector = hall_lookup_table[raw_hall_state];

    capture_value = hal_timer2_get_capture_value();

    if (capture_value > 0) {
        uint32_t time_per_sector_us = capture_value;
        uint32_t time_per_revolution_us = time_per_sector_us * 6;

        speed_rpm = (60000000 / time_per_revolution_us) / POLE_PAIRS;
    } else {
        speed_rpm = 0;
    }
}

hall_sector_t ecal_hall_sensor_get_sector(void)
{
    return current_sector;
}

uint8_t ecal_hall_sensor_get_raw_state(void)
{
    return raw_hall_state;
}

bool ecal_hall_sensor_is_valid(void)
{
    return (current_sector != HALL_SECTOR_UNKNOWN);
}

uint32_t ecal_hall_sensor_get_speed_rpm(void)
{
    return speed_rpm;
}
