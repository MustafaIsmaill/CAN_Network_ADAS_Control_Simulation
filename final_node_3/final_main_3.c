#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

#include "layers/servAL_led.h"
#include "layers/app_FSM.h"
#include "layers/mcal_can.h"
#include "layers/servAL_can.h"
#include "layers/app_Token_Ring_SWC.h"
#include "layers/servAL_delay.h"
#include "layers/servAL_uart.h"
#include "layers/app_control.h"
#include "layers/ecual_lcd.h"
#include "layers/servAL_lcd.h"

uint8_t main(void);

uint8_t
main(void)
{
    CAN_init();
    portF_init();
    uart_init();

    lcdInit((uint8_t)FUNCTION_SET_2_LINES, (uint8_t)ENTRY_MODE_SET_INCREMENT,
                (uint8_t)DISPLAY_ON | (uint8_t)DISPLAY_CURSOR | (uint8_t)DISPLAY_CURSOR_BLINK);

    create_token_receive_object();
    create_token_send_object();
    create_distance_receive_object();
    create_command_receive_object();
    create_diagnostic_receive_object();
    create_diagnostic_send_object();

    StartUpState();

    while(1)
    {
        token_ring_runnable();
        control_runnable();
        diagnostic_runnable();
    }
}
