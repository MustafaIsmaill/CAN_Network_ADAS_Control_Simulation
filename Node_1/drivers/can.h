#ifndef __CAN_H__
#define __CAN_H__

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


/*Function declarations*/
void CANIntHandler(void);
extern void CAN_init(void);

#endif // __CAN_H__
