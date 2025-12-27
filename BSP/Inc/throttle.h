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

void throttle_init(void);

void throttle_update(void);

uint8_t throttle_get_percent(void);

#endif /* INC_THROTTLE_H_ */
