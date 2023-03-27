///*
 //* FINGERPRINT.c
 //*
 //* Created: 3/13/2023 9:41:34 PM
 //*  Author: youssef's
 //*/ 
//
//#include "FINGERPRINT.h"
//
////R503 init function
//FINGERPRINT_INIT(){
	//UART_INIT();
	//r305_send_cmd(CMD_VERIFY_PWD,params,1,res)
	//
//}
//
//// Function to send a command to the R305 module and receive the response
//void r305_send_cmd(uint8 cmd, uint8 *params, uint8 param_len, uint8 *resp, uint8 resp_len) {
	//// Construct the command packet
	//uint8 packet[13] = {0xEF, 0x01, param_len+3, 0x00, cmd};
	//memcpy(packet+5, params, param_len);
	//uint16 sum = 0;
	//for (int i=0; i<param_len+5; i++) {
		//sum += packet[i];
	//}
	//packet[param_len+5] = sum & 0xFF;
	//packet[param_len+6] = sum >> 8;
	//packet[param_len+7] = 0x0D;
	//packet[param_len+8] = 0x0A;
	//
	//// Send the command packet to the R305 module
	//for (int i=0; i<param_len+9; i++) {
		//UART_TRANSMIT(packet[i]);
	//}
	//
	//// Receive the response from the R305 module
	//for (int i=0; i<resp_len; i++) {
		//resp[i] = UART_RECIEVE();
	//}
//}
//
//// Function to enroll a new fingerprint and store it in the R305 module's database
//uint8 r305_enroll_fingerprint(uint8 user_id) {
	//uint8 params[] = {0x01};
	//uint8 resp[12];
	//r305_send_cmd(CMD_GET_IMAGE, params, 1, resp, 12);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//r305_send_cmd(CMD_IMAGE_TO_CHAR, params, 1, resp, 12);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//params[0] = 0x02;
	//r305_send_cmd(CMD_GET_IMAGE, params, 1, resp, 12);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//r305_send_cmd(CMD_IMAGE_TO_CHAR, params, 1, resp, 12);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//params[0] = 0x03;
	//r305_send_cmd(CMD_GET_IMAGE, params, 1, resp, 12);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//r305_send_cmd(CMD_IMAGE_TO_CHAR, params, 1, resp, 12);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//params[0] = user_id;
	//r305_send_cmd(CMD_REG_MODEL, params, 1, resp, 12);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//r305_send_cmd(CMD_STORE_CHAR, params, 1, resp, 12);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//return 0;
//}
//
//// Function to search for a fingerprint in the R305 module's database and return the corresponding user ID
//uint8 r305_search_fingerprint(uint8 *user_id) {
	//uint8 params[] = {0x01, 0x00, 0x00, 0x00, 0x64};
	//uint8 resp[16];
	//r305_send_cmd(CMD_SEARCH, params, 5, resp, 16);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//// Check if a match was found
	//if (resp[10] == 0x00) {
		//*user_id = resp[11];
		//return 0;
		//} else {
		//return resp[10];
	//}
//}
//
//// Function to delete a fingerprint from the R305 module's database
//uint8 r305_delete_fingerprint(uint8 user_id) {
	//uint8 params[] = {user_id};
	//uint8 resp[12];
	//r305_send_cmd(CMD_DELETE_CHAR, params, 1, resp, 12);
	//// Check for error response
	//if (resp[9] != 0x00) {
		//return resp[9];
	//}
	//return 0;
//}
