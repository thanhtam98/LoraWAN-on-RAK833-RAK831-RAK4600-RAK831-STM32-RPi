#ifndef __EPPROM_H__
#define __EPPROM_H__

#include "i2c.h"
/*Porting I2C*/
extern I2C_HandleTypeDef hi2c1;

#define at24_i2c 	hi2c1
#define AT24_ADR		0xA0
//#define
enum
{
	OK = 0,
	ERR_TIMEOUT,
	ERR_MAX_SIZE
};


#define EEP_MAX_SIZE    192 //
//#define PARAM_MAX_SIZE 10
uint8_t at24_write_bytes(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData,
		uint16_t TxBufferSize);
uint8_t at24_read_bytes(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData,
		uint16_t RxBufferSize);
#endif
