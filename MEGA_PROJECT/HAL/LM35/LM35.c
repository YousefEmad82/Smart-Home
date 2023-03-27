/*
 * LM35.c
 *
 * Created: 3/2/2023 7:41:21 PM
 *  Author: youssef's
 */ 

#include "LM35.h"
void  LM35_init(){
	ADC_INIT(ADC1);
}

uint8 LM35_READ(){
	return (ADC_READ(ADC1)*5*100)/1023;
}