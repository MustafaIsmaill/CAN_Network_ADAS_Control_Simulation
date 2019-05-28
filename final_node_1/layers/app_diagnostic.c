/*****************************************************************
 * Module Name: app_diagnostic.c
 * Author: Mustafa Ismail
 * Purpose: contains application layer components for the
 *          diagnostic part.
 *****************************************************************/

#include "app_diagnostic.h"

/* initialize variable to hold service id */
int8_t ui8_service = 0;

/* initialize variable to hold previous service id */
int8_t ui8_prev_service = 0;

/* initialize constant to hold runnable delay value */
const uint32_t ui32_delay_ms = 10;

/*****************************************************************
 * Function Name: isChanged
 * Inputs: void
 * Outputs: boolean
 * Description: checks if newly received diagnostic is the same
 *              as the previously received diagnostic or not and
 *              returns a boolean flag.
 *****************************************************************/
bool isChanged(void)
{
    uint8_t flag;
    if(ui8_service != ui8_prev_service)
    {
        flag = (uint8_t)1;
    }
    else
    {
        flag = (uint8_t)0;
    }
    return flag;
}

/*****************************************************************
 * Function Name: print_reply
 * Inputs: void
 * Outputs: void
 * Description: prints received diagnostic msg from node 1 or 2
 *              to the UART
 *****************************************************************/
void
print_reply(void) /*Prints the reply to the LCD */
{
    if(pui8MsgDiagnostic_received[2] == error){ UARTprintf("Error\n"); }
    else if(pui8MsgDiagnostic_received[2] == fire) { UARTprintf("Fire Airbag\n"); }
    else if(pui8MsgDiagnostic_received[2] == brake) { UARTprintf("Brake\n"); }
    else if(pui8MsgDiagnostic_received[2] == decrease) { UARTprintf("Decrease speed\n"); }
    else if(pui8MsgDiagnostic_received[2] == maintain) { UARTprintf("Maintain speed\n"); }
    else if(pui8MsgDiagnostic_received[2] == nerror) { UARTprintf("No Error\n"); }
    else { UARTprintf("%i\n", pui8MsgDiagnostic_received[2]); }
}

/* initialize variable to hold received bytes counter */
uint8_t msg_counter = 0;

/* initialize variable to hold the three received bytes */
int8_t bb1, bb2, bb3;

/*****************************************************************
 * Function Name: diagnostic_runnable
 * Inputs: void
 * Outputs: void
 * Description: waits for UART buffer to have new msgs from the
 *              diagnostics and then sends the request over
 *              CAN BUS
 *****************************************************************/
void
diagnostic_runnable(void)
{
    if(UARTCharsAvail((uint32_t)UART0_BASE))
    {
        msg_counter++;
        ui8_service = UARTCharGetNonBlocking((uint32_t)UART0_BASE);
        if(msg_counter == (int8_t)1) { bb1 = (int8_t)ui8_service; }
        else if(msg_counter == (int8_t)2) { bb2 = (int8_t)ui8_service; }
        else
        {
            bb3 = ui8_service;
            send_request(bb1, bb2, bb3);
            msg_counter = (uint8_t)0;
        }
        ui8_prev_service = ui8_service;
    }

    if(g_Diagnostic_Flag) /* Check diagonistic flag if diagnostic message is sent or not */
    {
        diagnostic_can_receive();
        print_reply();
        g_Diagnostic_Flag = (uint8_t)0;
    }

    delay_msec(ui32_delay_ms);
}
