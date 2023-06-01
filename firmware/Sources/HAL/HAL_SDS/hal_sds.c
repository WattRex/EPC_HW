/*********************************************************************************
* @file           : hal_i2c.c
* @brief          : Implementation of HAL_SDS
***********************************************************************************/

/**********************************************************************************/
/*                  Include common and project definition header                  */
/**********************************************************************************/
#include "hal_sds.h"

#include "stm32f3xx_hal.h"

/**********************************************************************************/
/*                        Include headers of the component                        */
/**********************************************************************************/
#include "i2c.h"

/**********************************************************************************/
/*                              Include other headers                             */
/**********************************************************************************/

/**********************************************************************************/
/*                     Definition of local symbolic constants                     */
/**********************************************************************************/

/**********************************************************************************/
/*                    Definition of local function like macros                    */
/**********************************************************************************/

/**********************************************************************************/
/*            Definition of local types (typedef, enum, struct, union)            */
/**********************************************************************************/

/**********************************************************************************/
/*                         Definition of local variables                          */
/**********************************************************************************/
uint16_t devAddres = 0x4A; // Two options: 0x4A or 0x4B
/**********************************************************************************/
/*                        Definition of exported variables                        */
/**********************************************************************************/

/**********************************************************************************/
/*                      Definition of exported constant data                      */
/**********************************************************************************/

/**********************************************************************************/
/*                    Declaration of local function prototypes                    */
/**********************************************************************************/
/**
 * @fn HAL_SDS_result_t _I2cTransfer()
 * @brief Transfer the data
 * @return
 * 		@ref HAL_SDS_RESULT_SUCCESS if initialized correctly,
 * 		@ref HAL_SDS_RESULT_ERROR otherwise
 */
static HAL_SDS_result_e _I2cTransmit(const uint16_t devAddr, const uint8_t *comand);

/**
 * @fn HAL_SDS_result_t _I2cTransfer()
 * @brief Transfer the data
 * @return
 * 		@ref HAL_SDS_RESULT_SUCCESS if initialized correctly,
 * 		@ref HAL_SDS_RESULT_ERROR otherwise
 */
static HAL_SDS_result_e _I2cReceive(const uint16_t devAddr, uint16_t *data );
/**********************************************************************************/
/*                       Definition of local constant data                        */
/**********************************************************************************/

/**********************************************************************************/
/*                         Definition of local functions                          */
/**********************************************************************************/
static HAL_SDS_result_e _I2cTransmit(const uint16_t devAddr, const uint8_t *comand){
	uint16_t header = devAddr << 1 | 1;
	uint8_t* orders= &comand;
	HAL_SDS_result_e res = HAL_I2C_Master_Transmit(&hi2c1, header, orders, 2, EPC_CONF_I2C_TIMEOUT);
	return res;
}

static HAL_SDS_result_e _I2cReceive(const uint16_t devAddr, uint16_t *dataO ){
	uint16_t header = devAddr << 1 | 1;
	uint8_t data[4];
	HAL_SDS_result_e res = HAL_I2C_Master_Receive(&hi2c1, header, data, 3, EPC_CONF_I2C_TIMEOUT);
	*dataO = data[0]<<8 | data[1];
	return res;
}
/**********************************************************************************/
/*                        Definition of exported functions                        */
/**********************************************************************************/

HAL_SDS_result_e HAL_SdsInit (void){
	HAL_SDS_result_e res = HAL_SDS_RESULT_SUCCESS;
	error_raised = 0;
	MX_I2C1_Init();
	if (error_raised){
			res = HAL_SDS_RESULT_ERROR;
	}
	else{
		// Start periodical measurement Low repeatability 10mps
		uint8_t command[]= {0x27,0x2a};
		res = _I2cTransmit(devAddres, command);
	}
	return res;
}

HAL_SDS_result_e HAL_SdsReadTemperature(uint16_t* temp){

	HAL_SDS_result_e res = HAL_SDS_RESULT_SUCCESS;
	uint8_t command[]= {0xE0,0x00};
	res = _I2cTransmit(devAddres, command);
	if (res == HAL_SDS_RESULT_SUCCESS){
		uint16_t tempRaw;
		res = _I2cReceive(devAddres, &tempRaw);
		*temp = (uint16_t) ((int16_t) ((uint16_t) (((uint32_t) (1750*tempRaw)) >> 16)+1)-450);
	}
	return res;
}
