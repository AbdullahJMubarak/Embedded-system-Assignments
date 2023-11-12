#include <avr/io.h>
#include <util/delay.h>


const uint8_t segmentPatterns[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};


void displayNumber(uint8_t number) {
 
    PORTC = segmentPatterns[number % 10];
    PORTD = segmentPatterns[number / 10];
}

int main(void)
{
   
    DDRB = 0xFF;
    
    DDRC = 0xFF;
    DDRD = 0xFF;

    while (1)
    {
       
        for (int i = 10; i >= 0; i--) {
            PORTB = 0b00000100; // Green LED on
            displayNumber(i);
            _delay_ms(1000);
        }

      
        for (int i = 3; i >= 0; i--) {
            PORTB = 0b00000010; // Yellow LED on
            displayNumber(i);
            _delay_ms(1000);
        }

       
        for (int i = 10; i >= 0; i--) {
            PORTB = 0b00000001; // Red LED on
            displayNumber(i);
            _delay_ms(1000);
        }
    }
}
