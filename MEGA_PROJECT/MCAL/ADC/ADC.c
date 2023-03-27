/*
 * ADC.c
 *
 * Created: 3/1/2023 9:26:42 PM
 *  Author: youssef's
 */ 

#include "ADC_interface.h"
ADC_CONFIG ADC_Config = {DIV_2,AVCC,LEFT};
void ADC_INIT(uint8 channel){
	//set channel to be input
	CLEAR_BIT(DDRA,channel);
	
	//setting the vref
	if(ADC_Config.VREF == AVCC){
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
	}
	else if(ADC_Config.VREF == AREF){
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
	}
	
	//setting the prescaler
	ADCSRA |= ADC_Config.prescaler;
	
	//enabling the ADC
	SET_BIT(ADCSRA,ADEN);
	
	//adjusting the direction of ADC DATA register
	if(ADC_Config.ADJUST_LEFT_RIGHT == LEFT){
		SET_BIT(ADMUX,ADLAR);
	}
	else if(ADC_Config.ADJUST_LEFT_RIGHT == RIGHT){
		CLEAR_BIT(ADMUX,ADLAR);
	}
}
uint16 ADC_READ(uint8 channel){
	//initializing first five bits by 0
	ADMUX &= 0xE0;
	
	//choosing the channel
	ADMUX |=channel;
	 
	//starting conversion
	SET_BIT(ADCSRA,ADSC);
	
	while(READ_BIT(ADCSRA,ADIF) == 0);
	
	//read the converted input
	if(ADC_Config.ADJUST_LEFT_RIGHT == LEFT){
		return ADC_DATA_REGISTER>>6;
	}
	else if(ADC_Config.ADJUST_LEFT_RIGHT == RIGHT){
		return ADC_DATA_REGISTER;
	}
}