/*
 * voltage_sensor.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */


#include "voltage_sensor.h"
#include "hal_adc.h"

#define ADC_VREF            3.3f
#define ADC_RESOLUTION      4096.0f
#define VOLTAGE_DIVIDER     15.0f

static float vbus_voltage;

void ecal_voltage_sensor_init(void)
{
    vbus_voltage = 0.0f;
}

void ecal_voltage_sensor_update(void)
{
    uint16_t adc_value = (uint16_t)hal_adc2_get_raw_value(HAL_ADC2_CH_VBUS);

    float adc_voltage = ((float)adc_value / ADC_RESOLUTION) * ADC_VREF;

    vbus_voltage = adc_voltage * VOLTAGE_DIVIDER;
}

float ecal_voltage_sensor_get_vbus(void)
{
    return vbus_voltage;
}
