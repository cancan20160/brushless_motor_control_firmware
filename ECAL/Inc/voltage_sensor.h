/*
 * voltage_sensor.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */

#ifndef INC_VOLTAGE_SENSOR_H_
#define INC_VOLTAGE_SENSOR_H_

#include <stdint.h>

void ecal_voltage_sensor_init(void);

void ecal_voltage_sensor_update(void);

float ecal_voltage_sensor_get_vbus(void);

#endif /* INC_VOLTAGE_SENSOR_H_ */
