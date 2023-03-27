/*
 * SPI.c
 *
 *  Created on: Mar 4, 2023
 *      Author: dell
 */
#include "SPI.h"

void SPI_Init()
{
	switch(SPI_DOUBLE_SPEED_MODE)
	{
		case DOUBLE_SPEED_MODE_DIS:clearBit(SPSR,SPI2X); break;
		case DOUBLE_SPEED_MODE_EN: setBit(SPSR,SPI2X);   break;
	}
	switch(DATA_ORDER)
	{
		case MSB:clearBit(SPCR,DORD); break;
		case LSB: setBit(SPCR,DORD);  break;
	}
	switch(CLK_POLARITY)
	{
		case RISING_LEADING:clearBit(SPCR,CPOL); break;
		case FALLING_LEADING: setBit(SPCR,CPOL); break;
	}
	switch(CLK_PHASE)
	{
		case SAMPLE_LEADING: clearBit(SPCR,CPHA); break;
		case SETUP_LEADING: setBit(SPCR,CPHA);	  break;
	}
	switch(SPI_INT_ENABLE)
	{
		case SPI_INT_DIS:clearBit(SPCR,SPIE); break;
		case SPI_INT_EN: setBit(SPCR,SPIE);   break;
	}
	switch(SPI_ENABLE)
	{
		case SPI_DIS:clearBit(SPCR,SPE);  break;
		case SPI_EN: setBit(SPCR,SPE);    break;
	}
	switch(IS_MSTR)
		{
			case SLAVE:	clearBit(DDRB_R,MOSI); clearBit(DDRB_R,SCK); clearBit(DDRB_R,SS); setBit(DDRB_R,MISO); clearBit(SPCR,MSTR); break;
			case MASTER:setBit(DDRB_R,MOSI); setBit(DDRB_R,SCK); setBit(DDRB_R,SS); clearBit(DDRB_R,MISO); setBit(PORTB_R,SS); setBit(SPCR,MSTR);  break;
		}
	setBit(SPCR,SPR0);
	clearBit(SPCR,SPR1);
}
uint8 SPI_DATA_RW(uint8 Copy_u8data)
{
	SPDR = Copy_u8data;
	while (!getBit(SPSR,SPIF));
	return SPDR;
}
