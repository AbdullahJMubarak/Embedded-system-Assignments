

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include<avr/io.h>
#include<avr/delay.h>

int main(void){


	LCD_voidInit();

	while(1){


		LCD_GotoXY(0,0);

		LCD_voidSendData('A');
		LCD_voidSendData('B');
		LCD_voidSendData('D');
		LCD_voidSendData('A');
		LCD_voidSendData('L');
		LCD_voidSendData('L');
		LCD_voidSendData('A');
		_delay_ms(500);
		LCD_voidClearDisplay();

		LCD_GotoXY(1,3);
		LCD_voidSendData('A');
		LCD_voidSendData('B');
		LCD_voidSendData('D');
		LCD_voidSendData('A');
		LCD_voidSendData('L');
		LCD_voidSendData('L');
		LCD_voidSendData('A');
		_delay_ms(500);
		LCD_voidClearDisplay();

		LCD_GotoXY(0,6);
		LCD_voidSendData('A');
		LCD_voidSendData('B');
		LCD_voidSendData('D');
		LCD_voidSendData('A');
		LCD_voidSendData('L');
		LCD_voidSendData('L');
		LCD_voidSendData('A');
		_delay_ms(500);
		LCD_voidClearDisplay();

		LCD_GotoXY(1,9);
		LCD_voidSendData('A');
		LCD_voidSendData('B');
		LCD_voidSendData('D');
		LCD_voidSendData('A');
		LCD_voidSendData('L');
		LCD_voidSendData('L');
		LCD_voidSendData('A');
		_delay_ms(500);
		LCD_voidClearDisplay();


	}
	return 0;
}

