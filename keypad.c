/*
 * keypad.c
 *
 *  Created on: Apr 6, 2019
 *      Author: dell.pc
 */


#define F_CPU 8000000
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "keybad_interface.h"

void KBD_vidInit(void)
{
	DIO_u8SetPinDirection(DIO_PORT_0,DIO_PIN_0,1);
	DIO_u8SetPinDirection(DIO_PORT_0,DIO_PIN_1,1);
	DIO_u8SetPinDirection(DIO_PORT_0,DIO_PIN_2,1);
	DIO_u8SetPinDirection(DIO_PORT_0,DIO_PIN_3,1);
	DIO_u8SetPinDirection(DIO_PORT_0,DIO_PIN_4,0);
	DIO_u8SetPinDirection(DIO_PORT_0,DIO_PIN_5,0);
	DIO_u8SetPinDirection(DIO_PORT_0,DIO_PIN_6,0);
	DIO_u8SetPinDirection(DIO_PORT_0,DIO_PIN_7,0);

	DIO_u8SetPortValue(DIO_PORT_0,0xFF);
}


void KBD_u8GetPressedValue(u8* Copy_u8PressedKeyNB)
{
	u8 local_u8ColNB;
	u8 local_u8RowNB;
	u8 local_u8PinState;
	u8 Keys[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	for(local_u8ColNB=0;local_u8ColNB<Col_Final;local_u8ColNB++)
	{
		//activate the current column
		DIO_u8SetPinValue(KBD_PORT,local_u8ColNB,DIO_LOW);
		for(local_u8RowNB=Row_Start;local_u8RowNB<Row_Final;local_u8RowNB++)
		{
			DIO_u8GetPinValue(KBD_PORT,local_u8RowNB,&local_u8PinState);

		while(local_u8PinState==DIO_LOW)
		{
			//Get NB
			(*Copy_u8PressedKeyNB)=Keys[local_u8RowNB-Row_Start][local_u8ColNB];


			DIO_u8GetPinValue(KBD_PORT,local_u8RowNB,&local_u8PinState);
		}

		}

		DIO_u8SetPinValue(KBD_PORT,local_u8ColNB,DIO_HIGH);
	}

}
