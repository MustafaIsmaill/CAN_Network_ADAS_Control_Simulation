#ifndef __APP_SENSOR_H__
#define __APP_SENSOR_H__

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

#include "ecual_sensor.h"
#include "servAL_uart.h"
#include "servAL_can.h"

extern int8_t err_flag;
extern uint8_t ui8_duty_cycle;
extern int8_t i8_distance;
extern uint8_t ui8_command;

bool isChanged(void);
void distance_sensor_runnable(void);
void sensor_overwrite(uint8_t dc);
void sensor_clear_error(void);

#endif /*__APP_SENSOR_H__*/
