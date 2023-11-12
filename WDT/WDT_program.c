/*
 * WDT_program.c
 *
 *  Created on: Aug 27, 2023
 *      Author: ABDALLAH
 */
#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "WDT_interface.h"

void WDT_voidEnable(void) {

	SET_BIT(WDTCR,3);
	WDTCR&=0b11111000;
	WDTCR |=7;
}

void WDT_voidDisable(void) {
	WDTCR=(1<<4)|(1<<3);
	WDTCR=0X00;
}


void WDT_voidSleep(u8 Copy_sleepTime) {

	WDTCR |= copy_u8sleep;


}
