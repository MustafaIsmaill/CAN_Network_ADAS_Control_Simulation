#include "portF.h"

void
portF_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED);

    GPIODirModeSet(GPIO_PORTF_BASE, SW1, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTF_BASE, SW1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}
