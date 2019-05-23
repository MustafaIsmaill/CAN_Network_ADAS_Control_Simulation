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
#include "layers/app_sensor.h"
#include "layers/ecual_sensor.h"

uint8_t main(void);

uint8_t
main(void)
{
    CAN_init();
    portF_init();
    uart_init();

    create_token_receive_object();
    create_token_send_object();
    create_distance_send_object();
    create_command_send_object();
    create_diagnostic_receive_object();
    create_diagnostic_send_object();

    StartUpState();

    while(1)
    {
        token_ring_runnable();
        distance_sensor_runnable();
        diagnostic_runnable();
    }
}
