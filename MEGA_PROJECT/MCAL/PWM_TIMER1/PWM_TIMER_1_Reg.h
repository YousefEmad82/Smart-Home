/*
 * PWM_Reg.h
 *
 *  Created on: Feb 26, 2023
 *      Author: dell
 */

#ifndef MCAL_PWM_TIMER_1_DRIVER_PWM_TIMER_1_REG_H_
#define MCAL_PWM_TIMER_1_DRIVER_PWM_TIMER_1_REG_H_

#include "PWM_TIMER_1_Interface.h"

/*TIMER1 REGISTERS*/

#define TCCR1A_REG      *((volatile uint8*)0x4F)
#define TCCR1B_REG      *((volatile uint8*)0x4E)
#define TCNT1_REG      *((volatile uint16*)0x4C)
#define TCNT1L_REG      *((volatile uint8*)0x4C)
#define TCNT1H_REG      *((volatile uint8*)0x4D)
#define OCR1A_REG       *((volatile uint16*)0x4A)
#define OCR1B_REG       *((volatile uint16*)0x48)
#define OCR1AL_REG       *((volatile uint8*)0x4A)
#define OCR1AH_REG       *((volatile uint8*)0x4B)
#define OCR1BL_REG       *((volatile uint8*)0x48)
#define OCR1BH_REG       *((volatile uint8*)0x48)
#define ICR1_REG         *((volatile uint16*)0x46)
#define ICR1H_REG        *((volatile uint8*)0x47)
#define ICR1L_REG        *((volatile uint8*)0x46)
#define PWM_OUTPUT_REG   *((volatile uint8*)0x31)



/*TIMER1 TIMSK_REG PINS*/
#define TOIE1_PIN    2
#define OCIE1B_PIN     3
#define OCIE1A_PIN     4
#define TICIE1_PIN    5
/*TIMER1 TIFR_REG PINS*/

#define TOV1_PIN    2
#define OCF1B_PIN   3
#define OCF1A_PIN   4
#define ICF1_PIN   5

/*TIMER1 TCCRA1_REG PINS*/
#define WGM10_PIN    0
#define WGM11_PIN    1
#define FOC1B_PIN    2
#define FOC1A_PIN    3
#define COM1B0_PIN   4
#define COM1B1_PIN   5
#define COM1A0_PIN   6
#define COM1A1_PIN   7

/*TIMER1 TCCRB1_REG PINS*/

#define CS10_PIN    0
#define CS11_PIN    1
#define CS12_PIN    2
#define WGM12_PIN    3
#define WGM13_PIN    4
#define ICES1_PIN    6
#define ICNC1_PIN    7


#define OC1A 5
#define OC1B 4

#endif /* MCAL_PWM_TIMER_1_DRIVER_PWM_TIMER_1_REG_H_ */
