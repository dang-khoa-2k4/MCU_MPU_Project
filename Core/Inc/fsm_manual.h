#ifndef __FSM_MANUAL_H
#define __FSM_MANUAL_H

#include <stdint.h>
#include "input_reading.h"
#include "led_display.h"

typedef enum {
    RED_GREEN_MANUAL,
    RED_AMBER_MANUAL,
    GREEN_RED_MANUAL,
    AMBER_RED_MANUAL,
    INIT_MANUAL
} manual_state_t;

#define MANUAL_TIMER 0
 

void manual_init(void);
void manual_run(void);

/* Format data for LCD display
 * data[0] : color of light 1
 * data[1] : color of light 2 
 * data[2] : None
 * data[3] : None
 */
void manual_generate_lcd_data(uint8_t * data);

#endif // __FSM_MANUAL_H