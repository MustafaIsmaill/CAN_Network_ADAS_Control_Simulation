#include "servAL_led.h"

void
portF_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED | GREEN_LED);
}

void
Set_Led_Status(uint8_t led, uint8_t stat)
{
    if(stat == HIGH)
    {
        stat = led;
    }
    else
    {
        stat = 0;
    }

    GPIOPinWrite(GPIO_PORTF_BASE, led, stat);
}
