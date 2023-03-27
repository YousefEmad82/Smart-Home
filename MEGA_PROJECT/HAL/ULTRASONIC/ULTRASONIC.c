/*
 * ULTRASONIC.c
 *
 * Created: 3/16/2023 10:41:08 AM
 *  Author: youssef's
 */ 
#include  "../../LIB_FOLDER/common_macros.h"
#include  "../../LIB_FOLDER/std_types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER_0/Timer0_Interface.h"
#include "../OLED/OLED_SSD1306_Interface.h"

#include "ULTRASONIC.h"
#include "util/delay.h"
static	Timer0Config config={T0_CTC,T0_FCPU_8,T0_NO_INTERRUPT,0,0};
static float ultrasonic_distance=0;
static const float speedOfSound = 0.0343/2;
static int numTicks=0;

void ULTRASONIC_INIT(void)

{

	DIO_vSetPinDirection(TRIG_PORT, TRIG_Pin, OUTPUT);
	DIO_vSetPinDirection(ECHO_PORT, ECHO_Pin, INPUT_WITHOUT_PULLUP);
	TIMER0_init(&config);
	//OLED_Clear();
	//OLED_Printf("ultra init");

}


float ULTRASONIC_GET_DISTANCE(void )
{	

	///starting trigger Pulse
	DIO_vWritePin(TRIG_PORT, PIN0, HIGH);
	_delay_us(10);
	DIO_vWritePin(TRIG_PORT, PIN0, LOW);
	
	//Wait for ECHO pin to become high 
	while( !  DIO_u8GetPinValue(ECHO_PORT, ECHO_Pin) );
	
	//Start measuring ECHO time in usec
	while(DIO_u8GetPinValue(ECHO_PORT, ECHO_Pin) == 1)
	{
		numTicks++;
		_ultrasonic__Tim_delay_us(1);
		
	}
	
	//calculate distance in cm
	ultrasonic_distance =(float)(numTicks*2.8*speedOfSound*2);
	numTicks=0;
	_delay_ms(10);
	return ultrasonic_distance;

}

void _ultrasonic__Tim_delay_us(uint8 uSec)
{
	
	OCR0=uSec;
	while(READ_BIT(TIFR,7)==1);
	SET_BIT(TIFR,7);


}

void ULTRASONIC_DISTANCE_DISPLAY_OLED(){
	float  ultrasonic_distance = ULTRASONIC_GET_DISTANCE();
	if(ultrasonic_distance <20){
		DIO_vWritePin(PORT_C,PIN6,HIGH);
		_delay_ms(1000);
		DIO_vWritePin(PORT_C,PIN6,LOW);
	}
	OLED_Init();
	OLED_Printf("dist = %f",ultrasonic_distance);
	_delay_ms(2000);
} 
