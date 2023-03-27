/*
 * Timer0.c
 *
 *  Created on: Feb 24, 2023
 *      Author: Yousef
 */

#include "Timer0_Interface.h"
#include "../DIO/DIO_Interface.h"

static void (*g_ptr)(uint16,const Timer0Config *) = NULL_PTR;
static void (*g_callback_ptr)(void) = NULL_PTR;
static uint8 flag = 0;
static uint16 g_Milli_Seconds;
static Timer0Config g_config;
ISR(TIMER0_OVF_vect)
{
	if(*g_ptr != NULL_PTR)
	{
		(*g_ptr)(g_Milli_Seconds,&g_config);
	}
	if(flag != 0 && *g_callback_ptr != NULL_PTR)
	{
		(*g_callback_ptr)();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(*g_ptr != NULL_PTR)
	{
		(*g_ptr)(g_Milli_Seconds,&g_config);
	}
	if(flag != 0 && *g_callback_ptr != NULL_PTR)
	{
		(*g_callback_ptr)();
	}
}

void TIMER0_init(const Timer0Config *a_config_ptr)
{
	TCCR0 = 0;
	if(a_config_ptr -> s_timer0Mode == T0_OVERFLOW && a_config_ptr ->s_interruptMode0 == T0_INTERRUPT)
	{
		SET_BIT(TIMSK,TOIE0);
		SET_BIT(SREG,GIE);
	}
	else if(a_config_ptr -> s_timer0Mode == T0_CTC && a_config_ptr ->s_interruptMode0 == T0_INTERRUPT)
	{
		SET_BIT(TIMSK,OCIE0);
		SET_BIT(SREG,GIE);
	}
	else
	{
		CLEAR_BIT(TIMSK,TOIE0);
		CLEAR_BIT(TIMSK,OCIE0);
	}
	SET_BIT(TCCR0,FOC0);
	TCCR0 |= (((a_config_ptr -> s_timer0Mode)&0x01)<<WGM00) | (((a_config_ptr -> s_timer0Mode)&0x02)<<(WGM01-1));
	TCNT0 = a_config_ptr -> s_timerValue;
	OCR0 = a_config_ptr -> s_ctcValue;
}

void TIMER0_callback(void (*a_ptr)(void))
{
	g_callback_ptr = a_ptr;
}

void TIMER0_Delay_with_Blocking_ms(uint16 Milli_Seconds,const Timer0Config *a_config_ptr)
{
	TCNT0 = 0;
	TCCR0 |= a_config_ptr -> s_prescaler0;
	uint16 pre;
	if(a_config_ptr ->s_prescaler0 == T0_FCPU)
	{
		pre = 1;
	}
	else if(a_config_ptr ->s_prescaler0 == T0_FCPU_8)
	{
		pre = 8;
	}
	else if(a_config_ptr ->s_prescaler0 == T0_FCPU_64)
	{
		pre = 64;
	}
	else if(a_config_ptr ->s_prescaler0 == T0_FCPU_256)
	{
		pre = 256;
	}
	else if(a_config_ptr ->s_prescaler0 == T0_FCPU_1024)
	{
		pre = 1024;
	}
	uint16 MAX,over,ticks;
	if(a_config_ptr -> s_timer0Mode == T0_OVERFLOW)
	{
		MAX = 256;
	}
	else if(a_config_ptr -> s_timer0Mode == T0_CTC)
	{
		MAX = a_config_ptr -> s_ctcValue;
	}
	ticks = ((Milli_Seconds*(F_CPU/1000))/pre)/MAX;
	over = ((Milli_Seconds*(F_CPU/1000))/pre)%MAX;
	for(uint16 t=0;t<ticks;t++)
	{
		if(a_config_ptr -> s_timer0Mode == T0_OVERFLOW)
		{
			while(BIT_IS_CLEAR(TIFR,TOV0));
			SET_BIT(TIFR,TOV0);
		}
		else if(a_config_ptr -> s_timer0Mode == T0_CTC)
		{
			while(BIT_IS_CLEAR(TIFR,OCF0));
			SET_BIT(TIFR,OCF0);
		}
	}
	TCNT0 = MAX - over;
	if(over != 0)
	{
		if(a_config_ptr -> s_timer0Mode == T0_OVERFLOW)
		{
			while(BIT_IS_CLEAR(TIFR,TOV0));
			SET_BIT(TIFR,TOV0);
		}
		else if(a_config_ptr -> s_timer0Mode == T0_CTC)
		{
			while(BIT_IS_CLEAR(TIFR,OCF0));
			SET_BIT(TIFR,OCF0);
		}
	}
	TCCR0 = TCCR0 & 0xF8;
}

void TIMER0_Delay_with_Blocking_us(uint32 Micro_Seconds,const Timer0Config *a_config_ptr)
{
	TCNT0 = 0;
	TCCR0 |= a_config_ptr -> s_prescaler0;
	uint16 pre;
	if(a_config_ptr ->s_prescaler0 == T0_FCPU)
	{
		pre = 1;
	}
	else if(a_config_ptr ->s_prescaler0 == T0_FCPU_8)
	{
		pre = 8;
	}
	else if(a_config_ptr ->s_prescaler0 == T0_FCPU_64)
	{
		pre = 64;
	}
	else if(a_config_ptr ->s_prescaler0 == T0_FCPU_256)
	{
		pre = 256;
	}
	else if(a_config_ptr ->s_prescaler0 == T0_FCPU_1024)
	{
		pre = 1024;
	}
	uint16 MAX;
	uint32 over,ticks;
	if(a_config_ptr -> s_timer0Mode == T0_OVERFLOW)
	{
		MAX = 256;
	}
	else if(a_config_ptr -> s_timer0Mode == T0_CTC)
	{
		MAX = a_config_ptr -> s_ctcValue;
	}
	ticks = ((Micro_Seconds*(F_CPU/1000000))/pre)/MAX;
	over = ((Micro_Seconds*(F_CPU/1000000))/pre)%MAX;
	for(uint16 t=0;t<ticks;t++)
	{
		if(a_config_ptr -> s_timer0Mode == T0_OVERFLOW)
		{
			while(BIT_IS_CLEAR(TIFR,TOV0));
			SET_BIT(TIFR,TOV0);
		}
		else if(a_config_ptr -> s_timer0Mode == T0_CTC)
		{
			while(BIT_IS_CLEAR(TIFR,OCF0));
			SET_BIT(TIFR,OCF0);
		}
	}
	TCNT0 = MAX - over;
	if(over != 0)
	{
		if(a_config_ptr -> s_timer0Mode == T0_OVERFLOW)
		{
			while(BIT_IS_CLEAR(TIFR,TOV0));
			SET_BIT(TIFR,TOV0);
		}
		else if(a_config_ptr -> s_timer0Mode == T0_CTC)
		{
			while(BIT_IS_CLEAR(TIFR,OCF0));
			SET_BIT(TIFR,OCF0);
		}
	}
	TCCR0 = TCCR0 & 0xF8;
}

void TIMER0_Delay_without_Blocking(uint16 Milli_Seconds,const Timer0Config *a_config_ptr)
{
	static uint16 MAX = 0;
	static uint32 over = 0,ticks = 0,t = 0;
	if(t == 0){
		TCNT0 = 0;
		TCCR0 |= a_config_ptr -> s_prescaler0;
		g_Milli_Seconds = Milli_Seconds;
		g_config = *a_config_ptr;
		g_ptr = TIMER0_Delay_without_Blocking;
		flag = 0;
		if(a_config_ptr -> s_timer0Mode == T0_OVERFLOW)
		{
			MAX = 256;
		}
		else if(a_config_ptr -> s_timer0Mode == T0_CTC)
		{
			MAX = a_config_ptr -> s_ctcValue;
		}
		uint16 pre;
		if(a_config_ptr ->s_prescaler0 == T0_FCPU)
		{
			pre = 1;
		}
		else if(a_config_ptr ->s_prescaler0 == T0_FCPU_8)
		{
			pre = 8;
		}
		else if(a_config_ptr ->s_prescaler0 == T0_FCPU_64)
		{
			pre = 64;
		}
		else if(a_config_ptr ->s_prescaler0 == T0_FCPU_256)
		{
			pre = 256;
		}
		else if(a_config_ptr ->s_prescaler0 == T0_FCPU_1024)
		{
			pre = 1024;
		}
		ticks = ((Milli_Seconds*(F_CPU/1000))/pre)/MAX;
		over = ((Milli_Seconds*(F_CPU/1000))/pre)%MAX;
	}
	if(t < ticks)
	{
		t++;
	}
	else if(t == ticks && over != 0)
	{
		TCNT0 = MAX - over;
		t++;
	}
	else{
		flag = 1;
		TCCR0 = 0;
		MAX = 0;
		over = 0;
		ticks = 0;
		t = 0;
	}
}
