/*
 * SPI_program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: ABDALLAH
 */
#include <avr/io.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI_interface.h"

void SPI_voidMasterInit(void)
{
	//Master init

     SET_BIT(SPCR,4);

	//clck prescalar -->64

     SET_BIT(SPCR,1);
     CLR_BIT(SPCR,0);
     CLR_BIT(SPSR,0);

	// SPI enable
     SET_BIT(SPCR,6);

}
void SPI_voidSlaveInit(void)
{
	//slave init

	   CLR_BIT(SPCR,4);

	//enable slave

	   SET_BIT(SPCR,6);

}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
//send data

	SPDR=Copy_u8Data;
// wait until transfer is completed
while(GET_BIT(SPSR,7)==0);
// GET The exchanged data
return SPDR;

}

