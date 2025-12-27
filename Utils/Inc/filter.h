/*
 * filter.h
 *
 *  Created on: Dec 26, 2025
 *      Author: Can
 */

#ifndef FILTER_H_
#define FILTER_H_

#include <stdint.h>

/* ================= CONFIGURATION ================= */

/* ADC resolution */
#define ADC_BITS            12
#define ADC_MAX_VALUE       ((1U << ADC_BITS) - 1)

/* Oversampling */
#define OVERSAMPLE_FACTOR   16      // 16x → +2 bit
#define OVERSAMPLE_SHIFT    4       // log2(16)

/* Median filter */
#define MEDIAN_SIZE         3       // 3-point median

/* EMA filter (Q15 format) */
#define EMA_ALPHA_Q15       3277    // ≈ 0.1 * 32768


void app_init(void);

uint16_t adc_callback(uint16_t adc_raw);

#endif /* FILTER_H_ */
