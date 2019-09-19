/*
 * KEYPAD_program.c
 *
 *  Created on: Apr 6, 2019
 *      Author: a7mad
 */

#include<util/delay.h>
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"KEYPAD_interface.h"
/**********************************************************************************
 *                         Keypad Matrix                                          *
 **********************************************************************************/
u8 Keys[4][4]={    { 1 , 2  , 3  , 4  },
                   { 5 , 6  , 7  , 8  },
                   { 9 , 10 , 11 , 12 },
                   { 13, 14 , 15 , 16 }
               };

void KPD_voidInitialize(void)
{
  DIO_u8SetPortDirection(KPD_PORT,DIO_OUTPUT); /*nossohom inout w nossohom output*/
  DIO_u8SetPortValue(KPD_PORT,DIO_OUTPUT);     /*nossohom HIGH w nossohom LOW*/

}

u8 KPD_u8GetPressedKey(u8 *Copy_u8PressedKeyNB)
{
  u8 local_u8ColNB=0;
  u8 local_u8PortNB=0;
  u8 local_u8RowNB=0;
  u8 local_u8PinState;  /* da 2lly 7a2ra fih 2l pin HIGH wala LOW*/

  DIO_u8SetPinValue(KPD_PORT,local_u8ColNB,DIO_HIGH);

  for(local_u8ColNB=0;local_u8ColNB<COL_MAX_NB;local_u8ColNB++)
    {
      /*Activate first Column*/
      DIO_u8SetPinValue(KPD_PORT,local_u8ColNB,DIO_LOW);  /*7ab3atlo low 3shan enta faker 2n e7na beneb3at zero 3shan n activate 3shan 2l AVR mafihoush Pulldown resistor*/

      for(local_u8PortNB=ROW_START;local_u8PortNB<ROW_FINAL;local_u8PortNB++)  /*3shan ana mewasal 2l rows bedaya mn PIN 4 fil PORT 2lly aa mesta5demo*/
	{
	  DIO_u8GetPinValue(KPD_PORT,local_u8RowNB,&local_u8PinState); /*ba2olaha ro7y hatily 7alet 2l PIN da HIGH wala LOW*/

	  if(local_u8PinState==DIO_LOW)  /*law 2l button metdas 3leh*/
	    {
	       while(local_u8PinState==DIO_LOW)  /*Press Until release toul mana dayes 3leh 2l function wa2fa*/
		 {

		     (*Copy_u8PressedKeyNB)=Keys[local_u8RowNB-ROW_START][local_u8ColNB];

		   DIO_u8GetPinValue(KPD_PORT,local_u8RowNB,&local_u8PinState); /*efdal scan 3la PIN value le3'ayet ma tet3'ayar*/
		 }
	    }
	}

      DIO_u8SetPinValue(KPD_PORT,local_u8ColNB,DIO_HIGH); /*baraga3o l High tany zay ma kan*/

    }
  return(local_u8PinState);
}

