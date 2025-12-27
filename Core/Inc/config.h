///*
// * config.h
// *
// *  Created on: Dec 24, 2025
// *      Author: Can
// */
//
//#ifndef INC_CONFIG_H_
//#define INC_CONFIG_H_
//
//#include <stdint.h>
//#include <stdbool.h>
//
///* VBUS Calibration constants */
//#define VREF_MV					3300.0f
//#define ADC_MAX					4095.0f
//#define R_TOP_K					360.0f
//#define R_BOTTOM_K				10.0f
//#define DIVIDER_RATIO			((R_TOP_K + R_BOTTOM_K) / R_BOTTOM_K)
//#define VBUS_SCALE_MV_PER_LSB	((VREF_MV / ADC_MAX) * DIVIDER_RATIO)
//
///* ADC Channels */
//#define ADC_CH_VBUS				0U
//#define ADC_CH_MOSFET_TEMP		1U
//#define ADC_CH_MOTOR_TEMP		2U
//#define ADC_CH_THROTTLE			3U
//#define ADC_CHANNEL_COUNT		4U
//
//typedef enum {
//	MOTOR_DIR_CW = 0U,
//	MOTOR_DIR_CCW,
//} motor_direction_t;
//
//typedef enum {
//	HALL_SECTOR_0,
//	HALL_SECTOR_1,
//	HALL_SECTOR_2,
//	HALL_SECTOR_3,
//	HALL_SECTOR_4,
//	HALL_SECTOR_5,
//	HALL_SECTOR_INVALID,
//} hall_sector_t;
//
//typedef enum {
//	PHASE_OFF = 0,
//	PHASE_HS_PWM,
//	PHASE_LS_ON
//} phase_cmd_t;
//
//typedef struct {
//	phase_cmd_t phaseU_state;
//	phase_cmd_t phaseV_state;
//	phase_cmd_t phaseW_state;
//} comm_t;
//
//typedef enum {
//	phaseU = 0U,
//	phaseV,
//	phaseW,
//} phase_t;
//
//typedef struct {
//	float throttle_percent;
//	uint32_t vbus_voltage_v;
//	uint32_t phase_current_a;
//	uint32_t mosfet_temperature_c;
//	uint32_t motor_temperature_c;
//	hall_sector_t sector;
//} sensor_data_t;
//
//typedef struct {
//	sensor_data_t sensor_data;
//	motor_direction_t direction;
//	bool is_brake_active;
//	comm_t phase_state;
//} motor_context_t;
//
//#endif /* INC_CONFIG_H_ */
