#include "portF.h"
#include "can.h"

/*Initialization of flag*/
volatile bool button_Flag = 0;

/*Interrupt handler for port F*/
void
portF_handler(void)
{
    /*Check if the token is present at the node*/
    if(g_bRXFlag)
    {
        /*Raise the button flag indicating the switch has been pressed*/
        button_Flag = 1;
        /*Clear Interrupt*/
        GPIOIntClear(GPIO_PORTF_BASE, SW1);
    }
    /*If the token is not present, take no action*/
    else
    {
        /*Clear Interrupt*/
        GPIOIntClear(GPIO_PORTF_BASE, SW1);
    }
}


/*Initialization of port F*/
void
portF_init(void)
{
    /*Enable clock for port F*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    /*Wait for clock to stabilize*/
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    /*Define switch 1 as an input*/
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, SW1);
    /*Define the red and blue LEDs as outputs*/
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED | BLUE_LED);

    /*Define the interrupt handler for port F as the portF_handler function*/
    GPIOIntRegister(GPIO_PORTF_BASE, portF_handler);

    GPIODirModeSet(GPIO_PORTF_BASE, SW1, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTF_BASE, SW1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    /*Enable Interrupt on switch 1*/
    GPIOIntEnable(GPIO_PORTF_BASE, SW1);

}
