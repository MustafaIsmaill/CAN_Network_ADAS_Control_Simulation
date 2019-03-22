#include "portF.h"
#include "can.h"

volatile bool button_Flag = 0;

void
portF_handler(void)
{
    if(g_bRXFlag)
    {
        button_Flag = 1;
        GPIOIntClear(GPIO_PORTF_BASE, SW1);
    }
    else
    {
        GPIOIntClear(GPIO_PORTF_BASE, SW1);
    }
}

void
portF_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, SW1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED | BLUE_LED);

    GPIOIntRegister(GPIO_PORTF_BASE, portF_handler);

    GPIODirModeSet(GPIO_PORTF_BASE, SW1, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTF_BASE, SW1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    GPIOIntEnable(GPIO_PORTF_BASE, SW1);

}
