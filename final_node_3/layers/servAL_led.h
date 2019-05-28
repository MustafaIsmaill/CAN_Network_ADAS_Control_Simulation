/*****************************************************************
 * Module Name: servAL_led.h
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the led
 *          functionalities.
 *****************************************************************/

#ifndef __SERVAL_LED_H__
#define __SERVAL_LED_H__

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

/* define red led hex value */
#define RED_LED     0x00000002U
/* define green led hex value */
#define GREEN_LED   0x00000008U

/* define HIGH value as 1 */
#define HIGH    1U
/* define LOW value as 0 */
#define LOW     0U

void portF_init(void);
void Set_Led_Status(uint8_t led, uint8_t stat);

#endif /* __SERVAL_LED_H__ */
