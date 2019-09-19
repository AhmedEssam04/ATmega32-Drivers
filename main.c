/*
 * APP.c
 *
 *  Created on: Mar 29, 2019
 *      Author: Knight
 */

/********************************************/
/*Author:			AhmedK					*/
/*File Name:		APP.c					*/
/*Component:		LCD						*/
/*File Version:		v1.0					*/
/********************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>

int main(void) {
	u8 i, j;

	DIO_u8SetPortDirection(LCD_DATA_PORT, 0xff);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_OUTPUT);

	LCD_voidInitialize();

	while (1) {
		for (j = 0; j < (16 - 5); j++) {
			LCD_u8GoTo(1,1);
			for (i = 0; i < j; i++) {
				LCD_u8WriteData(' ');
			}
			LCD_u8WriteString((u8*) "AHMED", 5);
			_delay_ms(300);
			LCD_u8WriteCommand(1); /*clear*/
		}
		for (; j > 0; j--) {
			for (i = j; i > 0; i--) {
				LCD_u8WriteData(' ');
			}
			LCD_u8WriteString((u8*) "AHMED", 5);
			_delay_ms(300);
			LCD_u8WriteCommand(1); /*clear*/
		}
	}
	return (0);
}

