/*
 * keybad_interface.h
 *
 *  Created on: Apr 6, 2019
 *      Author: dell.pc
 */

#ifndef KEYBAD_INTERFACE_H_
#define KEYBAD_INTERFACE_H_

#define KBD_PORT  DIO_PORT_0
#define Col_Final 		4
#define Row_Start 		4
#define Row_Final 		8


void KBD_vidInit(void);
void KBD_u8GetPressedValue(u8* Copy_u8PressedKeyNB);


#endif /* KEYBAD_INTERFACE_H_ */
