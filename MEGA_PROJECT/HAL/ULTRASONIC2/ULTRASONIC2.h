/*
 * ULTRASONIC2.h
 *
 * Created: 3/17/2023 9:42:51 PM
 *  Author: youssef's
 */ 


#ifndef ULTRASONIC2_H_
#define ULTRASONIC2_H_
#include  "../../LIB_FOLDER/std_types.h"
#include  "../../LIB_FOLDER/common_macros.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER_0/Timer0_Interface.h"
#include "util/delay.h"




#define  TRIG2_Pin      PIN0

#define  ECHO2_Pin      PIN1

#define  TRIG2_PORT     PORT_D

#define  ECHO2_PORT     PORT_D


//APIs
void ULTRASONIC2_INIT(void);
float ULTRASONIC2_GET_DISTANCE(void );
void _ultrasonic2__Tim_delay_us(uint8 uSec);
void ULTRASONIC2_DISTANCE_DISPLAY_OLED();







#endif /* ULTRASONIC2_H_ */