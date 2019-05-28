/*****************************************************************
 * Module Name: main file
 * Author: Mustafa Ismail
 * Purpose: Run the main function for Node 3
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
#include "layers/app_control.h"
#include "layers/ecual_lcd.h"
#include "layers/servAL_lcd.h"

uint8_t main(void);

uint8_t
main(void)
{
    CAN_init(); /* Initializes CAN Bus */
    portF_init(); /* Port F initialization */
    uart_init(); /* UART Initialization */

    lcdInit((uint8_t)FUNCTION_SET_2_LINES, (uint8_t)ENTRY_MODE_SET_INCREMENT,
                (uint8_t)DISPLAY_ON | (uint8_t)DISPLAY_CURSOR | (uint8_t)DISPLAY_CURSOR_BLINK);

    create_token_receive_object(); /* Creates CAN message object to recieve token */
    create_token_send_object(); /* Create CAN message object to send token */
    create_distance_receive_object(); /* Creates CAN message object to recieve distance */
    create_command_receive_object(); /*Creates CAN message object to recieve command */
    create_diagnostic_receive_object(); /* Creates CAN messsage object to recieve diagnostic */
    create_diagnostic_send_object(); /* Creates CAN message object to send diagnostic */

    StartUpState(); /* Go to startup state and wait for the token to be recieved */

    while(1)
    {
        token_ring_runnable(); /* waits for the token and then waits for 1 second before sending it to the next ECU */
        control_runnable();
        diagnostic_runnable(); /* waits for service from the UART and reply according to the service to node number 1 */
    }
}
