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

extern volatile uint32_t g_ui32MsgCount;

// A flag to indicate that some transmission error occurred.
extern volatile bool g_bErrFlag;
extern volatile bool g_bRXFlag;
extern volatile bool g_bTXFlag;

void CANIntHandler(void);
extern void CAN_init(void);

#endif // __CAN_H__
