/*****************************************************************
 * Module Name: ecual_sensor
 * Author: Mustafa Ismail
 * Purpose: Calculates the duty cycles and calculates commands
 *****************************************************************/

#include "ecual_sensor.h"

/*****************************************************************
 * Function Name: sensor_overwrite
 * Inputs: uint8_t duty cycle
 * Outputs: void
 * Description: If the service from the diagnostic is called to 
 *				override the sensor
 *****************************************************************/
void
sensor_overwrite(uint8_t dc)
{
    distance = calc_distance(dc);
    command = compute_cmd(distance);

    lcdClear();
    lcdWriteDistance(distance);
    print_cmd(command);
}

/*****************************************************************
 * Function Name: calc_distance
 * Inputs: uint8_t duty cycle
 * Outputs: int8_t distance
 * Description: Calculates the distance 
 *****************************************************************/
int8_t
calc_distance(uint8_t ui8_duty_cycle) /*Calculates the distance */
{
    return floor((0.75*ui8_duty_cycle)-7.5);
}

/*****************************************************************
 * Function Name: compute_cmd
 * Inputs: uint8_t command
 * Outputs: int8_t distance
 * Description: Computes the commanc according to the duty cycle
 *****************************************************************/
uint8_t
compute_cmd(int8_t i8_distance)
{
    if(i8_distance < 0) {return error;}
    else if(i8_distance == 0) {return fire;}
    else if(i8_distance <= 10) {return brake;}
    else if(i8_distance <= 30) {return decrease;}
    else if(i8_distance <= 60) {return maintain;}
    else{return error;}
}

