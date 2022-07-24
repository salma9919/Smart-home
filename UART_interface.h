/*
 * UART_interface.h
 *
 *  Created on: Aug 26, 2021
 *      Author: HP
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
void UART_init(void);
void UART_SENDDATA(u8 copy_data);
void UART_send_string( char *ptr);
u8 UART_receive(void);
char compareString(char arr1[10] , char arr2[10]);
void  UART_recieve_string(char * ptr);
#endif /* UART_INTERFACE_H_ */

