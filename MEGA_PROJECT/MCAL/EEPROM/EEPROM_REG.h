/*
 * EEPROM_REG.h
 *
 * Created: 3/11/2023 9:09:59 PM
 *  Author: youssef's
 */ 


#ifndef EEPROM_REG_H_
#define EEPROM_REG_H_
#include "../../LIB_FOLDER/common_macros.h"
#include "../../LIB_FOLDER/std_types.h"

//registers of EEPROM
#define EEARL_REG       *((volatile uint8*)(0x3E))  
#define EEARH_REG		*((volatile uint8*)(0x3F))  
#define EEAR_REG		*((volatile uint16*)(0x3E))  
#define EEDR_REG		*((volatile uint8*)(0x3D))  
#define EECR_REG		*((volatile uint8*)(0x3C))  



//EECR bits (control register)
#define EERIE		3     //EEPROM interrupt enable 
#define EEMWE		2     //EEPROM master write enable 
#define EEWE		1     //EEPROM write enable 
#define EERE		0	  //EEPROM read enable 



#endif /* EEPROM_REG_H_ */