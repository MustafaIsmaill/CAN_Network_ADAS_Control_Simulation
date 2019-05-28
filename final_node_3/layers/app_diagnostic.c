/*****************************************************************
 * Module Name: app_diagnostic.c
 * Author: Mustafa Ismail
 * Purpose: contains application layer components for the
 *          diagnostic part.
 *****************************************************************/

#include "app_diagnostic.h"

/*****************************************************************
 * Function Name: diagnostic_runnable
 * Inputs: void
 * Outputs: void
 * Description: waits for UART buffer to have new msgs from the
 *              diagnostics and then sends the request over
 *              CAN BUS
 *****************************************************************/
void
diagnostic_runnable(void) /*waits for UART service and according to the service it replys to the CAN Bus */
{
    int8_t reply;
    if(g_diagnostic_Flag) /* Check diagonistic flag if diagnostic message is sent or not */
    {
        diagnostic_can_receive();
        if(isMine(pui8MsgDiagnostic_received[0]))
        {
            reply = get_reply_data(pui8MsgDiagnostic_received[1], pui8MsgDiagnostic_received[2]);
            send_reply(pui8MsgDiagnostic_received[0], pui8MsgDiagnostic_received[1], reply);
        }
        g_diagnostic_Flag = 0;
    }
    delay_msec(10);
}
