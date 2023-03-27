 /******************************************************************************
 *
 * Module: TIMER_driver
 *
 * File Name: TIMER.c
 *
 * Description: Source file for the TIMER_driver
 *
 * Author: yousef
 *
 *******************************************************************************/

#include "TIMER_2_Reg.h"

static volatile timer_callback_ptr T2_callBack_Ptr = NULL;

                                     /*ISR for timer 2*/
ISR(TIMER2_OVF)
{
	if(T2_callBack_Ptr != NULL)
	{

		(*T2_callBack_Ptr)(); //calling the function from the main using pointer to function
	}
}

ISR(TIMER2_COMP)
{
	if(T2_callBack_Ptr != NULL)
	{

		(*T2_callBack_Ptr)(); //calling the function from the main using pointer to function
	}
}



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

       /*function to take a pointer of the needed function in main and pass it to the ISR function*/

void Timer2_vSetCallBack(void(*Function_ptr)(void))
{
T2_callBack_Ptr = Function_ptr;
}


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


         /*function to set the initial values for any timer type*/

void Timer2_vInit(){
	Timer2_vDeInit();// reset all registers
	ASSR_REG  &= 0X00;
	        TCNT2_REG = (Configuration_Ptr.timer_Initial_Value) & 0xFF;
			TCCR2_REG  = (TCCR2_REG  & CLEAR_CLOCK_VALUE) | (Configuration_Ptr.timer_clk);
			TCCR2_REG  = CLEAR_BIT(TCCR2_REG ,  COM20_PIN);
			TCCR2_REG  = CLEAR_BIT(TCCR2_REG ,  COM21_PIN);

	        if(Configuration_Ptr.timer_mode== Overflow)
	        {
	        	TCCR2_REG  = CLEAR_BIT(TCCR2_REG , WGM20_PIN);
	        	TCCR2_REG  = CLEAR_BIT(TCCR2_REG , WGM21_PIN);
	        	TCCR2_REG  = CLEAR_BIT(TCCR2_REG,FOC2_PIN);
	        	TIMSK_REG = SET_BIT(TIMSK_REG, TOIE2_PIN);//

	        }
	        else if(Configuration_Ptr.timer_mode==Compare)
	        {
	        TCCR2_REG = CLEAR_BIT(TCCR2_REG , WGM20_PIN);
	        TCCR2_REG  = SET_BIT(TCCR2_REG , WGM21_PIN);
	        TCCR2_REG  = SET_BIT(TCCR2_REG,FOC2_PIN);
	        OCR2_REG   = (Configuration_Ptr.timer_Match_Value) & 0xFF;
	        TIMSK_REG  = SET_BIT(  TIMSK_REG, OCIE2_PIN);
	        }



}

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



                          /*stop function to stop the timer from counting*/

void Timer2_vStop()// stop timer clk
{
	TCCR2_REG = TCCR2_REG  & CLEAR_CLOCK_VALUE ;

}

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



                                /*de intializing   the timer registers       */

void Timer2_vDeInit()
{

		TCNT2_REG =0x00;//timer 2 initial value register
		TCCR2_REG &=0x00;//timer 2 control register
		OCR2_REG  &=0x00;//timer 2 o/p compare register
		TIMSK_REG &=0x00;//timer 2 interrupt mask register

}

void Timer2_vClear(void)
{
	TCNT2_REG =0x00;
}
uint8 Timer2_vReadValue(void)
{
	return TCNT2_REG;
}
