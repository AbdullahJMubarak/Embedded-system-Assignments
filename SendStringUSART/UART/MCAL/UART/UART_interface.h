/*
 * UART_interface.h
 *
 *  Created on: Aug 27, 2023
 *      Author: ABDALLAH
 */

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void USART_voitInit(void);

void USART_voidTransmitData(u8 Copy_u8Data);


u8 USART_u8ReceiveData(void);
void USART_voidTransmitString(u8* Copy_pcString);

#endif
