/*
 * DIO_REG.h
 *
 *  Created on: Feb 17, 2023
 *      Author: youssef's
 */
#ifndef MCAL_INCLUDES_DIO_REG_H_
#define MCAL_INCLUDES_DIO_REG_H_
#include "../../LIB_FOLDER/std_types.h"
#include "../../LIB_FOLDER/common_macros.h"


#define PORTA_BASE ((volatile DIO_Regs* )0x39)
#define PORTB_BASE ((volatile DIO_Regs* )0x36)
#define PORTC_BASE ((volatile DIO_Regs* )0x33)
#define PORTD_BASE ((volatile DIO_Regs* )0x30)

typedef struct
{
	uint8 Pin;
	uint8 DDR;
	uint8 Port;
}DIO_Regs;


#endif /* MCAL_INCLUDES_DIO_REG_H_ */
