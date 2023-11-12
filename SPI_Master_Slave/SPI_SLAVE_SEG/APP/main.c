
#include <avr/io.h>
#include <avr/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
const int segments[] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
    0b01110111, // A
    0b01111100, // B
    0b00111001, // C
    0b01011110, // D
    0b01111001, // E
    0b01110001  // F
};

void main (void)
{
	DIO_voidSetSpecificPortDirection(DIO_PORTC,0XFF);
	//CLK
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,INPUT);

	//MOSI
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,INPUT);

	//MISO

	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,OUTPUT);

	//SS
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,INPUT);


	    // Initialize SPI Slave
	    SPI_voidSlaveInit();

	    // Initialize 7-segment display
	    DIO_voidSetSpecificPortDirection(DIO_PORTC, 0xFF); // Set PORTA pins as output

	    u8 receivedNumber = 0;

	    while (1)
	    {
	        receivedNumber = SPI_u8Transceive(0); // Receive the number from master
	        //receivedNumber=atoi(receivedNumber);
	        // Display the received number on the 7-segment display

	        DIO_voidSetSpecificPortValue(DIO_PORTC, segments[receivedNumber]);
	        _delay_ms(100);

	        if(receivedNumber==15)
	        	receivedNumber=0;
	    }


	}










