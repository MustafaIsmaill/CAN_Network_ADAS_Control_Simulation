#include "app_FSM.h"

void
StartUpState(void)
{
    lcdStartup();
    while(!g_bRXFlag)
    {
        Set_Led_Status(GREEN_LED, HIGH);
    }
    Set_Led_Status(GREEN_LED, LOW);

    lcdClear();
}
