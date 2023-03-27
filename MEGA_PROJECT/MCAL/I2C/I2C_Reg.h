/*
 * I2C_Reg.h
 *
 *  Created on: Mar 6, 2023
 *      Author: Yousef
 */

#ifndef MCAL_I2C_DRIVER_I2C_REG_H_
#define MCAL_I2C_DRIVER_I2C_REG_H_
#include "I2C_Interface.h"
#include "../../LIB_FOLDER/std_types.h"
#include "../../LIB_FOLDER/common_macros.h"
/*Registers*/
#define  TWBR_REG    *(volatile uint8 *)0x20
#define  TWSR_REG    *(volatile uint8 *)0x21
#define  TWAR_REG    *(volatile uint8 *)0x22
#define  TWDR_REG    *(volatile uint8 *)0x23
#define  TWCR_REG    *(volatile uint8 *)0x56


/*pins*/
/*TWSR_Reg*/
#define TWPS0_PIN 0
#define TWPS1_PIN 1
#define TWS3_PIN 3
#define TWS4_PIN 4
#define TWS5_PIN 5
#define TWS6_PIN 6
#define TWS7_PIN 7
/*TWAR_Reg*/
#define TWGCE_PIN 0
#define TWA0_PIN 1
#define TWA1_PIN 2
#define TWA2_PIN 3
#define TWA3_PIN 4
#define TWA4_PIN 5
#define TWA5_PIN 6
#define TWA6_PIN 7
/*TWCR_Reg*/
#define TWIE_PIN 0
#define TWEN_PIN 2
#define TWWC_PIN 3
#define TWSTO_PIN 4
#define TWSTA_PIN 5
#define TWEA_PIN 6
#define TWINT_PIN 7



/*I2C INTERRUPT*/
#define NULL (void*)0
#define    TWI   __vector_19

#define ISR(vector)   void vector(void)  __attribute__((signal)); \
	                    void vector (void)







#endif /* MCAL_I2C_DRIVER_I2C_REG_H_ */
