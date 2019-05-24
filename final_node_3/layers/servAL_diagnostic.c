#include "servAL_diagnostic.h"

bool 
isMine(uint8_t first_byte)
{
	uint8_t flag;

	if((0x0F & first_byte) == ((uint8_t)3))
	{
		flag = (uint8_t)1;
	}
	else
	{
		flag = (uint8_t)0;
	}
	return flag;
}

int8_t
get_reply_data(int8_t serv_id, int8_t param)
{
    int8_t ret_val;
    switch(serv_id)
    {
        /* read error */
        case 0x19:
            ret_val = err_flag;
            break;
        /* clear error */
        case 0x14:
            err_flag = 0;
            ret_val = 0;
            lcdWriteCmd("No Error ");
            break;
        /* read sensor data */
        case 0x22:
            if(param == 0) { ret_val = distance; }
            else { ret_val = command; }
            break;
        /* overwrite sensor data */
        case 0x2E:
            sensor_overwrite(param);
            ret_val = 0;
            break;
    }
    return ret_val;
}

void
send_reply(int8_t b1, int8_t b2, int8_t b3)
{
    diagnostic_can_send(b1, b2, b3);
}
