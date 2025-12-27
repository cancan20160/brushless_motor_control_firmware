/*
 * current_sensor.c
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */


#include "current_sensor.h"
#include "hal_adc.h"
#include "filter.h"

#define ADC_VREF            3.3f
#define ADC_RESOLUTION      4096.0f
#define SHUNT_RESISTANCE    0.001f
#define OPAMP_GAIN          16.0f
#define ADC_OFFSET          2382

static float phase_current;

void current_sensor_init(void)
{
    phase_current = 0.0f;
}

void current_sensor_update(void)
{

    uint16_t adc_value = (uint16_t)hal_adc3_get_raw_value();
    uint16_t adc_value_filtered = adc_callback(adc_value);

    int32_t adc_diff = (int32_t)adc_value_filtered - ADC_OFFSET;

    float voltage = ((float)adc_diff / ADC_RESOLUTION) * ADC_VREF;

    phase_current = voltage / (SHUNT_RESISTANCE * OPAMP_GAIN);
}

float current_sensor_get_phase_current(void)
{
    return phase_current;
}
