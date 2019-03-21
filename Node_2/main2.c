#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

#include "drivers/can.h"
#include "drivers/portF.h"

void
InitConsole(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTStdioConfig(0, 115200, 16000000);
}

void
SimpleDelay(void)
{
    // 1 second
    SysCtlDelay(16000000 / 3);
}

int
main(void)
{
    #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
        defined(TARGET_IS_TM4C129_RA1) ||                                         \
        defined(TARGET_IS_TM4C129_RA2)
        uint32_t ui32SysClock;
    #endif

    #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
        defined(TARGET_IS_TM4C129_RA1) ||                                         \
        defined(TARGET_IS_TM4C129_RA2)
        ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                           SYSCTL_OSC_MAIN |
                                           SYSCTL_USE_OSC)
                                           25000000);
    #else
        SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);
    #endif

    InitConsole();
    CAN_init();
    portF_init();

    /////////////////////////////////////////////////////////////////////
    // Received msg //
    tCANMsgObject sCANMessage_received;
    uint8_t pui8MsgData_received[1];

    sCANMessage_received.ui32MsgID = 2;
    sCANMessage_received.ui32MsgIDMask = 0xFFFFFFFF;
    sCANMessage_received.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
    sCANMessage_received.ui32MsgLen = 1;
    sCANMessage_received.pui8MsgData = pui8MsgData_received;

    CANMessageSet(CAN0_BASE, 1, &sCANMessage_received, MSG_OBJ_TYPE_RX);
    /////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////
    // Sent message to node 2
    tCANMsgObject sCANMessage_sent;
    
    uint32_t ui32MsgData_sent;
    uint8_t *pui8MsgData_sent;

    pui8MsgData_sent = (uint8_t *)&ui32MsgData_sent;

    ui32MsgData_sent = 0;
    sCANMessage_sent.ui32MsgID = 1;
    sCANMessage_sent.ui32MsgIDMask = 0;
    sCANMessage_sent.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    sCANMessage_sent.ui32MsgLen = 1;
    sCANMessage_sent.pui8MsgData = pui8MsgData_sent;
    // CANMessageSet(CAN0_BASE, 2, &sCANMessage_sent, MSG_OBJ_TYPE_TX);
    //////////////////////////////////////////////

    while(1)
    {
        // message received
        if(g_bRXFlag)
        {
            // read msg
            CANMessageGet(CAN0_BASE, 1, &sCANMessage_received, 0);
            
            // clear receive flag
            g_bRXFlag = 0;

            // red led on
            GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, RED_LED);

            // wait one second
            SimpleDelay();

            // send token to next node
            CANMessageSet(CAN0_BASE, 2, &sCANMessage_sent, MSG_OBJ_TYPE_TX);

            // red led off
            GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, 0);
            
            // wait one second
            SimpleDelay();
        }

        if(g_bTXFlag)
        {
            g_bTXFlag = 0;
        }
    }

}
