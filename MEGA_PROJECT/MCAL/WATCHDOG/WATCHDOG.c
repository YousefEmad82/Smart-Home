/*
 * WATCHDOG.c
 *
 * Created: 3/18/2023 12:08:51 PM
 *  Author: youssef's
 */ 

#include "WATCHDOG.h"
void WATCHDOG_ON(void){
	//watchdog resets after 2.1 seconds 
	WDTCR_REG = (1<<WDE)|(1<<WDP2)|(1<<WDP0);
	CLEAR_BIT(WDTCR_REG,WDP1);
}
void WATCHDOG_OFF(void){
	//sets the watch dog off 
	WDTCR_REG = (1<<WDTOE)|(1<<WDE);
	WDTCR_REG = 0x00;
}