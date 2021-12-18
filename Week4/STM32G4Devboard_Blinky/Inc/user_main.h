/*
 * user_main.h
 *
 *  Created on: Dec 16, 2021
 *      Author: bot-10
 */

#ifndef USER_MAIN_H_
#define USER_MAIN_H_

#include "main.h"

#define BUTTON_PRESSED  0		  // Pin is connected to pull up  Resitor, pressing the switch drive the pin to ground reading 0V.
#define BUTTON_DEBOUNCE_COUNT 5  // Each count is worth 1ms , so 10 count = 10ms
volatile uint8_t button_state_debounce; // Used to detect button pressed.

void user_main(void);



#endif /* USER_MAIN_H_ */
