/*
 * UART.c
 *
 * Created: 3/3/2023 12:04:54 PM
 *  Author: youssef's
 */ 
#include "UART_Interface.h"
//set mode 
//set data size
//set baud rate 
//set parity 
//set stop bits
//enable rec,trans

void UART_INIT(void){
	//setting baud rate
	#if (UART_ASYNC_MODE == UART_NORMAL_MODE)
	uint16 UBRR_VALUE ;
	UBRR_VALUE = (uint16)((((float32)F_CPU / (BAUD_RATE * 16UL))) - 1);
	UBRRH_REG = (UBRR_VALUE>>8);
	UBRRL_REG = UBRR_VALUE;
	#elif (UART_ASYNC_MODE == UART_DOUBLE_SPEED_MODE)
	uint16 UBRR_VALUE;
	UBRR_VALUE = (uint16)((((float32)F_CPU / (BAUD_RATE * 8UL))) - 1);
	UBRRH_REG = (UBRR_VALUE>>8);
	UBRRL_REG = UBRR_VALUE;
	#endif
	uint8 ucsrc_data = 0;
	SET_BIT(ucsrc_data,URSEL); //select register 
	//configuring modes
	#if (UART_MODE == ASYNC)
		CLEAR_BIT(ucsrc_data,UMSEL);
		#if (UART_ASYNC_MODE == UART_NORMAL_MODE)
			CLEAR_BIT(UCSRA_REG,U2X);
		#elif (UART_ASYNC_MODE == UART_DOUBLE_SPEED_MODE)
			SET_BIT(UCSRA_REG,U2X);
		#endif	
	#elif (UART_MODE == SYNC)
		SET_BIT(ucsrc_data,UMSEL);
	#endif
	
	
	//setting data size 
	#if (DATA_SIZE == 5)
		CLEAR_BIT(ucsrc_data,UCSZ0);
		CLEAR_BIT(ucsrc_data,UCSZ1);
		CLEAR_BIT(UCSRB_REG,UCSZ2);
	#elif (DATA_SIZE == 6)
		SET_BIT(ucsrc_data,UCSZ0);
		CLEAR_BIT(ucsrc_data,UCSZ1);
		CLEAR_BIT(UCSRB_REG,UCSZ2);
	#elif (DATA_SIZE == 7)
		CLEAR_BIT(ucsrc_data,UCSZ0);
		SET_BIT(ucsrc_data,UCSZ1);
		CLEAR_BIT(UCSRB_REG,UCSZ2);
	#elif (DATA_SIZE == 8)
		SET_BIT(ucsrc_data,UCSZ0);
		SET_BIT(ucsrc_data,UCSZ1);
		CLEAR_BIT(UCSRB_REG,UCSZ2);
	#elif (DATA_SIZE == 9)
		SET_BIT(ucsrc_data,UCSZ0);
		SET_BIT(ucsrc_data,UCSZ1);
		SET_BIT(UCSRB_REG,UCSZ2);
	#endif
	
	//configure parity 
	#if (PARITY == PARITY_DISABLED)
		CLEAR_BIT(ucsrc_data,UPM0);
		CLEAR_BIT(ucsrc_data,UPM1);
	#elif (PARITY == PARITY_EVEN)
		CLEAR_BIT(ucsrc_data,UPM0);
		SET_BIT(ucsrc_data,UPM1);
	#elif (PARITY_ODD)
		SET_BIT(ucsrc_data,UPM0);
		SET_BIT(ucsrc_data,UPM1);
	#endif

	
	//configure stop bits
	#if (STOP_BITS == 1)
	CLEAR_BIT(ucsrc_data,USBS);
	#elif (STOP_BITS ==2)
	SET_BIT(ucsrc_data,USBS);
	#endif
	//transmitter and receiver enable
	SET_BIT(UCSRB_REG,RXEN);
	SET_BIT(UCSRB_REG,TXEN);
	UCSRC_REG = ucsrc_data;

	
}

void UART_TRANSMIT(uint16 data){
	
	while(((UCSRA_REG)&(1<<UDRE))==0);
	if(DATA_SIZE == 9){
		if(READ_BIT(data,8)==1){ //loading the ninth bit to the TXB8 in case of data size 9
			SET_BIT(UCSRB_REG,TXB8);
		}else{
			CLEAR_BIT(UCSRB_REG,TXB8);
		}
	}
	UDR_REG = data; //load data to the register 
	
}
uint16 UART_RECIEVE(void){
	while(((UCSRA_REG)&(1<<RXC))==0);
	uint16 data = 0;
	if(DATA_SIZE == 9){
		if(READ_BIT(UCSRB_REG,RXB8)){
			SET_BIT(data,8);
		}else{
			CLEAR_BIT(data,8);
		}
	}
	//data = UDR_REG;
	//return data;
	return UDR_REG;
}