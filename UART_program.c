/*
 * UART_program.c
 *
 *  Created on: Aug 26, 2021
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_reg.h"
#include "util/delay.h"



void UART_init(void)
{
	u8 local_variable=0;
	SET_BIT(local_variable,UCSRC_URSEL);//to enable UCSRC

	CLR_BIT(local_variable,UCSRC_USBS); //1 STOP BIT
	// NO PARITY

	CLR_BIT(local_variable,UCSRC_UPM1);
	CLR_BIT(local_variable,UCSRC_UPM0);



	//8-BIT DATA
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(local_variable,UCSRC_UCSZ1);
	SET_BIT(local_variable,UCSRC_UCSZ0);

	//CHOOSE ASSYNCRONIS
	CLR_BIT(local_variable,UCSRC_UMSEL);

	UCSRC=local_variable;
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

	UBRRL=51;

}

void UART_SENDDATA(u8 copy_data)
{

        while(UCSRA_UDRE==0);

    	UDR=copy_data;

}
void UART_send_string( char *ptr)
{
	int i=0;

	while(ptr[i] != '\0')
	{
		UART_SENDDATA(ptr[i]);
		_delay_ms(1);
		i++;
	}
	UART_SENDDATA(ptr[i]);
}

u8 UART_receive(void)
{
//	u8 output;
	//_delay_ms(2);
	while((UCSRA & (1<<UCSRA_RXC))==0);
	//output=UDR;


	return UDR;
}
char compareString(char arr1[10] , char arr2[10])
{
	int i=0;
	char flag=0;
	while((arr2[i]!='\0'))
	{
		if(arr1[i]==arr2[i])
		{
			flag=1;
		}else{
			flag=0;
			break;
		}
		i++;
	}
	return flag ;
}
void  UART_recieve_string(char * ptr)
{
	int i=0;
	ptr[i]=UART_receive();
	//_delay_ms(2);
	while(ptr[i] !='#')
	{
		i++;
		ptr[i]=UART_receive();
	//	_delay_ms(2);

	}
	ptr[i]='\0';

}

