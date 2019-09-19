/********************************************
*Author:	        Ahmed Essam Kamal   *
*File Name:		LCD_program.c	    *
*Component:		LCD		    *
*File Version:		v1.4		    *
********************************************/

/*******************************************************************************
 *                            Includes                                         *
 *******************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>

/*******************************************************************************
 *                      Functions Declarations                                 *
 *******************************************************************************/

u8 LCD_u8SendCommand (u8 copy_u8Command)
{
  u8 Local_u8Error = 0;
  /*Put Rs to LOW*/
  Local_u8Error = DIO_u8SetPinValue (LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
  /* Put Rw to LOW*/
  Local_u8Error = DIO_u8SetPinValue (LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
  _delay_ms(1);
  /* Put EN to High*/
  Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_HIGH);
  /* Put command on bus*/
  Local_u8Error = LCD_u8PutOnBus (copy_u8Command);

  return (Local_u8Error);
}

/*******************************************************************************
 *******************************************************************************/

u8 LCD_u8PutOnBus (u8 copy_u8Command)
{
  u8 Local_u8Error = 0;

  Local_u8Error = DIO_u8SetPortValue (LCD_DATA_PORT, copy_u8Command);
  /* make Enable High to low with delay to enable the internal latch at the LCD*/
  Local_u8Error = DIO_u8SetPinValue (LCD_CONTROL_PORT,LCD_EN_PIN,DIO_HIGH);
  _delay_ms (2);
  Local_u8Error = DIO_u8SetPinValue (LCD_CONTROL_PORT,LCD_EN_PIN,DIO_LOW);
  _delay_ms (2);

  return (Local_u8Error);
}

/*******************************************************************************
 *******************************************************************************/

u8 LCD_u8GoToXY (u8 Copy_u8PoseX, u8 Copy_u8PoseY)
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
      if (Copy_u8PoseY == 0)
	{
	  Address = 128 + Copy_u8PoseX;
	}
      else if (Copy_u8PoseY == 1)
	{
	  Address = 128 + 0x40 + Copy_u8PoseX;  /* try 0b10000000 instead of 0x40*/
	}
      else
	{
	  Local_u8Error = 1;
	}
      LCD_u8SendCommand(Address);
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

/*******************************************************************************
 *******************************************************************************/

u8 LCD_u8WriteData (u8 Copy_u8Data)
{
  /*Local Error state */
  u8 Local_u8Error = 0;
  /*Put Rs to HIGH*/
  Local_u8Error = DIO_u8SetPinValue (LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
  /* Put Rw to LOW*/
  Local_u8Error = DIO_u8SetPinValue (LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
  /* Put EN to High*/
  Local_u8Error = DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,DIO_HIGH);
  /* Put command on bus*/
  Local_u8Error = LCD_u8PutOnBus (Copy_u8Data);

  return (Local_u8Error);
}

/*******************************************************************************
 *******************************************************************************/

u8 LCD_u8WriteString (u8 *Copy_u8String)
{
  /*Local Error state */
  u8 Local_u8Error = 0;


  while(*Copy_u8String != NULL_CHAR)
    {
      Local_u8Error = LCD_u8WriteData (*Copy_u8String);
      Copy_u8String++;
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

/*******************************************************************************
 *******************************************************************************/

void LCD_voidInitialize (void)
{
  _delay_ms (35);
  LCD_u8SendCommand (LCD_FUNCTION_SET);
  _delay_ms (40);
  LCD_u8SendCommand (LCD_DISPLAY_ON_OFF);
  _delay_ms (40);
  LCD_u8SendCommand (LCD_CLEAR_DISPLAY);
  _delay_ms (2);
  LCD_u8SendCommand (LCD_ENTRY_MODE_SET);
}

/*******************************************************************************
 *******************************************************************************/
void LCD_voidClearScreen(void)
{
  LCD_u8SendCommand(LCD_CLEAR_DISPLAY);
}

/*******************************************************************************
 *******************************************************************************/

void LCD_voidDisplayStringRowColumn(u8 *str, u8 PoseX,u8 PoseY)
{
  LCD_u8GoToXY(PoseX, PoseY);
  LCD_u8WriteString(str);
}


/*******************************************************************************
 *******************************************************************************/

void LCD_voidShiftLeft(void)
{
  LCD_u8SendCommand(LCD_SHIFT_DISPLAY_LEFT);
}


/*******************************************************************************
 *******************************************************************************/

void LCD_voidShiftRight(void)
{
  LCD_u8SendCommand(LCD_SHIFT_DISPLAY_RIGHT);
}

/*******************************************************************************
 *******************************************************************************/


void CreateCustomCharacter (u8 *character,const u8 ChLocation)
{


     LCD_u8SendCommand (LCD_CGRAM_ADDRESS + (ChLocation * 8)); /*Send the Address of CGRAM*/
  for (u8 ArrayIndex=0;ArrayIndex<8;ArrayIndex++)
   {
     LCD_u8WriteData(character[ArrayIndex]); /*Pass the bytes of pattern on LCD*/
   }
}
