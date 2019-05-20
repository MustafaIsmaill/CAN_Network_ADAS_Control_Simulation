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

void control_runnable(void);
void print_cmd(uint8_t cmd);

#endif /*__APP_CONTROL_H__*/
