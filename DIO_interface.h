/*
 * DIO_interface.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Knight
 */

/********************************************/
/*Author:			AhmedK					*/
/*File Name:		DIO_interface.h			*/
/*Component:		DIO						*/
/*File Version:		v1.0					*/
/********************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Port Numbers */
#define DIO_PORT_0 0
#define DIO_PORT_1 1
#define DIO_PORT_2 2
#define DIO_PORT_3 3

/* Pin Numbers */
#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

/* Directions */
#define DIO_INPUT  0
#define DIO_OUTPUT 1

/* Values */
#define DIO_LOW  0
#define DIO_HIGH 1

/* Types */
#define DIO_FLOAT  0
#define DIO_PULL_UP 1

/* DIO_Directions*/

/*
 * Description: Set Port Direction
 * Inputs: Port Number , Direction
 * Outputs:NA
 */
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB, u8 Copy_u8Dir);

/*
 * Description: Set Pin Direction
 * Inputs: Port Number , Pin Number , Direction
 * Outputs:NA
 */
u8 DIO_u8SetPinDirection(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Dir);

/* Set_Values */

/*
 * Description: Set Port Value
 * Inputs: Port Number , Value
 * Outputs:NA
 */
u8 DIO_u8SetPortValue(u8 Copy_u8PortNB, u8 Copy_u8Value);

/*
 * Description: Set Pin Value
 * Inputs: Port Number , Pin Number , Value
 * Outputs:NA
 */
u8 DIO_u8SetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Value);

/* Get_Values */

/*
 * Description: Get Port Value
 * Inputs: Port Number , Pointer to Value
 * Outputs:NA
 */
u8 DIO_u8GetPortValue(u8 Copy_u8PortNB, u8 *Copy_u8Value);

/*
 * Description: Get Pin Value
 * Inputs: Port Number , Pin Number , Pointer to Value
 * Outputs:NA
 */
u8 DIO_u8GetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 *Copy_u8Value);

/*
 * Description: Set Port Input Type
 * Inputs: Port Number , Value
 * Outputs:NA
 */
u8 DIO_u8SetPortInputType(u8 Copy_u8PortNB, u8 Copy_u8Type);

/*
 * Description: Set Pin Input Type
 * Inputs: Port Number , Pin Number , Type
 * Outputs:NA
 */
u8 DIO_u8SetPinInputType(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Type);

#endif /* DIO_INTERFACE_H_ */
