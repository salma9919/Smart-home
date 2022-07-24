/*
 * LCD_interface.h
 *
 *  Created on: Aug 15, 2021
 *      Author: HP
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidsendcommand(u8 Copy_u8Command);
void LCD_voidsendData(u8 Copy_u8Data);
void LCD_voidInit(void);
void LCD_sendString(const char* copy_pcString);
void gotoxy(u8 copy_xpos, u8 copy_ypos);
void LCD_writeSpecial_char(u8 * copy_patter, u8 copy_pattnumber,u8 copy_xpos,u8 copy_ypos);

#endif /* LCD_INTERFACE_H_ */
