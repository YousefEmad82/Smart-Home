/*
 * External_INT.c
 *
 *  Created on: 19 Feb 2023
 *      Author: yousef
 */

#include "External_INT_Interface.h"
#include <avr/interrupt.h>
#include "../DIO/DIO_Interface.h"

static interrupt_callback_tcallback INT0_PTR =NULL_PTR;
static interrupt_callback_tcallback INT1_PTR =NULL_PTR;
static interrupt_callback_tcallback INT2_PTR =NULL_PTR;

ISR(INT0_vect)
{	
	if(INT0_PTR!=NULL_PTR)
	{
		(*INT0_PTR)();
	}


}

ISR(INT1_vect)
{	
	if(INT1_PTR!=NULL_PTR)
	{
		(*INT1_PTR)();
	}

}

ISR (INT2_vect)
{
	if(INT2_PTR!=NULL_PTR)
	{
		(*INT2_PTR)();
	}


}

void EXT_INT_Init(void)
{
	//Configure INT0/PD2 as input pin
	CLEAR_BIT(INT0_1_DDR,Pin_Int0);
	SET_BIT(INT0_1_PORT,Pin_Int0);
	// Configure INT1/PD3 as input pin
	CLEAR_BIT(INT0_1_DDR,Pin_Int1);
	SET_BIT(INT0_1_PORT,Pin_Int1);
	// Configure INT2/PB2 as input pin
	CLEAR_BIT(INT2_DDR,Pin_Int2);
	SET_BIT(INT2_PORT,Pin_Int2);

}
void EXT_INT_SET_CONFIG(void)
{

	if(config.Enable_INT0_Interrupt==ENABLE_INT0)
	{
		SET_BIT(GICR,ENABLE_INT0);
	}
	else
	{
		CLEAR_BIT(GICR,ENABLE_INT0);
	}
	if(config.Enable_INT1_Interrupt==ENABLE_INT1)
	{
		SET_BIT(GICR,ENABLE_INT1);
	}
	else
	{
		CLEAR_BIT(GICR,ENABLE_INT1);
	}
	if(config.Enable_INT2_Interrupt==ENABLE_INT2)
	{
		SET_BIT(GICR,ENABLE_INT2);
	}
	else
	{
		CLEAR_BIT(GICR,ENABLE_INT2);
	}
	MCUCR|=config.INT0_Triggering_Mode;
	MCUCR|=((config.INT1_Triggering_Mode)<<ISC10_BIT);
	MCUCSR|=((config.INT2_Triggering_Mode)<<ISC2_BIT);
}
void external_interrupt_register_callback(interrupt_callback_tcallback ptr,uint8 Int_Type)
{
	if(Int_Type==INT_0)
	{
		INT0_PTR=ptr;
	}
	else if (Int_Type==INT_1)
	{
		INT1_PTR=ptr;
	}
	else if (Int_Type==INT_2)
	{
		INT2_PTR=ptr;
	}

}
