/*****************************************************************
 * Module Name: servAL_diagnostic
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the diagnosis
 *          functionality
 *****************************************************************/

#include "servAL_diagnostic.h"

/*****************************************************************
 * Function Name: isMine
 * Inputs: int8_t first byte
 * Outputs: void
 * Description: Checks if the diagnostic is for the current node
 *****************************************************************/
bool 
isMine(int8_t first_byte) /*Checks if the diagnostic is for the current node */
{
	uint8_t flag;

	if((0x0F & first_byte) == 2)
	{
		flag = (uint8_t)1;
	}
	else
	{
		flag = (uint8_t)0;
	}
	return flag;
}

/*****************************************************************
 * Function Name: get_reply_data
 * Inputs: int8_t service id, int8_t parameter
 * Outputs: int8_t
 * Description: Checks the service id and according to the ID the
 *		        data is returned
 *****************************************************************/
int8_t
get_reply_data(int8_t serv_id, int8_t param) /* Checks the service id and according to the ID the data is returned */
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
            sensor_clear_error();
            break;
        /* read sensor data */
        case 0x22:
            if(param == 0) { ret_val = i8_distance; }
            else { ret_val = ui8_command; }
            break;
        /* overwrite sensor data */
        case 0x2E:
            sensor_overwrite(param);
            ret_val = 0;
            break;
    }
    return ret_val;
}

/*****************************************************************
 * Function Name: send_reply
 * Inputs: int8_t byte1, int8_t byte2, int8_t byte3
 * Outputs: void
 * Description: Sends the data to the CAN 
 *****************************************************************/
void
send_reply(int8_t b1, int8_t b2, int8_t b3) /*Sends the data to the CAN */
{
    diagnostic_can_send(b1, b2, b3);
}
