#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_ADC_REG.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>



void initialization(void)
{
	/*select pre-scaler value*/

	CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);

	/*select Adjustment (left)*/

	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*No Interrupt*/

	CLR_BIT(ADCSRA,ADCSRA_ADIF);

	/*Enable ADC*/

	SET_BIT(ADCSRA,ADCSRA_ADEN);

	/*reference selection bit*/

	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

}

void GetADCValue(u8 Channel_NB, u16 *value)
{
	/*select channel (channel 0)*/

	CLR_BIT(ADMUX,ADMUX_MUX4);
	CLR_BIT(ADMUX,ADMUX_MUX3);
	CLR_BIT(ADMUX,ADMUX_MUX2);
	CLR_BIT(ADMUX,ADMUX_MUX1);
	CLR_BIT(ADMUX,ADMUX_MUX0);

	/*start Conversion*/

	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*wait till conversion is*/
	while(!GET_BIT(ADCSRA,ADCSRA_ADIF))
	{

	}
	*value=ADCH;

}

/*Thermal Sensor*/
/*int main(void)
{
	u16 x=0;
	u16 voltage=0;


	initialization();
	DIO_u8SetPortDirection(DIO_PORT_0,255);
	DIO_u8SetPortDirection(DIO_PORT_1,255);

	DIO_u8SetPortDirection(LCD_DATA_PORT,255);
        DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
        DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
        DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_OUTPUT);
        LCD_voidInitialize();
        LCD_u8WriteCommand(1);


	while(1)
	{
		GetADCValue(0,&x);

		voltage=(x*5*100)/256;

		LCD_u8GoTo(0,0);
		LCD_u8WriteString((u8*) "Temp Now=", 11);
		LCD_u8GoTo(9,0);

		LCD_u8WriteInt(x);
		_delay_ms(1000);
		if(voltage==0 && voltage<2500)
		  {
		    DIO_u8SetPinValue(DIO_PORT_0,DIO_PIN_0,255);
		  }
		else if(voltage==2500 && voltage<3750)
		  {
		    DIO_u8SetPinValue(DIO_PORT_0,DIO_PIN_0,255);
		    DIO_u8SetPinValue(DIO_PORT_0,DIO_PIN_1,255);
		  }
		else if(voltage==3750 && voltage<5000)
		  {
		    DIO_u8SetPinValue(DIO_PORT_0,DIO_PIN_0,255);
		    DIO_u8SetPinValue(DIO_PORT_0,DIO_PIN_1,255);
		    DIO_u8SetPinValue(DIO_PORT_0,DIO_PIN_2,255);
		  }

	}
  return(0);
}*/

/* Light Sensor*/

int main (void)
{
  	initialization();
  	DIO_u8SetPortDirection(DIO_PORT_0,255);
  	DIO_u8SetPortDirection(DIO_PORT_1,255);

  	DIO_u8SetPortDirection(LCD_DATA_PORT,255);
        DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
        DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
        DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_OUTPUT);
        LCD_voidInitialize();
        LCD_u8WriteCommand(1);


 while(1)
{
     u16 x=0;
     GetADCValue(8,&x);
     LCD_u8GoTo(1,1);
     for(u8 i=0;i<5;i++)
       {
	 LCD_u8GoTo(0,0);
	 LCD_u8WriteString((u8*) "Value Now=", 11);
	 LCD_u8GoTo(9,0);
         LCD_u8WriteInt(x);

       }
     _delay_ms(500);

}
  return(NULL);
}
