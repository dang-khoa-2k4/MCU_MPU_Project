/*
 * fsm_automatic.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include <stdint.h>
#include "sw_timer.h"
#include "led_display.h"
#include "fsm.h"
/*
    AB
    00 OFF
    01 AMBER
    10 GREEN
    11 RED
*/
typedef enum {
    AMBER_AUTO = 0, 
    GREEN_AUTO,
    RED_AUTO,
    INIT_AUTO
} trafficLight_t;

#define LIGHT_TIMER 0
// #define LIGHT_2_TIMER 1

void automatic_init(void);
void automatic_run(void);

/* Format data for LCD display
 * data[0] : color of light 1
 * data[1] : color of light 2 
 * data[2] : time of light 1
 * data[3] : time of light 2
 */
void automatic_generate_lcd_data(uint8_t * data);

#endif /* INC_FSM_AUTOMATIC_H_ */

