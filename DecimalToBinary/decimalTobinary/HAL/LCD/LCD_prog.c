/*
 * LCD_prog.c
 *
 *  Created on: Aug 15, 2023
 *      Author: ABDALLAH
 */
#include <avr/delay.h>
#include <stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_interface.h"



void LCD_voidSendData(u8 Copy_u8Data)
{
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN ,HIGH);//Send data
   DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN ,LOW);//Write
   for(u8 i=0;i<8;i++)
   {
	   DIO_voidSetPinValue(LCD_DATA_PORT,i,GET_BIT(Copy_u8Data,i));
   }
  DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
  _delay_ms(2);
  DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);

}


void LCD_voidSendCommand(u8 Copy_u8Command)
{
	 DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN ,LOW);//Send Command
	   DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN ,LOW);//Write
	   for(u8 i=0;i<8;i++)
	   {
		   DIO_voidSetPinValue(LCD_DATA_PORT,i,GET_BIT(Copy_u8Command,i));
	   }
	  DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	  _delay_ms(2);
	  DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);

}

void LCD_voidInit(void)
{
	for(u8 i=0;i<8;i++)
	{
		DIO_voidSetPinDirection(LCD_DATA_PORT,i,OUTPUT);
	}

	DIO_voidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	DIO_voidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
	DIO_voidSetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	_delay_ms(40);
   LCD_voidSendCommand(0b00111000);
   LCD_voidSendCommand(0b00001100);
   LCD_voidSendCommand(0b00000001);
}

void LCD_voidClearDisplay(void)
{
	 LCD_voidSendCommand(0b00000001);
}
/**
 * at x=0 ,y=0  address=0x00
 * at x=0 , y=1  address=0x01
 * at x=0 ,y=17  address=0x17
 * at x=1 y=0    address=0x40
 * at x=1  y=3    address=0x43
 *
 * at x=0   address=y position
 * at x=1    address=y+0x40
 */

void LCD_GotoXY(u8 Copy_u8X,u8 Copy_u8Y)
{

	u8 Local_u8Address=0;
	if( Copy_u8X==0)
	{
		Local_u8Address= Copy_u8Y;
	}
	else
	{
		Local_u8Address= Copy_u8Y+0x40;
	}

	SET_BIT(Local_u8Address,7);
	LCD_voidSendCommand(Local_u8Address);

}
void LCD_voidSendString(u8* Copy_pcString)
{
	u8 Local_u8Index=0;

	while(Copy_pcString[Local_u8Index]!='\0')
	{
		LCD_voidSendData(Copy_pcString[Local_u8Index]);
		Local_u8Index++;
	}
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
   u8 Local_u8Str[10];
   itoa(Copy_u32Number, Local_u8Str,10);
   LCD_voidSendString(Local_u8Str);

}

