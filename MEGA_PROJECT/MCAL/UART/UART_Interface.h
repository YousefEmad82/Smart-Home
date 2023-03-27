/*
 * UART_Interface.h
 *
 * Created: 3/3/2023 12:05:35 PM
 *  Author: youssef's
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
//initiallization 
/*
set baud rate
set frame format
enable transmittter or the reciver 
before  reinitilallization of uart you need to check TXC or RXC
TXC must be cleared before every transmition (before writing UDR)

*/
#include "UART_REG.h"

//UART ASYNC modes
#define UART_NORMAL_MODE         0
#define UART_DOUBLE_SPEED_MODE   1

//UART modes
#define ASYNC 0
#define SYNC  1

//parity modes
#define PARITY_DISABLED 0
#define PARITY_ODD      1
#define PARITY_EVEN     2

//UCSRA BITS
#define MPCM         0//Bit 0 – MPCM: Multi-processor Communication Mode     
#define U2X          1//Bit 1 – U2X: Double the USART Transmission Speed   
#define PE		     2//Bit 2 – PE: Parity Error
#define DOR          3//Bit 3 – DOR: Data OverRun
#define FE           4//Bit 4 – FE: Frame Error
#define UDRE         5//Bit 5 – UDRE: USART Data Register Empty
#define TXC          6//Bit 6 – TXC: USART Transmit Complete
#define RXC          7//Bit 7 – RXC: USART Receive Complete

//UCSRB BITS
#define TXB8         0//• Bit 0 – TXB8: Transmit Data Bit 8#define RXB8         1//• Bit 1 – RXB8: Receive Data Bit 8#define UCSZ2        2//• Bit 2 – UCSZ2: Character Size#define TXEN         3//• Bit 3 – TXEN: Transmitter Enable#define RXEN         4//• Bit 4 – RXEN: Receiver Enable#define UDRIE        5//• Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable#define TXCIE        6//• Bit 6 – TXCIE: TX Complete Interrupt Enable#define RXCIE        7//• Bit 7 – RXCIE: RX Complete Interrupt Enable
//UCSRC BITS
#define UCPOL        0//• Bit 0 – UCPOL: Clock Polarity#define UCSZ0        1//bit 1,2 with bit 2 in UCSRB are used to set number of data bits #define UCSZ1        2 //#define USBS         3//• Bit 3 – USBS: Stop Bit Select#define UPM0         4//bit 4 and bit 5 are used to  set parity mode type #define UPM1         5#define UMSEL        6//• Bit 6 – UMSEL: USART Mode Select#define URSEL        7//• Bit 7 – URSEL: Register Select
//UBRRH BITS
//bit0->3 are the high 4 bits of baud rate register 

//UBRRL BITS are the lower 7 bits of the baud rate register


//configuration
#define UART_MODE ASYNC
#define UART_ASYNC_MODE UART_DOUBLE_SPEED_MODE
#define BAUD_RATE  9600
#define DATA_SIZE  8
#define PARITY     PARITY_DISABLED
#define STOP_BITS   1


//APIs
void UART_INIT(void);
void UART_TRANSMIT(uint16 data);
uint16 UART_RECIEVE(void);

#endif /* UART_INTERFACE_H_ */