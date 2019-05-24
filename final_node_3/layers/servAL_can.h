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
#include "layers/app_diagnostic.h"

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

/* DIAGNOSTIC RECEIVE OBJECT */
tCANMsgObject sCANDiagnostic_received;
extern uint8_t pui8MsgDiagnostic_received[3];

/* DIAGNOSTIC SEND MSG */
tCANMsgObject sCANDiagnostic_sent;
uint8_t ui32MsgDiagnostic_sent[3];
uint8_t *pui8MsgDiagnostic_sent;

void create_token_send_object(void);
void create_token_receive_object(void);
void create_distance_receive_object(void);
void create_command_receive_object(void);
void create_diagnostic_receive_object(void);
void create_diagnostic_send_object(void);

void token_can_send(void);
void token_can_receive(void);
int8_t distance_can_receive(void);
uint8_t command_can_receive(void);
void diagnostic_can_receive(void);
void diagnostic_can_send(uint8_t b1, uint8_t b2, uint8_t b3);

#endif /*__SERVAL_CAN_H__*/
