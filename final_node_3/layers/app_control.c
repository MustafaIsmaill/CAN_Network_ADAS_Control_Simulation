#include "app_control.h"

int8_t distance = 0;
uint8_t command = 0;

const bool reset = 0;

void
print_cmd(uint8_t cmd)
{
    switch(cmd) {
       case 69:
           UARTprintf("Command: Error\n ");;
           break;
       case 70:
            UARTprintf("Command: Fire Airbag\n ");;
            break;
       case 66:
            UARTprintf("Command: Brake\n ");;
            break;
       case 68:
            UARTprintf("Command: Decrease speed\n ");;
            break;
       case 77:
            UARTprintf("Command: Maintain speed\n ");;
            break;
    }
}

void
control_runnable(void)
{
    if(g_bRX_Distance_Flag)
    {
        distance = distance_can_receive();
        UARTprintf("Distance: %i\n", distance);
        g_bRX_Distance_Flag = reset;
    }
    if(g_bRX_Command_Flag)
    {
        command = command_can_receive();
        print_cmd(command);
        g_bRX_Command_Flag = reset;
    }
}
