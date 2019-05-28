/*****************************************************************
 * Module Name: app_FSM.c
 * Author: Mustafa Ismail
 * Purpose: contains application layer component for the startup
 *          state.
 *****************************************************************/

#include "app_FSM.h"
#include "servAL_delay.h"
#include "servAL_led.h"

/*****************************************************************
 * Function Name: StartUpState
 * Inputs: void
 * Outputs: void
 * Description: turns on the green led for one sec and then turns
 *              off the green led
 *****************************************************************/
void
StartUpState(void) /*Initalize the startup state */
{
    Set_Led_Status(GREEN_LED, HIGH);
    delay_one_sec();
    Set_Led_Status(GREEN_LED, LOW);
}
