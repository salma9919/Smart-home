/*
 * DIO_program.c
 *
 *  Created on: Aug 12, 2021
 *      Author: HP
 */




#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO_interface.h"

#include "DIO_reg.h"

void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDir)
{
	if((Copy_u8PortId <= DIO_u8PORT_D) && (Copy_u8PinId <= DIO_u8PIN_7))
	{
		if(Copy_u8PinDir == DIO_u8OUTPUT)
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8PORT_A: SET_BIT(DDRA, Copy_u8PinId); break;
			case DIO_u8PORT_B: SET_BIT(DDRB, Copy_u8PinId); break;
			case DIO_u8PORT_C: SET_BIT(DDRC, Copy_u8PinId); break;
			case DIO_u8PORT_D: SET_BIT(DDRD, Copy_u8PinId); break;
			}
		}
		else if(Copy_u8PinDir == DIO_u8INPUT)
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8PORT_A: CLR_BIT(DDRA, Copy_u8PinId); break;
			case DIO_u8PORT_B: CLR_BIT(DDRB, Copy_u8PinId); break;
			case DIO_u8PORT_C: CLR_BIT(DDRC, Copy_u8PinId); break;
			case DIO_u8PORT_D: CLR_BIT(DDRD, Copy_u8PinId); break;
			}
		}
		else
		{

		}
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinVal)
{
	if((Copy_u8PortId <= DIO_u8PORT_D) && (Copy_u8PinId <= DIO_u8PIN_7))
	{
		if(Copy_u8PinVal == DIO_u8HIGH)
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8PORT_A: SET_BIT(PORTA, Copy_u8PinId); break;
			case DIO_u8PORT_B: SET_BIT(PORTB, Copy_u8PinId); break;
			case DIO_u8PORT_C: SET_BIT(PORTC, Copy_u8PinId); break;
			case DIO_u8PORT_D: SET_BIT(PORTD, Copy_u8PinId); break;
			}
		}
		else if(Copy_u8PinVal == DIO_u8LOW)
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8PORT_A: CLR_BIT(PORTA, Copy_u8PinId); break;
			case DIO_u8PORT_B: CLR_BIT(PORTB, Copy_u8PinId); break;
			case DIO_u8PORT_C: CLR_BIT(PORTC, Copy_u8PinId); break;
			case DIO_u8PORT_D: CLR_BIT(PORTD, Copy_u8PinId); break;
			}
		}
		else
		{

		}
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 var=0;
	if((Copy_u8PortId <= DIO_u8PORT_D) && (Copy_u8PinId <= DIO_u8PIN_7))
		{
		switch(Copy_u8PortId)
					{
					case DIO_u8PORT_A: var=  GET_BIT(PINA, Copy_u8PinId); break;
					case DIO_u8PORT_B: var= GET_BIT(PINB, Copy_u8PinId); break;
					case DIO_u8PORT_C: var= GET_BIT(PINC, Copy_u8PinId); break;
					case DIO_u8PORT_D: var= GET_BIT(PIND, Copy_u8PinId); break;

					}
		}
	else var=0xff;
	return var;
}

void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PinDir)
{
	if((Copy_u8PortId <= DIO_u8PORT_D) )
		{

				switch(Copy_u8PortId)
				{
				case DIO_u8PORT_A: DDRA =Copy_u8PinDir; break;
				case DIO_u8PORT_B: DDRB =Copy_u8PinDir; break;
				case DIO_u8PORT_C: DDRC =Copy_u8PinDir; break;
				case DIO_u8PORT_D: DDRD =Copy_u8PinDir; break;
				}


		}
}
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PinVal)
{
	if((Copy_u8PortId <= DIO_u8PORT_D))
		{

				switch(Copy_u8PortId)
				{
				case DIO_u8PORT_A: PORTA=Copy_u8PinVal;break;
				case DIO_u8PORT_B: PORTB=Copy_u8PinVal;break;
				case DIO_u8PORT_C: PORTC=Copy_u8PinVal;break;
				case DIO_u8PORT_D: PORTD=Copy_u8PinVal;break;
				}


		}
}
