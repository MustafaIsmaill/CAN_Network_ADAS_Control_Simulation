/*****************************************************************
 * Module Name: servAL_delay.c
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the delay
 *          functionalities.
 *****************************************************************/

#include "servAL_delay.h"

uint32_t ms_convert = 1000;
uint32_t us_convert = 1000000;
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
 * Function Name: delay_us
 * Inputs: uint32_t
 * Outputs: void
 * Description: Delay for microsecond second
 *****************************************************************/
void
delay_us(uint32_t us) { /* Delay for microsecond second */
    SysCtlDelay(us * (SysCtlClockGet() / (systick_factor * us_convert)));
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
