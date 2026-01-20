/*
 * hal_timer.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */


#include "hal_timer.h"
#include "tim.h"

static uint16_t pwm_duty[HAL_PWM_CH_COUNT] = {0};

void hal_timer1_pwm_init(void)
{
	MX_TIM1_Init();
}

void hal_timer1_pwm_start(uint8_t channel)
{
    if (channel >= HAL_PWM_CH_COUNT) {
        return;
    }

    switch (channel) {
        case HAL_PWM_CH_U:
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
            HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
            break;
        case HAL_PWM_CH_V:
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
            HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
            break;
        case HAL_PWM_CH_W:
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
            HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
            break;
    }
}

void hal_timer1_pwm_stop(uint8_t channel)
{
    if (channel >= HAL_PWM_CH_COUNT) {
        return;
    }

    switch (channel) {
        case HAL_PWM_CH_U:
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
            HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
            break;
        case HAL_PWM_CH_V:
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
            break;
        case HAL_PWM_CH_W:
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
            HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);
            break;
    }
}

void hal_timer1_set_duty(uint8_t channel, uint16_t duty)
{
    if (channel >= HAL_PWM_CH_COUNT) {
        return;
    }

    pwm_duty[channel] = duty;

    switch (channel) {
        case HAL_PWM_CH_U:
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, duty);
            break;
        case HAL_PWM_CH_V:
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, duty);
            break;
        case HAL_PWM_CH_W:
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, duty);
            break;
    }
}

uint16_t hal_timer1_get_duty(uint8_t channel)
{
    if (channel < HAL_PWM_CH_COUNT) {
        return pwm_duty[channel];
    }
    return 0;
}

void hal_timer1_set_arr(uint16_t arr)
{
    __HAL_TIM_SET_AUTORELOAD(&htim1, arr);
}

uint16_t hal_timer1_get_arr(void)
{
    return __HAL_TIM_GET_AUTORELOAD(&htim1);
}

void hal_timer2_input_capture_init(void)
{
	MX_TIM2_Init();
}

void hal_timer2_input_capture_start(void)
{
    HAL_TIMEx_HallSensor_Start_IT(&htim2);
}

void hal_timer2_input_capture_stop(void)
{
    HAL_TIMEx_HallSensor_Stop_IT(&htim2);
}

uint32_t hal_timer2_get_capture_value(void)
{
    return HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
}
