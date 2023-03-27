/*
 * main.c
 *
 * Created: 3/11/2023 9:02:57 PM
 *  Author: youssef's
 */ 
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/ULTRASONIC/ULTRASONIC.h"
#include "HAL/OLED/OLED_SSD1306_Interface.h"
#include "APP/APP.h"
#include <util/delay.h>
#include <stdio.h>
#include "MCAL/UART/UART_Interface.h"
#include "HAL/SERVO_MOTOR/SERVO_MOTOR_Interface.h"
#include "MCAL/PWM_TIMER1/PWM_TIMER_1_Interface.h"
#include "MCAL/EXTERNAL_INT_driver/External_INT_Interface.h"

//variables used by RFID
extern uint8 CardId[4] ;//the card id
extern uint8 Status_ID ;
extern uint8 ID[4] ;//ID of the  currently used card
extern uint8 id_count;//count to the compared bytes  between the enrolled cardId and the currently used card
extern uint8 card__enroll_flag ; //flag to determine if a card is enrolled in the EEPROM or not
extern uint8 person_count ;




int main(void)
{	
	external_interrupt_register_callback(BUTTON_1_INT,INT_1);

	SREG |=(1<<7);//enable global interrupt of avr
	EXT_INT_Init();
	EXT_INT_SET_CONFIG();
	APP_INIT();
	while(1)
	{
		
		RFID_READ_CARD();
		ULTRASONIC_TURN_LEDS_ON();
		
}

	
	
	
	
		}