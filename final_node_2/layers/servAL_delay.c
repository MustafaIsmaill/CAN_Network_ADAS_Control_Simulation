/*****************************************************************
 * Module Name: servAL_delay
 * Author: Mustafa Ismail
 * Purpose: delay for milliseconds function and delay for 1 second
 *****************************************************************/

#include "servAL_delay.h"

uint32_t ms_convert = 1000;
uint8_t systick_factor = 3;

/*****************************************************************
 * Function Name: delay_msec
 * Inputs: uint32_t
 * Outputs: void
 * Description: Delay in Milliseconds
 *****************************************************************/
void
delay_msec(uint32_t ms) /*Delay in Milliseconds */
{
    SysCtlDelay(ms * (SysCtlClockGet() / systick_factor / ms_convert));
}

/*****************************************************************
 * Function Name: delay_one_sec
 * Inputs: void
 * Outputs: void
 * Description: Delay for 1 second
 *****************************************************************/
void
delay_one_sec(void) /* Delay for 1 second */
{
    SysCtlDelay(SysCtlClockGet() / systick_factor);
}
