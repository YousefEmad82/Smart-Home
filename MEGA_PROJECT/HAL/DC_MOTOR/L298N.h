/*
 * L298N.h
 *
 * Created: 3/2/2023 7:50:17 PM
 *  Author: youssef's
 */ 


#ifndef L298N_H_
#define L298N_H_
#include "../../MCAL/DIO/DIO_Interface.h"


//MOTOR_A
#define INPUT1               PORT_C,PIN4
#define INPUT2               PORT_C,PIN5
#define DC_MOTOR_A_ENABLE    PORT_D,PIN7

//MOTOR_B
#define INPUT3 PORT_C,PIN6
#define INPUT4 PORT_C,PIN7
#define DC_MOTOR_B_ENABLE    PORT_D,PIN6


#define CLOCK_WISE       0
#define ANTI_CLOCK_WISE  1


void MOTOR_A_INIT();
void MOTOR_A_ROTATE(uint8 direcion);
void MOTOR_A_STOP();


void MOTOR_B_INIT();
void MOTOR_B_ROTATE(uint8 direcion);
void MOTOR_B_STOP();


#endif /* L298N_H_ */