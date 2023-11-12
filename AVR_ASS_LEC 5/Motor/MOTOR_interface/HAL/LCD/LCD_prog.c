/*
 * LCD_prog.c
 *
 *  Created on: Aug 15, 2023
 *      Author: ABDALLAH
 */
#include <avr/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_interface.h"


void LCD_voidSendData(u8 Copy_u8Data)
{
	DIO_voidSetpinvalue(LCD_RS_PORT, LCD_RS_PIN, HIGH);
	DIO_voidSetpinvalue(LCD_RW_PORT, LCD_RW_PIN, LOW);

	DIO_voidSetSpecificPortValue(LCD_PORT_DATA, Copy_u8Data);

	DIO_voidSetpinvalue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetpinvalue(LCD_EN_PORT,LCD_EN_PIN,LOW);

}

void LCD_voidSentCommand(u8 Copy_u8Data)
{

	DIO_voidSetpinvalue(LCD_RS_PORT, LCD_RS_PIN, LOW);
		DIO_voidSetpinvalue(LCD_RW_PORT, LCD_RW_PIN, LOW);
		DIO_voidSetSpecificPortValue(LCD_PORT_DATA, Copy_u8Data);
		DIO_voidSetpinvalue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(2);
		DIO_voidSetpinvalue(LCD_EN_PORT,LCD_EN_PIN,LOW);



}

void LCD_voidInit(void)
{

	DIO_voidSetSpecificPortDirection(LCD_PORT_DATA,0XFF );

	DIO_voidSetpindirection(LCD_RS_PORT, LCD_RS_PIN, OUTPUT);
	DIO_voidSetpindirection(LCD_RW_PORT, LCD_RW_PIN, OUTPUT);
	DIO_voidSetpindirection(LCD_EN_PORT, LCD_EN_PIN, OUTPUT);
	_delay_ms(40);
	LCD_voidSentCommand(0b00111000);
	LCD_voidSentCommand(0b00001100);

	LCD_voidSentCommand(0b00000001);

}

void LCD_voidClearDisplay(void)
{

	LCD_voidSentCommand(0b00000001);

}

void LCD_GotoXY(u8 Copy_u8X,u8 Copy_u8Y)
{
	u8 Local_u8Address;
	if(Copy_u8X == 0)
	{
	Local_u8Address= Copy_u8Y;
	}else
	{

		Local_u8Address = 0x40 + Copy_u8Y;
	}

	SET_BIT(Local_u8Address,7);
	LCD_voidSentCommand(Local_u8Address);

}
