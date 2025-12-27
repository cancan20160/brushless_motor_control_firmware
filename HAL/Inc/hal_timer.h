/*
 * hal_timer.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */

#ifndef INC_HAL_TIMER_H_
#define INC_HAL_TIMER_H_

#include <stdint.h>

#define HAL_PWM_CH_U  0
#define HAL_PWM_CH_V  1
#define HAL_PWM_CH_W  2
#define HAL_PWM_CH_COUNT 3

void hal_timer1_pwm_init(void);

void hal_timer1_pwm_start(uint8_t channel);

void hal_timer1_pwm_stop(uint8_t channel);

void hal_timer1_set_duty(uint8_t channel, uint16_t duty);

uint16_t hal_timer1_get_duty(uint8_t channel);

void hal_timer1_set_arr(uint16_t arr);

uint16_t hal_timer1_get_arr(void);

void hal_timer2_input_capture_init(void);

void hal_timer2_input_capture_start(void);

void hal_timer2_input_capture_stop(void);

uint32_t hal_timer2_get_capture_value(void);

#endif /* INC_HAL_TIMER_H_ */
