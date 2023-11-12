/*
 * ADC_program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: ABDALLAH
 */
#include <avr/io.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ADC_interface.h"


void ADC_voidInit()
{
	//set source voltage -->AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

	//adjust left bit
	SET_BIT(ADMUX,5);

	//set ADC prescaler -->/64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);


	//enable ADC
	SET_BIT(ADCSRA,7);
}

u8 ADC_u8StartConversion(u8 Copy_u8ChannelNumber)
{// 	ADC channel select
	ADMUX &=0b11100000;

	ADMUX |=Copy_u8ChannelNumber;

	//ADC start conversion

	SET_BIT(ADCSRA,6);


	//wait until conversion complete

	while(GET_BIT(ADCSRA,4)==0);


	// clear flag

	SET_BIT(ADCSRA,4);

	return ADCH;

}
