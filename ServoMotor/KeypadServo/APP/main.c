
#include <avr/io.h>
#include <avr/delay.h>
#include <stdlib.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include "../HAL/LCD/LCD_interface.h"



int main(void)
{
    // Initialize components (keypad, LCD, and servo motor)
	KPD_voidInit();
    LCD_voidInit();
    DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,OUTPUT);


    while (1)
    {

        LCD_voidClearDisplay();
        LCD_voidSendString("Enter Angle:");

        // Read user input from keypad
        s8 inputBuffer[4];
        u32 inputIndex = 0;

        while (1)
        {
            u8 key = KPD_u8GetPressedKey();
            if (key != 0xAA )
            {
                if (key == '=')
                {
                    inputBuffer[inputIndex] = '\0';


                    u32 desiredAngle = atoi(inputBuffer);


                           if (desiredAngle > 180)
                           {
                               desiredAngle = 180;
                           }

                    break;
                }
                else
                {

                    inputBuffer[inputIndex] = key;// Append p
                    inputIndex++;
                    if (inputIndex >= 3)
                    {
                        inputIndex = 3; // Prevent buffer overflow
                    }


                    LCD_voidClearDisplay();
                    LCD_voidSendString(inputBuffer);
                }
            }
        }

        // Convert input to integer angle
        u32 desiredAngle = atoi(inputBuffer); // Convert string to integer
        u32 printedAngle=desiredAngle;


        if (desiredAngle > 180)
        {
            desiredAngle = 180;

        }
        else if (desiredAngle > 90)
        {

            desiredAngle -=90;
        }
        else{
        desiredAngle +=90;

        }
        TIMER1_voidFastPWM();
        SERVO_voidSetAngle(desiredAngle);
        // Display actual angle on LCD
        LCD_voidClearDisplay();
        LCD_voidSendString("Angle: ");
        LCD_voidSendNumber(printedAngle);


        _delay_ms(1500);
    }

    return 0;
}
////GIE_voidEnableGlobalInterrupt();
//
//DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0,OUTPUT);
////TIMER_voidTimer0SetCompareMatchValue(250);
//TIMER_voidTimer0CTCInit();
//
////while(1);
//while(1)
//{
//DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0,HIGH);
//TIMER_voidSetBusyWaitTimer0_ms(1000);
//DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0,LOW);
//TIMER_voidSetBusyWaitTimer0_ms(1000);
//
//}
