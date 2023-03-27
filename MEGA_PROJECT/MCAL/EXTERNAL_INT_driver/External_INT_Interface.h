/*
 * External_INT_Interface.h
 *
 *  Created on: 19 Feb 2023
 *      Author: yousef
 */

#ifndef MCAL_EXTERNAL_INT_INTERFACE_H_
#define MCAL_EXTERNAL_INT_INTERFACE_H_

#include "External_INT_Reg.h"


typedef void  (*interrupt_callback_tcallback)(void);
/************* Modes ***********************/
// Modes that will be used for the external interrupt configuration
#define INT2_FALLING_EDGE_MODE 0
#define INT2_RISING_EDGE_MODE 1
/********** Enable Ext Interrupts ***********/
#define ENABLE_INT0 6
#define ENABLE_INT1 7
#define ENABLE_INT2 5
#define DISABLE_INT 0

#define INT_0       1
#define INT_1       2
#define INT_2       3

/********************************************/
#define Pin_Int0 2
#define Pin_Int1 3
#define Pin_Int2 2
#define GIE 7

#define ISC2_BIT  6
#define ISC10_BIT  2


typedef enum
{
	LOW_LEVEL,ANY_LOGICAL_CHANGE,FALLING_EDGE,RISING_EDGE
}Trigger_Mode;
//Struct that contains the external interrupt configuration options.
typedef struct
{
uint8 Enable_INT0_Interrupt;
uint8 Enable_INT1_Interrupt;
uint8 Enable_INT2_Interrupt;
Trigger_Mode INT0_Triggering_Mode;
Trigger_Mode INT1_Triggering_Mode;
uint8 INT2_Triggering_Mode;
}EXT_Int_Conf;


volatile static EXT_Int_Conf config={ENABLE_INT0,ENABLE_INT1,DISABLE_INT,FALLING_EDGE,FALLING_EDGE,INT2_FALLING_EDGE_MODE};
/*********** External_Interrupt APIS ****************/
void EXT_INT_Init(void);
void EXT_INT_SET_CONFIG(void);
/* Note that interrupt_callback_t is a pointer to function that should
defined by the developer this pointer to function take void and returns
void */
void external_interrupt_register_callback(interrupt_callback_tcallback ptr,uint8 Int_Type);
#endif /* MCAL_EXTERNAL_INT_INTERFACE_H_ */
