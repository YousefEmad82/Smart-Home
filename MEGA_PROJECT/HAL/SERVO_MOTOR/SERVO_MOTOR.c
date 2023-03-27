/*
 * SERVO_MOTOR.c
 *
 *  Created on: Mar 14, 2023
 *      Author: dell
 */

#include "SERVO_MOTOR_Interface.h"
#include "../../MCAL/PWM_TIMER1/PWM_TIMER_1_Interface.h"


void Servo_vInit(void)
{	PWM_Init();
	PWM_Generate_CHANNELA(5,50);//fPWM=50Hz (Period = 20ms Standard) for 8Mhz F_CPU
	/*1ms ~ 5% duty cycle*/
}

void Servo_vSetAngle(uint8 angle)
{
	uint16 OCR_value  = (((uint16)angle*100)/41.1)+97;//97 is the value of the ocrb1 register (high time) at witch the servo motor is stopped
    uint16 dutycycle = (OCR_value/50)*100;
    PWM_Generate_CHANNELA(dutycycle,50);

}
