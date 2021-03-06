/*****************************************************************
 * Module Name: app_Token_Ring_SWC
 * Author: Mustafa Ismail
 * Purpose: Application layer component for token ring handling
 *****************************************************************/

#include "app_Token_Ring_SWC.h"
#include "mcal_can.h"

const bool FALSE = 0;

/*****************************************************************
 * Function Name: token_ring_runnable
 * Inputs: void
 * Outputs: void
 * Description: Checks if the message is recieved to turn on led 
 *				sends token to the next node
 *****************************************************************/
void
token_ring_runnable(void)
{
    /* Check if a message is received*/
    if(g_bRXFlag)
    {
        /*clear receive flag*/
        g_bRXFlag = FALSE;

        /*Read Message*/
        token_can_receive();

        /*Turn on Red LED*/
        Set_Led_Status(RED_LED, HIGH);

        /*Wait Half A Second*/
        delay_msec(500);

        /* Send token to next node*/
        token_can_send();

        /* Turn off red LED, indicating the token is no longer at this node*/
        Set_Led_Status(RED_LED, LOW);
    }

    /*Clear the send flag if it is still set to high*/
    if(g_bTXFlag)
    {
        g_bTXFlag = FALSE;
    }
}
