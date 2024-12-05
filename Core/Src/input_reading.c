/*
 * input_reading.c
 *
 *  Created on: Oct 3, 2024
 *      Author: ADMIN
 */

#include "input_reading.h"

static const uint16_t btn_pin[N0_OF_BUTTONS] = {BTN1_Pin, BTN2_Pin, BTN3_Pin};
static const GPIO_TypeDef * btn_port[N0_OF_BUTTONS] = {BTN1_GPIO_Port, BTN2_GPIO_Port, BTN3_GPIO_Port};

// debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS] = {BUTTON_RELEASED};
// we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS] = {BUTTON_RELEASED};
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS] = {BUTTON_RELEASED};
static GPIO_PinState debounceButtonBuffer3[N0_OF_BUTTONS] = {BUTTON_RELEASED};
// we define a flag for a button pressed more than 1 second .
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
// we define counter for automatically increasing the value
// after the button is pressed more than 1 second .
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
void button_reading(void)
{
    for (char i = 0; i < N0_OF_BUTTONS; i++)
    {
        debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(btn_port[i], btn_pin[i]);
        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]
            && debounceButtonBuffer2[i] == debounceButtonBuffer3[i])
        {
            if (buttonBuffer[i] != debounceButtonBuffer1[i])
            {
                buttonBuffer[i] = debounceButtonBuffer1[i];
                if (buttonBuffer[i] == BUTTON_IS_PRESSED)
                {
                    if (i == TIME_BUTTON)
                        update_light_time();
                    counterForButtonPress1s[i] = DURATION_FOR_AUTO_INCREASING;
                }
            }
            else 
            {   
                if (buttonBuffer[i] == BUTTON_IS_PRESSED)
                {
                    counterForButtonPress1s[i]--;
                    if (counterForButtonPress1s[i] <= 0)
                    {
                        // TODO
                        if (i == TIME_BUTTON)
                            update_light_time();
                        counterForButtonPress1s[i] = DURATION_FOR_AUTO_INCREASING;
                    }
                }
            }
        }
        
    }
}

unsigned char is_button_pressed(uint8_t index)
{
    if (index < 0 || index >= N0_OF_BUTTONS)
        return 0;
    return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}