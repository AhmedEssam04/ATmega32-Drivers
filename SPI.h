/********************************************
 *Author:		Ahmed Essam Kamal   *
 *File Name:		SPI.h	    *
 *Created on:           May 18, 2019             *
 *Component:		SPI_Driver	    *
 *File Version:		v1.0		    *
 ********************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#ifndef SPI_H_
#define SPI_H_

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
u8   SPI_Transmit(u8 data);

#endif /* SPI_H_ */
