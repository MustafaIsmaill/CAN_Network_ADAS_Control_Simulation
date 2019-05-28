/*****************************************************************
 * Module Name: app_FSM.h
 * Author: Mustafa Ismail
 * Purpose: contains application layer component for the startup
 *          state.
 *****************************************************************/

#ifndef __APP_FSM_H__
#define __APP_FSM_H__

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

/* define HIGH as 1
 * define LOW as 0
 */
#define HIGH    1U
#define LOW     0U

/*****************************************************************
 * Function Name: StartUpState
 * Inputs: void
 * Outputs: void
 * Description: turns on the green led for one sec and then turns
 *              off the green led
 *****************************************************************/
void StartUpState(void);

#endif /* __APP_FSM_H__ */
