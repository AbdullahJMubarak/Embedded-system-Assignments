/*
 * LCD_interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: ABDALLAH
 */
#ifndef LCD_ITERFACE_H
#define LCD_ITERFACE_H

#define LCD_RS_PORT DIO_PORTB
#define LCD_RS_PIN  DIO_PIN0


#define LCD_RW_PORT  DIO_PORTB
#define LCD_RW_PIN   DIO_PIN1


#define LCD_EN_PORT  DIO_PORTB
#define LCD_EN_PIN  DIO_PIN2


#define LCD_PORT_DATA  DIO_PORTD





void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidSentCommand(u8 Copy_u8Data);

void LCD_voidInit(void);


void LCD_voidClearDisplay(void);
void LCD_GotoXY(u8 Cop_u8X,u8 Cop_u8Y);






#endif
