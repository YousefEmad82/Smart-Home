/*
 * ULTRASONIC2.c
 *
 * Created: 3/17/2023 9:42:33 PM
 *  Author: youssef's
 */ 

#include  "../../LIB_FOLDER/common_macros.h"
#include  "../../LIB_FOLDER/std_types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER_0/Timer0_Interface.h"
#include "../OLED/OLED_SSD1306_Interface.h"

#include "ULTRASONIC2.h"
#include "util/delay.h"
static	Timer0Config config={T0_CTC,T0_FCPU_8,T0_NO_INTERRUPT,0,0};
static float ultrasonic_distance=0;
static const float speedOfSound = 0.0343/2;
static int numTicks=0;

void ULTRASONIC2_INIT(void)

{

	DIO_vSetPinDirection(TRIG2_PORT, TRIG2_Pin, OUTPUT);
	DIO_vSetPinDirection(ECHO2_PORT, ECHO2_Pin, INPUT_WITHOUT_PULLUP);
	TIMER0_init(&config);
	//OLED_Clear();
	//OLED_Printf("ultra init");

}


float ULTRASONIC2_GET_DISTANCE(void )
{	

	///starting trigger Pulse
	DIO_vWritePin(TRIG2_PORT, TRIG2_Pin, HIGH);
	_delay_us(10);
	DIO_vWritePin(TRIG2_PORT, TRIG2_Pin, LOW);
	
	//Wait for ECHO pin to become high 
	while( !  DIO_u8GetPinValue(ECHO2_PORT, ECHO2_Pin) );
	
	//Start measuring ECHO time in usec
	while(DIO_u8GetPinValue(ECHO2_PORT, ECHO2_Pin) == 1)
	{
		numTicks++;
		_ultrasonic2__Tim_delay_us(2);
		
	}
	
	//calculate distance in cm
	ultrasonic_distance =(float)(numTicks*2.8*speedOfSound*2);
	numTicks=0;
	_delay_ms(10);
	return ultrasonic_distance;

}

void _ultrasonic2__Tim_delay_us(uint8 uSec)
{
	if(uSec < 2) uSec = 2;

	OCR0=uSec-1;

	while(READ_BIT(TIFR,7)==1);
	SET_BIT(TIFR,7);


}

void ULTRASONIC2_DISTANCE_DISPLAY_OLED(){
	float  ultrasonic_distance = ULTRASONIC2_GET_DISTANCE();
	if(ultrasonic_distance <20){
		DIO_vWritePin(PORT_C,PIN6,HIGH);
		_delay_ms(1000);
		DIO_vWritePin(PORT_C,PIN6,LOW);
	}
	OLED_Init();
	OLED_Printf("dist = %f",ultrasonic_distance);
	_delay_ms(2000);
} 
