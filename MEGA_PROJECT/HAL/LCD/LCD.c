/*
 * LCD.c
 *
 * Created: 2/20/2023 9:44:50 PM
 *  Author: yousef
 */ 

#include "LCD.h"
//static	Timer0Config config={T0_CTC,T0_FCPU_8,T0_NO_INTERRUPT,0,250};
	
void LCD_4_bit_init(void){
	//TIMER0_init(&config);
	
	DIO_vSetPortDirection(LCD_data_port, OUTPUT); /*set LCD port as OUTPUTPUTput*/
	DIO_vSetPinDirection(LCD_control_port, RS, OUTPUT);
	DIO_vSetPinDirection(LCD_control_port, EN, OUTPUT);
	
	//TIMER0_Delay_with_Blocking_ms(40,&config);/*LCD power on delay*/
	_delay_ms(40);
	LCD_4_bit_sendCommand(0x32); /*4 bit mode*/
	LCD_4_bit_sendCommand(0x28); /*2 line, 5*7 matrix in 4-bit mode*/
	LCD_4_bit_sendCommand(0x0C); /*Display on cursor off*/
	LCD_4_bit_sendCommand(0x06); /*increment cursor*/
	LCD_4_bit_sendCommand(0x01); /*clear display screen*/
}


void LCD_4_bit_sendCommand(uint8 cmnd){
	 /*send higher nibble*/
	DIO_vWritePin(LCD_data_port, D4, READ_BIT(cmnd,4));
	DIO_vWritePin(LCD_data_port, D5, READ_BIT(cmnd,5));
	DIO_vWritePin(LCD_data_port, D6, READ_BIT(cmnd,6));
	DIO_vWritePin(LCD_data_port, D7, READ_BIT(cmnd,7));
	
	
	DIO_vWritePin(LCD_control_port, RS, LOW); /*select command register*/
	
	DIO_vWritePin(LCD_control_port, EN, HIGH); /*enable pulse*/
	//TIMER0_Delay_with_Blocking_us(1,&config);
	_delay_us(1);
	DIO_vWritePin(LCD_control_port, EN, LOW);
	//TIMER0_Delay_with_Blocking_us(200,&config);
	_delay_us(200);
	/*send lower nibble*/
	DIO_vWritePin(LCD_data_port, D4, READ_BIT(cmnd,0));
	DIO_vWritePin(LCD_data_port, D5, READ_BIT(cmnd,1));
	DIO_vWritePin(LCD_data_port, D6, READ_BIT(cmnd,2));
	DIO_vWritePin(LCD_data_port, D7, READ_BIT(cmnd,3));
	
	DIO_vWritePin(LCD_control_port, EN, HIGH); /*enable pulse*/
	//TIMER0_Delay_with_Blocking_us(1,&config);
	_delay_us(1);
	DIO_vWritePin(LCD_control_port, EN, LOW);	
	//TIMER0_Delay_with_Blocking_ms(2,&config);
	_delay_ms(2);
}


void LCD_4_bit_sendChar(uint8 data){
	/*send higher nibble*/
	DIO_vWritePin(LCD_data_port, D4, READ_BIT(data,4));
	DIO_vWritePin(LCD_data_port, D5, READ_BIT(data,5));
	DIO_vWritePin(LCD_data_port, D6, READ_BIT(data,6));
	DIO_vWritePin(LCD_data_port, D7, READ_BIT(data,7));
	
	DIO_vWritePin(LCD_control_port, RS, HIGH); /*select data register*/
	
	DIO_vWritePin(LCD_control_port, EN, HIGH); /*enable pulse*/
	//TIMER0_Delay_with_Blocking_us(1,&config);
	_delay_us(1);
	DIO_vWritePin(LCD_control_port, EN, LOW);
	//TIMER0_Delay_with_Blocking_us(200,&config);
	_delay_us(200);
	/*send lower nibble*/
	DIO_vWritePin(LCD_data_port, D4, READ_BIT(data,0));
	DIO_vWritePin(LCD_data_port, D5, READ_BIT(data,1));
	DIO_vWritePin(LCD_data_port, D6, READ_BIT(data,2));
	DIO_vWritePin(LCD_data_port, D7, READ_BIT(data,3));
	
	DIO_vWritePin(LCD_control_port, EN, HIGH); /*enable pulse*/
	//TIMER0_Delay_with_Blocking_us(1,&config);
	_delay_us(1);
	DIO_vWritePin(LCD_control_port, EN, LOW);
	//TIMER0_Delay_with_Blocking_ms(2,&config);
	_delay_ms(2);
}


