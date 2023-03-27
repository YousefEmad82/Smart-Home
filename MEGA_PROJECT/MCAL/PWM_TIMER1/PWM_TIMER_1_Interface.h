/*
 * PWM_Interface.h
 *
 *  Created on: Feb 26, 2023
 *      Author: dell
 */


#include "../../LIB_FOLDER/std_types.h"
#include "../../LIB_FOLDER/common_macros.h"




#define  FAST_PWM_8_bit 0
#define  PHASE_CORRECT_8_bit 1
#define  FAST_PWM_TOP_ICR 2
#define  PHASE_CORRECT_TOP_ICR 3


#define  channelA 0
#define  channelB 1

#define  normal 0
#define  Toggle 1
#define  inverting 2
#define  non_inverting 3
#define  FCPU_64 3

/*configuration*/

#define PWM_mode FAST_PWM_TOP_ICR
#define PWM_channel channelA
#define PWM_polarity non_inverting
#define PWM_prescaler FCPU_64
#define TIMER1_initial_value 0x0000
#define CLEAR_CLOCK_VALUE 0XF8
#define prescaler 64


void PWM_Init(void);
void PWM_Generate_CHANNELA(float32 Copy_u8DutyCycle, uint32 Copy_u8Dutyfreq);
void PWM_Generate_CHANNELB(uint8 Copy_u8DutyCycle, uint32 Copy_u8Dutyfreq);


