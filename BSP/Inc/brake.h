/*
 * brake.h
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */

#ifndef INC_BRAKE_H_
#define INC_BRAKE_H_

#include <stdint.h>
#include <stdbool.h>

void brake_init(void);

void brake_update(void);

bool brake_is_pressed(void);

#endif /* INC_BRAKE_H_ */
