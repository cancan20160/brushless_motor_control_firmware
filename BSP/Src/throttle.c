/*
 * throttle.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */


#include "throttle.h"
#include "hal_adc.h"

#define THROTTLE_ADC_MIN      200
#define THROTTLE_ADC_MAX      4000
#define THROTTLE_DEADZONE     50

static uint8_t throttle_percent;

void throttle_init(void)
{
    throttle_percent = 0;
}

void throttle_update(void)
{
    uint16_t adc_value = (uint16_t)hal_adc2_get_raw_value(HAL_ADC2_CH_THROTTLE);

    if (adc_value < THROTTLE_ADC_MIN + THROTTLE_DEADZONE) {
        throttle_percent = 0;
        return;
    }

    if (adc_value > THROTTLE_ADC_MAX) {
        throttle_percent = 100;
        return;
    }

    uint32_t range = THROTTLE_ADC_MAX - THROTTLE_ADC_MIN;
    uint32_t value = adc_value - THROTTLE_ADC_MIN;

    throttle_percent = (uint8_t)((value * 100) / range);

    if (throttle_percent > 100) {
        throttle_percent = 100;
    }
}

uint8_t throttle_get_percent(void)
{
    return throttle_percent;
}
