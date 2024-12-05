/*
 * fsm_automatic.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSM_SETTING_H_
#define INC_FSM_SETTING_H_

#include "fsm.h"
#include "input_reading.h"

typedef enum {
    AMBER_TUNING = 0,
    GREEN_TUNING,
    RED_TUNING,
    INIT_TUNING
} tunnig_state_t;

#define TIME_OUT 10 //s
#define MAX_TIME 100

#define TUNING_TIMER 0     // set time out for tuning
#define TUNING_TIMER_OUT 1000 // 10s
#define TOGGLE_TIMER 1      // set time for toggle
#define TOGGLE_TIME 50 // 500ms

extern uint8_t time_tuning[3];

void update_light_time(void);
void tuning_init(void);
void tuning_run(void);
void save_time();
void timeout_handler(void);

/* Format data for LCD display
 * data[0] : color mode
 * data[1] : time of light
 * data[2] : None
 * data[3] : None
 */
void tuning_generate_lcd_data(uint8_t * data);
#endif /* INC_FSM_AUTOMATIC_H_ */

