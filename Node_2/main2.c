// #include <stdbool.h>
// #include <stdint.h>
// #include "inc/hw_can.h"
// #include "inc/hw_ints.h"
// #include "inc/hw_memmap.h"
// #include "inc/hw_types.h"
// #include "driverlib/can.h"
// #include "driverlib/gpio.h"
// #include "driverlib/interrupt.h"
// #include "driverlib/pin_map.h"
// #include "driverlib/sysctl.h"
// #include "driverlib/uart.h"
// #include "utils/uartstdio.h"

// // CAN message object for receiving
// // tCANMsgObject CAN_msg_receive;
// // uint8_t CAN_msg_receive_data[8];

// // CAN message object for sending
// // tCANMsgObject CAN_msg_send;
// // uint32_t CAN_msg_data_send;
// // uint8_t *p_CAN_msg_data_send;
// //
// // void init_send_msg(void);
// // void init_receive_msg(void);
// // void toggle_msg_direction(void);
// void init_uart(void);
// void delay_one_second(void);

// int
// main(void)
// {
//     SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

//     // p_CAN_msg_data_send = (uint8_t *)&CAN_msg_data_send;
//     // init_send_msg();
//     // init_receive_msg();
//     init_uart();
//     // InitCAN();

//     // CANMessageSet(CAN0_BASE, 1, &CAN_msg_receive, MSG_OBJ_TYPE_RX);

//     ///////////////////////////////////////////////////////////////
//     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
//     while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));
//     GPIOPinConfigure(GPIO_PB4_CAN0RX);
//     GPIOPinConfigure(GPIO_PB5_CAN0TX);
//     GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);

//     tCANMsgObject sMsgObjectRx;
//     uint8_t pui8BufferIn[8];
//     SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
//     while(!SysCtlPeripheralReady(SYSCTL_PERIPH_CAN0));
//     CANInit(CAN0_BASE);
//     CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);
//     CANEnable(CAN0_BASE);
//     sMsgObjectRx.ui32MsgID = 0;
//     sMsgObjectRx.ui32MsgIDMask = 0;
//     sMsgObjectRx.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
//     CANMessageSet(CAN0_BASE, 2, &sMsgObjectRx, MSG_OBJ_TYPE_RX);
//     ///////////////////////////////////////////////////////////////

//     while(1)
//     {
// //        UARTprintf("waiting for msg\n");
//         // if(g_bRXFlag)
//         // {
// //            UARTprintf("Here\n");
//             // CANMessageGet(CAN0_BASE, 1, &CAN_msg_receive, 0);

// //            if(CAN_msg_receive.ui32MsgID == 2)
// //            {
// //                UARTprintf("REVEIVED WITH ID 2\n");
// //            }
// //            else
// //            {
// //                UARTprintf("RECEIVED WITH WRONG ID\n");
// //            }

//             // Clear the pending message flag so that the interrupt handler can
//             // set it again when the next message arrives.
//              // g_bRXFlag = 0;
//         // }

//         while((CANStatusGet(CAN0_BASE, CAN_STS_NEWDAT) & 1) == 0)
//         {
//             //
//             // Read the message out of the message object.
//             //
//             CANMessageGet(CAN0_BASE, 2, &sMsgObjectRx, true);
//             UARTprintf(" Received: %i", sMsgObjectRx.ui32MsgID);
//             delay_one_second();
//         }
//     }
// }

// // void
// // init_send_msg(void)
// // {
// //     CAN_msg_data_send = 0;
// //     CAN_msg_send.ui32MsgID = 2;
// //     CAN_msg_send.ui32MsgIDMask = 0;
// //     CAN_msg_send.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
// //     CAN_msg_send.ui32MsgLen = sizeof(p_CAN_msg_data_send);
// //     CAN_msg_send.pui8MsgData = p_CAN_msg_data_send;
// // }

// // void
// // init_receive_msg(void)
// // {
// //    CAN_msg_receive.ui32MsgID = 1;
// //    CAN_msg_receive.ui32MsgIDMask = 0;
// //    CAN_msg_receive.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
// //    CAN_msg_receive.ui32MsgLen = 8;
// // }

// // void
// // toggle_msg_direction(void)
// // {
// // 	if(CAN_msg_send.ui32MsgID == 2)
// // 	{
// // 		CAN_msg_send.ui32MsgID = 3;
// // 	}
// // 	else if(CAN_msg_send.ui32MsgID == 3)
// // 	{
// // 		CAN_msg_send.ui32MsgID = 2;
// // 	}
// // }

// void
// init_uart(void)
// {
//     // Enable GPIO port A which is used for UART0 pins.
//     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

//     // Configure the pin muxing for UART0 functions on port A0 and A1.
//     GPIOPinConfigure(GPIO_PA0_U0RX);
//     GPIOPinConfigure(GPIO_PA1_U0TX);

//     // Enable UART0 so that we can configure the clock.
//     SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

//     // Use the internal 16MHz oscillator as the UART clock source.
//     UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

//     // Select the alternate (UART) function for these pins.
//     GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

//     // Initialize the UART for console I/O.
//     UARTStdioConfig(0, 115200, 16000000);
// }

// void
// delay_one_second(void)
// {
//     // Delay cycles for 1 second
//     SysCtlDelay(16000000 / 3);
// }

//*****************************************************************************
//
// simple_rx.c - Example demonstrating simple CAN message reception.
//
// Copyright (c) 2010-2017 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 

//*****************************************************************************
//
// simple_rx.c - Example demonstrating simple CAN message reception.
//
// Copyright (c) 2010-2017 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 2.1.4.178 of the Tiva Firmware Development Package.
//
//*****************************************************************************

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

volatile uint32_t g_ui32MsgCount = 0;
volatile bool g_bRXFlag = 0;
volatile bool g_bTXFlag = 0;
volatile bool g_bErrFlag = 0;

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
CANIntHandler(void)
{
    uint32_t ui32Status;

    ui32Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);

    // error occured
    if(ui32Status == CAN_INT_INTID_STATUS)
    {
        ui32Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);

        // set the error flag
        g_bErrFlag = 1;
    }
    // message received
    else if(ui32Status == 1)
    {
        // clear interrupt flag
        CANIntClear(CAN0_BASE, 1);

        // raise Tx flag
        g_bRXFlag = 1;

        // clear error flag
        g_bErrFlag = 0;
    }
    // message sent
    else if(ui32Status == 2)
    {
        // clear interrupt flag
        CANIntClear(CAN0_BASE, 2);

        // raise Rx flag
        g_bTXFlag = 1;

        // clear error flag
        g_bErrFlag = 0;
    }
}

void
CAN_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    GPIOPinConfigure(GPIO_PB4_CAN0RX);
    GPIOPinConfigure(GPIO_PB5_CAN0TX);

    GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

    CANInit(CAN0_BASE);

    #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
        defined(TARGET_IS_TM4C129_RA1) ||                                         \
        defined(TARGET_IS_TM4C129_RA2)
        CANBitRateSet(CAN0_BASE, ui32SysClock, 500000);
    #else
        CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);
    #endif

    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);
    IntEnable(INT_CAN0);
    CANEnable(CAN0_BASE);
}

void
SimpleDelay(void)
{
    // 1 second
    SysCtlDelay(16000000 / 3);
}

#define RED_LED   GPIO_PIN_1
#define SW1       GPIO_PIN_4

void 
portF_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED);

    GPIODirModeSet(GPIO_PORTF_BASE, SW1, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTF_BASE, SW1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
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
