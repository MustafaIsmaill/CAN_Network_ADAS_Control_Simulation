/*****************************************************************
 * Module Name: servAL_diagnostic.c
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the diagnostic
 *          functionalities.
 *****************************************************************/

#include "servAL_diagnostic.h"

/*****************************************************************
 * Function Name: send_request
 * Inputs: int8_t first byte, int8_t second byte, int8_t third byte
 * Outputs: void
 * Description: Sends the data to the CAN
 *****************************************************************/
void
send_request(int8_t b1, int8_t b2, int8_t b3) /*Sends the data to the CAN */
{
    if(!g_bTXFlag)
    {
        diagnostic_can_send(b1, b2, b3);
    }
}
