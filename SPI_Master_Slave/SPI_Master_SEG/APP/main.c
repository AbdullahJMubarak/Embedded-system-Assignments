
#include <avr/io.h>
#include <avr/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
void main (void)
{

	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN3,OUTPUT);
	//CLK
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,OUTPUT);

	//MOSI
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,OUTPUT);

	//MISO

	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,INPUT);

	//SS
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,INPUT);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,HIGH);

	    // Initialize SPI Master
	    SPI_voidMasterInit();

	    // Set push button as input
	    DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,INPUT);
	    DIO_voidSetPinValue(DIO_PORTD, DIO_PIN2,LOW);
	    u8 numberToSend = -1;

	    while (1)
	    {
	        if (DIO_u8GetPinValue(DIO_PORTD, DIO_PIN2))  // Check if push button is pressed
	        {

	        	while (DIO_u8GetPinValue(DIO_PORTD, DIO_PIN2));

	        			numberToSend++;
	        				SPI_u8Transceive(numberToSend);

	        				  //_delay_ms(500);
	        				DIO_voidSetPinValue(DIO_PORTD, DIO_PIN2,LOW);


	        	//DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,HIGH);
	             // Send the current number to the slave
	            //_delay_ms(500); // Delay for stability
	            // Increment the number
	            //DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,LOW);
	            if(numberToSend==15)
	            	numberToSend=-1;
	        }


	    }


	}





