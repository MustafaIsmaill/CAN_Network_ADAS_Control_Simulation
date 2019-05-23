#ifndef __SERVAL_DIAGNOSTIC_H__
#define __SERVAL_DIAGNOSTIC_H__

#include <stdbool.h>
#include <stdint.h>
#include "layers/mcal_can.h"
#include "layers/servAL_can.h"
#include "layers/servAL_led.h"
#include "layers/servAL_delay.h"
#include "layers/app_diagnostic.h"
#include "layers/servAL_uart.h"

uint32_t can_frame;

void send_request(int8_t b1, int8_t b2, int8_t b3);

#endif /*__SERVAL_DIAGNOSTIC_H__*/
