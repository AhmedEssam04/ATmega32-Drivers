/*
 * AVR_ADC_REG.h
 *
 *  Created on: May 3, 2019
 *      Author: dell.pc
 */

#ifndef AVR_ADC_REG_H_
#define AVR_ADC_REG_H_

/* ADC control registers*/
#define    ADMUX  (*((u8*)0x27))
#define    ADCSRA (*((u8*)0x26))
#define    ADCH   (*((u8*)0x25))
#define    ADCL   (*((u8*)0x24))
#define    SFIOR  (*((u8*)0x50))

/*control bits*/
/*ADMUX*/
#define  ADMUX_REFS1  7
#define  ADMUX_REFS0  6
#define  ADMUX_ADLAR  5
#define  ADMUX_MUX4   4
#define  ADMUX_MUX3   3
#define  ADMUX_MUX2   2
#define  ADMUX_MUX1   1
#define  ADMUX_MUX0   0

/*ADCSRA*/
#define  ADCSRA_ADEN   7
#define  ADCSRA_ADSC   6
#define  ADCSRA_ADATE  5
#define  ADCSRA_ADIF   4
#define  ADCSRA_ADIE   3
#define  ADCSRA_ADPS2  2
#define  ADCSRA_ADPS1  1
#define  ADCSRA_ADPS0  0

/*SFIOR*/

#define  SFIOR_ADTS2   7
#define  SFIOR_ADTS1   6
#define  SFIOR_ADTS0   5








#endif /* AVR_ADC_REG_H_ */
