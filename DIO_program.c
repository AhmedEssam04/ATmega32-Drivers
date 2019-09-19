/*
 * DIO_program.c
 *
 *  Created on: Mar 29, 2019
 *      Author: Knight
 */

/********************************************/
/*Author:			AhmedK					*/
/*File Name:		DIO_program.c			*/
/*Component:		DIO						*/
/*File Version:		v1.0					*/
/********************************************/

/*file includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "DIO_interface.h"

/*function implementation*/

/*
 * Description: Set Port Direction
 * Inputs: Port Number , Direction
 * Outputs:NA
 */
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB, u8 Copy_u8Dir) {
	/*Local Error state */
	u8 Local_u8Error = ok;
	/* Check on the Required PORT Number */
	switch (Copy_u8PortNB) {
	case DIO_PORT_0:
		DDRA = Copy_u8Dir;
		break;
	case DIO_PORT_1:
		DDRB = Copy_u8Dir;
		break;
	case DIO_PORT_2:
		DDRC = Copy_u8Dir;
		break;
	case DIO_PORT_3:
		DDRD = Copy_u8Dir;
		break;
	default: /* Wrong Port Number */
		Local_u8Error = nok;
	}
	/*Function shall return the Error state*/
	return (Local_u8Error);
}

/*
 * Description: Set Port Value
 * Inputs: Port Number , Value
 * Outputs:NA
 */
u8 DIO_u8SetPortValue(u8 Copy_u8PortNB, u8 Copy_u8Value) {
	/*Local Error state */
	u8 Local_u8Error = ok;
	/* Check on the Required PORT Number */
	switch (Copy_u8PortNB) {
	case DIO_PORT_0:
		PORTA = Copy_u8Value;
		break;
	case DIO_PORT_1:
		PORTB = Copy_u8Value;
		break;
	case DIO_PORT_2:
		PORTC = Copy_u8Value;
		break;
	case DIO_PORT_3:
		PORTD = Copy_u8Value;
		break;
	default: /* Wrong Port Number */
		Local_u8Error = nok;
	}
	/*Function shall return the Error state*/
	return (Local_u8Error);
}

/*
 * Description: Set Pin Direction
 * Inputs: Port Number , Pin Number , Direction
 * Outputs:NA
 */
u8 DIO_u8SetPinDirection(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Dir) {
	/*Local Error state */
	u8 Local_u8Error = ok;
	/* Make sure that the Pin Number is in the valid range */
	if (Copy_u8PinNB > DIO_PIN_7) {
		Local_u8Error = nok;
		/* Make sure that the Directions are in the valid range */
	} else if ((Copy_u8Dir != DIO_INPUT) && (Copy_u8Dir != DIO_OUTPUT)) {
		Local_u8Error = nok;
	} else {
		/* Check on the Required PORT Number */
		switch (Copy_u8PortNB) {
		case DIO_PORT_0:
			ASSIGN_BIT(DDRA, Copy_u8PinNB, Copy_u8Dir);
			break;
		case DIO_PORT_1:
			ASSIGN_BIT(DDRB, Copy_u8PinNB, Copy_u8Dir);
			break;
		case DIO_PORT_2:
			ASSIGN_BIT(DDRC, Copy_u8PinNB, Copy_u8Dir);
			break;
		case DIO_PORT_3:
			ASSIGN_BIT(DDRD, Copy_u8PinNB, Copy_u8Dir);
			break;
		default: /* Wrong Port Number */
			Local_u8Error = nok;
			break;
		}
	}
	/*Function shall return the Error state*/
	return (Local_u8Error);
}

/*
 * Description: Set Pin Value
 * Inputs: Port Number , Pin Number , Value
 * Outputs:NA
 */
u8 DIO_u8SetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Value) {
	/*Local Error state */
	u8 Local_u8Error = ok;
	/* Make sure that the Pin Number is in the valid range */
	if (Copy_u8PinNB > DIO_PIN_7) {
		Local_u8Error = nok;
		/* Make sure that the Values are in the valid range */
	} else if ((Copy_u8Value != DIO_LOW) && (Copy_u8Value != DIO_HIGH)) {
		Local_u8Error = nok;
	} else {
		/* Check on the Required PORT Number */
		switch (Copy_u8PortNB) {
		case DIO_PORT_0:
			ASSIGN_BIT(PORTA, Copy_u8PinNB, Copy_u8Value);
			break;
		case DIO_PORT_1:
			ASSIGN_BIT(PORTB, Copy_u8PinNB, Copy_u8Value);
			break;
		case DIO_PORT_2:
			ASSIGN_BIT(PORTC, Copy_u8PinNB, Copy_u8Value);
			break;
		case DIO_PORT_3:
			ASSIGN_BIT(PORTD, Copy_u8PinNB, Copy_u8Value);
			break;
		default: /* Wrong Port Number */
			Local_u8Error = nok;
			break;
		}
	}
	/*Function shall return the Error state*/
	return (Local_u8Error);
}

