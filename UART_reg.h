/*
 * UART_reg.h
 *
 *  Created on: Aug 26, 2021
 *      Author: HP
 */

#ifndef UART_REG_H_
#define UART_REG_H_

#define UDR    *((volatile u8*)0x2C)

#define UCSRA    *((volatile u8*)0x2B)
#define UCSRA_RXC       7  //1 if there is new data
#define UCSRA_TXC       6  //not used
#define UCSRA_UDRE      5  //used before writing
#define UCSRA_FE        4  //if there is an error
#define UCSRA_DOR       3  //1 if there is over run
#define USCRA_PE        2
#define UCSRA_U2X       1  //for doubling speed


#define UCSRB    *((volatile u8*)0x2A)
#define UCSRB_RXCIE       7  ///IF 1 ENABLES RX INTERRUPT
#define UCSRB_TXCIE       6  //IF 1 ENABLES TX INTERRUPT

#define UCSRB_UDRIE       5
#define UCSRB_RXEN        4  //RX ENABLE
#define UCSRB_TXEN        3  //TX ENABLE
#define UCSRB_UCSZ2       2 //TO COMBINE WITH UCSZ1 TO FORM SIZE OF DATA

#define UCSRC    *((volatile u8*)0x40)
#define UCSRC_URSEL       7///ENABLES USCRC WHEN 1
#define UCSRC_UMSEL       6 // 0 FOR ASSYNCRO
#define UCSRC_UPM1        5
#define UCSRC_UPM0        4
#define UCSRC_USBS        3 //0 FOR 1-BIT STOP
#define UCSRC_UCSZ1       2
#define UCSRC_UCSZ0       1
#define UCSRC_UCPOL       0 //CLK POLARITY

#define UBRRL            *((volatile u8*)0x29)
#define UBRRH            *((volatile u8*)0x40)



#endif /* UART_REG_H_ */
