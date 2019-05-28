/*****************************************************************
 * Module Name: main file
 * Author: Mustafa Ismail
 * Purpose: Run the main function for Node 1
 *****************************************************************/

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
#include "layers/app_diagnostic.h"
#include "layers/servAL_diagnostic.h"

/* main function prototype */
uint8_t main(void);

uint8_t
main(void)
{
    /* Initializes CAN Bus */
    CAN_init();
    /* Port F initialization */
    portF_init();
    /* UART Initialization */
    uart_init();
    /* Go to startup state and wait for the token to be received */
    StartUpState();

    /* Creates CAN message object to recieve token */
    create_token_receive_object();
    /* Create CAN message object to send token */
    create_token_send_object();
    /* Creates CAN message object to send diagnostic */
    create_diagnostic_send_object();
    /* Creates CAN messsage object to recieve diagnostic */
    create_diagnostic_receive_object();

    while(1)
    {
        /* waits for the token and then waits for 1 second before sending it to the next ECU */
        token_ring_runnable();
        /* waits for service from the UART and reply according to the service to node number 1 */
        diagnostic_runnable();
    }
}
