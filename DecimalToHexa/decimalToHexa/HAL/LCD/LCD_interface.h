#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_RS_PORT    DIO_PORTD
#define LCD_RS_PIN     DIO_PIN0

#define LCD_RW_PORT   DIO_PORTD
#define LCD_RW_PIN    DIO_PIN1

#define LCD_EN_PORT   DIO_PORTD
#define LCD_EN_PIN    DIO_PIN2


#define LCD_DATA_PORT  DIO_PORTC

void LCD_voidSendData(u8 Copy_u8Data);


void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidInit(void);

void LCD_voidClearDisplay(void);

void LCD_GotoXY(u8 Copy_u8X,u8 Copy_u8Y);

void LCD_voidSendString(u8* Copy_pcString);

void LCD_voidSendNumber(u32 Copy_u32Number);

#endif
