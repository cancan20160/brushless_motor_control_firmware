/**
 * @file brake.h
 * @brief 
 * @author Şükrü Can Kılıç
 * @date 2025-12-25
 * 
 */

#ifndef INC_BRAKE_H_
#define INC_BRAKE_H_

#include <stdint.h>
#include <stdbool.h>

void ecal_brake_init(void);

void ecal_brake_update(void);

bool ecal_brake_is_pressed(void);

#endif /* INC_BRAKE_H_ */
