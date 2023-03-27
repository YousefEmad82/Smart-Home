/*
 * L298N.c
 *
 * Created: 3/2/2023 7:50:33 PM
 *  Author: youssef's
 */ 
#include "../DC_MOTOR/L298N.h"

void MOTOR_A_INIT(){
	DIO_vSetPinDirection(INPUT1,OUTPUT);
	DIO_vSetPinDirection(INPUT2,OUTPUT);
	DIO_vSetPinDirection(DC_MOTOR_A_ENABLE,OUTPUT);

}
void MOTOR_A_ROTATE(uint8 direcion){
	if(direcion == CLOCK_WISE){
		DIO_vWritePin(INPUT1,HIGH);
		DIO_vWritePin(INPUT2,LOW);
	}
	else if(direcion == ANTI_CLOCK_WISE){
		DIO_vWritePin(INPUT1,LOW);
		DIO_vWritePin(INPUT2,HIGH);
	}
	//DIO_vWritePin(DC_MOTOR_A_ENABLE,HIGH);
}
void MOTOR_A_STOP(){
	DIO_vWritePin(DC_MOTOR_A_ENABLE,LOW);
}


void MOTOR_B_INIT(){
	DIO_vSetPinDirection(INPUT3,OUTPUT);
	DIO_vSetPinDirection(INPUT4,OUTPUT);
	DIO_vSetPinDirection(DC_MOTOR_B_ENABLE,OUTPUT);
}
void MOTOR_B_ROTATE(uint8 direcion){
	if(direcion == CLOCK_WISE){
		DIO_vWritePin(INPUT3,HIGH);
		DIO_vWritePin(INPUT4,LOW);
	}
	else if(direcion == ANTI_CLOCK_WISE){
		DIO_vWritePin(INPUT3,LOW);
		DIO_vWritePin(INPUT4,HIGH);
	}
	DIO_vWritePin(DC_MOTOR_B_ENABLE,HIGH);

}

void MOTOR_B_STOP(){
	DIO_vWritePin(DC_MOTOR_B_ENABLE,LOW);
}