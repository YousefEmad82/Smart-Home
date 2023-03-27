/*
 * EEPROM_interface.h
 *
 * Created: 3/11/2023 9:10:35 PM
 *  Author: youssef's
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_
#include "EEPROM_REG.h"

//write function
void EEPROM_WRITE(uint16 address, uint8 data);

//read function 
uint8 EEPROM_READ( uint16 address);

//delete byte function 
void EEPROM_DELETE(uint8 address);

#endif /* EEPROM_INTERFACE_H_ */