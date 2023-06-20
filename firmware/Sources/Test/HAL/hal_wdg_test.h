/*********************************************************************************
* @file           : hal_wdg_test.h
* @brief          : HAL header file for watchdog test
***********************************************************************************/
#ifndef HAL_WDG_TEST_H_
#define HAL_WDG_TEST_H_

/**********************************************************************************/
/*                               Project Includes                                 */
/**********************************************************************************/
#include "hal_wdg.h"

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

/**
 * @fn HAL_WDG_result_e TestWdg(void)
 * @brief Start the watchdog and send 5 refresh on each stage:
 * - Stage 1: refresh every 300 us
 * - Stage 2: refresh every 500 us
 * - Stage 3: refresh every 900 us
 * - Stage 4: refresh every 1100 us
 * The test finishes with a reset.
 * @note: If GPIO is used, toggle pin PB0
 * @return @ref HAL_TMR_RESULT_ERROR if whatchdog not raised when time elapsed.
 */
HAL_WDG_result_e TestWdg(void);

#endif /* HAL_TMR_TEST_H_ */