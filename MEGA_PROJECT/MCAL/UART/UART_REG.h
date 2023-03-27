/*
 * UART_REG.h
 *
 * Created: 3/3/2023 12:05:15 PM
 *  Author: youssef's
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_
#include "../../LIB_FOLDER/common_macros.h"
#include "../../LIB_FOLDER/std_types.h"

#define UDR_REG                    *((volatile uint8 *)(0x2C))
#define UCSRA_REG                  *((volatile uint8 *)(0x2B))
#define UCSRB_REG                  *((volatile uint8 *)(0x2A))
#define UCSRC_REG                  *((volatile uint8 *)(0x40))
#define UBRRH_REG                  *((volatile uint8 *)(0x40))
#define UBRRL_REG                  *((volatile uint8 *)(0x29))






#endif /* UART_REG_H_ */