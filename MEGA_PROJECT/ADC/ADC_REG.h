/*
 * ADC_REG.h
 *
 * Created: 3/1/2023 9:26:15 PM
 *  Author: youssef's
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_
#include "../../LIB_FOLDER/std_types.h"
/***************************************************************************************************************/
/***************************************ADMUX DESCRIPTION************************************************************/
/*bits 4:0 are used to select pin  to read from
00000 ADC0
00001 ADC1
00010 ADC2
00011 ADC3 
00100 ADC4
00101 ADC5
00110 ADC6
00111 ADC7
*********************************************************************************************************************
bits 7:6 are used  to select the vref 
REFS1 REFS0 Voltage Reference Selection
0 0 AREF, Internal Vref turned off
0 1 AVCC with external capacitor at AREF pin   --------->we will use this 
1 0 Reserved
1 1 Internal 2.56V Voltage Reference with external capacitor at AREF pin
*********************************************************************************************************************
bit 5 is used to change the data representation in the ADC Data register immediately 
*/
/***************************************************************************************************************/


/***************************************ADCSRA DESCRIPTION************************************************************/
/*
Bit 7    6     5    4     3    2     1     0
   ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0 
   
   
Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
000 2
001 2
010 4
011 8
100 16
101 32
110 64
111 128
*********************************************************************************************************************
*/



//registers of the ADC
#define  ADMUX                *(volatile uint8 *)(0x27)
#define  ADCSRA               *(volatile uint8 *)(0x26)
#define  ADC_DATA_REGISTER    *(volatile uint16 *)(0x24)
#define  DDRA                 *(volatile uint8 *)(0x3A)












#endif /* ADC_REG_H_ */