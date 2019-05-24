#ifndef __SERVAL_LCD_H__
#define __SERVAL_LCD_H__

#include <stdint.h>
#include <stdbool.h>
#include "inc/std_lib.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#include "servAL_delay.h"
#include "ecual_lcd.h"

void lcdWriteDistance(uint8_t num);
void lcdWriteCmd(char* cmd);
void lcdStartup(void);
void lcdWriteChar(char ch);
void lcdWriteString(char * s);
void lcdGoToXY(uint8_t x, uint8_t y);
void lcdClear(void);

#endif /* __ECUAL_LCD_H__ */
