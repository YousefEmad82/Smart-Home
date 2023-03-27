/*
 * External_INT_Reg.h
 *
 *  Created on: 19 Feb 2023
 *      Author: yousef
 */

#ifndef MCAL_EXTERNAL_INT_REG_H_
#define MCAL_EXTERNAL_INT_REG_H_

#include "../../LIB_FOLDER/std_types.h"
#include "../../LIB_FOLDER/common_macros.h"

#define MCUCR     (*(volatile uint8*)0x55)
#define MCUCSR    (*(volatile uint8*)0x54)
#define GICR      (*(volatile uint8*)0x5B)
#define GIFR      (*(volatile uint8*)0x5A)

#define INT0_1_DDR      (*(volatile uint8*)0x31)
#define INT2_DDR        (*(volatile uint8*)0x37)
#define INT0_1_PORT     (*(volatile uint8*)0x32)
#define INT2_PORT       (*(volatile uint8*)0x38)

#endif /* MCAL_EXTERNAL_INT_REG_H_ */
