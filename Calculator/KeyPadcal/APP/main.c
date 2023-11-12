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
            buffer[buffer_index++] = key; // Append key to buffer
            buffer[buffer_index] = '\0'; // Null-terminate the buffer
            LCD_voidSendData(key); // Display key on LCD
        }

        if (key == '=')
        {
            s32 num1, num2, result;
            s8 operator;

            // Use sscanf to extract numbers and operator from buffer
            sscanf(buffer, "%d %c %d", &num1, &operator, &num2);

            // Perform calculations based on operator
            switch (operator)
            {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 != 0) {
                        result = num1 / num2;
                    } else {
                    	LCD_voidClearDisplay(); // Clear the LCD
                        LCD_voidSendString("Error: Division by 0");
                        _delay_ms(2000);
                        LCD_voidClearDisplay(); // Clear the LCD
                        buffer_index = 0;
                        continue;
                    }
                    break;
                default:
                    result = 0;
                    break;
            }

            // Display the result on the LCD
            LCD_voidClearDisplay(); // Clear the LCD
            sprintf(buffer, "Result: %d", result);
            LCD_voidSendString(buffer);

            // Clear buffer and reset index
            buffer_index = 0;
            _delay_ms(2000);
            LCD_voidClearDisplay();
        }

        _delay_ms(100);
       // Delay for stability
    }

    return 0;
}
