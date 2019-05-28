/*****************************************************************
 * Module Name: servAL_diagnostic.c
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the diagnostic
 *          functionalities.
 *****************************************************************/

#include "servAL_diagnostic.h"

/*****************************************************************
 * Function Name: isMine
 * Inputs: void
 * Outputs: boolean
 * Description: Checks if the diagnostic is for the current node
 *****************************************************************/
bool 
isMine(uint8_t first_byte) /*Checks if the diagnostic is for the current node */
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

/*****************************************************************
 * Function Name: get_reply_data
 * Inputs: int8_t service id, int8_t parameter
 * Outputs: int8_t data received from CAN
 * Description:Checks the service id and according to the ID the 
 *			   data is returned
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

/*****************************************************************
 * Function Name: send_reply
 * Inputs: int8_t first byte, int8_t second byte, int8_t third byte
 * Outputs: void
 * Description:Sends the data to the CAN
 *****************************************************************/
void
send_reply(int8_t b1, int8_t b2, int8_t b3) /*Sends the data to the CAN */
{
    diagnostic_can_send(b1, b2, b3);
}
