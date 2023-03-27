#include "DIO_Interface.h"


//input without pullup clear ddr
//input with pullup clear ddr, set port
//output set ddr

void DIO_vSetPinDirection(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber,uint8 copy_u8state)
{
	if((Copy_u8PinNumber >= NUM_OF_PINS_PER_PORT) || (Copy_u8PORT >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		switch(Copy_u8PORT)
		{
			case PORT_A: //PORTA
			if(copy_u8state == OUTPUT)
			{
				SET_BIT(PORTA_BASE->DDR ,Copy_u8PinNumber);
			}
			else if (copy_u8state == INPUT_WITHOUT_PULLUP)
			{
				CLEAR_BIT(PORTA_BASE->DDR,Copy_u8PinNumber);
			}
			else if (copy_u8state == INPUT_WITH_PULLUP)
			{
				CLEAR_BIT(PORTA_BASE->DDR,Copy_u8PinNumber);
				SET_BIT(PORTA_BASE ->Port,Copy_u8PinNumber);
			}
			break;
			case PORT_B: //PORTB
			if(copy_u8state == OUTPUT)
			{
				SET_BIT(PORTB_BASE->DDR,Copy_u8PinNumber);
			}
			else if (copy_u8state == INPUT_WITHOUT_PULLUP)
			{
				CLEAR_BIT(PORTB_BASE->DDR,Copy_u8PinNumber);
			}
			else if (copy_u8state == INPUT_WITH_PULLUP)
			{
				CLEAR_BIT(PORTB_BASE->DDR,Copy_u8PinNumber);
				SET_BIT(PORTB_BASE ->Port,Copy_u8PinNumber);
			}
			break;
			case PORT_C: //PORTC
			if(copy_u8state == OUTPUT)
			{
				SET_BIT(PORTC_BASE->DDR,Copy_u8PinNumber);
			}
			else if (copy_u8state == INPUT_WITHOUT_PULLUP)
			{
				CLEAR_BIT(PORTC_BASE->DDR,Copy_u8PinNumber);
			}
			else if (copy_u8state == INPUT_WITH_PULLUP)
			{
				CLEAR_BIT(PORTC_BASE->DDR,Copy_u8PinNumber);
				SET_BIT(PORTC_BASE ->Port,Copy_u8PinNumber);
			}
			break;
			case PORT_D: //PORTD
			if(copy_u8state == OUTPUT)
			{
				SET_BIT(PORTD_BASE->DDR,Copy_u8PinNumber);
			}
			else if (copy_u8state == INPUT_WITHOUT_PULLUP)
			{
				CLEAR_BIT(PORTD_BASE->DDR,Copy_u8PinNumber);
			}
			else if (copy_u8state == INPUT_WITH_PULLUP)
			{
				CLEAR_BIT(PORTD_BASE->DDR,Copy_u8PinNumber);
				SET_BIT(PORTD_BASE ->Port,Copy_u8PinNumber);
			}
			break;
		}
	}

}

void DIO_vWritePin(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber,uint8 Copy_u8value)
{
	if((Copy_u8PinNumber >= NUM_OF_PINS_PER_PORT) || (Copy_u8PORT >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		switch(Copy_u8PORT)
		{
			case PORT_A: //PORTA
			if(Copy_u8value == HIGH)
			{
				SET_BIT(PORTA_BASE->Port ,Copy_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(PORTA_BASE->Port ,Copy_u8PinNumber);
			}
			break;
			case PORT_B: //PORTB
			if(Copy_u8value == HIGH)
			{
				SET_BIT(PORTB_BASE->Port,Copy_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(PORTB_BASE->Port ,Copy_u8PinNumber);
			}
			break;
			case PORT_C: //PORTC
			if(Copy_u8value == HIGH)
			{
				SET_BIT(PORTC_BASE->Port,Copy_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(PORTC_BASE->Port ,Copy_u8PinNumber);
			}
			break;
			case PORT_D: //PORTD
			if(Copy_u8value == HIGH)
			{
				SET_BIT(PORTD_BASE->Port,Copy_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(PORTD_BASE->Port ,Copy_u8PinNumber);
			}
			break;
		}
	}

}
void DIO_vTogglePin(uint8 Copy_u8PORT, uint8 Copy_u8PinNumber) {
	switch (Copy_u8PORT) {
		case PORT_A: //PORTA
		TOGGLE_BIT(PORTA_BASE->Port,Copy_u8PinNumber);
		break;
		case PORT_B: //PORTB
		TOGGLE_BIT(PORTB_BASE->Port,Copy_u8PinNumber);
		break;
		case PORT_C: //PORTC
		TOGGLE_BIT(PORTC_BASE->Port,Copy_u8PinNumber);
		break;
		case PORT_D: //PORTD
		TOGGLE_BIT(PORTD_BASE->Port,Copy_u8PinNumber);
		break;
	}
}

void DIO_vSetPortDirection(uint8 Copy_u8PORT, uint8 copy_u8state) {
	switch (Copy_u8PORT) {
		case PORT_A: //PORTA
		if(copy_u8state == OUTPUT){
			PORTA_BASE->DDR = 0xFF;
		}
		else if(copy_u8state == INPUT_WITH_PULLUP){
			PORTA_BASE->DDR = 0x00;
			PORTA_BASE->Port = 0xFF;
		}
		else if(copy_u8state == INPUT_WITHOUT_PULLUP){
			PORTA_BASE->DDR = 0x00;
		}
		break;
		case PORT_B: //PORTB
		if(copy_u8state == OUTPUT){
			PORTB_BASE->DDR = 0xFF;
		}
		else if(copy_u8state == INPUT_WITH_PULLUP){
			PORTB_BASE->DDR = 0x00;
			PORTB_BASE->Port = 0xFF;
		}
		else if(copy_u8state == INPUT_WITHOUT_PULLUP){
			PORTB_BASE->DDR = 0x00;
		}
		break;
		case PORT_C: //PORTC
		if(copy_u8state == OUTPUT){
			PORTC_BASE->DDR = 0xFF;
		}
		else if(copy_u8state == INPUT_WITH_PULLUP){
			PORTC_BASE->DDR = 0x00;
			PORTC_BASE->Port = 0xFF;
		}
		else if(copy_u8state == INPUT_WITHOUT_PULLUP){
			PORTC_BASE->DDR = 0x00;
		}
		break;
		case PORT_D: //PORTD
		if(copy_u8state == OUTPUT){
			PORTD_BASE->DDR = 0xFF;
		}
		else if(copy_u8state == INPUT_WITH_PULLUP){
			PORTD_BASE->DDR = 0x00;
			PORTD_BASE->Port = 0xFF;
		}
		else if(copy_u8state == INPUT_WITHOUT_PULLUP){
			PORTD_BASE->DDR = 0x00;
		}
		break;
	}
}

void DIO_vWritePort(uint8 Copy_u8PORT, uint8 Copy_u8value) {
	switch (Copy_u8PORT) {
		case PORT_A: //PORTA
		if(Copy_u8value == HIGH){
			PORTA_BASE->Port = 0xFF;
		}
		else{
			PORTA_BASE->Port = 0x00;
		}
		break;
		case PORT_B: //PORTB
		if(Copy_u8value == HIGH){
			PORTB_BASE->Port = 0xFF;
		}
		else{
			PORTB_BASE->Port = 0x00;
		}
		break;
		case PORT_C: //PORTC
		if(Copy_u8value == HIGH){
			PORTC_BASE->Port = 0xFF;
		}
		else{
			PORTC_BASE->Port = 0x00;
		}
		break;
		case PORT_D: //PORTD
		if(Copy_u8value == HIGH){
			PORTD_BASE->Port = 0xFF;
		}
		else{
			PORTD_BASE->Port = 0x00;
		}
		break;
	}
}
//returns the pin value, if the port was wrong it returns -1
uint8 DIO_u8GetPinValue(uint8 Copy_u8PORT, uint8 Copy_u8PinNumber) {
		uint8 u8Pin_Value;
	switch (Copy_u8PORT) {
		case PORT_A: //PORTA
		if(BIT_IS_SET(PORTA_BASE->Pin,Copy_u8PinNumber))
		{
			u8Pin_Value = HIGH;
		}
		else
		{
			u8Pin_Value = LOW;
		}
		break;
		case PORT_B: //PORTB
		if(BIT_IS_SET(PORTB_BASE->Pin,Copy_u8PinNumber))
		{
			u8Pin_Value = HIGH;
		}
		else
		{
			u8Pin_Value = LOW;
		}
		break;
		case PORT_C: //PORTC
		if(BIT_IS_SET(PORTC_BASE->Pin,Copy_u8PinNumber))
		{
			u8Pin_Value = HIGH;
		}
		else
		{
			u8Pin_Value = LOW;
		}
		break;
		case PORT_D: //PORTD
		if(BIT_IS_SET(PORTD_BASE->Pin,Copy_u8PinNumber))
		{
			u8Pin_Value = HIGH;
		}
		else
		{
			u8Pin_Value = LOW;
		}
		break;
	}
	return u8Pin_Value;

}

void DIO_vTogglrPort(uint8 Copy_u8PORT) {
	switch (Copy_u8PORT) {
		case PORT_A: //PORTA
			TOGGLE_BIT(PORTA_BASE->Port ,PIN0);
			TOGGLE_BIT(PORTA_BASE->Port ,PIN1);
			TOGGLE_BIT(PORTA_BASE->Port ,PIN2);
			TOGGLE_BIT(PORTA_BASE->Port ,PIN3);
			TOGGLE_BIT(PORTA_BASE->Port ,PIN4);
			TOGGLE_BIT(PORTA_BASE->Port ,PIN5);
			TOGGLE_BIT(PORTA_BASE->Port ,PIN6);
			TOGGLE_BIT(PORTA_BASE->Port ,PIN7);
		case PORT_B: //PORTB
			TOGGLE_BIT(PORTB_BASE->Port ,PIN0);
			TOGGLE_BIT(PORTB_BASE->Port ,PIN1);
			TOGGLE_BIT(PORTB_BASE->Port ,PIN2);
			TOGGLE_BIT(PORTB_BASE->Port ,PIN3);
			TOGGLE_BIT(PORTB_BASE->Port ,PIN4);
			TOGGLE_BIT(PORTB_BASE->Port ,PIN5);
			TOGGLE_BIT(PORTB_BASE->Port ,PIN6);
			TOGGLE_BIT(PORTB_BASE->Port ,PIN7);
		break;
		case PORT_C: //PORTC
			TOGGLE_BIT(PORTC_BASE->Port ,PIN0);
			TOGGLE_BIT(PORTC_BASE->Port ,PIN1);
			TOGGLE_BIT(PORTC_BASE->Port ,PIN2);
			TOGGLE_BIT(PORTC_BASE->Port ,PIN3);
			TOGGLE_BIT(PORTC_BASE->Port ,PIN4);
			TOGGLE_BIT(PORTC_BASE->Port ,PIN5);
			TOGGLE_BIT(PORTC_BASE->Port ,PIN6);
			TOGGLE_BIT(PORTC_BASE->Port ,PIN7);
		break;
		case PORT_D: //PORTD
			TOGGLE_BIT(PORTD_BASE->Port ,PIN0);
			TOGGLE_BIT(PORTD_BASE->Port ,PIN1);
			TOGGLE_BIT(PORTD_BASE->Port ,PIN2);
			TOGGLE_BIT(PORTD_BASE->Port ,PIN3);
			TOGGLE_BIT(PORTD_BASE->Port ,PIN4);
			TOGGLE_BIT(PORTD_BASE->Port ,PIN5);
			TOGGLE_BIT(PORTD_BASE->Port ,PIN6);
			TOGGLE_BIT(PORTD_BASE->Port ,PIN7);
		break;
	}
}


void DIO_vWritePortValue(uint8 Copy_u8PORT, uint8 Copy_u8value) {
	switch (Copy_u8PORT) {
		case PORT_A: //PORTA
		PORTA_BASE->Port = Copy_u8value;
		break;
		
		case PORT_B: //PORTB
		PORTB_BASE->Port = Copy_u8value;
		break;
		
		case PORT_C: //PORTC
		PORTC_BASE->Port = Copy_u8value;
		break;
		
		case PORT_D: //PORTD
		PORTD_BASE->Port = Copy_u8value;
		break;
	}
}





