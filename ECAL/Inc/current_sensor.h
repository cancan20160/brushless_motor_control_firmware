/*
 * current_sensor.h
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */

#ifndef INC_CURRENT_SENSOR_H_
#define INC_CURRENT_SENSOR_H_

#include <stdint.h>

void ecal_current_sensor_init(void);

void ecal_current_sensor_update(void);

float ecal_current_sensor_get_phase_current(void);

#endif /* INC_CURRENT_SENSOR_H_ */
