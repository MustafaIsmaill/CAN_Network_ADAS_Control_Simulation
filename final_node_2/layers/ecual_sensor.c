/*****************************************************************
 * Module Name: ecual_sensor
 * Author: Mustafa Ismail
 * Purpose: Recieves duty cycles and calculates distances and 
 *			commands
 *****************************************************************/

#include "ecual_sensor.h"

/*****************************************************************
 * Function Name: print_reply
 * Inputs: uint8_t duty cycle
 * Outputs: int8_t distance
 * Description: Recieves a duty cycle and calculates the distance
 *****************************************************************/
int8_t
calc_distance(uint8_t ddc) /* Recieves a duty cycle and calculates the distance */
{
    return floor((0.75*ddc)-7.5);
}

/*****************************************************************
 * Function Name: compute_cmd
 * Inputs:int8_t distance
 * Outputs:uint8_t command
 * Description:Recieves a distance and calculates a corresponding 
 *			   command
 *****************************************************************/
uint8_t
compute_cmd(int8_t ui8_distance) /* Recieves a duty cycle and calculates a corresponding command */
{
    if(i8_distance < 0) {return error;}
    else if(i8_distance == 0) {return fire;}
    else if(i8_distance <= 10) {return brake;}
    else if(i8_distance <= 30) {return decrease;}
    else if(i8_distance <= 60) {return maintain;}
    else{return error;}
}

