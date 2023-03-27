 /******************************************************************************
 *
 * Module: TIMER_driver
 *
 * File Name: TIMER_Interface.h
 *
 * Description: Header file for the TIMER_driver can be included in other files
 *
 * Author: yousef
 *
 *******************************************************************************/

#ifndef MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_
#define MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_


#include "../../LIB_FOLDER/dataTypes.h"
#include "../../LIB_FOLDER/common_macros.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#define CLEAR_CLOCK_VALUE        0XF8
#define NULL   (void*)0


typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Timer_Clock;


typedef enum
{
	Overflow,Compare
}Timer_Mode;


typedef enum
{
	enable, disable
}timer_int;

typedef  void(* timer_callback_ptr)(void);


typedef struct
{
	uint16 timer_Initial_Value;
	uint16 timer_Match_Value;
	Timer_Clock timer_clk;
	Timer_Mode  timer_mode;
	timer_int interrupt;
}Timer_Configuration;

/*static configuration for the delay function */
volatile static Timer_Configuration Configuration_Ptr ={0,0,F_CPU_CLOCK,Overflow,enable};
/***************************************************************************************************
 * [Function Name]: TimerSetCallBack
 *
 * [Description]:  Function to set the Call Back function address.
 *
 * [Args]:        timer_type ,Function_ptr
 *
 * [In]           Function_ptr: -Pointer to function
 *                        -To use it to save receive the function call back name
 *                        -To store it in the global pointer to function to use it in
 *
 *                 timer_type: -Variable from type enum Timer_Type
 *                             -To use it to choose the type of the timer
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/

void Timer2_vSetCallBack(void(*Function_ptr)(void) );

/***************************************************************************************************
 * [Function Name]: TimerInit
 *
 * [Description]:  Function to Initialize Timer Driver
 *                 - Working in Interrupt Mode
 *                  - Choose Timer initial value
 *                 - Choose Timer match value  if using CTC mode (compare mode)
 *                 - Choose Timer_Type (Timer_0, Timer_1, Timer_2)
 *                  - Choose Timer_Clock
 *                 - Choose Timer_Mode (OverFlow, Compare)
 *                 - Choose channel_Type in case of Timer_1
 *
 *
 *
 * [Args]:         Configuration_Ptr
 *
 * [In]            Configuration_Ptr which is a Pointer to Structure of Timer Configurations
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/

void Timer2_vInit(void);

/***************************************************************************************************
 * [Function Name]: TimerStop
 *
 * [Description]:  Function to stop the clock of the timer to stop incrementing
 *
 * [Args]:         timer_type
 *
 *
 * [In]            timer_type: -Variable from type enum Timer_Type
 *                             -To use it to choose the type of the timer
 *                             -stop the required timer
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/

void Timer2_vStop(void);

/***************************************************************************************************
 * [Function Name]: TimerDeInit
 *
 * [Description]:  Function to DeInit the timer to start again from beginning
 *
 * [Args]:         timer_type
 *
 *
 * [In]            timer_type: -Variable from type enum Timer_Type
 *                             -To use it to choose the type of the timer
 *                             -DeInit the required timer
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/

void Timer2_vDeInit(void);
void Timer2_vClear(void);
uint8 Timer2_vReadValue(void);

#endif /* MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_ */
