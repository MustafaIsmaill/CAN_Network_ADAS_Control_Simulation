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

void diagnostic_runnable(void);

#endif /*__APP_DIAGNOSTIC_H__*/
