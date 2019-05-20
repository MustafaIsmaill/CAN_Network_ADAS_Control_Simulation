#include "servAL_uart.h"

void
uart_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTStdioConfig(0, 115200, 16000000);
}

uint8_t
uart_receive(void)
{
    if(UARTCharsAvail(UART0_BASE))
    {
        ui8_rec_char =  UARTCharGetNonBlocking(UART0_BASE);
    }

    return ui8_rec_char;
}

void
uart_send(uint8_t ui8_send_char)
{
    UARTprintf("%i ", ui8_send_char);
}
