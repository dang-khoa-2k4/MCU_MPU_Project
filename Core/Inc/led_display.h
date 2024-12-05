/*
 * led.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"
#include <stdint.h>
// Define part
#define LED_ON 1
#define LED_OFF 0

#define LIGHT_1 0
#define LIGHT_2 1

#define AMBER 0
#define GREEN 1
#define RED 2

void light_1_handle(uint8_t led);
void light_2_handle(uint8_t led);
void light_toggle(uint8_t led);
void light_off_all(void);

#endif /* INC_LED_DISPLAY_H_ */
