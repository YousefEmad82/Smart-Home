/*
 * DIO_Interface.h
 *
 *  Created on: Feb 17, 2023
 *      Author: youssef's
 */


#ifndef MCAL_INCLUDES_DIO_INTERFACE_H_
#define MCAL_INCLUDES_DIO_INTERFACE_H_
#include "DIO_REG.h"

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


#define INPUT_WITH_PULLUP          0
#define INPUT_WITHOUT_PULLUP       1
#define OUTPUT                     2

#define HIGH 1
#define LOW  0

#define NUM_OF_PINS_PER_PORT 8
#define NUM_OF_PORTS         4

void DIO_vSetPinDirection(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber,uint8 copy_u8state);

void DIO_vWritePin(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber,uint8 Copy_u8value);

void DIO_vTogglePin(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber);

void DIO_vSetPortDirection(uint8 Copy_u8PORT,uint8 copy_u8state);

void DIO_vWritePort(uint8 Copy_u8PORT,uint8 Copy_u8value);

uint8 DIO_u8GetPinValue(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber);

void DIO_vTogglrPort(uint8 Copy_u8PORT);

void DIO_vWritePortValue(uint8 Copy_u8PORT, uint8 Copy_u8value);


#endif /* MCAL_INCLUDES_DIO_INTERFACE_H_ */
