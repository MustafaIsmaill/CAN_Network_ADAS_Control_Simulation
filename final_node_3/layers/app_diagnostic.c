#include "app_diagnostic.h"

void
diagnostic_runnable(void)
{
    int8_t reply;
    if(g_diagnostic_Flag)
    {
        diagnostic_can_receive();
        if(isMine(pui8MsgDiagnostic_received[0]))
        {
            reply = get_reply_data(pui8MsgDiagnostic_received[1], pui8MsgDiagnostic_received[2]);
            send_reply(pui8MsgDiagnostic_received[0], pui8MsgDiagnostic_received[1], reply);
        }
        g_diagnostic_Flag = 0;
    }
    delay_msec(10);
}
