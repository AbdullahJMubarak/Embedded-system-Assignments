
#include <avr/io.h>
#include <avr/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"

void main (void)
{
DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN0,INPUT);
DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN1,OUTPUT);
DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,OUTPUT);
	USART_voitInit();
//	USART_voidTransmitData('A');
//	USART_voidTransmitData('B');
//	USART_voidTransmitData('D');
//	USART_voidTransmitData('A');
//	USART_voidTransmitData('L');
//
//	USART_voidTransmitData('L');
//	USART_voidTransmitData('A');
    USART_voidTransmitString("ABDALLA MUBARAK");
//	u8 Data;
	while(1){
//
//		Data=USART_u8ReceiveData();
//
//		if(Data=='1')
//			DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,HIGH);
//		else if (Data=='0')
//			DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,LOW);


	}

}




