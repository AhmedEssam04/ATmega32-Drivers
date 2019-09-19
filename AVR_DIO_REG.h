/*
 * AVR_DIO_REG.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Knight
 */

/********************************************/
/*Author:			AhmedK					*/
/*File Name:		AVR_DIO_REG.h			*/
/*Component:		DIO						*/
/*File Version:		v1.0					*/
/********************************************/

#ifndef AVR_DIO_REG_H_
#define AVR_DIO_REG_H_

/* A Registers */
#define DDRA  (*((u8 *)0x3A))
#define PORTA (*((u8 *)0x3B))
#define PINA  (*((u8 *)0x39))

/* B Registers */
#define DDRB  (*((u8 *)0x37))
#define PORTB (*((u8 *)0x38))
#define PINB  (*((u8 *)0x36))

/* C Registers */
#define DDRC  (*((u8 *)0x34))
#define PORTC (*((u8 *)0x35))
#define PINC  (*((u8 *)0x33))

/* D Registers */
#define DDRD  (*((u8 *)0x31))
#define PORTD (*((u8 *)0x32))
#define PIND  (*((u8 *)0x30))

#endif /* AVR_DIO_REG_H_ */
