/*****************************************************************
 * Module Name: servAL_led.c
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the led
 *          functionalities.
 *****************************************************************/

#include "servAL_led.h"

/*****************************************************************
 * Function Name: portF_init
 * Inputs: void
 * Outputs: void
 * Description: Initialize PortF for red and green leds as output
 *****************************************************************/
void
portF_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED | GREEN_LED);
}

/*****************************************************************
 * Function Name: Set_Led_Status
 * Inputs: uint8_t led name, uint8_t led status
 * Outputs: void
 * Description: sets led status to high or low
 *****************************************************************/
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
