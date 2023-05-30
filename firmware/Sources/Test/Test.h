/*********************************************************************************
* @file           : hal_gpio.h
* @brief          : HAL header file for testing
**********************************************************************************
* @attention
* Research Laboratory in Fluid Dynamics and Combustion Technologies (LIFTEC)
*   Spanish National Research Council (CSIC)
*   c/ María de Luna 10, 50018 Zaragoza, Spain
*
*   All rights reserved. Distribution or duplication without previous
*   written agreement of the owner prohibited.
***********************************************************************************/

#ifndef TEST_H_
#define TEST_H_
/**********************************************************************************/
/*                               Project Includes                                 */
/**********************************************************************************/
#include "epc_conf.h"

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
/*            Definition of exported types (typedef, enum, struct, union)         */
/**********************************************************************************/

/**********************************************************************************/
/*                        Definition of exported variables                        */
/**********************************************************************************/
/**
 * @enum TEST_result_e
 * @brief Structure for the result of the test operation.
 */
typedef enum
{
	TEST_RESULT_SUCCESS = 0x0U, /**< HAL_GPIO success operation result **/
	TEST_RESULT_ERROR 			/**< HAL_GPIO error operation result **/
}TEST_result_e;

/**********************************************************************************/
/*                       Definition of local constant data                        */
/**********************************************************************************/

/**********************************************************************************/
/*                        Definition of exported variables                        */
/**********************************************************************************/

/**********************************************************************************/
/*                      Definition of exported constant data                      */
/**********************************************************************************/

/**********************************************************************************/
/*                   Declaration of exported function prototypes                  */
/**********************************************************************************/

TEST_result_e Test_PWM(void);

TEST_result_e Test_GPIO(void);

TEST_result_e Test_SlowAdc(void);

TEST_result_e Test_FastAdc(void);

TEST_result_e Test_I2C(void);

TEST_result_e Test_Timers(void);

TEST_result_e Test_WDG(void);

TEST_result_e Test_Can(void);

TEST_result_e Test_HAL(void);
#endif /* TEST_H_ */