void LCD_4_bit_clear(void){
	LCD_4_bit_sendCommand(0x01); /*clear display screen*/
	LCD_4_bit_sendCommand(0x80); /*cursor at home position*/
	//TIMER0_Delay_with_Blocking_ms(2,&config);
	_delay_ms(2);
}


void LCD_4_bit_sendString(uint8 *data){
	for(uint8 i=0; data[i]; i++)
		LCD_4_bit_sendChar(data[i]);
}

void LCD_4_bit_firstLine(void){
	LCD_4_bit_sendCommand(0x80);
}

void LCD_4_bit_secondLine(void){
	LCD_4_bit_sendCommand(0xC0);
}

void LCD_intgerToString(int data){
	char buff[16]; /* String to hold the ascii result */
	sprintf(buff,"%d",data); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_4_bit_sendString(buff); /* Display the string */
}
void LCD_8_bit_init(void){
	DIO_vSetPortDirection(LCD_data_port, OUTPUT); /*set LCD port as OUTPUTput*/
	DIO_vSetPinDirection(LCD_control_port, RS, OUTPUT);
	DIO_vSetPinDirection(LCD_control_port, EN, OUTPUT);
	
	//TIMER0_Delay_with_Blocking_ms(40,&config); /*LCD power on delay*/
	_delay_ms(40);
	
	LCD_8_bit_sendCommand(0x34); /*1 line, 5*10 matrix in 8-bit mode*/
	LCD_8_bit_sendCommand(0x0E); /*Display on, cursor blinking*/
	LCD_8_bit_sendCommand(0x06); /*increment cursor*/
	LCD_8_bit_sendCommand(0x01); /*clear display screen*/
	LCD_8_bit_sendCommand(0x80); /*cursor at home position*/
	
}


void LCD_8_bit_sendCommand(uint8 cmnd){
	DIO_vWritePortValue(LCD_data_port, cmnd); /*send command*/
	DIO_vWritePin(LCD_control_port, RS, LOW); /*select command register*/
	
	DIO_vWritePin(LCD_control_port, EN, HIGH); /*enable pulse*/
	//TIMER0_Delay_with_Blocking_ms(1,&config);
	_delay_ms(1);
	DIO_vWritePin(LCD_control_port, EN, LOW);
	//TIMER0_Delay_with_Blocking_ms(2,&config);
	_delay_ms(2);

}


void LCD_8_bit_sendChar(uint8 data){
	DIO_vWritePortValue(LCD_data_port, data); /*send character*/
	DIO_vWritePin(LCD_control_port, RS, HIGH); /*select data register*/
	
	DIO_vWritePin(LCD_control_port, EN, HIGH); /*enable pulse*/
	//TIMER0_Delay_with_Blocking_us(1,&config);
	_delay_us(1);
	DIO_vWritePin(LCD_control_port, EN, LOW);
	//TIMER0_Delay_with_Blocking_ms(2,&config);
	_delay_ms(2);
}


void LCD_8_bit_clear(void){
	LCD_8_bit_sendCommand(0x01); /*clear display screen*/
	LCD_8_bit_sendCommand(0x80); /*cursor at home position*/
}


void LCD_8_bit_sendString(uint8 *data){
	for(uint8 i=0; data[i]; i++)
	LCD_8_bit_sendChar(data[i]);
}

void LCD_8_bit_firstLine(void){
	LCD_8_bit_sendCommand(0x80);
}

void LCD_8_bit_secondLine(void){
	LCD_8_bit_sendCommand(0xC0);
}