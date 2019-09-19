/********************************************
 *Author:		Ahmed Essam Kamal   *
 *File Name:		main.c	    *
 *Created on:           May 18, 2019             *
 *Component:		SPI_Driver	    *
 *File Version:		v1.0		    *
 ********************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "SPI.h"

int main (void)
{
     SPI_MasterInit();
     u8 data='A';

     while(1)
       {
	 SPI_Transmit(data);
	 if('B'==SPI_Transmit(data))
	     {
	       PORTA =0xff;
	       _delay_ms (500);
	       PORTA =0x00;
	       _delay_ms (500);
	     }
       }


}

