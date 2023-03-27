/*
 * RFID.h
 *
 *  Created on: Mar 12, 2023
 *      Author: dell
 */

#ifndef HAL_RFID_RFID_H_
#define HAL_RFID_RFID_H_

#include "../../MCAL/SPI/SPI.h"
#include "RFID_REG.h"
#include "../OLED/OLED_SSD1306_Interface.h"


#define CARD_FOUND		1
#define CARD_NOT_FOUND	2
#define ERROR			3

#define MAX_LEN			16

//Card types
#define Mifare_UltraLight 	0x4400
#define Mifare_One_S50		0x0400
#define Mifare_One_S70		0x0200
#define Mifare_Pro_X		0x0800
#define Mifare_DESFire		0x4403

// Mifare_One card command word
# define PICC_REQIDL          0x26               // find the antenna area does not enter hibernation
# define PICC_REQALL          0x52               // find all the cards antenna area
# define PICC_ANTICOLL        0x93               // anti-collision
# define PICC_SElECTTAG       0x93               // election card
# define PICC_AUTHENT1A       0x60               // authentication key A
# define PICC_AUTHENT1B       0x61               // authentication key B
# define PICC_READ            0x30               // Read Block
# define PICC_WRITE           0xA0               // write block
# define PICC_DECREMENT       0xC0               // debit
# define PICC_INCREMENT       0xC1               // recharge
# define PICC_RESTORE         0xC2               // transfer block data to the buffer
# define PICC_TRANSFER        0xB0               // save the data in the buffer
# define PICC_HALT            0x50               // Sleep

//command set
#define Idle_CMD 				0x00
#define Mem_CMD					0x01
#define GenerateRandomId_CMD	0x02
#define CalcCRC_CMD				0x03
#define Transmit_CMD			0x04
#define NoCmdChange_CMD			0x07
#define Receive_CMD				0x08
#define Transceive_CMD			0x0C
#define Reserved_CMD			0x0D
#define MFAuthent_CMD			0x0E
#define SoftReset_CMD			0x0F



void begin ();
uint8 DetectCard ();
uint8 GetCardId (uint8 *uid);
uint8 SelectCard (uint8 *uid);
uint8 Authenticate (uint8 authType, uint8 blockAddr, uint8 *key, uint8 *uid);
uint8 Deauthenticate ();
uint8 ReadBlock (uint8 block_address, uint8 *data, uint8 *dataLen);
uint8 WriteBlock (uint8 blockAddr, uint8 *dataToWrite, uint8 dataLen);
uint8 getFirmwareVersion ();

uint8 ReadReg(uint8 reg);
void WriteReg(uint8 reg, uint8 value);



#endif /* HAL_RFID_RFID_H_ */
