/********************************************
 *Author:		Ahmed Essam Kamal   *
 *File Name:		USART.c	            *
 *Created on:           May 17, 2019        *
 *Component:		USART_Driver	    *
 *File Version:		v1.0		    *
 ********************************************/

#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void UART_init(void)
{
  UCSRB=0b00011000;
  UCSRC=0b10001110;
  UBRRH=0x00;
  UBRRL=0x33;
}

void UART_Send(u8 data)
{
  while(GET_BIT(UCSRA,5)==0)
  UDR= data;
}

u8 UART_Receiver(void)
{
  while(GET_BIT(UCSRA,7)==0);

  return (UDR);
}
