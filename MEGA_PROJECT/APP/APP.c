/*
 * APP.c
 *
 * Created: 3/14/2023 2:09:32 PM
 *  Author: youssef's
 */ 
#include "APP.h"

//variables used by RFID
uint8 CardId[4] = {0,0,0,0};//the card id
uint8 Status_ID = 0;
uint8 ID[4] ;//ID of the  currently used card
uint8 id_count = 0;//count to the compared bytes  between the enrolled cardId and the currently used card
uint8 card__enroll_flag = 0; //flag to determine if a card is enrolled in the EEPROM or not
uint8 person_count = 0;



//RFID init function 
void RFID_INIT(void){
	ULTRASONIC_INIT();
	LM35_AND_DC_MOTOR_INIT();
	SPI_Init();
	PWM_Init();
	begin();
	DIO_vSetPinDirection(PORT_A,PIN4,OUTPUT);
	DIO_vSetPinDirection(PORT_A,PIN5,OUTPUT);
	DIO_vSetPinDirection(PORT_A,PIN6,OUTPUT);
	DIO_vSetPinDirection(PORT_C,PIN6,OUTPUT);
	DIO_vSetPinDirection(PORT_D,PIN5,OUTPUT);//setting PWM channelA pin  as output 
	OLED_Init();
}

//enroll function 
void RFID_ENROLL(void){
	STARTING_SCREEN();
	while(card__enroll_flag == 0){
		if(DetectCard())
		{	
			//OLED_Init();  //initialize the OLED
			card__enroll_flag = 1;
			OLED_SetCursor(0, 0);        //set the cursor position to (0, 0)
			OLED_Clear();
			OLED_Printf("the card is detected successfully !");
			Status_ID = GetCardId(CardId);
			EEPROM_WRITE(1000,CardId[0]);
			EEPROM_WRITE(1001,CardId[1]);
			EEPROM_WRITE(1002,CardId[2]);
			EEPROM_WRITE(1003,CardId[3]);
		}
	}
}


