/*
 * LCD_program.c
 *
 *  Created on: Aug 15, 2021
 *      Author: HP
 */

#define F_CPU 8000000
#include "util/delay.h"

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"

void LCD_voidsendcommand(u8 Copy_u8Command)
{
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8LOW);
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);
	_delay_ms(2);


	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);


}

void LCD_voidsendData(u8 Copy_u8Data)
{
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8HIGH);
			DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);
			DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Data);
			DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);
			_delay_ms(2);
			DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);
}

void LCD_voidInit(void)
{
	_delay_ms(30);
	LCD_voidsendcommand(0b00111000); ///working on 8-bit _ 2-line _ 5x7 font
	LCD_voidsendcommand(0b00001100); ///function ON /OFF DISPLAY //KAN FE 0 ZYADA!!
	LCD_voidsendcommand(1);
}

void LCD_sendString(const char* copy_pcString)
{
	u8 local_u8counter=0;
	while(copy_pcString[local_u8counter]!='\0')
	{
		LCD_voidsendData(copy_pcString[local_u8counter]);

		local_u8counter++;
	}


}
/*void Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	LCD_voidsendcommand(X+127);
		    break;
		    case 2:
		    	LCD_voidsendcommand(X+191);
		    break;
		    default:
		    break;
	    }
	}
}*/
void gotoxy(u8 copy_xpos, u8 copy_ypos)
{
	u8 address=0;
	if(copy_ypos<=16)
	{
	if(copy_xpos==0)
	{
		address=copy_ypos;
		LCD_voidsendcommand(address+127);

	}
	else if(copy_xpos==1)
	{
		address=copy_ypos+0x40;
		LCD_voidsendcommand(address+127);
	}
	}
}
void LCD_writeSpecial_char(u8 * copy_patter, u8 copy_pattnumber,u8 copy_xpos,u8 copy_ypos)
{
	u8 local_u8Address =copy_pattnumber*8;
	LCD_voidsendcommand(local_u8Address+64);
	u8 local_counter=0;
	for(local_counter=0;local_counter<8;local_counter++)
	{
		LCD_voidsendData(copy_patter[local_counter]);
	}
	gotoxy(copy_xpos,copy_ypos);
	LCD_voidsendData(copy_pattnumber);

}
