/*
 * AVR_EXT_REG.h
 *
 *  Created on: Apr 19, 2019
 *      Author: dell.pc
 */

#ifndef AVR_EXT_REG_H_
#define AVR_EXT_REG_H_

#define  SREG    (*((u8*)0x5F))
#define  MCUCR   (*((u8*)0x55))
#define  MCUCSR  (*((u8*)0x54))
#define  GICR    (*((u8*)0x5B))
#define  GIFR    (*((u8*)0x5A))


#define MCUCR_ISC_00  0
#define MCUCR_ISC_01  1
#define MCUCR_ISC_10  2
#define MCUCR_ISC_11  4

#define MCUCSR_ISC2   6

#define GICR_INT_2    5
#define GICR_INT_0    6
#define GICR_INT_1    7

#define GIFR_INTF2    5
#define GIFR_INTF0    6
#define GIFR_INTF1    7

#define SREG_C       0
#define SREG_Z       1
#define SREG_N       2
#define SREG_V       3
#define SREG_S       4
#define SREG_H       5
#define SREG_T       6
#define SREG_I       7



#endif /* AVR_EXT_REG_H_ */
