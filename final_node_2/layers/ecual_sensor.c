#include "ecual_sensor.h"

int8_t
calc_distance(uint8_t ddc)
{
    return floor((0.75*ddc)-7.5);
}

uint8_t
compute_cmd(int8_t ui8_distance)
{
    if(i8_distance < 0) {return error;}
    else if(i8_distance == 0) {return fire;}
    else if(i8_distance <= 10) {return brake;}
    else if(i8_distance <= 30) {return decrease;}
    else if(i8_distance <= 60) {return maintain;}
    else{return error;}
}

