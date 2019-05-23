#include "servAL_diagnostic.h"

void
send_request(int8_t b1, int8_t b2, int8_t b3)
{
    if(!g_bTXFlag)
    {
        diagnostic_can_send(b1, b2, b3);
    }
}
