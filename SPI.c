/********************************************
 *Author:		Ahmed Essam Kamal   *
 *File Name:		SPI.c	    *
 *Created on:           May 18, 2019             *
 *Component:		SPI_Driver	    *
 *File Version:		v1.0		    *
 ********************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include "SPI.h"

void SPI_MasterInit(void)
{
  SPCR=0b01110010;
}


void SPI_SlaveInit(void)
{
  SPCR=0b01100010;
}

u8 SPI_Transmit(u8 data)
{
  SPDR=data;
  while(GET_BIT(SPSR,7)==0);

  return (SPDR);
}
