/*
 * hal_adc.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */


#include "hal_adc.h"
#include "adc.h"
#include "opamp.h"

static uint16_t adc2_dma_buffer[HAL_ADC2_CH_COUNT];
static uint32_t adc3_dma_buffer;

void hal_adc2_init(void)
{
	MX_ADC2_Init();
}

void hal_adc3_init(void)
{
	MX_OPAMP3_Init();
	MX_ADC3_Init();
}

void hal_adc2_start(void)
{
	HAL_OPAMP_Start(&hopamp3);
	HAL_ADC_Start_DMA(&hadc2, (uint32_t*)adc2_dma_buffer, HAL_ADC2_CH_COUNT);
}

void hal_adc3_start(void)
{
	HAL_ADC_Start_DMA(&hadc3, &adc3_dma_buffer, 1);
}

uint16_t hal_adc2_get_raw_value(uint8_t channel)
{
    if (channel < HAL_ADC2_CH_COUNT) {
        return adc2_dma_buffer[channel];
    }
    return 0;
}

uint16_t hal_adc3_get_raw_value(void)
{
	return (uint16_t)adc3_dma_buffer;
}
