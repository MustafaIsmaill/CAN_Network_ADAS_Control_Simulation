/*****************************************************************
 * Module Name: servAL_uart.h
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the UART
 *          functionalities.
 *****************************************************************/

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
uint8_t uart_receive(void);
void uart_send(uint8_t ui8_send_char);

uint8_t ui8_rec_char;

#endif /* __SERVAL_UART_H__ */
