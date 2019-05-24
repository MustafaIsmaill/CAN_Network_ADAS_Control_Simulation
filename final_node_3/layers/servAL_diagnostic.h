#ifndef __SERVAL_DIAGNOSTIC_H__
#define __SERVAL_DIAGNOSTIC_H__

#include <stdbool.h>
#include <stdint.h>
#include "layers/app_FSM.h"
#include "layers/mcal_can.h"
#include "layers/servAL_can.h"
#include "layers/servAL_led.h"
#include "layers/servAL_delay.h"
#include "layers/app_diagnostic.h"
#include "layers/servAL_uart.h"
#include "layers/ecual_sensor.h"
#include "layers/ecual_lcd.h"
#include "layers/servAL_lcd.h"
#include "layers/app_control.h"
#include "layers/ecual_sensor.h"

bool isMine(uint8_t first_byte);
int8_t get_reply_data(int8_t serv_id, int8_t param);
void send_reply(int8_t b1, int8_t b2, int8_t b3);

#endif /*__SERVAL_DIAGNOSTIC_H__*/
