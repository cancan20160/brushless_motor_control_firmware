/*
 * commutate.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Can
 */


#include "commutation.h"
#include "pwm_driver.h"

typedef struct {
    phase_state_t u;
    phase_state_t v;
    phase_state_t w;
} commutation_step_t;

static const commutation_step_t forward_table[8] = {
	    [HALL_SECTOR_UNKNOWN]	= {PHASE_OFF,		PHASE_OFF,		PHASE_OFF	},
	    [HALL_SECTOR_4]			= {PHASE_OFF,		PHASE_LS_ON,	PHASE_HS_PWM},
	    [HALL_SECTOR_2]			= {PHASE_LS_ON,		PHASE_HS_PWM,	PHASE_OFF	},
	    [HALL_SECTOR_3]			= {PHASE_LS_ON,		PHASE_OFF,		PHASE_HS_PWM},
	    [HALL_SECTOR_6]			= {PHASE_HS_PWM,	PHASE_OFF,		PHASE_LS_ON	},
	    [HALL_SECTOR_5]			= {PHASE_HS_PWM,	PHASE_LS_ON,	PHASE_OFF	},
	    [HALL_SECTOR_1]			= {PHASE_OFF,		PHASE_HS_PWM,	PHASE_LS_ON	},
	    [HALL_SECTOR_UNKNOWN]	= {PHASE_OFF,		PHASE_OFF,		PHASE_OFF	},
};

static const commutation_step_t reverse_table[8] = {
	    [HALL_SECTOR_UNKNOWN]	= {PHASE_OFF,		PHASE_OFF,		PHASE_OFF	},
	    [HALL_SECTOR_4]			= {PHASE_OFF,		PHASE_HS_PWM,	PHASE_LS_ON	},
	    [HALL_SECTOR_2]			= {PHASE_HS_PWM,	PHASE_LS_ON,	PHASE_OFF	},
	    [HALL_SECTOR_3]			= {PHASE_HS_PWM,	PHASE_OFF,		PHASE_LS_ON	},
	    [HALL_SECTOR_6]			= {PHASE_LS_ON,		PHASE_OFF,		PHASE_HS_PWM},
	    [HALL_SECTOR_5]			= {PHASE_LS_ON,		PHASE_HS_PWM,	PHASE_OFF	},
	    [HALL_SECTOR_1]			= {PHASE_OFF,		PHASE_LS_ON,	PHASE_HS_PWM},
	    [HALL_SECTOR_UNKNOWN]	= {PHASE_OFF,		PHASE_OFF,		PHASE_OFF	},
};

static void apply_phase_state(pwm_phase_t phase, phase_state_t state, uint8_t duty)
{
    switch (state) {
        case PHASE_OFF:
            pwm_driver_stop(phase);
            pwm_driver_set_duty_percent(phase, 0);
            break;

        case PHASE_LS_ON:
            pwm_driver_set_duty_percent(phase, 0);
            pwm_driver_start(phase);
            break;

        case PHASE_HS_PWM:
            pwm_driver_set_duty_percent(phase, duty);
            pwm_driver_start(phase);
            break;
    }
}

void commutation_init(void)
{
    pwm_driver_init();
}

void commutation_update(hall_sector_t sector, direction_t dir, uint8_t duty)
{
    if (sector > HALL_SECTOR_6) {
        commutation_stop();
        return;
    }

    const commutation_step_t *table = (dir == DIRECTION_FORWARD) ? forward_table : reverse_table;
    const commutation_step_t *step = &table[sector];

    apply_phase_state(PWM_PHASE_U, step->u, duty);
    apply_phase_state(PWM_PHASE_V, step->v, duty);
    apply_phase_state(PWM_PHASE_W, step->w, duty);
}

void commutation_stop(void)
{
    pwm_driver_stop_all();
}
