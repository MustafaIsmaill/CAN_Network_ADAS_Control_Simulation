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

uint8_t byte1;
uint8_t byte2;
uint8_t byte3;

enum state {error = 69, fire = 70, brake = 66, decrease = 68, maintain = 77, nerror = 80};

bool isChanged(void);
void diagnostic_runnable(void);
void print_reply(void);

#endif /*__APP_DIAGNOSTIC_H__*/
