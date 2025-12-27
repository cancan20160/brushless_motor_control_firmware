/*
 * commutate.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */

#ifndef INC_COMMUTATION_H_
#define INC_COMMUTATION_H_

#include <stdint.h>
#include "hall_sensor_driver.h"
#include "direction.h"

typedef enum {
    PHASE_OFF = 0,
    PHASE_LS_ON,
    PHASE_HS_PWM
} phase_state_t;

void commutation_init(void);

void commutation_update(hall_sector_t sector, direction_t dir, uint8_t duty);

void commutation_stop(void);

#endif /* INC_COMMUTATION_H_ */
