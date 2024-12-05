#include "fsm.h"

MODE fsm_state;
uint8_t lcd_data[4];

static uint8_t btn_mode_state = BUTTON_RELEASED;
uint8_t time[3] = {3, 7, 10}; // AMBER, GREEN, RED

static void mode_press_handler(void)
{
    if (!is_button_pressed(MODE_BUTTON) && btn_mode_state == BUTTON_PRESSED)
    {
        btn_mode_state = BUTTON_RELEASED;

        switch (fsm_state)
        {
        case AUTO:
            manual_init();
            fsm_state = MANUAL;
            break;
        case MANUAL:
            tuning_init();
            fsm_state = TUNING;
            break;
        case TUNING:
            save_time();
            automatic_init();
            fsm_state = AUTO;
            break;
        default:
            break;
        }
    }
}

void fsm_init(void)
{
    // Initialize the FSM
    fsm_state = INIT_FSM;
}

void fsm_run(void)
{
    if (is_button_pressed(MODE_BUTTON))
    {
        btn_mode_state = BUTTON_PRESSED;
    }
    // Run the FSM
    switch (fsm_state)
    {
    case INIT_FSM:
        if (1)
        {
            fsm_state = AUTO;
            automatic_init();
        }
        break;
    case AUTO:
        automatic_run();
        automatic_generate_lcd_data(lcd_data);
        break;
    case MANUAL:
        manual_run();
        manual_generate_lcd_data(lcd_data);
        break;
    case TUNING:
        tuning_run();
        tuning_generate_lcd_data(lcd_data);
        break;
    default:
        break;
    }
    mode_press_handler();
}

void timeout_handler(void)
{
    if (fsm_state == TUNING && isTimerExpired(TUNING_TIMER))
    {
        light_off_all();
        save_time();
        automatic_init();
        fsm_state = AUTO;
    }
}
