/*
 * ADC_interface.h
 *
 * Created: 3/1/2023 9:26:00 PM
 *  Author: youssef's
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "ADC_REG.h"
#include "../../LIB_FOLDER/common_macros.h"


//ADMUX pins 4:0
#define ADC0 0x00
#define ADC1 0x01
#define ADC2 0x02
#define ADC3 0x03
#define ADC4 0x04
#define ADC5 0x05
#define ADC6 0x06
#define ADC7 0x07

//vcc REFS1 REFS0
//     0     1
//vref pins in ADMUX 
#define REFS1 7
#define REFS0 6
#define ADLAR 5
//vref
#define AVCC 0
#define AREF 1
//ADC DATA REG DIRECTION
#define LEFT 1
#define RIGHT 0


//pins of ADCSRA
#define ADEN 7
#define ADSC 6
#define ADIF 4
//pins of prescaler in  ADCSRA
#define DIV_2     0x00
#define DIV_4	  0x02
#define DIV_8     0x03
#define DIV_16	  0x04
#define DIV_32    0x05
#define DIV_64    0x06
#define DIV_128   0x07

typedef struct
	{
		uint8 prescaler;
		uint8 VREF;
		uint8 ADJUST_LEFT_RIGHT;
	
	}ADC_CONFIG;



//APIS
void ADC_INIT(uint8 channel);
uint16 ADC_READ( uint8 channel);






#endif /* ADC_INTERFACE_H_ */