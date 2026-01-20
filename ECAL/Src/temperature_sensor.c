/*
 * temperature_sensor.c
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */

#include "temperature_sensor.h"
#include "hal_adc.h"
#include <math.h>

#define ADC_VREF            3.3f
#define ADC_RESOLUTION      4096.0f
#define NTC_R25             10000.0f
#define NTC_B_VALUE         3950.0f
#define SERIES_RESISTOR     10000.0f
#define T25_KELVIN          298.15f

static float mosfet_temp;
static float motor_temp;

static float calculate_temperature(uint16_t adc_value)
{
    float adc_voltage = ((float)adc_value / ADC_RESOLUTION) * ADC_VREF;

    float ntc_resistance = SERIES_RESISTOR * (ADC_VREF / adc_voltage - 1.0f);

    float temp_kelvin = 1.0f / ((1.0f / T25_KELVIN) + (1.0f / NTC_B_VALUE) * logf(ntc_resistance / NTC_R25));

    return temp_kelvin - 273.15f;
}

void ecal_temperature_sensor_init(void)
{
    mosfet_temp = 0.0f;
    motor_temp = 0.0f;
}

void ecal_temperature_sensor_update(void)
{
    uint16_t adc_mosfet = (uint16_t)hal_adc2_get_raw_value(HAL_ADC2_CH_TEMP_MOSFET);
    uint16_t adc_motor = (uint16_t)hal_adc2_get_raw_value(HAL_ADC2_CH_TEMP_MOTOR);

    mosfet_temp = calculate_temperature(adc_mosfet);
    motor_temp = calculate_temperature(adc_motor);
}

float ecal_temperature_sensor_get_mosfet_temp(void)
{
    return mosfet_temp;
}

float ecal_temperature_sensor_get_motor_temp(void)
{
    return motor_temp;
}
