#include "ecual_sensor.h"

void
sensor_overwrite(uint8_t dc)
{
    distance = calc_distance(dc);
    command = compute_cmd(distance);

    lcdClear();
    lcdWriteDistance(distance);
    print_cmd(command);
}

int8_t
calc_distance(uint8_t ui8_duty_cycle)
{
    return floor((0.75*ui8_duty_cycle)-7.5);
}

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

