/*
 * fsm_automatic.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */
#include "fsm_tuning.h"

static tunnig_state_t tuning_state;
uint8_t btn_tuning_state = BUTTON_RELEASED;
uint8_t time_tuning[3];

void save_time()
{
    time[RED_TUNING]   =   time_tuning[RED_TUNING]; 
    time[GREEN_TUNING] =   time_tuning[GREEN_TUNING]; 
    time[AMBER_TUNING] =   time_tuning[AMBER_TUNING]; 
}

static void color_press_handler(void)
{
    if (!is_button_pressed(COLOR_BUTTON) && btn_tuning_state == BUTTON_PRESSED)
    {
        btn_tuning_state = BUTTON_RELEASED;

        switch (tuning_state)
        {
        case RED_TUNING:
            tuning_state = GREEN_TUNING;
            break;
        case GREEN_TUNING:
            tuning_state = AMBER_TUNING;
            break;
        case AMBER_TUNING:
            tuning_state = RED_TUNING;
            break;
        default:
            break;
        }

		light_off_all();
		setTimer(TUNING_TIMER, TUNING_TIMER_OUT);
		setTimer(TOGGLE_TIMER, TOGGLE_TIME);
    }
}

// update the time of the light in input_reading.c
void update_light_time()
{
	time_tuning[tuning_state] = (time_tuning[tuning_state] + 1) % MAX_TIME;
	setTimer(TUNING_TIMER, TUNING_TIMER_OUT); 
}

static void clone_time()
{
    time_tuning[RED_TUNING]      = time[RED_TUNING]; 
    time_tuning[GREEN_TUNING]    = time[GREEN_TUNING]; 
    time_tuning[AMBER_TUNING]    = time[AMBER_TUNING]; 
}

void tuning_init(void)
{
	// Initialize the automatic FSM
	clone_time();
	tuning_state = INIT_TUNING;
}


void tuning_run (void)
{
	if (is_button_pressed(COLOR_BUTTON))
	{
		btn_tuning_state = BUTTON_PRESSED;
	}
	switch (tuning_state)
	{
		case INIT_TUNING:
			if (1)
			{
				tuning_state = RED_TUNING;
				light_toggle(RED_TUNING);
				setTimer(TUNING_TIMER, TUNING_TIMER_OUT);
				setTimer(TOGGLE_TIMER, TOGGLE_TIME);
			}
			break;
		case RED_TUNING:
			timeout_handler();
			if (isTimerExpired(TOGGLE_TIMER))
			{
				light_toggle(RED_TUNING);
				setTimer(TOGGLE_TIMER, TOGGLE_TIME);
			}
			break;
		case GREEN_TUNING:
			timeout_handler();
			if (isTimerExpired(TOGGLE_TIMER))
			{
				light_toggle(GREEN_TUNING);
				setTimer(TOGGLE_TIMER, TOGGLE_TIME);
			}
			break;
		case AMBER_TUNING:
			timeout_handler();
			if (isTimerExpired(TOGGLE_TIMER))
			{
				light_toggle(AMBER_TUNING);
				setTimer(TOGGLE_TIMER, TOGGLE_TIME);
			}
			break;
		default:
			break;
	}
	color_press_handler();
}

void tuning_generate_lcd_data(uint8_t * data)
{
	data[0] = tuning_state;
	data[1] = time_tuning[tuning_state];
}
