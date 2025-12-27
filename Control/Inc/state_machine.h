/*
 * state_machine.h
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */

#ifndef INC_STATE_MACHINE_H_
#define INC_STATE_MACHINE_H_

#include <stdint.h>

typedef enum {
    STATE_INIT = 0,
    STATE_IDLE,
    STATE_ALIGN,
    STATE_START,
    STATE_RUN,
    STATE_STOP,
    STATE_BRAKE,
    STATE_FAULT
} motor_state_t;

typedef enum {
    EVENT_NONE = 0,
    EVENT_THROTTLE_ACTIVE,
    EVENT_THROTTLE_ZERO,
    EVENT_SECTOR_DETECTED,
    EVENT_SPEED_REACHED,
    EVENT_SPEED_ZERO,
    EVENT_BRAKE_PRESSED,
    EVENT_BRAKE_RELEASED,
    EVENT_FAULT_OCCURRED,
    EVENT_FAULT_CLEARED
} motor_event_t;

void state_machine_init(void);

void state_machine_process_event(motor_event_t event);

motor_state_t state_machine_get_state(void);

void state_machine_update(void);

#endif /* INC_STATE_MACHINE_H_ */
