#include "fsm_manual.h"

static manual_state_t manual_state;
static uint8_t btn_manual_state = BUTTON_RELEASED;

void static color_press_handler(void)
{
    if (!is_button_pressed(COLOR_BUTTON) && btn_manual_state == BUTTON_PRESSED)
    {
        btn_manual_state = BUTTON_RELEASED;

        switch (manual_state)
        {
        case RED_GREEN_MANUAL:
            manual_state = RED_AMBER_MANUAL;
            break;
        case RED_AMBER_MANUAL:
            manual_state = GREEN_RED_MANUAL;
            break;
        case GREEN_RED_MANUAL:
            manual_state = AMBER_RED_MANUAL;
            break;
        case AMBER_RED_MANUAL:
            manual_state = RED_GREEN_MANUAL;
            break;
        default:
            break;
        }
    }
}

void manual_init(void)
{
    // Initialize the manual FSM
    btn_manual_state = BUTTON_RELEASED;
    manual_state = INIT_MANUAL;
}

void manual_generate_lcd_data(uint8_t * data)
{
    switch (manual_state)
    {
    case RED_GREEN_MANUAL:
        data[0] = RED;
        data[1] = GREEN;
        break;
    case RED_AMBER_MANUAL:
        data[0] = RED;
        data[1] = AMBER;
        break;
    case GREEN_RED_MANUAL:
        data[0] = GREEN;
        data[1] = RED;
        break;
    case AMBER_RED_MANUAL:
        data[0] = AMBER;
        data[1] = RED;
        break;
    default:
        break;
    }
}

void manual_run(void)
{
    if (is_button_pressed(COLOR_BUTTON))
    {
        btn_manual_state = BUTTON_PRESSED;
    }
    // Run the manual FSM
    switch (manual_state)
    {
    case INIT_MANUAL:
        if (1)
        {
            manual_state = RED_GREEN_MANUAL;
        }
        break;
    case RED_GREEN_MANUAL:
        light_1_handle(RED);
        light_2_handle(GREEN);
        break;
    case RED_AMBER_MANUAL:
        light_1_handle(RED);
        light_2_handle(AMBER);
        break;
    case GREEN_RED_MANUAL:
        light_1_handle(GREEN);
        light_2_handle(RED);
        break;
    case AMBER_RED_MANUAL:
        light_1_handle(AMBER);
        light_2_handle(RED);
        break;
    default:
        break;
    }
    color_press_handler();
}