/*
 * TIMER_program.c
 *
 *  Created on: Aug 23, 2023
 *      Author: ABDALLAH
 */
#include <avr/io.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_interface.h"
#include "TIMER_interface.h"


void TIMER_voidTimer0Init(void)
{
	//set normal mode
	   CLR_BIT(TCCR0,3);
	   CLR_BIT(TCCR0,6);




	//set prescaler div by 8
	    CLR_BIT(TCCR0,0);
	    SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);


	//set preload value

		TCNT0=192;



	//enable overflow interrupt

		SET_BIT(TIMSK,0);


}

void TIMER_voidTimer0CTCInit(void)
{
	//set CTC mode

	SET_BIT(TCCR0,3);
	 CLR_BIT(TCCR0,6);


	// set prescalar DIV

		   CLR_BIT(TCCR0,0);
		  	    SET_BIT(TCCR0,1);
		  		CLR_BIT(TCCR0,2);


	//enable CTC interrupt
		  		SET_BIT(TIMSK,1);

}




void TIMER_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{

OCR0=Copy_u8CompareMatchValue;


}


void __vector_11 (void) __attribute__((signal));

void __vector_11 (void)
{

		static u16 counter=0;
		counter++;
		static u8 flag=0;
		if(counter==3907)
		{
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0,flag);
			TOG_BIT(flag,0);
			TCNT0=192;
			counter=0;

		}


}

void __vector_10 (void) __attribute__((signal));

void __vector_10 (void)
{

		static u16 counter=0;
		counter++;
		static u8 flag=0;
		if(counter==4000)
		{
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0,flag);
			TOG_BIT(flag,0);

			counter=0;

		}


}
void TIMER_voidSetBusyWaitTimer0_ms(u32 Copy_u32Time_ms)
{
	TIMER_voidTimer0SetCompareMatchValue(250);
	// delay copy_time * 1sec
	for(u16 Local_u16Counter1=0;Local_u16Counter1<Copy_u32Time_ms;Local_u16Counter1++)
	{
		// delay 1 sec
	for(u16 Local_u16Counter2=0;Local_u16Counter2<4;Local_u16Counter2++)
	{
	while(GET_BIT(TIFR,1)==0);

	SET_BIT(TIFR,1);


	}
	}
}



void TIMER_voidTimer2FastPWM(void)

{//set  fast pwm
	SET_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);

	//set prescaler div 8
	CLR_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	CLR_BIT(TCCR2,2);

	//NON inverted mode

	SET_BIT(TCCR2,5);
	CLR_BIT(TCCR2,4);

}
void TIMER_voidTimer2SetCompareMatchVakue(u8 Copy_u8CompareMatchValue)
{
	OCR2=Copy_u8CompareMatchValue;


}

void TIMER_voidTimer1Init(void)
{
	//set prescaler div by 8
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);

	CLR_BIT(TCCR1B,2);




	//set pwm mode clear on compare set at top

	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	//SET mode 14

	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);

	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);




}
void TIMER_voidSetTimer1OverFlowValue(u16 Copy_u16OverFlowValue)
{

	ICR1=Copy_u16OverFlowValue;

}
void TIMER_voidTimer1ChannelASetCompareMatchValue(u16 Copy_u16CompareMatchValue)
{

	OCR1A=Copy_u16CompareMatchValue;

}
void TIMER1_voidFastPWM(void)
{
	// fast PWM
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

	/* CLEAR OC1A */
	CLR_BIT(TCCR1A, COM1A0); 	// CLEAR OC1A
	SET_BIT(TCCR1A, COM1A1);


	ICR1 = 19999;

	// div by 8
	CLR_BIT(TCCR1B, CS10);
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);
}
void SERVO_voidSetAngle(u8 copy_u8Angle)
{
	OCR1A = ((50* copy_u8Angle)+8991)/9;
}

