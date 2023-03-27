///*
 //* FINGERPRINT.h
 //*
 //* Created: 3/14/2023 2:38:31 PM
 //*  Author: youssef's
 //*/ 
//
//
//#ifndef FINGERPRINT_H_
//#define FINGERPRINT_H_
//#include "../../MCAL/UART/UART_Interface.h"
//#include "../../LIB_FOLDER/std_types.h"
//#include <stdio.h>
//// R305 command codes
//#define CMD_GET_IMAGE              0x01
//#define CMD_IMAGE_TO_CHAR          0x02
//#define CMD_REG_MODEL              0x05
//#define CMD_STORE_CHAR             0x06
//#define CMD_SEARCH                 0x04
//#define CMD_DELETE_CHAR            0x0c
//#define CMD_VERIFY_PWD             0x13
////APIs
//
////R503 init function 
//FINGERPRINT_INIT();
//// Function to send a command to the R305 module and receive the response
//void r305_send_cmd(uint8 cmd, uint8 *params, uint8 param_len, uint8 *resp, uint8 resp_len);
//
//// Function to enroll a new fingerprint and store it in the R305 module's database
//uint8 r305_enroll_fingerprint(uint8 user_id);
//
//// Function to search for a fingerprint in the R305 module's database and return the corresponding user ID
//uint8 r305_search_fingerprint(uint8 *user_id);
//
//// Function to delete a fingerprint from the R305 module's database
//uint8 r305_delete_fingerprint(uint8 user_id);
//
//
//
//
//#endif /* INCFILE1_H_ */