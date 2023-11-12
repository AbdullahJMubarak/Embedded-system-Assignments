/*
 * SPI_interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: ABDALLAH
 */
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);

u8 SPI_u8Transceive(u8 Copy_u8Data);

#endif
