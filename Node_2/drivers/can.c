#include "can.h"

/*Initialization of variables*/
volatile bool g_bErrFlag = 0;
volatile bool g_bRXFlag = 0;
volatile bool g_bTXFlag = 0;
volatile uint32_t g_ui32MsgCount = 0;

/*Interrupt Handler for CAN communication*/
void
CANIntHandler(void)
{
    /*Create variable to indicate current status*/
    uint32_t ui32Status;

    ui32Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);

    /*If an error occurred*/
    if(ui32Status == CAN_INT_INTID_STATUS)
    {
        ui32Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);

        /*set the error flag*/
        g_bErrFlag = 1;
    }

    /*message received*/
    else if(ui32Status == 1)
    {
        /*clear interrupt flag*/
        CANIntClear(CAN0_BASE, 1);

        /*raise RX flag*/
        g_bRXFlag = 1;

        /*clear error flag*/
        g_bErrFlag = 0;
    }

    /*message sent*/
    else if(ui32Status == 2)
    {
        /*clear interrupt flag*/
        CANIntClear(CAN0_BASE, 2);

        /*raise TX flag*/
        g_bTXFlag = 1;

        /*clear error flag*/
        g_bErrFlag = 0;
    }
}

/*Initialization of CAN0*/
void
CAN_init(void)
{
    /*Enable GPIO B*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);


    /*Configure CAN RX and TX pins*/
    GPIOPinConfigure(GPIO_PB4_CAN0RX);
    GPIOPinConfigure(GPIO_PB5_CAN0TX);

    GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    /*Enable CAN0*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

    /*Initialize CAN0*/
    CANInit(CAN0_BASE);

#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    CANBitRateSet(CAN0_BASE, ui32SysClock, 500000);
#else
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);
#endif

    /*Setup Interrupt on CAN0*/
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);
    IntEnable(INT_CAN0);

    /*Enable CAN0*/
    CANEnable(CAN0_BASE);
}
