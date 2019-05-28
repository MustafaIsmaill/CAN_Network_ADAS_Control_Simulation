/*****************************************************************
 * Module Name: app_sensor
 * Author: Mustafa Ismail
 * Purpose: Checks the current reading from the sensor and waits
 *			waits for a duty cycle to take action accordingly
 *****************************************************************/

#include "app_sensor.h"

uint8_t ui8_duty_cycle;
uint8_t ui8_prev_duty_cycle = 150;

int8_t i8_distance;
uint8_t ui8_command;

const uint32_t ui32_delay_ms = 10;

int8_t err_flag = -1;

/*****************************************************************
 * Function Name: isChanged
 * Inputs: void
 * Outputs: boolean
 * Description: checks if newly received diagnostic is the same
 *              as the previously received diagnostic or not and
 *              returns a boolean flag.
 *****************************************************************/
bool
isChanged(void) /* Checks if the current sensor reading is the same reading as the previous one to reduce proccessing power */
{
    if(ui8_duty_cycle == ui8_prev_duty_cycle){ return 0; } 
    else{ return 1; }
}

/*****************************************************************
 * Function Name: distance_sensor_runnable
 * Inputs: void
 * Outputs: void
 * Description: Gets a duty cycle to calculate the distance upon
 *			    which an action is taken
 *****************************************************************/
void
distance_sensor_runnable(void) /* Gets a duty cycle to calculate the distance upon which an action is taken */
{
    /* receive msg from sensor */
    ui8_duty_cycle = uart_receive();

    if(isChanged())
    {
        /* calculate distance */
        i8_distance = calc_distance(ui8_duty_cycle);

        /* compute command */
        ui8_command = compute_cmd(i8_distance);

        if(ui8_command == 69) { err_flag = 1; }
        else{ err_flag = 0; }

        /* send distance and command over CAN */
        UARTprintf("duty: %i \n", ui8_duty_cycle);
        UARTprintf("distance: %i \n", i8_distance);
        UARTprintf("cmd: %i \n", ui8_command);

        distance_can_send(i8_distance);
        command_can_send(ui8_command);

        delay_msec(ui32_delay_ms);
    }

    ui8_prev_duty_cycle = ui8_duty_cycle;
}

/*****************************************************************
 * Function Name: sensor_overwrite
 * Inputs: uint8_t
 * Outputs: void
 * Description: When a service from a diagnostic is called to 
 *				overwrite
 *****************************************************************/
void
sensor_overwrite(uint8_t dc) /* When a service from a diagnostic is called to overwrite */
{
    i8_distance = calc_distance(dc);
    ui8_command = compute_cmd(i8_distance);

    distance_can_send(i8_distance);
    command_can_send(ui8_command);
}

/*****************************************************************
 * Function Name: sensor_clear_error
 * Inputs: void
 * Outputs: void
 * Description: When a service from a diganostic is called to clear
 *				the error
 *****************************************************************/
void
sensor_clear_error(void) /* When a service from a diganostic is called to clear the error */ 
{
    distance_can_send((int8_t)0);
    command_can_send((uint8_t)80);
}
