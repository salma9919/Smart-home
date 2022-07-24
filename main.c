/*
 * main.c
 *
 *  Created on: Aug 26, 2021
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "util/delay.h"
#include <string.h>
#include "DIO_reg.h"
#include "LCD_interface.h"
#include "UART.h"


#define maximum   3
u8 password_set(u8 *passwords[],u8 index)
{
	u8 correct=0;
	    	u8 password[8];
	    	u16 local_itteration =0;


	    	for(local_itteration=0;local_itteration<maximum;local_itteration++)
	    	{
	    		gotoxy(1,1);
	    			    	LCD_sendString("enter pass:");
	    		UART_recieve_string(password);
	    	    LCD_sendString(password);
	    		if(strcasecmp(password,passwords[index])==0)
	    		{
	    			correct=1;
	    			LCD_sendString("welcome");
	    			break;
	    		}
	    		else
	    		{
	    			LCD_sendString("try again");
	    		}
	    	}
	    	if(correct==0)
	    	{
	    		DIO_voidSetPinValue(DIO_u8PORT_D,DIO_u8PIN_3,DIO_u8HIGH);
	    	}

}
u8 username_set(u8 *usernames[],u8 *passwords[])
{
	u8 member=0;
    	u8 username[8];
    	u16 local_itteration =0;

    	for(local_itteration=0;local_itteration<maximum;local_itteration++)
    	{
    		gotoxy(0,1);
    		UART_recieve_string(username);
    		    	LCD_sendString(username);
    		if(strcasecmp(username,usernames[local_itteration])==0)
    		{
    			member=1;
    			password_set(passwords,local_itteration);
    			break;
    		}
    		else
    		{
    			LCD_sendString("try again");
    		}
    	}
    	if(member==0)
    	{
    		DIO_voidSetPinValue(DIO_u8PORT_D,DIO_u8PIN_3,DIO_u8HIGH);
    	}


}


int main(void)
{
	UART_init();
	DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_0,DIO_u8INPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_2,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_3,DIO_u8OUTPUT);
	DIO_voidSetPortDirection(DIO_u8PORT_C,0xff);
	DIO_voidSetPortDirection(DIO_u8PORT_B,0xff);
	LCD_voidInit();
	u8 *usernames[3] ;
	usernames[0]="salma";
	usernames[1]="amira";
	usernames[2]="7ramy";

	u8 *pass[3];
	pass[0]="123";
	pass[1]="456";
	pass[2]="X0X0";
	LCD_sendString("HII1");
    u8 *welcome="welcome please enter your user name";
    UART_send_string(welcome);
    username_set(usernames,pass);



    while(1)
    {

    }


	return 0;
}
