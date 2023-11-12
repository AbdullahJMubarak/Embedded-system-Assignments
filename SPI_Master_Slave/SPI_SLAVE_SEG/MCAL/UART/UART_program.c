/*
 * UART_program.c
 *
 *  Created on: Aug 27, 2023
 *      Author: ABDALLAH
 */
#include <avr/io.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "UART_interface.h"




void USART_voitInit(void)
{
	u8 Local_u8UCSRC_value=0;

	//select UCSRC
	SET_BIT(Local_u8UCSRC_value,7);
	//select asynchrouns
	CLR_BIT(Local_u8UCSRC_value,6);
	//disable paritymode
	CLR_BIT(Local_u8UCSRC_value,5);
	CLR_BIT(Local_u8UCSRC_value,4);


	//select stop bit to be 1

	CLR_BIT(Local_u8UCSRC_value,3);


	//select 8 bit size
	SET_BIT(Local_u8UCSRC_value,2);
	SET_BIT(Local_u8UCSRC_value,1);
	CLR_BIT(UCSRB,2);


	UCSRC=Local_u8UCSRC_value;
// buade rate
		UBRRL=51;


	//enable receiver
	SET_BIT(UCSRB,4);

	//enable transmitter
	SET_BIT(UCSRB,3);


}

void USART_voidTransmitData(u8 Copy_u8Data)
{	//wait until trans buff is empty
	while(GET_BIT(UCSRA,5)==0);
		//clear flag
		SET_BIT(UCSRA,5);


		UDR=Copy_u8Data;



}


u8 USART_u8ReceiveData(void)
{
	while(GET_BIT(UCSRA,7)==0);

	return UDR;

}

void USART_voidTransmitString(u8* Copy_pcString)
{
	u8 Local_u8Index=0;

		while(Copy_pcString[Local_u8Index]!='\0')
		{
			USART_voidTransmitData(Copy_pcString[Local_u8Index]);
			Local_u8Index++;
		}


}
