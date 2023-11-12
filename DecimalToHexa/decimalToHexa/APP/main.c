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


// Function to convert decimal to hexadecimal
void decimalToHexadecimal(s32 decimal, u8 *hexadecimal) {
    for (s32 i = 1; i >= 0; i--) {
        int hexDigit = (decimal >> (i * 4)) & 0xF;
        if (hexDigit < 10) {
            hexadecimal[1 - i] = hexDigit + '0';
        } else {
            hexadecimal[1 - i] = hexDigit - 10 + 'A';
        }
    }
    hexadecimal[2] = '\0';
}

int main(void)
{
    LCD_voidInit(); // Initialize the LCD
    KPD_voidInit(); // Initialize the keypad

    s8 buffer[16]; // Buffer to store user input
    u32 buffer_index = 0; // Index to keep track of buffer position

    LCD_voidClearDisplay(); // Clear the LCD

    while (1)
    {
        u8 key = KPD_u8GetPressedKey(); // Get pressed key

        if (key != 0xAA && buffer_index < 16)
        {
            buffer[buffer_index++] = key; // Append
            buffer[buffer_index] = '\0'; // Null End buffer
            LCD_voidSendData(key); // Display
        }

        if (key == '=')
        {
            s32 decimal = 0;
            u8 hexadecimal[3]; // To store the hexadecimal

            // Parse the input manually
            u32 i = 0;
            while (buffer[i] != '\0')
            {
                if (buffer[i] >= '0' && buffer[i] <= '9')
                {
                    decimal = decimal * 10 + (buffer[i] - '0');
                }
                i++;
            }

            // Convert decimal to hexadecimal
            decimalToHexadecimal(decimal, hexadecimal);

            // Display the decimal and hexadecimal numbers on the LCD
            LCD_voidClearDisplay(); // Clear the LCD
            LCD_voidSendString("Decimal: ");
            LCD_voidSendString(buffer);
            LCD_GotoXY(1,0);
            LCD_voidSendString("Hexadecimal:0x");
            LCD_voidSendString(hexadecimal);

            // Clear buffer and reset index
            buffer_index = 0;
        }

        _delay_ms(100); // Delay for stability
    }

    return 0;
}

