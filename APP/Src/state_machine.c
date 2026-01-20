/*
 * state_machine.c
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */


#include "state_machine.h"
#include "commutation.h"

static motor_state_t current_state;
static motor_state_t previous_state;

static void state_transition(motor_state_t new_state);
static void state_entry_init(void);
static void state_entry_idle(void);
static void state_entry_align(void);
static void state_entry_start(void);
static void state_entry_run(void);
static void state_entry_stop(void);
static void state_entry_brake(void);
static void state_entry_fault(void);

void app_state_machine_init(void)
{
    current_state = STATE_INIT;
    previous_state = STATE_INIT;
    state_entry_init();
}

void app_state_machine_process_event(motor_event_t event)
{
    switch (current_state) {
        case STATE_INIT:
            state_transition(STATE_IDLE);
            break;

        case STATE_IDLE:
            if (event == EVENT_BRAKE_PRESSED) {
                state_transition(STATE_BRAKE);
            } else if (event == EVENT_FAULT_OCCURRED) {
                state_transition(STATE_FAULT);
            } else if (event == EVENT_THROTTLE_ACTIVE) {
                if (event == EVENT_SECTOR_DETECTED) {
                    state_transition(STATE_START);
                } else {
                    state_transition(STATE_ALIGN);
                }
            }
            break;

        case STATE_ALIGN:
            if (event == EVENT_BRAKE_PRESSED) {
                state_transition(STATE_BRAKE);
            } else if (event == EVENT_FAULT_OCCURRED) {
                state_transition(STATE_FAULT);
            } else if (event == EVENT_THROTTLE_ZERO) {
                state_transition(STATE_IDLE);
            } else if (event == EVENT_SECTOR_DETECTED) {
                state_transition(STATE_START);
            }
            break;

        case STATE_START:
            if (event == EVENT_BRAKE_PRESSED) {
                state_transition(STATE_BRAKE);
            } else if (event == EVENT_FAULT_OCCURRED) {
                state_transition(STATE_FAULT);
            } else if (event == EVENT_THROTTLE_ZERO) {
                state_transition(STATE_IDLE);
            } else if (event == EVENT_SPEED_REACHED) {
                state_transition(STATE_RUN);
            }
            break;

        case STATE_RUN:
            if (event == EVENT_BRAKE_PRESSED) {
                state_transition(STATE_BRAKE);
            } else if (event == EVENT_FAULT_OCCURRED) {
                state_transition(STATE_FAULT);
            } else if (event == EVENT_THROTTLE_ZERO) {
                state_transition(STATE_STOP);
            }
            break;

        case STATE_STOP:
            if (event == EVENT_BRAKE_PRESSED) {
                state_transition(STATE_BRAKE);
            } else if (event == EVENT_FAULT_OCCURRED) {
                state_transition(STATE_FAULT);
            } else if (event == EVENT_SPEED_ZERO) {
                state_transition(STATE_IDLE);
            } else if (event == EVENT_THROTTLE_ACTIVE) {
                state_transition(STATE_RUN);
            }
            break;

        case STATE_BRAKE:
            if (event == EVENT_FAULT_OCCURRED) {
                state_transition(STATE_FAULT);
            } else if (event == EVENT_BRAKE_RELEASED) {
                if (event == EVENT_SPEED_ZERO) {
                    state_transition(STATE_IDLE);
                } else {
                    state_transition(STATE_STOP);
                }
            }
            break;

        case STATE_FAULT:
            if (event == EVENT_FAULT_CLEARED) {
                state_transition(STATE_IDLE);
            }
            break;
    }
}

motor_state_t app_state_machine_get_state(void)
{
    return current_state;
}

void app_state_machine_update(void)
{

}

static void state_transition(motor_state_t new_state)
{
    previous_state = current_state;
    current_state = new_state;

    switch (new_state) {
        case STATE_INIT:
            state_entry_init();
            break;
        case STATE_IDLE:
            state_entry_idle();
            break;
        case STATE_ALIGN:
            state_entry_align();
            break;
        case STATE_START:
            state_entry_start();
            break;
        case STATE_RUN:
            state_entry_run();
            break;
        case STATE_STOP:
            state_entry_stop();
            break;
        case STATE_BRAKE:
            state_entry_brake();
            break;
        case STATE_FAULT:
            state_entry_fault();
            break;
    }
}

static void state_entry_init(void)
{
    app_commutation_stop();
}

static void state_entry_idle(void)
{
    app_commutation_stop();
}

static void state_entry_align(void)
{

}

static void state_entry_start(void)
{

}

static void state_entry_run(void)
{

}

static void state_entry_stop(void)
{
    app_commutation_stop();
}

static void state_entry_brake(void)
{
    app_commutation_stop();
}

static void state_entry_fault(void)
{
    app_commutation_stop();
}
