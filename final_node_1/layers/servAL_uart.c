/*****************************************************************
 * Module Name: servAL_uart.c
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the UART
 *          functionalities.
 *****************************************************************/

#include "servAL_uart.h"

/*****************************************************************
 * Function Name: uart_init
 * Inputs: void
 * Outputs: void
 * Description: initialize UART, portA, baudrate: 256000
 *****************************************************************/
void
uart_init(void) /*initalize UART */
{
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure((uint32_t)GPIO_PA0_U0RX);
    GPIOPinConfigure((uint32_t)GPIO_PA1_U0TX);

    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_UART0);

    UARTClockSourceSet((uint32_t)UART0_BASE, UART_CLOCK_PIOSC);

    GPIOPinTypeUART((uint32_t)GPIO_PORTA_BASE, (uint32_t)GPIO_PIN_0 | (uint32_t)GPIO_PIN_1);

    UARTStdioConfig((uint32_t)0, (uint32_t)256000, (uint32_t)16000000);
}

/*****************************************************************
 * Function Name: uart_receive
 * Inputs: void
 * Outputs: uint32_t received character
 * Description: UART recieving function
 *****************************************************************/
uint32_t
uart_receive(void) /*UART recieving function */
{
    if(UARTCharsAvail((uint32_t)UART0_BASE))
    {
        ui32_rec_char =  UARTCharGetNonBlocking((uint32_t)UART0_BASE);
    }
    return ui32_rec_char;
}

/*****************************************************************
 * Function Name: uart_send
 * Inputs: uint8_t character
 * Outputs: void
 * Description: UART recieving function
 *****************************************************************/
void
uart_send(uint8_t ui8_send_char) /*UART sending function */
{
    UARTprintf("%i ", ui8_send_char);
}
