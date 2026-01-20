/*
 * pwm_driver.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */

#ifndef INC_PWM_DRIVER_H_
#define INC_PWM_DRIVER_H_

#include <stdint.h>

typedef enum {
    PWM_PHASE_U = 0,
    PWM_PHASE_V = 1,
    PWM_PHASE_W = 2
} pwm_phase_t;

void ecal_pwm_driver_init(void);

void ecal_pwm_driver_start(pwm_phase_t phase);

void ecal_pwm_driver_stop(pwm_phase_t phase);

void ecal_pwm_driver_set_duty_percent(pwm_phase_t phase, uint8_t duty_percent);

uint8_t ecal_pwm_driver_get_duty_percent(pwm_phase_t phase);

void ecal_pwm_driver_stop_all(void);

#endif /* INC_PWM_DRIVER_H_ */
