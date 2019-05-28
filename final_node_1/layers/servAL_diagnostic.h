/*****************************************************************
 * Module Name: servAL_diagnostic.h
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the diagnostic
 *          functionalities.
 *****************************************************************/

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

void send_request(int8_t b1, int8_t b2, int8_t b3);

#endif /*__SERVAL_DIAGNOSTIC_H__*/
