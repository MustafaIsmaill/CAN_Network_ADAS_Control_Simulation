/*****************************************************************
 * Module Name: app_control
 * Author: Mustafa Ismail
 * Purpose: Prints commands and waits for the duty cycle 
 *****************************************************************/

#ifndef __APP_CONTROL_H__
#define __APP_CONTROL_H__

#include <stdbool.h>
#include <stdint.h>
#include "layers/servAL_led.h"
#include "layers/app_FSM.h"
#include "layers/mcal_can.h"
#include "layers/servAL_can.h"
#include "layers/app_Token_Ring_SWC.h"
#include "layers/servAL_delay.h"
#include "layers/servAL_uart.h"
#include "layers/servAL_lcd.h"
#include "layers/ecual_sensor.h"

extern uint8_t err_flag;
extern int8_t distance;
extern uint8_t command;

void control_runnable(void);
void print_cmd(uint8_t cmd);

#endif /*__APP_CONTROL_H__*/
