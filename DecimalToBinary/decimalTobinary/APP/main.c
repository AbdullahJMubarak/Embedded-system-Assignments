#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/DIO/DIO_interface.h"


// Function to convert decimal to binary
void decimalToBinary(s32 decimal, u8 *binary) {
    for (s32 i = 7; i >= 0; i--) {
        binary[i] = (decimal & 1) + '0';
        decimal >>= 1;
    }
    binary[8] = '\0';
}

int main(void)
{
    LCD_voidInit(); // Initialize the LCD
    KPD_voidInit(); // Initialize the keypad

    s8 buffer[16];
    u32 buffer_index = 0; // Index

    LCD_voidClearDisplay();
    while (1)
    {
    	u8 key = KPD_u8GetPressedKey(); // Get pressed key

        if (key != 0xAA && buffer_index < 16)
        {
            buffer[buffer_index++] = key; // Append
            buffer[buffer_index] = '\0'; // Null
            LCD_voidSendData(key); // Display
        }

        if (key == '=')
        {
        	s32 decimal = 0;
        	u8 binary[9]; // binary representation


        	u32 i = 0;
            while (buffer[i] != '\0')
            {
                if (buffer[i] >= '0' && buffer[i] <= '9')
                {
                    decimal = decimal * 10 + (buffer[i] - '0');
                }
                i++;
            }


            decimalToBinary(decimal, binary);  // Convert decimal to binary


            LCD_voidClearDisplay(); // Clear the LCD
            LCD_voidSendString("Decimal: \n");
            LCD_voidSendString(buffer);

            LCD_GotoXY(1,0);
            LCD_voidSendString("Binary: ");
            LCD_voidSendString(binary);

            // Clear buffer and reset index
            buffer_index = 0;
        }

        _delay_ms(100); // Delay for stability
    }

    return 0;
}






//void main(void)
//{
//    LCD_voidInit(); // Initialize the LCD
//   KPD_voidInit(); // Initialize the keypad
//    u8 num1,op,num2;
//
//while(1){
//num1=0;
//op=0;
//num2=0;
//	while(num1==0){
//	 num1= KPD_u8GetPressedKey();
//		}
//		LCD_voidSendData(num1);
//		while(op==0){
//
//	   op= KPD_u8GetPressedKey();
//
//
//				}	LCD_voidSendData(op);
//		while(num2==0){
//
//
//	  num2= KPD_u8GetPressedKey();
//		}
//		LCD_voidSendData(num2);
//
//}

//    while(1);
//}









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
