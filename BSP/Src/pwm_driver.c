/*
 * pwm_driver.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */


#include "pwm_driver.h"
#include "hal_timer.h"

#define PWM_MAX_DUTY_PERCENT 100

static uint8_t duty_percent[3] = {0, 0, 0};

void pwm_driver_init(void)
{
    duty_percent[PWM_PHASE_U] = 0;
    duty_percent[PWM_PHASE_V] = 0;
    duty_percent[PWM_PHASE_W] = 0;
}

void pwm_driver_start(pwm_phase_t phase)
{
    if (phase > PWM_PHASE_W) {
        return;
    }

    hal_timer1_pwm_start(phase);
}

void pwm_driver_stop(pwm_phase_t phase)
{
    if (phase > PWM_PHASE_W) {
        return;
    }

    hal_timer1_pwm_stop(phase);
}

void pwm_driver_set_duty_percent(pwm_phase_t phase, uint8_t duty_pct)
{
    if (phase > PWM_PHASE_W) {
        return;
    }

    if (duty_pct > PWM_MAX_DUTY_PERCENT) {
        duty_pct = PWM_MAX_DUTY_PERCENT;
    }

    duty_percent[phase] = duty_pct;

    uint16_t arr = hal_timer1_get_arr();
    uint16_t duty_value = (uint16_t)((arr * duty_pct) / 100);

    hal_timer1_set_duty(phase, duty_value);
}

uint8_t pwm_driver_get_duty_percent(pwm_phase_t phase)
{
    if (phase > PWM_PHASE_W) {
        return 0;
    }

    return duty_percent[phase];
}

void pwm_driver_stop_all(void)
{
    pwm_driver_stop(PWM_PHASE_U);
    pwm_driver_stop(PWM_PHASE_V);
    pwm_driver_stop(PWM_PHASE_W);

    pwm_driver_set_duty_percent(PWM_PHASE_U, 0);
    pwm_driver_set_duty_percent(PWM_PHASE_V, 0);
    pwm_driver_set_duty_percent(PWM_PHASE_W, 0);
}
