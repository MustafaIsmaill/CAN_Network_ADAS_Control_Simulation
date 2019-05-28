/*****************************************************************
 * Module Name: main file
 * Author: Mustafa Ismail
 * Purpose: Run the main function for Node 2
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
#include "layers/app_sensor.h"
#include "layers/ecual_sensor.h"

uint8_t main(void);

uint8_t
main(void)
{
    CAN_init(); /* Initializes CAN Bus */
    portF_init(); /* Port F initialization */
    uart_init(); /* UART Initialization */

    create_token_receive_object(); /* Creates CAN message object to recieve token */
    create_token_send_object(); /* Create CAN message object to send token */
    create_distance_send_object(); /* Creates CAN message object to send distance */
    create_command_send_object(); /*Creates CAN message object to send command */
    create_diagnostic_receive_object(); /* Creates CAN messsage object to recieve diagnostic */
    create_diagnostic_send_object(); /* Creates CAN message object to send diagnostic */

    StartUpState(); /* Go to startup state and wait for the token to be recieved */

    while(1)
    {
        token_ring_runnable(); /* waits for the token and then waits for 1 second before sending it to the next ECU */
        distance_sensor_runnable(); /* waits for duty cycle from the UART and then calculates the command and distance from the duty cycles and sends them to the node number 3 */
        diagnostic_runnable(); /* waits for service from the UART and reply according to the service to node number 1 */
    }
}
