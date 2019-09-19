/*
 * DIO_program.c
 *
 *  Created on: Mar 29, 2019
 *      Author: Knight
 */

/********************************************/
/*Author:		Ahmed Essam Kamal   */
/*File Name:		DIO_program.c	    */
/*Component:		DIO		    */
/*File Version:		v1.0		    */
/********************************************/

/*file includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "DIO_interface.h"

/*Function Implementation*/

u8
DIO_u8SetPortDirection (u8 Copy_u8PortNB, u8 Copy_u8Dir)
{
  /*Local Error state */
  u8 (Local_u8Error) = 0;
  /* Check on the Required PORT Number */
  switch (Copy_u8PortNB)
    {
    case DIO_PORT_A:
      DDRA = Copy_u8Dir;
      break;
    case DIO_PORT_B:
      DDRB = Copy_u8Dir;
      break;
    case DIO_PORT_C:
      DDRC = Copy_u8Dir;
      break;
    case DIO_PORT_D:
      DDRD = Copy_u8Dir;
      break;
    default: /* Wrong Port Number */
      (Local_u8Error) = 1;
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

u8
DIO_u8SetPortValue (u8 Copy_u8PortNB, u8 Copy_u8Value)
{
  /*Local Error state */
  u8 (Local_u8Error) = 0;
  /* Check on the Required PORT Number */
  switch (Copy_u8PortNB)
    {
    case DIO_PORT_A:
      PORTA = Copy_u8Value;
      break;
    case DIO_PORT_B:
      PORTB = Copy_u8Value;
      break;
    case DIO_PORT_C:
      PORTC = Copy_u8Value;
      break;
    case DIO_PORT_D:
      PORTD = Copy_u8Value;
      break;
    default: /* Wrong Port Number */
      (Local_u8Error) = 1;
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

u8
DIO_u8SetPinDirection (u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Dir)
{
  /*Local Error state */
  u8 (Local_u8Error) = 0;
  /* Make sure that the Pin Number is in the valid range */
  if (Copy_u8PinNB > DIO_PIN_7)
    {
      (Local_u8Error) = 1;
      /* Make sure that the Directions are in the valid range */
    }
  else if ((Copy_u8Dir != DIO_INPUT) && (Copy_u8Dir != DIO_OUTPUT))
    {
      (Local_u8Error) = 1;
    }
  else
    {
      /* Check on the Required PORT Number */
      switch (Copy_u8PortNB)
	{
	case DIO_PORT_A:
	  ASSIGN_BIT(DDRA, Copy_u8PinNB, Copy_u8Dir);
	  break;
	case DIO_PORT_B:
	  ASSIGN_BIT(DDRB, Copy_u8PinNB, Copy_u8Dir);
	  break;
	case DIO_PORT_C:
	  ASSIGN_BIT(DDRC, Copy_u8PinNB, Copy_u8Dir);
	  break;
	case DIO_PORT_D:
	  ASSIGN_BIT(DDRD, Copy_u8PinNB, Copy_u8Dir);
	  break;
	default: /* Wrong Port Number */
	  (Local_u8Error) = 1;
	  break;
	}
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

u8
DIO_u8SetPinValue (u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Value)
{
  /*Local Error state */
  u8 (Local_u8Error) = 0;
  /* Make sure that the Pin Number is in the valid range */
  if (Copy_u8PinNB > DIO_PIN_7)
    {
      (Local_u8Error) = 1;
      /* Make sure that the Values are in the valid range */
    }
  else if ((Copy_u8Value != DIO_LOW) && (Copy_u8Value != DIO_HIGH))
    {
      (Local_u8Error) = 1;
    }
  else
    {
      /* Check on the Required PORT Number */
      switch (Copy_u8PortNB)
	{
	case DIO_PORT_A:
	  ASSIGN_BIT(PORTA, Copy_u8PinNB, Copy_u8Value);
	  break;
	case DIO_PORT_B:
	  ASSIGN_BIT(PORTB, Copy_u8PinNB, Copy_u8Value);
	  break;
	case DIO_PORT_C:
	  ASSIGN_BIT(PORTC, Copy_u8PinNB, Copy_u8Value);
	  break;
	case DIO_PORT_D:
	  ASSIGN_BIT(PORTD, Copy_u8PinNB, Copy_u8Value);
	  break;
	default: /* Wrong Port Number */
	  (Local_u8Error) = 1;
	  break;
	}
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

u8
DIO_u8GetPortValue (u8 Copy_u8PortNB, u8 *Copy_u8Value)
{
  /*Local Error state */
  u8 (Local_u8Error) = 0;
  /* Make sure that the Pointer is not a Null Pointer */
  if (Copy_u8Value == NULL_POINTER)
    {
      (Local_u8Error) = 1;
    }
  else
    {
      /* Check on the Required PORT Number */
      switch (Copy_u8PortNB)
	{
	case DIO_PORT_A:
	  (*Copy_u8Value) = PINA;
	  break;
	case DIO_PORT_B:
	  (*Copy_u8Value) = PINB;
	  break;
	case DIO_PORT_C:
	  (*Copy_u8Value) = PINC;
	  break;
	case DIO_PORT_D:
	  (*Copy_u8Value) = PIND;
	  break;
	default: /* Wrong Port Number */
	  (Local_u8Error) = 1;
	  break;
	}
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

u8
DIO_u8GetPinValue (u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 *Copy_u8Value)
{
  /*Local Error state */
  u8 (Local_u8Error) = 0;
  /* Make sure that the Pointer is not a Null Pointer */
  if (Copy_u8Value == NULL_POINTER)
    {
      (Local_u8Error) = 1;
      /* Make sure that the Pin Number is in the valid range */
    }
  else if (Copy_u8PinNB > DIO_PIN_7)
    {
      (Local_u8Error) = 1;
    }
  else
    {
      /* Check on the Required PORT Number */
      switch (Copy_u8PortNB)
	{
	case DIO_PORT_A:
	  (*Copy_u8Value) = GET_BIT(PINA, Copy_u8PinNB);
	  break;
	case DIO_PORT_B:
	  (*Copy_u8Value) = GET_BIT(PINB, Copy_u8PinNB);
	  break;
	case DIO_PORT_C:
	  (*Copy_u8Value) = GET_BIT(PINC, Copy_u8PinNB);
	  break;
	case DIO_PORT_D:
	  (*Copy_u8Value) = GET_BIT(PIND, Copy_u8PinNB);
	  break;
	default: /* Wrong Port Number */
	  (Local_u8Error) = 1;
	  break;
	}
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

u8
DIO_u8SetPortInputType (u8 Copy_u8PortNB, u8 Copy_u8Type)
{
  /*Local Error state */
  u8 (Local_u8Error) = 0;
  /* Check on the Required PORT Number */
  switch (Copy_u8PortNB)
    {
    case DIO_PORT_A:
      PORTA = Copy_u8Type;
      break;
    case DIO_PORT_B:
      PORTB = Copy_u8Type;
      break;
    case DIO_PORT_C:
      PORTC = Copy_u8Type;
      break;
    case DIO_PORT_D:
      PORTD = Copy_u8Type;
      break;
    default: /* Wrong Port Number */
      (Local_u8Error) = 1;
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

u8
DIO_u8SetPinInputType (u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Type)
{
  /*Local Error state */
  u8 (Local_u8Error) = 0;
  /* Make sure that the Pin Number is in the valid range */
  if (Copy_u8PinNB > DIO_PIN_7)
    {
      (Local_u8Error) = 1;
      /* Make sure that the Types are in the valid range */
    }
  else if ((Copy_u8Type != DIO_FLOAT) && (Copy_u8Type != DIO_PULL_UP))
    {
      (Local_u8Error) = 1;
    }
  else
    {
      /* Check on the Required PORT Number */
      switch (Copy_u8PortNB)
	{
	case DIO_PORT_A:
	  ASSIGN_BIT(PORTA, Copy_u8PinNB, Copy_u8Type);
	  break;
	case DIO_PORT_B:
	  ASSIGN_BIT(PORTB, Copy_u8PinNB, Copy_u8Type);
	  break;
	case DIO_PORT_C:
	  ASSIGN_BIT(PORTC, Copy_u8PinNB, Copy_u8Type);
	  break;
	case DIO_PORT_D:
	  ASSIGN_BIT(PORTD, Copy_u8PinNB, Copy_u8Type);
	  break;
	default: /* Wrong Port Number */
	  (Local_u8Error) = 1;
	  break;
	}
    }
  /*Function shall return the Error state*/
  return (Local_u8Error);
}

