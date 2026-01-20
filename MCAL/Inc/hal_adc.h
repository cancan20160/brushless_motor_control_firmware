/*
 * hal_adc.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */

#ifndef INC_HAL_ADC_H_
#define INC_HAL_ADC_H_

#include <stdint.h>

#define HAL_ADC2_CH_VBUS          0
#define HAL_ADC2_CH_TEMP_MOSFET   1
#define HAL_ADC2_CH_TEMP_MOTOR    2
#define HAL_ADC2_CH_THROTTLE      3
#define HAL_ADC2_CH_COUNT         4

void hal_adc2_init(void);
void hal_adc3_init(void);
void hal_adc2_start(void);
void hal_adc3_start(void);
void hal_adc2_stop(void);
void hal_adc3_stop(void);
uint16_t hal_adc2_get_raw_value(uint8_t channel);
uint16_t hal_adc3_get_raw_value(void);

#endif /* INC_HAL_ADC_H_ */
