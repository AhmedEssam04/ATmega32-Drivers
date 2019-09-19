/*
 * KPD_main.c

 *
 *  Created on: Apr 6, 2019
 *      Author: a7mad
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "KEYPAD_interface.h"
int main(void)
{

  while(1)
    {
      u8 variable;
      KPD_u8GetPressedKey(&variable);       /*gebt 2l function 2lly ana 3amelha w 2edetha addrees l variable ana 3amlo*/
      DIO_u8SetPortValue(KPD_PORT,variable);
      if(variable!=NULL_CHAR)
	{
	  DIO_u8SetPortValue(DIO_PORT_B,variable);
	}
    }
}

