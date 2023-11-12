/*
 * TIMER_interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: ABDALLAH
 */

#ifndef TIMER_INTERFACE
#define TIMER_INTERFACE


void TIMER_voidTimer0Init(void);
void TIMER_voidTimer0CTCInit(void);
void TIMER_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue);
void TIMER_voidSetBusyWaitTimer0_ms(u32 Copy_u32Time_ms);

void TIMER_voidTimer1Init(void);
void TIMER_voidSetTimer1OverFlowValue(u16 Copy_u16OverFlowValue);
void TIMER_voidTimer1ChannelASetCompareMatchValue(u16 Copy_u16CompareMatchValue);

void TIMER_voidTimer2FastPWM(void);
void TIMER_voidTimer2SetCompareMatchVakue(u8 Copy_u8CompareMatchValue);



#endif
