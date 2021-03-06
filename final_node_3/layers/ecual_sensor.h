/*****************************************************************
 * Module Name: ecual_sensor
 * Author: Mustafa Ismail
 * Purpose: Calculates the duty cycles and calculates commands
 *****************************************************************/

#ifndef __ECUAL_SENSOR_H__
#define __ECUAL_SENSOR_H__

#include <stdbool.h>
#include <stdint.h>
#include <math.h>
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
#include "layers/servAL_lcd.h"
#include "layers/app_control.h"

/* Commands in decimal
 * E = 69
 * F = 70
 * B = 66
 * D = 68
 * M = 77
 *  */
enum state {error = 69, fire = 70, brake = 66, decrease = 68, maintain = 77, nerror = 80};

void sensor_overwrite(uint8_t dc);
int8_t calc_distance(uint8_t ui8_duty_cycle);
uint8_t compute_cmd(int8_t i8_distance);

#endif /*__ECUAL_SENSOR_H__*/
