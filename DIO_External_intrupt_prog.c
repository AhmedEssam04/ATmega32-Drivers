/*
 * DIO_intrupt_prog.c
 *
 *  Created on: Apr 28, 2019
 *      Author: dell.pc
 */
#include "STD_TYPES.h"
#include "AVR_EXT_REG.h"
#include "DIO_External_intrupt.h"
#include"BIT_MATH.h"

/*3 initialization functions*/

u8 DIO_INT0_u8Init(void)
{
        u8        LOC_u8Err=0;
#if(INT0_STATE==ENABLED )
        {
                SET_BIT(GICR,GICR_INT_0);
        }
#elif(INT0_STATE==DISABLED )
        {
                CLR_BIT(GICR,GICR_INT_0);
        }
#else
        {
                LOC_u8Err=1;
        }
#endif
        return (LOC_u8Err);
}

u8 DIO_INT1_u8Init(void)
{
        u8        LOC_u8Err=0;
#if(INT1_STATE==ENABLED )
        {
                SET_BIT(GICR,GICR_INT_1);
        }
#elif(INT1_STATE==DISABLED )
        {
                CLR_BIT(GICR,GICR_INT_1);
        }
#else
        {
                LOC_u8Err=1;
        }
#endif
        return (LOC_u8Err);
}

u8 DIO_INT2_u8Init(void)
{
        u8        LOC_u8Err=0;
#if(INT2_STATE==ENABLED )
        {
                SET_BIT(GICR,GICR_INT_2);
        }
#elif(INT2_STATE==DISABLED )
        {
                CLR_BIT(GICR,GICR_INT_2);
        }
#else
        {
                LOC_u8Err=1;
        }
#endif
        return (LOC_u8Err);
}



/*3 enable functions*/


void DIO_INT0_vidEnable(void)
{
        SET_BIT(GICR,GICR_INT_0);
}
void DIO_INT1_vidEnable(void)
{
        SET_BIT(GICR,GICR_INT_1);
}

void DIO_INT2_vidEnable(void)
{
        SET_BIT(GICR,GICR_INT_2);
}

/*3 disable functions*/

void DIO_INT0_vidDisable(void)
{
        CLR_BIT(GICR,GICR_INT_0);
}
void DIO_INT1_vidDisable(void)
{
        CLR_BIT(GICR,GICR_INT_1);
}
void DIO_INT2_vidDisable(void)
{
        CLR_BIT(GICR,GICR_INT_2);
}

/* Global intrupt enable and disable*/

void DIO_INTGlobal_vidEnable(void)
{
        SET_BIT(SREG,SREG_I);
}
void DIO_INTGlobal_vidDisable(void)
{
        CLR_BIT(SREG,SREG_I);
}

/*3 intrupt Event types*/

/*
 * select event type for int 0
 */
u8 DIO_INT0_u8EventType(DIO_INT_tenuEventType COPY_enuEventType)
{
        u8 LOC_u8Err=0;
        switch(COPY_enuEventType)
        {
        case DIO_INT_enuFallingEdge:
                SET_BIT(MCUCR,MCUCR_ISC_01);
                CLR_BIT(MCUCR,MCUCR_ISC_00);
                break;
        case DIO_INT_enuRisingEdge:
                SET_BIT(MCUCR,MCUCR_ISC_01);
                SET_BIT(MCUCR,MCUCR_ISC_00);
                break;
        case DIO_INT_enuLow:
                CLR_BIT(MCUCR,MCUCR_ISC_01);
                CLR_BIT(MCUCR,MCUCR_ISC_00);
                break;
        case DIO_INT_enuONChain:
                CLR_BIT(MCUCR,MCUCR_ISC_01);
                SET_BIT(MCUCR,MCUCR_ISC_00);
                break;
        default:
                LOC_u8Err=1;
                break;

        }
        return (LOC_u8Err);
}


/*
 * select event type for int 1
 */
u8 DIO_INT1_u8EventType(DIO_INT_tenuEventType COPY_enuEventType)
{
        u8 LOC_u8Err=0;
        switch(COPY_enuEventType)
        {
        case DIO_INT_enuFallingEdge:
                SET_BIT(MCUCR,MCUCR_ISC_01);
                CLR_BIT(MCUCR,MCUCR_ISC_00);
                break;
        case DIO_INT_enuRisingEdge:
                SET_BIT(MCUCR,MCUCR_ISC_01);
                SET_BIT(MCUCR,MCUCR_ISC_00);
                break;
        case DIO_INT_enuLow:
                CLR_BIT(MCUCR,MCUCR_ISC_01);
                CLR_BIT(MCUCR,MCUCR_ISC_00);
                break;
        case DIO_INT_enuONChain:
                CLR_BIT(MCUCR,MCUCR_ISC_01);
                SET_BIT(MCUCR,MCUCR_ISC_00);
                break;
        default:
                LOC_u8Err=1;
                break;

        }
        return (LOC_u8Err);
}

/*
 * select event type for int 2
 */
u8 DIO_INT2_u8EventType(DIO_INT_tenuEventType COPY_enuEventType)
{
        u8 LOC_u8Err=0;
        switch(COPY_enuEventType)
        {
        case DIO_INT_enuFallingEdge:
                SET_BIT(MCUCR,MCUCR_ISC_01);
                CLR_BIT(MCUCR,MCUCR_ISC_00);
                break;
        case DIO_INT_enuRisingEdge:
                SET_BIT(MCUCR,MCUCR_ISC_01);
                SET_BIT(MCUCR,MCUCR_ISC_00);
                break;
        case DIO_INT_enuLow:
                CLR_BIT(MCUCR,MCUCR_ISC_01);
                CLR_BIT(MCUCR,MCUCR_ISC_00);
                break;
        case DIO_INT_enuONChain:
                CLR_BIT(MCUCR,MCUCR_ISC_01);
                SET_BIT(MCUCR,MCUCR_ISC_00);
                break;
        default:
                LOC_u8Err=1;
                break;

        }
        return (LOC_u8Err);
}
