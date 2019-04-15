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

/* Declaration of used Functions*/
void InitConsole(void);
void SimpleDelay(void);
void StartUpState(void);
int main(void);

/*This function sets up UART0 to be used for a console to display information
as the example is running*/
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

/* Function to execute a delay of 1 second*/
void
SimpleDelay(void)
{

    SysCtlDelay(16000000 / 3);
}
/* This function is implemented at the start of the program. A blue LED is set on for one second then turned off again*/
void
StartUpState(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
    SimpleDelay();
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
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
    /*System Initialization*/
    InitConsole();
    CAN_init();
    portF_init();

    /*Creation of object for the received message called sCANMessage_received. An array for the received data is created to hold 1 unsigned
        8-bit integer*/

    tCANMsgObject sCANMessage_received;
    uint8_t pui8MsgData_received[1];

    sCANMessage_received.ui32MsgID = 3;
    sCANMessage_received.ui32MsgIDMask = 0xFFFFFFFF;
    sCANMessage_received.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
    sCANMessage_received.ui32MsgLen = 1;
    sCANMessage_received.pui8MsgData = pui8MsgData_received;

    CANMessageSet(CAN0_BASE, 1, &sCANMessage_received, MSG_OBJ_TYPE_RX);


    /* An object for sent messages is created called sCANMessage_sent.*/
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


    /*The Startup state, keep the blue LED on until the first message arrives.*/
    while(!g_bRXFlag)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
    }
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);

    /*Main Program Loop*/
    while(1)
    {
        /* Check if a message is received*/
        if(g_bRXFlag)
        {
            /*Read Message*/
            CANMessageGet(CAN0_BASE, 1, &sCANMessage_received, 0);

            /*Turn on Red LED*/
            GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, RED_LED);

            /*Wait One Second*/
            SimpleDelay();

            /*clear receive flag*/
            g_bRXFlag = 0;

            /*Check if the button to switch direction has been pushed*/
            if(button_Flag)
            {
                /*If the current direction was forward*/
                if(pui8MsgData_received[0] == 0)
                {
                    /*Switch the direction to reverse*/
                    pui8MsgData_sent[0] = 1;
                    /*Set ID for the next node to 2*/
                    sCANMessage_sent.ui32MsgID = 2;
                }
                /*If the current direction was reverse*/
                else
                {
                    /*Switch direction to forward*/
                    pui8MsgData_sent[0] = 0;
                    /*Set ID for the next node to 1*/
                    sCANMessage_sent.ui32MsgID = 1;
                }
                /*Clear the button flag*/
                button_Flag = 0;
            }
            /*If the switch button has not been pressed*/
            else
            {
                /*If the direction was forward*/
                if(pui8MsgData_received[0] == 0)
                {
                    /*Keep the direction as it is*/
                    pui8MsgData_sent[0] = 0;
                    /*Set ID for the next node to 1*/
                    sCANMessage_sent.ui32MsgID = 1;
                }
                /*If the direction was reverse*/
                else
















                {
                    /*Keep the direction as it is*/
                    pui8MsgData_sent[0] = 1;
                    /*Set ID for the next node to 2*/
                    sCANMessage_sent.ui32MsgID = 2;
                }
            }

            /* Send token to next node*/
            CANMessageSet(CAN0_BASE, 2, &sCANMessage_sent, MSG_OBJ_TYPE_TX);

            /* Turn off red LED, indicating the token is no longer at this node*/
            GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, 0);

        }

        /*Clear the send flag if it is still set to high*/
        if(g_bTXFlag)
        {
            g_bTXFlag = 0;
        }
    }

}
