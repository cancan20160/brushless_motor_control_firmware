/*
 * hall_sensor.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */

#ifndef INC_HALL_SENSOR_DRIVER_H_
#define INC_HALL_SENSOR_DRIVER_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    HALL_SECTOR_UNKNOWN = 0,
    HALL_SECTOR_1 = 1,
    HALL_SECTOR_2 = 2,
    HALL_SECTOR_3 = 3,
    HALL_SECTOR_4 = 4,
    HALL_SECTOR_5 = 5,
    HALL_SECTOR_6 = 6
} hall_sector_t;

void ecal_hall_sensor_init(void);

void ecal_hall_sensor_update(void);

hall_sector_t ecal_hall_sensor_get_sector(void);

uint8_t ecal_hall_sensor_get_raw_state(void);

bool ecal_hall_sensor_is_valid(void);

uint32_t ecal_hall_sensor_get_speed_rpm(void);

#endif /* INC_HALL_SENSOR_DRIVER_H_ */
