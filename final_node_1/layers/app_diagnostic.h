/*****************************************************************
 * Module Name: app_diagnostic.h
 * Author: Mustafa Ismail
 * Purpose: contains application layer components for the
 *          diagnostic part.
 *****************************************************************/

#ifndef __APP_DIAGNOSTIC_H__
#define __APP_DIAGNOSTIC_H__

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

#include "servAL_uart.h"
#include "servAL_can.h"
#include "servAL_delay.h"
#include "servAL_diagnostic.h"

/* Initialize three bytes to hold received diagnostic msg */
uint8_t byte1;
uint8_t byte2;
uint8_t byte3;

/* enum that holds state representation in hex
 * error:       'E' = 0x69
 * fire:        'F' = 0x70
 * brake:       'B' = 0x66
 * decrease:    'D' = 0x68
 * maintain:    'M' = 0x77
 * no error:        = 0x80 */
enum state {error = 69, fire = 70, brake = 66, decrease = 68, maintain = 77, nerror = 80};

/*****************************************************************
 * Function Name: isChanged
 * Inputs: void
 * Outputs: boolean
 * Description: checks if newly received diagnostic is the same
 *              as the previously received diagnostic or not and
 *              returns a boolean flag.
 *****************************************************************/
bool isChanged(void);

/*****************************************************************
 * Function Name: diagnostic_runnable
 * Inputs: void
 * Outputs: void
 * Description: waits for UART buffer to have new msgs from the
 *              diagnostics and then sends the request over
 *              CAN BUS
 *****************************************************************/
void diagnostic_runnable(void);

/*****************************************************************
 * Function Name: print_reply
 * Inputs: void
 * Outputs: void
 * Description: prints received diagnostic msg from node 1 or 2
 *              to the UART
 *****************************************************************/
void print_reply(void);

#endif /*__APP_DIAGNOSTIC_H__*/
