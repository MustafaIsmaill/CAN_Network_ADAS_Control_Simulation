/*****************************************************************
 * Module Name: app_FSM.c
 * Authors: Mustafa Ismail
 * Purpose: contains application layer component for the startup
 *          state.
 *****************************************************************/

#include "app_FSM.h"

/*****************************************************************
 * Function Name: StartUpState
 * Inputs: void
 * Outputs: void
 * Description: turns on the green led for one sec and then turns
 *              off the green led
 *****************************************************************/
void
StartUpState(void)
{
    while(!g_bRXFlag)
    {
        Set_Led_Status(GREEN_LED, HIGH);
    }
    Set_Led_Status(GREEN_LED, LOW);
}
