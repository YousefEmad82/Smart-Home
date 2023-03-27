/*
 * APP.h
 *
 * Created: 3/14/2023 2:09:21 PM
 *  Author: youssef's
 */ 


#ifndef APP_H_
#define APP_H_


#include "../MCAL/EEPROM/EEPROM_interface.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/SPI/SPI.h"
#include "../HAL/RFID/RFID.h"
#include "../HAL/DC_MOTOR/L298N.h"
#include "../HAL/LM35/LM35.h"
#include "util/delay.h"
#include "../MCAL/PWM_TIMER1/PWM_TIMER_1_Interface.h"
#include "../HAL/ULTRASONIC/ULTRASONIC.h"
#include "../HAL/ULTRASONIC2/ULTRASONIC2.h"
#include "../MCAL/WATCHDOG/WATCHDOG.h"


//RFID
void RFID_READ_CARD(void);//function to read a card 
void RFID_ENROLL(void);//function to enroll a card
void RFID_INIT(void); //RFID initialization function

//OLED
void DRAW_FRAME(void);
void STR_IN_MIDDLE_OF_SCREEN(char string[]);
void SHORT_STR_IN_MIDDLE_OF_SCREEN(char string[]);
void LONG_STR_IN_MIDDLE_OF_SCREEN(char string[]);
void STARTING_SCREEN();


//LM35 and DC motor
void LM35_AND_DC_MOTOR_INIT(void);
void TEMP_MOTOR_RUN(void);


//ULTRASONIC 
uint8 ULTRASONIC1_COUNT(void);
uint8 ULTRASONIC2_COUNT(void);
void ULTRASONIC_TURN_LEDS_ON(void);


//app init 
void APP_INIT(void);

//external interrupt to reset 
void BUTTON_1_INT();
#endif /* APP_H_ */