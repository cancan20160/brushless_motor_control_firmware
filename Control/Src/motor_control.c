/*
 * motor_control.c
 *
 *  Created on: Dec 25, 2025
 *      Author: Can
 */


#include "motor_control.h"
#include "state_machine.h"
#include "commutation.h"
#include "throttle.h"
#include "hall_sensor_driver.h"
#include "voltage_sensor.h"
#include "current_sensor.h"
#include "temperature_sensor.h"
#include "brake.h"
#include "direction.h"
#include "hal_adc.h"

static uint32_t task_counter;

void motor_control_init(void)
{
    hal_adc2_init();
    hal_adc3_init();

    throttle_init();
    hall_sensor_init();
    voltage_sensor_init();
    current_sensor_init();
    temperature_sensor_init();
    brake_init();
    direction_init();

    commutation_init();
    state_machine_init();

    hal_adc2_start();
    hal_adc3_start();

    task_counter = 0;
}

void motor_control_task(void)
{
    task_counter++;

    throttle_update();
    hall_sensor_update();
    voltage_sensor_update();
    current_sensor_update();
    temperature_sensor_update();
    brake_update();
    direction_update();

    motor_state_t current_state = state_machine_get_state();
    hall_sector_t sector = hall_sensor_get_sector();
    direction_t dir = direction_get();
    uint8_t throttle = throttle_get_percent();

    motor_event_t event = EVENT_NONE;

    if (brake_is_pressed()) {
        event = EVENT_BRAKE_PRESSED;
        state_machine_process_event(event);
        return;
    }

    if (throttle > 0) {
        event = EVENT_THROTTLE_ACTIVE;
    } else {
        event = EVENT_THROTTLE_ZERO;
    }

    if (hall_sensor_is_valid()) {
        state_machine_process_event(EVENT_SECTOR_DETECTED);
    }

    state_machine_process_event(event);

    current_state = state_machine_get_state();

    switch (current_state) {
        case STATE_INIT:
            break;

        case STATE_IDLE:
            break;

        case STATE_ALIGN:
            commutation_update(HALL_SECTOR_1, dir, 20);
            break;

        case STATE_START:
            commutation_update(sector, dir, throttle);
            break;

        case STATE_RUN:
            commutation_update(sector, dir, throttle);
            break;

        case STATE_STOP:
            break;

        case STATE_BRAKE:
            break;

        case STATE_FAULT:
            break;
    }
}

void motor_control_hall_interrupt_callback(void)
{
    hall_sensor_update();

    hall_sector_t sector = hall_sensor_get_sector();
    direction_t dir = direction_get();
    uint8_t throttle = throttle_get_percent();

    motor_state_t current_state = state_machine_get_state();

    if (current_state == STATE_RUN || current_state == STATE_START) {
        commutation_update(sector, dir, throttle);
    }
}

void motor_control_brake_interrupt_callback(void)
{
    brake_update();

    if (brake_is_pressed()) {
        state_machine_process_event(EVENT_BRAKE_PRESSED);
    } else {
        state_machine_process_event(EVENT_BRAKE_RELEASED);
    }
}

void motor_control_direction_interrupt_callback(void)
{
    direction_update();
}
