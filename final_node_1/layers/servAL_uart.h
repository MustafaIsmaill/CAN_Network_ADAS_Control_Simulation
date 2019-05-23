#ifndef __SERVAL_UART_H__
#define __SERVAL_UART_H__

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

void uart_init(void);
uint32_t uart_receive(void);
void uart_send(uint8_t ui8_send_char);

uint32_t ui32_rec_char;

#endif /* __SERVAL_UART_H__ */
