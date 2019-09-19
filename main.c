/********************************************
 *Author:		Ahmed Essam Kamal   *
 *File Name:		main.c	    *
 *Created on:           May 17, 2019             *
 *Component:		USART_Driver	    *
 *File Version:		v1.0		    *
 ********************************************/
#include <avr/io.h>
#include <avr/delay.h>

int main (void)
{
  UART_init();
  /*DIO_init();*/

  UART_Send('A');
  DDRA =0xff;

  if('B'==UART_Receiver())
    {
      PORTA =0xff;
      _delay_ms (500);
      PORTA =0x00;
      _delay_ms (500);
    }
  else
    {
      PORTA =0x00;
      _delay_ms (500);
    }

}

