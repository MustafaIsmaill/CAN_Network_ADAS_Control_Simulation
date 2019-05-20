#ifndef __APP_TOKEN_RING_SWC_H__
#define __APP_TOKEN_RING_SWC_H__

#include <stdbool.h>
#include <stdint.h>
#include "layers/mcal_can.h"
#include "layers/servAL_can.h"
#include "layers/servAL_led.h"
#include "layers/servAL_delay.h"

void token_ring_runnable(void);

#endif /*APP_TOKEN_RING_SWC*/
