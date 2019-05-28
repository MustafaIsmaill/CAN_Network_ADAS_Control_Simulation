/*****************************************************************
 * Module Name: mcal_can.c
 * Author: Mustafa Ismail
 * Purpose: contains MCAL components for the CAN BUS.
 *****************************************************************/
#include "mcal_can.h"

/* Initialization of error flag variable */
volatile bool g_bErrFlag = 0;
/* Initialization of receive flag variable */
volatile bool g_bRXFlag = 0;
/* Initialization of transmit flag variable */
volatile bool g_bTXFlag = 0;
/* Initialization of msg counter variable */
volatile uint32_t g_ui32MsgCount = 0;
/* Initialization of diagnostic msg flag variable */
volatile bool g_Diagnostic_Flag = 0;

/* Initialization of constant value of 1 to set flags */
const bool set = 1;
/* Initialization of constant value of 0 to clear flags */
const bool clear = 0;

/*Interrupt Handler for CAN communication*/
/*****************************************************************
 * Function Name: print_reply
 * Inputs: void
 * Outputs: void
 * Description: Interrupt Handler for CAN communication
 *****************************************************************/
void
CANIntHandler(void)
{
    /*Create variable to indicate current status*/
    uint32_t ui32_Status;

    ui32_Status = CANIntStatus((uint32_t)CAN0_BASE, CAN_INT_STS_CAUSE);

    /*If an error occurred*/
    if(ui32_Status == (uint32_t)CAN_INT_INTID_STATUS)
    {
        ui32_Status = CANStatusGet((uint32_t)CAN0_BASE, CAN_STS_CONTROL);

        /*set the error flag*/
        g_bErrFlag = set;
    }
    /*message received*/
    else if(ui32_Status == (uint32_t)1)
    {
        /*clear interrupt flag*/
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)1);

        /*raise RX flag*/
        g_bRXFlag = set;

        /*clear error flag*/
        g_bErrFlag = clear;
    }
    /*message sent*/
    else if(ui32_Status == (uint32_t)2)
    {
        /*clear interrupt flag*/
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)2);

        /*raise TX flag*/
        g_bTXFlag = set;

        /*clear error flag*/
        g_bErrFlag = clear;
    }
    /*distance sent*/
    else if(ui32_Status == (uint32_t)4)
    {
        /*clear interrupt flag*/
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)4);

        /*clear error flag*/
        g_bErrFlag = clear;
    }
    /*command sent*/
    else if(ui32_Status == (uint32_t)5)
    {
        /*clear interrupt flag*/
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)5);

        /*clear error flag*/
        g_bErrFlag = clear;
    }
    else if(ui32_Status == (uint32_t)6)
    {
        /*clear interrupt flag*/
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)6);

        g_Diagnostic_Flag = set;

        /*clear error flag*/
        g_bErrFlag = clear;
    }
    else if(ui32_Status == (uint32_t)7)
    {
        /*clear interrupt flag*/
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)7);

        /*clear error flag*/
        g_bErrFlag = clear;
    }
    else
    {

    }
}

#define SYSCTL_PERIPH_CAN0      0xf0003400U
#define SYSCTL_PERIPH_GPIOB     0xf0000801U

/*Initialization of CAN0*/
/*****************************************************************
 * Function Name: CAN_init
 * Inputs: void
 * Outputs: void
 * Description: Initialization of CAN0 for portB and bitrate of
 *              1 Mbps
 *****************************************************************/
void
CAN_init(void)
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
        SysCtlClockSet((uint32_t)SYSCTL_SYSDIV_1 | (uint32_t)SYSCTL_USE_OSC |
                       (uint32_t)SYSCTL_OSC_MAIN | (uint32_t)SYSCTL_XTAL_16MHZ);
    #endif

        /*Enable GPIO B*/
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_GPIOB);


    /*Configure CAN RX and TX pins*/
    GPIOPinConfigure((uint32_t)GPIO_PB4_CAN0RX);
    GPIOPinConfigure((uint32_t)GPIO_PB5_CAN0TX);

    GPIOPinTypeCAN((uint32_t)GPIO_PORTB_BASE, (uint8_t)GPIO_PIN_4 | (uint8_t)GPIO_PIN_5);

    /*Enable CAN0*/
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_CAN0);

    /*Initialize CAN0*/
    CANInit((uint32_t)CAN0_BASE);

#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    CANBitRateSet(CAN0_BASE, ui32SysClock, 500000);
#else
    CANBitRateSet((uint32_t)CAN0_BASE, (uint32_t)SysCtlClockGet(), (uint32_t)1000000);
#endif

    /*Setup Interrupt on CAN0*/
    CANIntRegister((uint32_t)CAN0_BASE, &CANIntHandler);

    CANIntEnable((uint32_t)CAN0_BASE, (uint32_t)CAN_INT_MASTER |
                 (uint32_t)CAN_INT_ERROR | (uint32_t)CAN_INT_STATUS);
    IntEnable((uint32_t)INT_CAN0);

    /*Enable CAN0*/
    CANEnable((uint32_t)CAN0_BASE);
}
