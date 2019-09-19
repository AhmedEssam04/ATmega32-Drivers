/*
 * LCD_program.c
 *
 *  Created on: Mar 30, 2019
 *      Author: Knight
 */

/********************************************/
/*Author:			AhmedK					*/
/*File Name:		LCD_program.c			*/
/*Component:		LCD						*/
/*File Version:		v1.0					*/
/********************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>

/*
 * Description: Write Command to LCD
 * Inputs: Command
 * Outputs:NA
 */
u8 LCD_u8WriteCommand(u8 Copy_u8Command)
{
	/*Local Error state */
	u8 Local_u8Error = 0;/*DIO sh3'al wla l2*/

	/* reset Enable */
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_LOW);

	/* RS =  command register */
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_LOW);

	/* RW = write */
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

	/* send command */
	Local_u8Error = DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);

	/* Enable sequence */
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_HIGH);
	_delay_ms(2);
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_LOW);

	/*Function shall return the Error state*/
	return (Local_u8Error);

}

/*
 * Description: set LCD AC " address counter "
 * Inputs: X , Y
 * Outputs:NA
 */
u8 LCD_u8GoTo(u8 Copy_u8PoseX, u8 Copy_u8PoseY)
{

	/*Local Error state */
	u8 Local_u8Error = 0;
	u8 Address;
	if (Copy_u8PoseX > 15)
	{
		Local_u8Error = 1;
	}
	else
	{
		if (Copy_u8PoseY == 0) {
			Address = 128 + Copy_u8PoseX;
		} else if (Copy_u8PoseY == 1) {
			Address = 128 + 0x40 + Copy_u8PoseX;
		} else {
			Local_u8Error = 1;
		}
		LCD_u8WriteCommand(Address);

	}
	/*Function shall return the Error state*/
	return (Local_u8Error);

}

/*
 * Description: Write Data to LCD
 * Inputs: Data
 * Outputs:NA
 */
u8 LCD_u8WriteData(u8 Copy_u8Data)
{
	/*Local Error state */
	u8 Local_u8Error = 0;

	/* reset Enable */
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_LOW);

	/* RS =  command register */
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_HIGH);

	/* RW = write */
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

	/* send command */
	Local_u8Error = DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);

	/* Enable sequence */
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_HIGH);
	_delay_ms(2);
	Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_LOW);

	/*Function shall return the Error state*/
	return (Local_u8Error);
}

/*
 * Description: Write string to LCD
 * Inputs: String , Size
 * Outputs:NA
 */
u8 LCD_u8WriteString(u8 * Copy_u8String, u8 Copy_u8Size)
{
	/*Local Error state */
	u8 Local_u8Error = 0;
	u8 Local_u8LoopCounter;

	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < Copy_u8Size;
			Local_u8LoopCounter++) {
		Local_u8Error = LCD_u8WriteData(Copy_u8String[Local_u8LoopCounter]);
	}
	/*Function shall return the Error state*/
	return (Local_u8Error);
}

/*
 * Description: Initialize LCD
 * Inputs: NA
 * Outputs:NA
 */
void LCD_voidInitialize(void)
{
	_delay_ms(30);
	/*function set */
	LCD_u8WriteCommand(0b00111000);
	_delay_ms(1);
	/*display on/off */
	LCD_u8WriteCommand(0b00001100);
	_delay_ms(1);
	/*clear display */
	LCD_u8WriteCommand(0b00000001);
	_delay_ms(2);
}

void LCD_voidWriteSpecialChar(void)
{
	u8 i;
	/*each block 8 bytes*/
	u8 ARR[]={0b00000100,0b00001010,0b00000100,0b00000100,0b00001110,0b00010101,0b00001010,0b00010001};
	/*move to CGRAM*/
	LCD_u8WriteCommand(0b01000000);

	for(i=0;i<8;i++)
	{
		LCD_u8WriteData(ARR[i]);
	}

	LCD_u8GoTo(0,0);
	LCD_u8WriteData(0);/*block 0*/

}

u8 LCD_u8WriteInt(u32 Copy_u8Int)
{
	/*local Error state*/
	u8 Local_u8Error=0;

	u8 Local_u8Remainder[10];
	u8 Local_u8Digits;

	if(Copy_u8Int==0)
	{
		Local_u8Error=LCD_u8WriteData('0');
	}
	else if((Copy_u8Int>0xFFFFFFFF)||(Copy_u8Int<0))
	{
		Local_u8Error=1;
	}
	else
	{
		for(Local_u8Digits=0;Copy_u8Int>0;Local_u8Digits++)
		{
			Local_u8Remainder[Local_u8Digits]=(Copy_u8Int%10)+'0';
			Copy_u8Int/=10;
		}
		do
		{
			Local_u8Error=LCD_u8WriteData(Local_u8Remainder[--Local_u8Digits]);
		}while(Local_u8Digits);

	}

	return (Local_u8Error);

}

/*LCD_voidWriteCustomChar(u8 ARR[64],u8 Copy_u8PoseX, u8 Copy_u8PoseY)
{


}*/
