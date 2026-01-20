/*
 * temperature.sensor.h
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */

#ifndef INC_TEMPERATURE_SENSOR_H_
#define INC_TEMPERATURE_SENSOR_H_

#include <stdint.h>

void ecal_temperature_sensor_init(void);

void ecal_temperature_sensor_update(void);

float ecal_temperature_sensor_get_mosfet_temp(void);

float ecal_temperature_sensor_get_motor_temp(void);

#endif /* INC_TEMPERATURE_SENSOR_H_ */
