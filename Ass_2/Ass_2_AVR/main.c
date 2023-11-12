#include <avr/io.h>
#include <util/delay.h>

void flashingAnimation() {
    PORTD ^= 0xFF; 
    _delay_ms(500);
}

void shiftLeftAnimation() {
    for (int i = 0; i < 8; i++) {
        PORTD = (1 << i);
        _delay_ms(250);
    }
}

void shiftRightAnimation() {
    for (int i = 7; i >= 0; i--) {
        PORTD = (1 << i);
        _delay_ms(250);
    }
}

void convergingAnimation() {
    for (int i = 0; i < 4; i++) {
        PORTD = (1 << i) | (1 << (7 - i));
        _delay_ms(300);
    }
}

void divergingAnimation() {
    for (int i = 0; i < 4; i++) {
        PORTD = (1 << i) | (1 << (7 - i));
        _delay_ms(300);
    }
}

void pingPongAnimation() {
    for (int i = 0; i < 8; i++) {
        PORTD = (1 << i);
        _delay_ms(250);
    }
    for (int i = 6; i > 0; i--) {
        PORTD = (1 << i);
        _delay_ms(250);
    }
}

void snakeAnimation() {
    for (int i = 0; i < 8; i++) {
        PORTD = (1 << i);
        _delay_ms(300);
    }
}

int main(void)
{
    DDRB &= ~(1 << PB0) & ~(1 << PB1) & ~(1 << PB2)& ~(1 << PB3);
    DDRD = 0xFF;

    while (1)
    {
        uint8_t dipValue = (PINB & 0x0F); 

        switch (dipValue) {
            case 1:
                flashingAnimation();
                break;
            case 2:
                shiftLeftAnimation();
                break;
            case 3:
                shiftRightAnimation();
                break;
            case 4:
                convergingAnimation();
                break;
            case 5:
                divergingAnimation();
                break;
            case 6:
                pingPongAnimation();
                break;
            case 7:
                snakeAnimation();
                break;
            case 8:
                convergingAnimation();
                divergingAnimation();
                break;
            default:
                PORTD = 0x00; 
        }
    }
}
