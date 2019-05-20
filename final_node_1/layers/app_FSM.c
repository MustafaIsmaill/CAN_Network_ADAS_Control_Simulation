#include "app_FSM.h"
#include "servAL_delay.h"
#include "servAL_led.h"

void
StartUpState(void)
{
    Set_Led_Status(GREEN_LED, HIGH);
    delay_one_sec();
    Set_Led_Status(GREEN_LED, LOW);
}
