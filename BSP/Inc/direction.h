/*
 * direction.h
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */

#ifndef INC_DIRECTION_H_
#define INC_DIRECTION_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    DIRECTION_REVERSE = 0,
    DIRECTION_FORWARD = 1
} direction_t;

void direction_init(void);

void direction_update(void);

direction_t direction_get(void);

bool direction_is_forward(void);

#endif /* INC_DIRECTION_H_ */
