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

void app_motor_control_init(void)
{
    hal_adc2_init();
    hal_adc3_init();

    ecal_throttle_init();
    ecal_hall_sensor_init();
    ecal_voltage_sensor_init();
    ecal_current_sensor_init();
    ecal_temperature_sensor_init();
    ecal_brake_init();
    ecal_direction_init();

    app_commutation_init();
    app_state_machine_init();

    hal_adc2_start();
    hal_adc3_start();

    task_counter = 0;
}

void app_motor_control_task(void)
{
    task_counter++;

    ecal_throttle_update();
    ecal_hall_sensor_update();
    ecal_voltage_sensor_update();
    ecal_current_sensor_update();
    ecal_temperature_sensor_update();
    ecal_brake_update();
    ecal_direction_update();

    motor_state_t current_state = app_state_machine_get_state();
    hall_sector_t sector = ecal_hall_sensor_get_sector();
    direction_t dir = ecal_direction_get();
    uint8_t throttle = ecal_throttle_get_percent();

    motor_event_t event = EVENT_NONE;

    if (ecal_brake_is_pressed()) {
        event = EVENT_BRAKE_PRESSED;
        app_state_machine_process_event(event);
        return;
    }

    if (throttle > 0) {
        event = EVENT_THROTTLE_ACTIVE;
    } else {
        event = EVENT_THROTTLE_ZERO;
    }

    if (ecal_hall_sensor_is_valid()) {
        app_state_machine_process_event(EVENT_SECTOR_DETECTED);
    }

    app_state_machine_process_event(event);

    current_state = app_state_machine_get_state();

    switch (current_state) {
        case STATE_INIT:
            break;

        case STATE_IDLE:
            break;

        case STATE_ALIGN:
            app_commutation_update(HALL_SECTOR_1, dir, 20);
            break;

        case STATE_START:
            app_commutation_update(sector, dir, throttle);
            break;

        case STATE_RUN:
            app_commutation_update(sector, dir, throttle);
            break;

        case STATE_STOP:
            break;

        case STATE_BRAKE:
            break;

        case STATE_FAULT:
            break;
    }
}

void app_motor_control_hall_interrupt_callback(void)
{
    ecal_hall_sensor_update();

    hall_sector_t sector = ecal_hall_sensor_get_sector();
    direction_t dir = ecal_direction_get();
    uint8_t throttle = ecal_throttle_get_percent();

    motor_state_t current_state = app_state_machine_get_state();

    if (current_state == STATE_RUN || current_state == STATE_START) {
        app_commutation_update(sector, dir, throttle);
    }
}

void app_motor_control_brake_interrupt_callback(void)
{
    ecal_brake_update();

    if (ecal_brake_is_pressed()) {
        app_state_machine_process_event(EVENT_BRAKE_PRESSED);
    } else {
        app_state_machine_process_event(EVENT_BRAKE_RELEASED);
    }
}

void app_motor_control_direction_interrupt_callback(void)
{
    ecal_direction_update();
}
