/*********************************************************************************
* @file           : hal_can.c
* @brief          : Implementation of HAL CAN
***********************************************************************************/

/**********************************************************************************/
/*                  Include common and project definition header                  */
/**********************************************************************************/

/**********************************************************************************/
/*                        Include headers of the component                        */
/**********************************************************************************/
#include "hal_can_test.h"

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

/**********************************************************************************/
/*                        Definition of exported variables                        */
/**********************************************************************************/

/**********************************************************************************/
/*                      Definition of exported constant data                      */
/**********************************************************************************/

/**********************************************************************************/
/*                    Declaration of local function prototypes                    */
/**********************************************************************************/

/**********************************************************************************/
/*                       Definition of local constant data                        */
/**********************************************************************************/

/**********************************************************************************/
/*                        Definition of exported functions    					  */
/**********************************************************************************/

HAL_CAN_result_e HAL_CanTest(void)
{
	/* Start the Transmission process */
	uint8_t data= 1, i= 1;
	uint8_t dataR[8]={0,0,0,0,0,0,0,0};
	uint32_t id, size;
	HAL_CAN_result_e res = HAL_CAN_RESULT_ERROR;
	res = HAL_CanTransmit(0x102, &data, 1);
	if (res == HAL_CAN_RESULT_SUCCESS){
		while (i<5){
			res = HAL_CanReceive(&id, &dataR, &size);
			if (res == HAL_CAN_RESULT_SUCCESS) break;
			HAL_Delay(1000);
			i++;
		}
		if (res == HAL_CAN_RESULT_SUCCESS){
			dataR[7]++;
			res = HAL_CanTransmit(0x102, &dataR, 8);
		}
	}
	return res;
}
