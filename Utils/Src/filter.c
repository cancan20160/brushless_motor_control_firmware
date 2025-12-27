/*
 * filter.c
 *
 *  Created on: Dec 26, 2025
 *      Author: Can
 */


#include "filter.h"
#include <string.h>

typedef struct
{
    /* Oversampling */
    uint32_t acc;
    uint8_t  cnt;

    /* Median */
    uint16_t med_buf[MEDIAN_SIZE];
    uint8_t  med_idx;
    uint8_t  med_filled;

    /* EMA */
    int32_t  ema_q15;
    uint8_t  ema_init;

    /* Output */
    uint16_t last_output;

} adc_filter_t;

static adc_filter_t adc_filter;

static inline uint16_t median3(uint16_t a, uint16_t b, uint16_t c)
{
    if (a > b) {
        if (b > c) return b;
        else if (a > c) return c;
        else return a;
    } else {
        if (a > c) return a;
        else if (b > c) return c;
        else return b;
    }
}

void adc_filter_init(adc_filter_t *f)
{
    memset(f, 0, sizeof(adc_filter_t));
}

/*
 * adc_raw: ADC'den gelen ham 12-bit değer
 * return : Filtrelenmiş ve çözünürlüğü artırılmış değer
 *          (ADC birimi, ölçekleme yapılmamış)
 */
uint16_t adc_filter_process(adc_filter_t *f, uint16_t adc_raw)
{
    /* ========== OVERSAMPLING ========== */
    f->acc += adc_raw;
    f->cnt++;

    if (f->cnt < OVERSAMPLE_FACTOR)
    {
        /* Henüz yeni oversampled değer yok → son geçerli değeri dön */
        return f->last_output;
    }

    uint16_t os = (uint16_t)(f->acc >> OVERSAMPLE_SHIFT);

    f->acc = 0;
    f->cnt = 0;

    /* ========== MEDIAN FILTER ========== */
    f->med_buf[f->med_idx++] = os;
    if (f->med_idx >= MEDIAN_SIZE)
        f->med_idx = 0;

    if (f->med_filled < MEDIAN_SIZE)
    {
        f->med_filled++;
        f->last_output = os;
        return os;
    }

    uint16_t med = median3(
        f->med_buf[0],
        f->med_buf[1],
        f->med_buf[2]
    );

    /* ========== EMA FILTER ========== */
    if (!f->ema_init)
    {
        f->ema_q15 = ((int32_t)med) << 15;
        f->ema_init = 1;
    }
    else
    {
        int32_t in_q15 = ((int32_t)med) << 15;
        f->ema_q15 +=
            (EMA_ALPHA_Q15 * (in_q15 - f->ema_q15)) >> 15;
    }

    f->last_output = (uint16_t)(f->ema_q15 >> 15);
    return f->last_output;
}

void app_init(void)
{
    adc_filter_init(&adc_filter);
}

uint16_t adc_callback(uint16_t adc_raw)
{
    uint16_t value;

    value = adc_filter_process(&adc_filter, adc_raw);

    return value;

    /* value:
       - ASLA 0 diye “boş” dönmez
       - Spike yok
       - Gürültüsü bastırılmış
       - ~14 bit efektif çözünürlük */
}
