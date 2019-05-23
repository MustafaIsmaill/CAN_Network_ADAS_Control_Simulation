#include "servAL_uart.h"

void
uart_init(void)
{
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure((uint32_t)GPIO_PA0_U0RX);
    GPIOPinConfigure((uint32_t)GPIO_PA1_U0TX);

    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_UART0);

    UARTClockSourceSet((uint32_t)UART0_BASE, UART_CLOCK_PIOSC);

    GPIOPinTypeUART((uint32_t)GPIO_PORTA_BASE, (uint32_t)GPIO_PIN_0 | (uint32_t)GPIO_PIN_1);

    UARTStdioConfig((uint32_t)0, (uint32_t)256000, (uint32_t)16000000);
}

uint32_t
uart_receive(void)
{
    if(UARTCharsAvail((uint32_t)UART0_BASE))
    {
        ui32_rec_char =  UARTCharGetNonBlocking((uint32_t)UART0_BASE);
    }
    return ui32_rec_char;
}

void
uart_send(uint8_t ui8_send_char)
{
    UARTprintf("%i ", ui8_send_char);
}
