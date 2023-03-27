 /******************************************************************************
 *
 * Module: TIMER_driver
 *
 * File Name: TIMER_REG.h
 *
 * Description: Header file for the TIMER_driver cannot be included in other files (except for TIMER.c)
 *              as it contains the target chip mapped registers
 * Author: yousef
 *
 *******************************************************************************/
#ifndef MCAL_TIMER_DRIVER_TIMER_REG_H_
#define MCAL_TIMER_DRIVER_TIMER_REG_H_

#include "../TIMER_2_driver/TIMER_2_Interface.h"


//////////////////////////////////*************REGISTERS*************/////////////////////////////////////
/*TIMER2 REGISTERS*/
#define TCNT2_REG     *((volatile uint8*)0x44)
#define TCCR2_REG     *((volatile uint8*)0x45)
#define OCR2_REG      *((volatile uint8*)0x43)
#define TIMSK_REG     *((volatile uint8*)0x59)
#define  ASSR_REG     *((volatile uint8*)0x42)
#define SFIOR_REG     *((volatile uint8*)0x50)
/////////////////////////////////////////////********PINS********///////////////////////////////////////

/*pins*/
 /*tccr2*/
#define FOC2_PIN  7
#define WGM20_PIN 6
#define COM21_PIN 5
#define COM20_PIN 4
#define WGM21_PIN 3
#define CS22_PIN  2
#define CS21_PIN  1
#define CS20_PIN  0
 /*timsk*/
#define OCIE2_PIN 7
#define TOIE2_PIN 6
 /*tifr*/
#define OCF2_PIN 7
#define TOV2_PIN 6
 /*sfior*/
#define PSR2 1//prescaler reset




//////////////////////////////////////************IMPORTANT MACROS*****************///////////////////////////////////

#define CLEAR_CLOCK_VALUE        0XF8

/*TIMER2 INTERRUPT*/
#define    TIMER2_COMP   __vector_4
#define    TIMER2_OVF   __vector_5
#define ISR(vector)   void vector(void)  __attribute__((signal)); \
	                    void vector (void)



#endif /* MCAL_TIMER_DRIVER_TIMER_REG_H_ */
