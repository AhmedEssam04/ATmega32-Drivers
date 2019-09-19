/*
 * KEYPAD_interface.h
 *
 *  Created on: Apr 6, 2019
 *      Author: a7mad
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KPD_PORT   DIO_PORT_A
#define COL_MAX_NB 4
#define ROW_START  4  /*awel pin metwasal 3leha 2l keypad*/
#define ROW_FINAL  8  /*a5er pin metwasal 3leha 2l keypad*/

#endif /* KEYPAD_INTERFACE_H_ */

void KPD_voidInitialize(void);
u8 KPD_u8GetPressedKey(u8 *Copy_u8PressedKeyNB);
