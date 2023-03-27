/*
 * Timer0_reg.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Yousef
 */

#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

#include "../../LIB_FOLDER/std_types.h"
#include "../../LIB_FOLDER/common_macros.h"


#define TCCR0	*(volatile uint8*)(0x53)
#define TCNT0	*(volatile uint8*)(0x52)
#define OCR0	*(volatile uint8*)(0x5C)
#define TIMSK	*(volatile uint8*)(0x59)
#define TIFR	*(volatile uint8*)(0x58)
#define SREG	*(volatile uint8*)(0x5F)

#define CS00	0
#define CS01	1
#define CS02 	2
#define WGM01 	3
#define COM00 	4
#define COM01 	5
#define WGM00 	6
#define FOC0 	7

#define TOIE0	0
#define OCIE0	1

#define TOV0	0
#define OCF0	1

#define GIE 7

#define TIMER0_COMP_vect 	__vector_10
#define TIMER0_OVF_vect 	__vector_11

#define ISR(TIMER0_VECT)	void TIMER0_VECT(void) __attribute__ ((signal,used));\
void TIMER0_VECT(void)



#endif /* TIMER0_REG_H_ */
