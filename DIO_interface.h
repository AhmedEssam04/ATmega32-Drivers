#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* AVR PORTS*/
#define DIO_PORT_A 0
#define DIO_PORT_B 1
#define DIO_PORT_C 2
#define DIO_PORT_D 3

/* AVR PINS */
#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

/* AVR Voltage */
#define DIO_LOW  0
#define DIO_HIGH 1

/* AVR INPUT type*/
#define DIO_INPUT  0x00
#define DIO_OUTPUT 0x0f

/* DIO_Directions*/
#define DIO_FLOAT   0
#define DIO_PULL_UP 1

/* Endless Loop */
#define ENDLESS_LOOP 1

/* DIO Driver Functions*/
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB, u8 Copy_u8Dir);

u8 DIO_u8SetPinDirection(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Dir);

u8 DIO_u8SetPortValue(u8 Copy_u8PortNB, u8 Copy_u8Value);

u8 DIO_u8SetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Value);

u8 DIO_u8GetPortValue(u8 Copy_u8PortNB, u8 *Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 *Copy_u8Value);

u8 DIO_u8SetPortInputType(u8 Copy_u8PortNB, u8 Copy_u8Type);

u8 DIO_u8SetPinInputType(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Type);

#endif
