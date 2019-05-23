#ifndef __SERVAL_CAN_H__
#define __SERVAL_CAN_H__

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

tCANMsgObject sCANMessage_received;
uint8_t pui8MsgData_received[1];

tCANMsgObject sCANMessage_sent;
uint32_t ui32MsgData_sent;
uint8_t *pui8MsgData_sent;

/* DISTANCE RECEIVE OBJECT */
tCANMsgObject sCANMessageDistance_received;
uint8_t pui8MsgDistance_received[1];

/* COMMAND RECEIVE OBJECT */
tCANMsgObject sCANMessageCommand_received;
uint8_t pui8MsgCommand_received[1];

void create_token_send_object(void);
void create_token_receive_object(void);
void create_distance_receive_object(void);
void create_command_receive_object(void);

void token_can_send(void);
void token_can_receive(void);
int8_t distance_can_receive(void);
int8_t command_can_receive(void);

#endif /*__SERVAL_CAN_H__*/
