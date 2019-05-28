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
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTStdioConfig(0, 115200, 16000000);
}

/*****************************************************************
 * Function Name: uart_receive
 * Inputs: void
 * Outputs: uint32_t received character
 * Description: UART recieving function
 *****************************************************************/
uint8_t
uart_receive(void) /*UART recieving function */
{
    if(UARTCharsAvail(UART0_BASE))
    {
        ui8_rec_char =  UARTCharGetNonBlocking(UART0_BASE);
    }

    return ui8_rec_char;
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
