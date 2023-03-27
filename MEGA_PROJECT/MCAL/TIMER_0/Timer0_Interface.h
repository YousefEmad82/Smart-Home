/*
 * Timer0_Interface.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Yousef
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "Timer0_reg.h"

typedef enum{
	T0_OVERFLOW,T0_CTC=2
}Timer0Mode;


typedef enum{
	T0_NO_CLOCK,T0_FCPU,T0_FCPU_8,T0_FCPU_64,T0_FCPU_256,T0_FCPU_1024,T0_EXTERNAL_CLOCK_FALLING,T0_EXTERNAL_CLOCK_RISING
}Prescaler0;

typedef enum
{
	T0_NO_INTERRUPT,T0_INTERRUPT
}InterruptMode0;

typedef struct{
	Timer0Mode 			s_timer0Mode;
	Prescaler0 			s_prescaler0;
	InterruptMode0 		s_interruptMode0;
	uint8 				s_timerValue;
	uint8 				s_ctcValue;
}Timer0Config;

void TIMER0_init(const Timer0Config *a_config_ptr);
void TIMER0_callback(void (*a_ptr)(void));
void TIMER0_Delay_with_Blocking_ms(uint16 Milli_Seconds,const Timer0Config *a_config_ptr);
void TIMER0_Delay_with_Blocking_us(uint32 Micro_Seconds,const Timer0Config *a_config_ptr);
void TIMER0_Delay_without_Blocking(uint16 Milli_Seconds,const Timer0Config *a_config_ptr);

#endif /* TIMER0_INTERFACE_H_ */
