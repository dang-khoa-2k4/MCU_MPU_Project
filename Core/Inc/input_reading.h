/*
 * input_reading.h
 *
 *  Created on: Oct 3, 2024
 *      Author: ADMIN
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#include <stdint.h>
#include "fsm_tuning.h"
// we aim to work with more than one buttons
#define N0_OF_BUTTONS 3
// timer interrupt duration is 10ms , so to pass 1 second ,
// we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING 20
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
// the buffer that the final result is stored after
#define BUTTON_PRESSED 0
#define BUTTON_RELEASED 1

#define MODE_BUTTON 0 // main fsm handle
#define SAVE_BUTTON 0 // main fsm handle
#define COLOR_BUTTON 1 // manual fsm and tuning fsm handle
#define TIME_BUTTON 2 // input_reading handle

void button_reading ( void ) ;
unsigned char is_button_pressed ( uint8_t index );

#endif /* INC_INPUT_READING_H_ */

