#ifndef __SERVAL_DELAY_H__
#define __SERVAL_DELAY_H__

#include <stdbool.h>
#include <stdint.h>
#include "driverlib/sysctl.h"

void delay_msec(uint32_t ms);
void delay_us(uint32_t us);
void delay_one_sec(void);

#endif /* __SERVAL_DELAY_H__ */
