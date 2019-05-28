/*****************************************************************
 * Module Name: app_FSM
 * Author: Mustafa Ismail
 * Purpose: Sets the startup state
 *****************************************************************/

#include "app_FSM.h"

/*****************************************************************
 * Function Name: StartUpState
 * Inputs: void
 * Outputs: void
 * Description: Setup of the startup state
 *****************************************************************/
void
StartUpState(void)
{
    lcdStartup();
    while(!g_bRXFlag)
    {
        Set_Led_Status(GREEN_LED, HIGH);
    }
    Set_Led_Status(GREEN_LED, LOW);

    lcdClear();
}
