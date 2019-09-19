/*
 * app.c
 *
 *  Created on: Apr 19, 2019
 *      Author: dell.pc
 */

#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"BIT_MATH.h"
#include"keybad_interface.h"
#include "AVR_EXT_REG.h"

void (*ptr)(void);/*defining pointer to a function*/

void __vector_1 (void) __attribute__((signal,used));


void INTP_func(void)
{
	DIO_u8SetPinValue(DIO_PORT_1,DIO_PIN_0,DIO_HIGH);
}

void __vector_1(void)
{
	ptr();/*function through a pointer*/
}
void main(void)
{

	ptr=INTP_func;/*pointer to a function*/

	/*interrupt sense control*/
	SET_BIT(MCUCR,MCUCR_ISC_01);

	CLR_BIT(MCUCR,MCUCR_ISC_00);
	/*enable PIE*/
	SET_BIT(GICR,GICR_INT_0);
	/*enable SREG*/
	SET_BIT(SREG,SREG_I);

	DIO_u8SetPinDirection(DIO_PORT_1,DIO_PIN_0,DIO_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORT_3,DIO_PIN_2,DIO_INPUT);


	while(1)
	{

	}

}

