#ifndef __APP_FSM_H__
#define __APP_FSM_H__

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

#define HIGH    1U
#define LOW     0U

void StartUpState(void);

#endif /* __APP_FSM_H__ */