//read a card 
void RFID_READ_CARD(void){
	
	TEMP_MOTOR_RUN();
	if(DetectCard())
	{
		Status_ID = GetCardId(CardId);
		ID[0] = EEPROM_READ(1000);
		ID[1] = EEPROM_READ(1001);
		ID[2] = EEPROM_READ(1002);
		ID[3] = EEPROM_READ(1003);
		for(uint8 i = 0;i<4;i++){ //comparing the current card id  by the enrolled card id 
			if(CardId[i] == ID[i]){
				id_count++;
			}
		}
		if(id_count == 4){ 
			DIO_vWritePin(PORT_C,PIN6,HIGH); //buzzer is on when a match occures 
			_delay_ms(1000);
			DIO_vWritePin(PORT_C,PIN6,LOW);
			PWM_Generate_CHANNELA(3,50);
			_delay_ms(2000);
			PWM_Generate_CHANNELA(12,50);
			OLED_SetCursor(0, 0);        //set the cursor position to (0, 0)
			OLED_Clear();
			OLED_Printf("you are authorized to enter !    ");
			id_count = 0;
			_delay_ms(3000);
		}
		else{
			OLED_SetCursor(0, 0);        //set the cursor position to (0, 0)
			OLED_Clear();
			OLED_Printf("you are not allowed  to enter !");
			_delay_ms(1000);
			id_count = 0;
		}
	}
	else if (!DetectCard())
	{
		OLED_SetCursor(0, 0);        //set the cursor position to (0, 0)
		//OLED_Clear();
		//OLED_Printf("no card is readed  ! ");
		_delay_ms(1000);
	}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/
//OLED FUNCTIONS


//function to draw a frame
void DRAW_FRAME(){
	OLED_Init();  //initialize the OLED
	
	for(uint8 i = 8;i<120;i++){
		OLED_SetCursor(0,i);
		OLED_Printf("-");
	}
	for(uint8 i = 8;i<120;i++){
		OLED_SetCursor(7,i);
		OLED_Printf("-");
	}
	for(uint8 i = 1;i<7;i++){
		OLED_SetCursor(i,5);
		OLED_Printf("|");
	}
	for(uint8 i = 1;i<7;i++){
		OLED_SetCursor(i,121);
		OLED_Printf("|");
	}
}

//function to put a long string at the middle of the screen 
void LONG_STR_IN_MIDDLE_OF_SCREEN(char string[]){
	OLED_SetCursor(3,25);        //set the cursor position to (0, 0)
	OLED_Printf(string); //Print out some text
	}
	
	
//function to put a SHORT string at the middle of the screen
void SHORT_STR_IN_MIDDLE_OF_SCREEN(char string[]){
	OLED_SetCursor(3,49);        //set the cursor position to (0, 0)
	OLED_Printf(string); //Print out some text
}

//send the main screen before doing any actions to the oled 
void STARTING_SCREEN(){
	char str[] = "TEAM 2 AVELABS";
	DRAW_FRAME();
	LONG_STR_IN_MIDDLE_OF_SCREEN(str);
}



/*-------------------------------------------------------------------------------------------------------------------------------------------*/
//LM35 AND DC MOTOR FUNCTIONS

//LM35 and DC motor
void LM35_AND_DC_MOTOR_INIT(void){
	LM35_init();
	DIO_vSetPinDirection(PORT_C,PIN7,OUTPUT); //setting relay pin as output 
	//MOTOR_A_INIT();
	//MOTOR_B_INIT();
	LCD_4_bit_init();
}
void TEMP_MOTOR_RUN(void){
	uint8 temperature = LM35_READ();
	uint8 string_data[16];
	if(temperature<20){
		DIO_vWritePin(PORT_C,PIN7,LOW);//setting relay off 
	//MOTOR_B_STOP();
	//MOTOR_A_STOP();
	}
	else if(temperature<25){
	//MOTOR_B_ROTATE(CLOCK_WISE);
	//MOTOR_A_ROTATE(CLOCK_WISE);
	DIO_vWritePin(PORT_C,PIN7,HIGH);//setting relay on 
	
	}
	else if(temperature>=30){
	//MOTOR_B_ROTATE(CLOCK_WISE);
	//MOTOR_A_ROTATE(CLOCK_WISE);
	DIO_vWritePin(PORT_C,PIN7,HIGH); //setting relay on 
	DIO_vWritePin(PORT_C,PIN6,HIGH); //buzzer is on
	_delay_ms(500);
	DIO_vWritePin(PORT_C,PIN6,LOW);//buzzer off 
	}
	sprintf(string_data,"Temperature=%d",temperature);
	LCD_4_bit_sendCommand(0x80); //return the cursor to the right
	LCD_4_bit_sendString(string_data);
	_delay_ms(100);
	

}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/
//ultrasonic functions 

//ultrasonic that counts  number of people that enter  the room 
uint8 ULTRASONIC1_COUNT(){
	float distance = ULTRASONIC_GET_DISTANCE();
	if(distance<20){
		if(person_count!=255)
		person_count++;
	}
}

//ultrasonic that counts  number of people that exits  the room 
uint8 ULTRASONIC2_COUNT(){
	float distance = ULTRASONIC2_GET_DISTANCE();
	if(distance<20){
		if(person_count!=0)
		person_count--;
	}
}

//function that trun lights on dependent on the number of people in the room 
void ULTRASONIC_TURN_LEDS_ON(){
	OLED_Clear();
	ULTRASONIC1_COUNT();
	ULTRASONIC2_COUNT();
	OLED_Printf("count =%d",person_count);
	_delay_ms(500);
	if(person_count == 0){
		DIO_vWritePin(PORT_A,PIN4,LOW);
		DIO_vWritePin(PORT_A,PIN5,LOW);
		DIO_vWritePin(PORT_A,PIN6,LOW);
	}
	if(person_count>0 && person_count<3){
		DIO_vWritePin(PORT_A,PIN4,HIGH);
		DIO_vWritePin(PORT_A,PIN5,LOW);
		DIO_vWritePin(PORT_A,PIN6,LOW);
		}else if(person_count>=3 && person_count<10){
		DIO_vWritePin(PORT_A,PIN5,HIGH);
		DIO_vWritePin(PORT_A,PIN6,LOW);
		}else{
		DIO_vWritePin(PORT_A,PIN6,HIGH);
	}

}


//app init 
void APP_INIT(){
	RFID_INIT();
	RFID_ENROLL();
	ULTRASONIC_INIT();
	ULTRASONIC2_INIT();
	OLED_Init();
	DIO_vSetPinDirection(PORT_A,PIN4,OUTPUT);
	DIO_vSetPinDirection(PORT_A,PIN5,OUTPUT);
	DIO_vSetPinDirection(PORT_A,PIN6,OUTPUT);
}


/*-------------------------------------------------------------------------------------------------------------------------------------------*/
//external interrupt fuctions to reset the MCU
void BUTTON_1_INT(){
	WATCHDOG_ON();
	
}
