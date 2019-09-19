/*
 * DIO_intrupt.h
 *
 *  Created on: Apr 28, 2019
 *      Author: dell.pc
 */

#ifndef DIO_EXTERNAL_INTRUPT_H_
#define DIO_EXTERNAL_INTRUPT_H_

typedef enum
{
        DIO_INT_enuFallingEdge=0,
        DIO_INT_enuRisingEdge,
        DIO_INT_enuLow,
        DIO_INT_enuONChain
}DIO_INT_tenuEventType;

#define ENABLED 1 /* interrupt enable*/
#define DISABLED 0 /* interrupt disaple*/
#define INT0_STATE DISABLED  /* int0 initial state*/
#define INT1_STATE DISABLED /* int1  initial state*/
#define INT2_STATE DISABLED/* int2 initial state*/
/* initialization of the 3 dio interrupts*/
u8 DIO_INT0_u8Init(void);
u8 DIO_INT1_u8Init(void);
u8 DIO_INT2_u8Init(void);
/*
 * enable for the 3 inturrupts
 */
void DIO_INT0_voidEnable(void);
void DIO_INT1_voidEnable(void);
void DIO_INT2_voidEnable(void);
/*
 * disable for the 3 interrupts
 */
void DIO_INT0_voidDisable(void);
void DIO_INT1_voidDisable(void);
void DIO_INT2_voidDisable(void);
/*
 * enable and disable for the global interrupt
 */
void DIO_INTGlobal_voidEnable(void);
void DIO_INTGlobal_voidDisable(void);
/*
* select event type for int 0
 */
u8 DIO_INT0_u8EventType(DIO_INT_tenuEventType COPY_enuEventType);
/*
 * select event type for int 1
 */
u8 DIO_INT1_u8EventType(DIO_INT_tenuEventType COPY_enuEventType);
/*
 * select event type for int 2
 */
u8 DIO_INT2_u8EventType(DIO_INT_tenuEventType COPY_enuEventType);


#endif /* DIO_EXTERNAL_INTRUPT_H_ */
