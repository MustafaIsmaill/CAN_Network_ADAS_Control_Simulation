#include "app_sensor.h"

uint8_t ui8_duty_cycle;
uint8_t ui8_prev_duty_cycle = 150;

int8_t i8_distance;
uint8_t ui8_command;

const uint32_t ui32_delay_ms = 10;

bool
isChanged(void)
{
    if(ui8_duty_cycle == ui8_prev_duty_cycle){ return 0; }
    else{ return 1; }
}

void
distance_sensor_runnable(void)
{
    /* receive msg from sensor */
    ui8_duty_cycle = uart_receive();

    if(isChanged())
    {
        /* calculate distance */
        i8_distance = calc_distance(ui8_duty_cycle);

        /* compute command */
        ui8_command = compute_cmd(i8_distance);

        /* send distance and command over CAN */
        UARTprintf("duty: %i \n", ui8_duty_cycle);
        UARTprintf("distance: %i \n", i8_distance);
        UARTprintf("cmd: %i \n", ui8_command);

        distance_can_send(i8_distance);

        delay_msec(ui32_delay_ms);
    }

    ui8_prev_duty_cycle = ui8_duty_cycle;
}
