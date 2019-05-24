#include "app_control.h"

int8_t distance = 0;
uint8_t command = 0;
uint8_t first_time_flag = 1;

uint8_t err_flag = 0;

const bool reset = 0;

void
print_cmd(uint8_t cmd)
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

void
control_runnable(void)
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
