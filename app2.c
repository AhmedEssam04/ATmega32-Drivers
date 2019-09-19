/*
 * app2.c
 *
 *  Created on: Apr 28, 2019
 *      Author: dell.pc
 */
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"BIT_MATH.h"
#include"keybad_interface.h"
#include "AVR_EXT_REG.h"
#include"DIO_External_intrupt.h"
#include<util/delay.h>

void __vector_1(void) __attribute__((signal,used));
void __vector_2(void) __attribute__((signal,used));/* pragma for interrupt functions*/

void __vector_1(void)
{
        DIO_u8SetPinValue(DIO_PORT_1,DIO_PIN_0,DIO_HIGH);
        _delay_ms(1000);
        DIO_u8SetPinValue(DIO_PORT_1,DIO_PIN_0,DIO_LOW);
        _delay_ms(1000);
}
void __vector_2(void)
{
	  DIO_u8SetPinValue(DIO_PORT_1,DIO_PIN_0,DIO_HIGH);
	        _delay_ms(2000);
	        DIO_u8SetPinValue(DIO_PORT_1,DIO_PIN_0,DIO_LOW);
	        _delay_ms(2000);
}

void main (void)
{/*set pin as input*/

        DIO_u8SetPinDirection(DIO_PORT_1,DIO_PIN_0,DIO_OUTPUT);
        DIO_u8SetPinDirection(DIO_PORT_3,DIO_PIN_2,DIO_INPUT);
        DIO_u8SetPinDirection(DIO_PORT_3,DIO_PIN_3,DIO_INPUT);
        DIO_u8SetPinValue(DIO_PORT_3,DIO_PIN_2,DIO_HIGH);
        DIO_u8SetPinValue(DIO_PORT_3,DIO_PIN_3,DIO_HIGH);

        DIO_INT0_vidEnable();
        DIO_INT1_vidEnable();
        DIO_INT0_u8EventType(DIO_INT_enuFallingEdge);
        DIO_INT1_u8EventType(DIO_INT_enuFallingEdge);
        DIO_INTGlobal_vidEnable();

        while(1)
        {

        }
}


