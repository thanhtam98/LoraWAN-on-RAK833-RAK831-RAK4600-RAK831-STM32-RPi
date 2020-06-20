/*
 * 	INFORMATION ABOUT THIS SOURCE - I COPIED AND MODIFIED  ":)
 * | -------------------------------- R2T Team Libraries -------------------------
 * | @Created On Sep,11,2015
 * | @File Name : at24_hal_i2c
 * | @Brief : STM32 HAL Driver for AT24 eeprom series
 * | @Copyright :
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * |
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * | @Author :  Sina Darvishi
 * | @Website : R2T.IR
 * |
 **/
/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include  "epprom.h"
#include  "i2c.h"
#include  "main.h"

/**
 * @brief               : This function handles Writing Array of Bytes on the specific Address .
 * 					   This program have this feature that don't force you to use absolute 16 bytes
 * 					   you can use more than 16 bytes buffer.
 * @param  hi2c         : Pointer to a I2C_HandleTypeDef structure that contains
 *                        the configuration information for the specified I2C.
 * @param	DevAddress   : specifies the slave address to be programmed(EEPROM ADDRESS).
 * @param	MemAddress   : Internal memory address (WHERE YOU WANNA WRITE TO)
 * @param	pData	     : Pointer to data buffer
 * @param  TxBufferSize : Amount of data you wanna Write
 * @retval
 */
/**
 * Note that function not work if the number of bytes > 16. Be careful!
 * */
uint8_t at24_write_bytes(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData,
		uint16_t TxBufferSize) {

	uint8_t TimeOut = 0;
	if (TxBufferSize > 16) return ERR_MAX_SIZE;
	while (HAL_I2C_Mem_Write(&at24_i2c, (uint16_t) DevAddress, (uint16_t) MemAddress,
	I2C_MEMADD_SIZE_8BIT, (uint8_t*) pData, (uint16_t) TxBufferSize, 1000)
			!= HAL_OK && TimeOut < 3) {
		DBG("Write Error \r\n");
		HAL_Delay(1000);
		TimeOut++;
	}
	if (TimeOut >2) return ERR_TIMEOUT;
	return OK;

}

/**
 * Note that function not work if the number of bytes > 16. Be careful!
 * */
uint8_t at24_read_bytes(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData,
		uint16_t RxBufferSize) {
	uint8_t TimeOut = 0;
	if (RxBufferSize > 16) return ERR_MAX_SIZE;
	while (HAL_I2C_Mem_Read(&at24_i2c, (uint16_t) DevAddress, (uint16_t) MemAddress,
	I2C_MEMADD_SIZE_8BIT, (uint8_t*) pData, (uint16_t) RxBufferSize, 1000)
			!= HAL_OK && TimeOut < 3) {
		DBG("Read Error \r\n");
		HAL_Delay(1000);
		TimeOut++;
	}
	if (TimeOut > 2) return ERR_TIMEOUT;
	return OK;
}

