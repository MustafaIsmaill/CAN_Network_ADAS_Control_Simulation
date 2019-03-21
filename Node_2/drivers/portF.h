#ifndef __PORTF_H__
#define __PORTF_H__

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

#define RED_LED   GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2

#define SW1       GPIO_PIN_4

void portF_init(void);

#endif // __PORTF_H__