/*
 * Description: Get Port Value
 * Inputs: Port Number , Pointer to Value
 * Outputs:NA
 */
u8 DIO_u8GetPortValue(u8 Copy_u8PortNB, u8 *Copy_u8Value) {
	/*Local Error state */
	u8 Local_u8Error = ok;
	/* Make sure that the Pointer is not a Null Pointer */
	if (Copy_u8Value == NULL_POINTER) {
		Local_u8Error = nok;
	} else {
		/* Check on the Required PORT Number */
		switch (Copy_u8PortNB) {
		case DIO_PORT_0:
			(*Copy_u8Value) = PINA;
			break;
		case DIO_PORT_1:
			(*Copy_u8Value) = PINB;
			break;
		case DIO_PORT_2:
			(*Copy_u8Value) = PINC;
			break;
		case DIO_PORT_3:
			(*Copy_u8Value) = PIND;
			break;
		default: /* Wrong Port Number */
			Local_u8Error = nok;
			break;
		}
	}
	/*Function shall return the Error state*/
	return (Local_u8Error);
}

/*
 * Description: Get Pin Value
 * Inputs: Port Number , Pin Number , Pointer to Value
 * Outputs: NA
 */
u8 DIO_u8GetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 *Copy_u8Value) {
	/*Local Error state */
	u8 Local_u8Error = ok;
	/* Make sure that the Pointer is not a Null Pointer */
	if (Copy_u8Value == NULL_POINTER) {
		Local_u8Error = nok;
		/* Make sure that the Pin Number is in the valid range */
	} else if (Copy_u8PinNB > DIO_PIN_7) {
		Local_u8Error = nok;
	} else {
		/* Check on the Required PORT Number */
		switch (Copy_u8PortNB) {
		case DIO_PORT_0:
			(*Copy_u8Value) = GET_BIT(PINA, Copy_u8PinNB);
			break;
		case DIO_PORT_1:
			(*Copy_u8Value) = GET_BIT(PINB, Copy_u8PinNB);
			break;
		case DIO_PORT_2:
			(*Copy_u8Value) = GET_BIT(PINC, Copy_u8PinNB);
			break;
		case DIO_PORT_3:
			(*Copy_u8Value) = GET_BIT(PIND, Copy_u8PinNB);
			break;
		default: /* Wrong Port Number */
			Local_u8Error = nok;
			break;
		}
	}
	/*Function shall return the Error state*/
	return (Local_u8Error);
}

/*
 * Description: Set Port Input Type
 * Inputs: Port Number , Value
 * Outputs:NA
 */
/*float or pull-up in case of input pin or port (lw ana 3ayez a5leha floating aw internal pull-up)*/
u8 DIO_u8SetPortInputType(u8 Copy_u8PortNB, u8 Copy_u8Type) {
	/*Local Error state */
	u8 Local_u8Error = ok;
	/* Check on the Required PORT Number */
	switch (Copy_u8PortNB) {
	case DIO_PORT_0:
		PORTA = Copy_u8Type;
		break;
	case DIO_PORT_1:
		PORTB = Copy_u8Type;
		break;
	case DIO_PORT_2:
		PORTC = Copy_u8Type;
		break;
	case DIO_PORT_3:
		PORTD = Copy_u8Type;
		break;
	default: /* Wrong Port Number */
		Local_u8Error = nok;
	}
	/*Function shall return the Error state*/
	return (Local_u8Error);
}

/*
 * Description: Set Pin Input Type
 * Inputs: Port Number , Pin Number , Type
 * Outputs:NA
 */

/*float or pull-up in case of input*/
u8 DIO_u8SetPinInputType(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Type) {
	/*Local Error state */
	u8 Local_u8Error = ok;
	/* Make sure that the Pin Number is in the valid range */
	if (Copy_u8PinNB > DIO_PIN_7) {
		Local_u8Error = nok;
		/* Make sure that the Types are in the valid range */
	} else if ((Copy_u8Type != DIO_FLOAT) && (Copy_u8Type != DIO_PULL_UP)) {
		Local_u8Error = nok;
	} else {
		/* Check on the Required PORT Number */
		switch (Copy_u8PortNB) {
		case DIO_PORT_0:
			ASSIGN_BIT(PORTA, Copy_u8PinNB, Copy_u8Type);
			break;
		case DIO_PORT_1:
			ASSIGN_BIT(PORTB, Copy_u8PinNB, Copy_u8Type);
			break;
		case DIO_PORT_2:
			ASSIGN_BIT(PORTC, Copy_u8PinNB, Copy_u8Type);
			break;
		case DIO_PORT_3:
			ASSIGN_BIT(PORTD, Copy_u8PinNB, Copy_u8Type);
			break;
		default: /* Wrong Port Number */
			Local_u8Error = nok;
			break;
		}
	}
	/*Function shall return the Error state*/
	return (Local_u8Error);
}

