/*
 * user_main.c
 *
 *  Created on: Dec 16, 2021
 *      Author: bot-10
 */
#include "user_main.h"


void user_main(void)
{
	while(1)
	{
		if(button_state_debounce == BUTTON_PRESSED)
		{
			HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,GPIO_PIN_RESET);
		}
	}
}
