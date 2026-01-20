/*
 * throttle.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */

#ifndef INC_THROTTLE_H_
#define INC_THROTTLE_H_

#include <stdint.h>
#include <stdbool.h>

void ecal_throttle_init(void);

void ecal_throttle_update(void);

uint8_t ecal_throttle_get_percent(void);

#endif /* INC_THROTTLE_H_ */
