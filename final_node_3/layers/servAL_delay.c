#include "servAL_delay.h"

uint32_t ms_convert = 1000;
uint8_t systick_factor = 3;

void
delay_msec(uint32_t ms)
{
    SysCtlDelay(ms * (SysCtlClockGet() / systick_factor / ms_convert));
}

void
delay_one_sec(void)
{
    SysCtlDelay(SysCtlClockGet() / systick_factor);
}
