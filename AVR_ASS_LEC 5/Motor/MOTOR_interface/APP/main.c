#include <avr/delay.h>
#include<avr/io.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"

#include<avr/delay.h>



int main(void){

	LCD_voidInit();
	DIO_voidSetpindirection(DIO_PORTC,DIO_PIN0, OUTPUT);
	DIO_voidSetpindirection(DIO_PORTC,DIO_PIN1, OUTPUT);
	DIO_voidSetpindirection(DIO_PORTA,DIO_PIN0, INPUT);
	DIO_voidSetpindirection(DIO_PORTA,DIO_PIN1, INPUT);

	DIO_voidSetpinvalue(DIO_PORTA,DIO_PIN0, HIGH);
	DIO_voidSetpinvalue(DIO_PORTA,DIO_PIN1, HIGH);

	DIO_voidSetpinvalue(DIO_PORTC,DIO_PIN0, LOW);
	DIO_voidSetpinvalue(DIO_PORTC,DIO_PIN1, LOW);



	while(1)
	{
		if(DIO_u8GetPinValue(DIO_PORTA,DIO_PIN0)==0){
			DIO_voidSetpinvalue(DIO_PORTC,DIO_PIN0, HIGH);
			DIO_voidSetpinvalue(DIO_PORTC,DIO_PIN1, LOW);
			LCD_voidClearDisplay();
			LCD_voidSendData('C');
			LCD_voidSendData('o');
			LCD_voidSendData('u');
			LCD_voidSendData('n');
			LCD_voidSendData('t');
			LCD_voidSendData('e');
	        LCD_voidSendData('r');
	        LCD_voidSendData(' ');
			LCD_voidSendData('C');
			LCD_voidSendData('W');
		}

		else if(DIO_u8GetPinValue(DIO_PORTA,DIO_PIN1)==0){
			DIO_voidSetpinvalue(DIO_PORTC,DIO_PIN0, LOW);
			DIO_voidSetpinvalue(DIO_PORTC,DIO_PIN1, HIGH);
			LCD_voidClearDisplay();
			LCD_voidSendData('C');
			LCD_voidSendData('W');
		}

	}


	return 0;
}






















//	DIO_voidSetSpecificPortDirection(DIO_PORTD,0XFF );
//	DIO_voidSetSpecificPortValue(DIO_PORTD,0XFF);


//


//	LCD_voidInit();
//	while(1){
//for(int i;i<20;i++)
//	   {
//
//	LCD_voidSendData('A');
//	LCD_voidSendData('B');
//	LCD_voidSendData('D');
//	LCD_voidSendData('A');
//	LCD_voidSendData('L');
//	LCD_voidSendData('L');
//	LCD_voidSendData('A');
//    _delay_ms(500);
//    LCD_voidClearDisplay();
//	LCD_GotoXY(0,i);
//
//	   }
//LCD_voidClearDisplay();
//	LCD_GotoXY(0,0);
//	LCD_voidInit();
//	}
//	while(1);
