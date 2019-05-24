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

#define RED_LED     0x00000002U
#define GREEN_LED   0x00000008U

#define HIGH    1U
#define LOW     0U

/*#define SYSCTL_PERIPH_GPIOF     0xf0000805U
#define GPIO_PORTF_BASE         0x40025000U*/

void portF_init(void);
void Set_Led_Status(uint8_t led, uint8_t stat);

#endif /* __SERVAL_LED_H__ */
