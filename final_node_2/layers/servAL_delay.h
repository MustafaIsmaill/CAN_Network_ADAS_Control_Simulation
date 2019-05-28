/*****************************************************************
 * Module Name: servAL_delay
 * Author: Mustafa Ismail
 * Purpose: delay for milliseconds function and delay for 1 second
 *****************************************************************/

#ifndef __SERVAL_DELAY_H__
#define __SERVAL_DELAY_H__

#include <stdbool.h>
#include <stdint.h>
#include "driverlib/sysctl.h"

void delay_msec(uint32_t ms);
void delay_one_sec(void);

#endif /* __SERVAL_DELAY_H__ */
