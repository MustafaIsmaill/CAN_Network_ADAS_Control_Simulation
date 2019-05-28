/*****************************************************************
 * Module Name: servAL_led
 * Author: Mustafa Ismail
 * Purpose: Initializes port F and checks the led status
 *****************************************************************/
#include "servAL_led.h"

/*****************************************************************
 * Function Name: portF_init
 * Inputs: void
 * Outputs: boolean
 * Description: Initialization of Port F
 *****************************************************************/
void
portF_init(void) /*Intialize port f */
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED | GREEN_LED);
}

/*****************************************************************
 * Function Name: Set_Led_Status
 * Inputs: uint8_t led name, uint8_t status
 * Outputs: void
 * Description: checks led status
 *****************************************************************/
void
Set_Led_Status(uint8_t led, uint8_t stat) /*checks led status */
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
