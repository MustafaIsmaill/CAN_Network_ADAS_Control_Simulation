/*****************************************************************
 * Module Name: app_control
 * Author: Mustafa Ismail
 * Purpose: Prints commands and waits for the duty cycle 
 *****************************************************************/

#include "app_control.h"

int8_t distance = 0;
uint8_t command = 0;
uint8_t first_time_flag = 1;

uint8_t err_flag = 0;

const bool reset = 0;

/*****************************************************************
 * Function Name: print_cmd
 * Inputs: uint8_t
 * Outputs: void
 * Description: Prints the commands to the LCD
 *****************************************************************/
void
print_cmd(uint8_t cmd) /*Prints the commands to the LCD */
{
    switch(cmd) {
       case error:
           err_flag = (uint8_t)1;
           lcdWriteCmd("Error ");
           break;
       case fire:
           err_flag = (uint8_t)0;
           lcdWriteCmd("Fire Airbag ");
           break;
       case brake:
           err_flag = (uint8_t)0;
           lcdWriteCmd("Brake ");
           break;
       case decrease:
           err_flag = (uint8_t)0;
           lcdWriteCmd("Decrease speed ");
           break;
       case maintain:
           err_flag = (uint8_t)0;
           lcdWriteCmd("Maintain speed ");
           break;
       case nerror:
            err_flag = (uint8_t)0;
            lcdWriteCmd("No Error ");
            break;
    }
}

/*****************************************************************
 * Function Name: control_runnable
 * Inputs: void
 * Outputs: void
 * Description: Waits for the distance to be sent and then decide
 *			    accordingly
 *****************************************************************/
void
control_runnable(void) /*Waits for the distance to be sent and then decide accordingly */
{
    if(g_bRX_Distance_Flag)
    {
        lcdClear();
        distance = distance_can_receive();
        lcdWriteDistance((uint8_t)distance);
        g_bRX_Distance_Flag = reset;
    }
    if(g_bRX_Command_Flag)
    {
        command = command_can_receive();
        print_cmd(command);
        g_bRX_Command_Flag = reset;
    }
    if(first_time_flag)
    {
        lcdClear();
        first_time_flag = (uint8_t)0;
    }
}
