/*****************************************************************
 * Module Name: app_Token_Ring_SWC.c
 * Author: Mustafa Ismail
 * Purpose: contains application layer component for the token
 *          ring handling.
 *****************************************************************/

#include "app_Token_Ring_SWC.h"
#include "mcal_can.h"

/* constant bool defined as 0 */
const bool FALSE = 0;

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

        /*Wait A Second*/
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
