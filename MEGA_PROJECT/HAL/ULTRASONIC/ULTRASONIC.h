/*
 * ULTRASONIC.h
 *
 * Created: 3/16/2023 10:41:20 AM
 *  Author: youssef's
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include  "../../LIB_FOLDER/std_types.h"
#include  "../../LIB_FOLDER/common_macros.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER_0/Timer0_Interface.h"
#include "util/delay.h"




#define  TRIG_Pin      PIN0

#define  ECHO_Pin      PIN1

#define  TRIG_PORT     PORT_A

#define  ECHO_PORT     PORT_A


//APIs
void ULTRASONIC_INIT(void);
float ULTRASONIC_GET_DISTANCE(void );
void _ultrasonic__Tim_delay_us(uint8 uSec);
void ULTRASONIC_DISTANCE_DISPLAY_OLED();




#endif /* ULTRASONIC_H_ */