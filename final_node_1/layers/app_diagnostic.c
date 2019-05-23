#include "app_diagnostic.h"

int8_t ui8_service = 0;
int8_t ui8_prev_service = 0;

const uint32_t ui32_delay_ms = 10;

bool isChanged(void)
{
    uint8_t flag;
    if(ui8_service != ui8_prev_service)
    {
        flag = (uint8_t)1;
    }
    else
    {
        flag = (uint8_t)0;
    }
    return flag;
}

uint8_t msg_counter = 0;
int8_t bb1, bb2, bb3;

void
diagnostic_runnable(void)
{
    if(UARTCharsAvail((uint32_t)UART0_BASE))
    {
        msg_counter++;
        ui8_service = UARTCharGetNonBlocking((uint32_t)UART0_BASE);
        if(msg_counter == (int8_t)1) { bb1 = (int8_t)ui8_service; }
        else if(msg_counter == (int8_t)2) { bb2 = (int8_t)ui8_service; }
        else
        {
            bb3 = ui8_service;
            send_request(bb1, bb2, bb3);
            msg_counter = (uint8_t)0;
        }
        ui8_prev_service = ui8_service;
    }
    delay_msec(ui32_delay_ms);
}
