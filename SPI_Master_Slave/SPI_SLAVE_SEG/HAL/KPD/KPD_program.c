/*
 * KPD_program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: ABDALLAH
 */

#include <avr/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"


void KPD_voidInit(void)
{
	DIO_voidSetPinDirection(KPD_COL_PORT,KPD_COL0_PIN, OUTPUT);
	DIO_voidSetPinDirection(KPD_COL_PORT,KPD_COL1_PIN, OUTPUT);
	DIO_voidSetPinDirection(KPD_COL_PORT,KPD_COL2_PIN, OUTPUT);

	DIO_voidSetPinValue(KPD_COL_PORT,KPD_COL2_PIN, HIGH);
	DIO_voidSetPinValue(KPD_COL_PORT,KPD_COL2_PIN, HIGH);
	DIO_voidSetPinValue(KPD_COL_PORT,KPD_COL2_PIN, HIGH);




	DIO_voidSetPinDirection(KPD_ROW_PORT,KPD_ROW0_PIN, INPUT);
	DIO_voidSetPinDirection(KPD_ROW_PORT,KPD_ROW1_PIN, INPUT);
	DIO_voidSetPinDirection(KPD_ROW_PORT,KPD_ROW2_PIN, INPUT);


	DIO_voidSetPinValue(KPD_ROW_PORT, KPD_ROW0_PIN, HIGH);
	DIO_voidSetPinValue(KPD_ROW_PORT, KPD_ROW1_PIN, HIGH);
	DIO_voidSetPinValue(KPD_ROW_PORT, KPD_ROW2_PIN, HIGH);
	DIO_voidSetPinValue(KPD_ROW_PORT, KPD_ROW3_PIN, HIGH);

}
u8 KPD_u8GetPressedKey(void)
{

	u8 Local_u8PressedKey=0xAA;

	u8 Local_u8ColumsArray[3]={KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN};
	u8 Local_u8RowsArray[4]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	u8 Local_u8KeyArray[4][3]={{1,2,3},{4,5,6},{7,8,9},{12,0,13}};

	for(u8 Local_u8ColumnsIndex=0;Local_u8ColumnsIndex<3;Local_u8ColumnsIndex++)
	{
		DIO_voidSetPinValue(KPD_COL_PORT, Local_u8ColumsArray[Local_u8ColumnsIndex],LOW);
		for(u8 Local_u8RowsIndex=0;Local_u8RowsIndex<4;Local_u8RowsIndex++)
		{
			u8 Local_u8PinState=DIO_u8GetPinValue(KPD_ROW_PORT, Local_u8RowsArray[Local_u8RowsIndex]);

			if(Local_u8PinState==0)
			{
				Local_u8PressedKey=Local_u8KeyArray[Local_u8RowsIndex][Local_u8ColumnsIndex];
				while(Local_u8PinState==0)
				{
					Local_u8PinState=DIO_u8GetPinValue(KPD_ROW_PORT, Local_u8RowsArray[Local_u8RowsIndex]);
				}
				return Local_u8PressedKey;
			}


		}
		DIO_voidSetPinValue(KPD_COL_PORT, Local_u8ColumsArray[Local_u8ColumnsIndex],HIGH);

	}

	return Local_u8PressedKey;

}

