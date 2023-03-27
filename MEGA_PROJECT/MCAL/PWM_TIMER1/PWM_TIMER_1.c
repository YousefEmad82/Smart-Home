/*
 * PWM.c
 *
 *  Created on: Feb 26, 2023
 *      Author: dell
 */

#ifndef MCAL_PWM_PWM_C_
#define MCAL_PWM_PWM_C_


#include "PWM_TIMER_1_Reg.h"
#include "../DIO/DIO_Interface.h"

void PWM_Init(void)
{

TCNT1_REG &=TIMER1_initial_value & 0xFFFF;

#if (PWM_mode==FAST_PWM_TOP_ICR)

CLEAR_BIT(TCCR1A_REG,WGM10_PIN);
SET_BIT(TCCR1A_REG,WGM11_PIN);
SET_BIT(TCCR1B_REG,WGM12_PIN);
SET_BIT(TCCR1B_REG,WGM13_PIN);

#elif (PWM_mode==FAST_PWM_8_bit)

SET_BIT(TCCR1A_REG,WGM10_PIN);
CLEAR_BIT(TCCR1A_REG,WGM11_PIN);
SET_BIT(TCCR1B_REG,WGM12_PIN);
CLEAR_BIT(TCCR1B_REG,WGM13_PIN);


#elif (PWM_mode==PHASE_CORRECT_8_bit)

SET_BIT(TCCR1A_REG,WGM10_PIN);
CLEAR_BIT(TCCR1A_REG,WGM11_PIN);
CLEAR_BIT(TCCR1B_REG,WGM12_PIN);
CLEAR_BIT(TCCR1B_REG,WGM13_PIN);

#elif (PWM_mode==PHASE_CORRECT_TOP_ICR)

CLEAR_BIT(TCCR1A_REG,WGM10_PIN);
SET_BIT(TCCR1A_REG,WGM11_PIN);
CLEAR_BIT(TCCR1B_REG,WGM12_PIN);
SET_BIT(TCCR1B_REG,WGM13_PIN);

#endif



#if (PWM_channel==channelA)


#if (PWM_polarity==normal)

CLEAR_BIT(TCCR1A_REG,COM1A0_PIN);
CLEAR_BIT(TCCR1A_REG,COM1A1_PIN);

#elif (PWM_polarity==toggle)

SET_BIT(TCCR1A_REG,COM1A0_PIN);
CLEAR_BIT(TCCR1A_REG,COM1A1_PIN);

#elif (PWM_polarity==non_inverting)

CLEAR_BIT(TCCR1A_REG,COM1A0_PIN);
SET_BIT(TCCR1A_REG,COM1A1_PIN);

#elif (PWM_polarity==inverting)


SET_BIT(TCCR1A_REG,COM1A0_PIN);
SET_BIT(TCCR1A_REG,COM1A1_PIN);

#endif


#elif (PWM_channel==channelB)

#if (PWM_polarity==normal)

CLEAR_BIT(TCCR1B_REG,COM1B0_PIN);
CLEAR_BIT(TCCR1B_REG,COM1B1_PIN);

#elif (PWM_polarity==toggle)

SET_BIT(TCCR1B_REG,COM1B0_PIN);
CLEAR_BIT(TCCR1B_REG,COM1B1_PIN);

#elif (PWM_polarity==non_inverting)

CLEAR_BIT(TCCR1B_REG,COM1B0_PIN);
SET_BIT(TCCR1B_REG,COM1B1_PIN);

#elif (PWM_polarity==inverting)


SET_BIT(TCCR1B_REG,COM1B0_PIN);
SET_BIT(TCCR1B_REG,COM1B1_PIN);

#endif

#endif


}
void PWM_Generate_CHANNELA(float32 Copy_u8DutyCycle, uint32 Copy_u8Dutyfreq)
{

#if (PWM_mode==FAST_PWM_TOP_ICR)

	uint16 TOP=(F_CPU/(prescaler*Copy_u8Dutyfreq))-1;
	ICR1_REG =TOP+1;
	uint16 DutyCycle=((float32)(TOP+1)*Copy_u8DutyCycle/100);//for non-inverting mode
	OCR1A_REG =DutyCycle;
	TCCR1B_REG |= (TCCR1B_REG & CLEAR_CLOCK_VALUE) | PWM_prescaler;


#elif (PWM_mode==PHASE_CORRECT_TOP_ICR)

	    uint16 TOP=(F_CPU)/(Copy_u8Dutyfreq*2*64);
		ICR1_REG =TOP;
		uint16 DutyCycle=((TOP)*Copy_u8DutyCycle/100);//for non-inverting mode
		OCR1A_REG =DutyCycle;
		TCCR1B_REG = (TCCR1B_REG & CLEAR_CLOCK_VALUE) | PWM_prescaler;


#endif



}
void PWM_Generate_CHANNELB(uint8 Copy_u8DutyCycle, uint32 Copy_u8Dutyfreq)
{

#if (PWM_mode==FAST_PWM_TOP_ICR)

	uint16 TOP=(F_CPU/(prescaler*Copy_u8Dutyfreq))-1;
	ICR1_REG =TOP+1;
	uint16 DutyCycle=((TOP+1)*Copy_u8DutyCycle/100);//for non-inverting mode
	OCR1B_REG =DutyCycle;
	TCCR1B_REG =  (TCCR1B_REG & CLEAR_CLOCK_VALUE) | PWM_prescaler;


#elif (PWM_mode==PHASE_CORRECT_TOP_ICR)

	    uint16 TOP=(F_CPU/(prescaler*Copy_u8Dutyfreq));
		ICR1_REG =TOP+1;
		uint16 DutyCycle=((TOP+1)*Copy_u8DutyCycle/100);//for non-inverting mode
		OCR1B_REG =DutyCycle;
		TCCR1B_REG =  (TCCR1B_REG & CLEAR_CLOCK_VALUE) | PWM_prescaler;
#endif

}


#endif /* MCAL_PWM_PWM_C_ */
