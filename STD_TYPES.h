/*
 * STD_TYPES.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Knight
 */

/********************************************/
/*Author:			AhmedK					*/
/*File Name:		STD_TYPES.h				*/
/*Component:		DIO						*/
/*File Version:		v1.0					*/
/********************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned long int u32;
typedef signed long int s32;

typedef unsigned long long int u64;
typedef signed long long int s64;

typedef float f32;
typedef double f64;
//typedef long double   compiler dependent  ;

#define NULL 0
#define NULL_POINTER (void *)NULL
#define NULL_CHAR NULL /* '\0' */
#define ok 0
#define nok 1//nok==error


#endif /* STD_TYPES_H_ */
