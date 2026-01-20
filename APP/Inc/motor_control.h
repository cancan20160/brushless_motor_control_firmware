/*
 * motor_control.h
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */

#ifndef INC_MOTOR_CONTROL_H_
#define INC_MOTOR_CONTROL_H_

#include <stdint.h>

void app_motor_control_init(void);

void app_motor_control_task(void);

void app_motor_control_hall_interrupt_callback(void);

void app_motor_control_brake_interrupt_callback(void);

void app_motor_control_direction_interrupt_callback(void);

#endif /* INC_MOTOR_CONTROL_H_ */
