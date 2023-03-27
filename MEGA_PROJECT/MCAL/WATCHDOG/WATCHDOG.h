/*
 * WATCHDOG.h
 *
 * Created: 3/18/2023 12:08:21 PM
 *  Author: youssef's
 */ 


#ifndef WATCHDOG_H_
#define WATCHDOG_H_
#include "../../LIB_FOLDER/std_types.h"
#include "../../LIB_FOLDER/common_macros.h"

//watch dog registers 
#define WDTCR_REG   *((volatile uint8 *)(0x41))


//WDTCR pins
#define WDTOE 4
#define WDE   3
#define WDP2  2
#define WDP1  1
#define WDP0  0


void WATCHDOG_ON(void);
void WATCHDOG_OFF(void);


#endif /* WATCHDOG_H_ */