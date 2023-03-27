/*
 * EEPROM.c
 *
 * Created: 3/11/2023 9:09:26 PM
 *  Author: youssef's
 */ 
#include "EEPROM_interface.h"

//write function
void EEPROM_WRITE(uint16 address, uint8 data)
{
	/* Wait for completion of previous write */
	while(READ_BIT(EECR_REG,EEWE) == 1);
	/* Set up address and data registers */
	EEAR_REG = address;
	EEDR_REG = data;
	/* Write logical one to EEMWE */
	SET_BIT(EECR_REG ,EEMWE);
	/* Start EEPROM write by setting EEWE */
	SET_BIT(EECR_REG ,EEWE);

}

//read function 
uint8 EEPROM_READ( uint16 address)
{
	/* Wait for completion of previous write */
	while(READ_BIT(EECR_REG,EEWE) == 1);
	/* Set up address register */
	EEAR_REG = address;
	/* Start EEPROM read by writing EERE */
	SET_BIT(EECR_REG ,EERE);
	/* Return data from data register */
	return EEDR_REG;
}


void EEPROM_DELETE(uint8 address){
	
	/* Wait for completion of previous write */
	while(READ_BIT(EECR_REG,EEWE) == 1);
	/* Set up address and data register to zero */
	EEAR_REG = address;
	EEDR_REG = 0x00;
	/* Write logical one to EEMWE */
	SET_BIT(EECR_REG ,EEMWE);
	/* Start EEPROM write by setting EEWE */
	SET_BIT(EECR_REG ,EEWE);
	
}


