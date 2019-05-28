/*****************************************************************
 * Module Name: mcal_can.h
 * Author: Mustafa Ismail
 * Purpose: contains MCAL components for the CAN BUS.
 *****************************************************************/

#ifndef __MCAL_CAN_H__
#define __MCAL_CAN_H__

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

/*Declaration of variables*/
extern volatile uint32_t g_ui32MsgCount;

/*A flag to indicate that some transmission error occurred.*/
extern volatile bool g_bErrFlag;
/*A flag to indicate that a message was received.*/
extern volatile bool g_bRXFlag;
/*A flag to indicate that a message has been transmitted*/
extern volatile bool g_bTXFlag;
/*A flag to indicate that distance message has been received*/
extern volatile bool g_bRX_Distance_Flag;
/*A flag to indicate that command message has been received*/
extern volatile bool g_bRX_Command_Flag;
/*A flag to indicate that diagnostic was received.*/
extern volatile bool g_diagnostic_Flag;

/*Function declarations*/
void CANIntHandler(void);
void CAN_init(void);

#endif /*__MCAL_CAN_H__*/
