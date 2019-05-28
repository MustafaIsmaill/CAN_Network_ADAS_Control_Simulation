/*****************************************************************
 * Module Name: ecual_lcd
 * Author: Mustafa Ismail
 * Purpose: Enables the lcd and writes commands and data
 *****************************************************************/

#ifndef __ECUAL_LCD_H__
#define __ECUAL_LCD_H__

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#include "servAL_delay.h"
#include "servAL_lcd.h"

/*
 * Pins interfacing:
 * RS   --- PA2
 * R/W  --- GND
 * E    --- PA3
 * DB0  --- Not used
 * DB1  --- Not used
 * DB2  --- Not used
 * DB3  --- Not used
 * DB4  --- PA4
 * DB5  --- PA5
 * DB6  --- PA6
 * DB7  --- PA7
 */

#define FUNCTION_SET_BASE           0x20
#define FUNCTION_SET_8_BIT          0x10 /* 4-bit display by default */
#define FUNCTION_SET_2_LINES        0x08 /* 1 line by default */
#define FUNCTION_SET_5_10_DOTS      0x04 /* 5x7 dots by default */
#define ENTRY_MODE_SET_BASE         0x04
#define ENTRY_MODE_SET_INCREMENT    0x02 /* Decrement cursor position by default */
#define ENTRY_MODE_SET_SHIFT        0x01 /* No display shift by default */
#define DISPLAY_BASE                0x08
#define DISPLAY_ON                  0x04
#define DISPLAY_CURSOR              0x02
#define DISPLAY_CURSOR_BLINK        0x01

#define SHIFT_BASE                  0x10
#define SHIFT_DISPLAY               0x08 /* cursor move by default */
#define SHIFT_RIGHT                 0x04 /* shift to the left by default */
#define CLEAR_DISPLAY               0x01
#define RETURN_HOME                 0x02

/*
 * Change this according to pins interfacing
 */
#define LCD_GPIO_DATA_PERIPH        0xf0000800
#define LCD_GPIO_CTL_PERIPH         0xf0000800
#define LCD_GPIO_DATA_BASE          0x40004000 /* port for sending data */
#define LCD_GPIO_CTL_BASE           0x40004000  /* port for controlling RS, RW and E */
#define DATA_PINS                   (GPIO_PIN_4| GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7)
#define RS_PIN                      0x00000004 /* pin 2 */
#define E_PIN                       0x00000008 /* pin 3 */

void lcdInit(uint8_t functionSetOptions, uint8_t entryModeSetOptions,
        uint8_t displayOptions);
void lcdWriteData(uint8_t data);
void lcdWriteCommand(uint8_t com);
void lcdEnable(void);

#endif /* __ECUAL_LCD_H__ */
