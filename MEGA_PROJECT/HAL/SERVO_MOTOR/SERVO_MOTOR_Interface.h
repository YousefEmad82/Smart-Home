/*
 * SERVO_MOTOR_Interface.h
 *
 *  Created on: Mar 14, 2023
 *      Author: dell
 */

#ifndef HAL_SERVO_MOTOR_SERVO_MOTOR_INTERFACE_H_
#define HAL_SERVO_MOTOR_SERVO_MOTOR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB_FOLDER/common_macros.h"
#include "../../LIB_FOLDER/std_types.h"



/************************************************************************/
/*								Functions Prototypes                    */
/************************************************************************/


/*********************************************************************************************************
 * Function Name: Servo_Init
 *
 * Description:  Function to initialize servo first position
 *
 * Function Parameters:	        NONE
 *
 * Returns:						NONE
 ********************************************************************************************************/
void Servo_vInit(void);


/*********************************************************************************************************
 * Function Name: Servo_SetAngle
 *
 * Description:  Function to set angle for servo
 *
 * Function Parameters:	 the only need parameter is servo desired angle
 *
 * Returns:						NONE
 ********************************************************************************************************/
void Servo_vSetAngle(uint8 angle);


#endif /* HAL_SERVO_MOTOR_SERVO_MOTOR_INTERFACE_H_ */
