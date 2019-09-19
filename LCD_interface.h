/********************************************
*  Author:       Ahmed Essam Kamal	    *
*  File Name:    LCD_interface.h     	    *
*  Date:         27 Apr 2019                *
*  Component:	 LCD	 	            *
*  File Version: v1.4	                    *
*********************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/********************************************************************************
 *                     Configuration Parameters                                 *
 ********************************************************************************/

#define LCD_EN_PIN 		DIO_PIN_0  /*Enable Signal High-->Read Data, Low-->Write Data*/
#define LCD_RW_PIN 		DIO_PIN_1  /*Read/Write Selection High-->Read operation, Low-->Write operation*/
#define LCD_RS_PIN 		DIO_PIN_2  /*Register Selection High-->Display Data, Low-->Instruction code*/

#define LCD_DATA_PORT 		DIO_PORT_C
#define LCD_CONTROL_PORT 	DIO_PORT_D

/*********************************************************************************
 *                      Display Control Instructions                             *
 *********************************************************************************/

/* NOTE: All these commands are executed when Rs=0 && Rw=0*/

#define LCD_FUNCTION_SET         (0b00111100)   /*00001|8bit_mode|2line_display|5*18Fint|DCare|DCare*/
#define LCD_DISPLAY_ON_OFF       (0b00001100)    /*0000001|DisplayON|CursorOFF|BlinkOFF*/
#define LCD_CLEAR_DISPLAY        (0b00000001)   /*Clears entire display and sets DDRAM address to 00H*/
#define LCD_ENTRY_MODE_SET       (0b00000110)   /*00000001|I/D|SH (s=1&&ID=1 --> shift left,s=1&&ID=1 --> shift right)Sets cursor move direction and enables shift of entire display*/
#define LCD_RETURN_HOME          (0b00000010)   /*sets DDRAM address to 00H in AC & returns to top left position*/
#define LCD_CGRAM_ADDRESS        (0b01000000)   /*01|ADDRESS sets CGRAM to the address counter data is then read from CGRAM*/
#define LCD_DDRAM_ADDRESS        (0b10000000)   /*1|ADDRESS sets the DDRAM address to the AC, law 3ayez an2el 2l ketaba l register mo3ayan fil DDRAM*/
#define LCD_SHIFT_DISPLAY_RIGHT  (0b00011100)   /*Shifts Display to the right*/
#define LCD_SHIFT_DISPLAY_LEFT   (0b00011000)   /*Shifts Display to the left*/
/* Note: the following commands are executed when Rs!=0 OR Rw!=0*/

#define LCD_BUSY_FLAG      (0x80)   /* Rs=0 & Rw=1*/ /*1|ADDRESS indicates that internal operation is in progress and the next instruction will not be accepted until BF=0*/

/* use LCD_CGRAM_ADDRESS or LCD_DDRAM_ADDRESS to choose which one is to be written*/

#define LCD_CGDDRAM_WRITE  (0x00)   /* Rs=1 & Rw=0*/ /* writes data into internal RAM (CGRAM or DDRAM)*/
#define LCD_CGDDRAM_READ   (0x00)   /* Rs=1 & Rw=1*/ /* read data from internal RAM (CGRAM or DDRAM)*/


/*********************************************************************************
 *                          Function Prototypes                                  *
 *********************************************************************************/
u8 LCD_u8SendCommand(u8 Copy_u8Command);

u8 LCD_u8GoToXY(u8 Copy_u8PoseX, u8 Copy_u8PoseY);

u8 LCD_u8WriteData(u8 Copy_u8Data);

u8 LCD_u8WriteString(u8 * Copy_u8String);

u8 LCD_u8PutOnBus(u8 copy_u8Command);

void LCD_voidInitialize(void);

void LCD_voidDisplayStringRowColumn(u8 *str, u8 PoseX,u8 PoseY);

void LCD_voidClearScreen(void);

void LCD_voidShiftRight(void);

void LCD_voidShiftLeft(void);

void LCD_voidCreateCustomCharacter (u8 *character,const u8 ChLocation);

#endif /* LCD_INTERFACE_H_ */
