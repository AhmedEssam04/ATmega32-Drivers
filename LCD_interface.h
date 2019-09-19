/*
 * LCD_interface.h
 *
 *  Created on: Mar 30, 2019
 *      Author: Knight
 */

/********************************************/
/*Author:			AhmedK					*/
/*File Name:		LCD_interface.h			*/
/*Component:		LCD						*/
/*File Version:		v1.0					*/
/********************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* configuration parameters */
#define LCD_DATA_PORT 		DIO_PORT_2
#define LCD_CONTROL_PORT 	DIO_PORT_1
#define LCD_RS_PIN 		DIO_PIN_0
#define LCD_RW_PIN 		DIO_PIN_1
#define LCD_EN_PIN 		DIO_PIN_2

/*
 * Description: Write Command to LCD
 * Inputs: Command
 * Outputs:NA
 */
u8 LCD_u8WriteCommand(u8 Copy_u8Command);

/*
 * Description: set LCD AC " address counter "
 * Inputs: PoseX , PoseY
 * Outputs:NA
 */
u8 LCD_u8GoTo(u8 Copy_u8PoseX, u8 Copy_u8PoseY);

/*
 * Description: Write Data to LCD
 * Inputs: Data
 * Outputs:NA
 */
u8 LCD_u8WriteData(u8 Copy_u8Data);

/*
 * Description: Write string to LCD
 * Inputs: String , Size
 * Outputs:NA
 */
u8 LCD_u8WriteString(u8 * Copy_u8String, u8 Copy_u8Size);

/*
 * Description: Initialize LCD
 * Inputs: NA
 * Outputs:NA
 */
void LCD_voidInitialize(void);

#endif /* LCD_INTERFACE_H_ */
