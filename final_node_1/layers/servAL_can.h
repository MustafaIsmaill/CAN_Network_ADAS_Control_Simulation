/*****************************************************************
 * Module Name: servAL_can.h
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the CAN BUS.
 *****************************************************************/

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

/* TOKEN RECEIVE MSG */
tCANMsgObject sCANMessage_received;
uint8_t pui8MsgData_received[1];

/* TOKEN SEND MSG */
tCANMsgObject sCANMessage_sent;
uint32_t ui32MsgData_sent;
uint8_t *pui8MsgData_sent;

/* DIAGNOSTIC SEND MSG */
tCANMsgObject sCANDiagnostic_sent;
uint8_t ui32MsgDiagnostic_sent[3];
uint8_t *pui8MsgDiagnostic_sent;

/* DIAGNOSTIC RECEIVE OBJECT */
tCANMsgObject sCANDiagnostic_received;
extern uint8_t pui8MsgDiagnostic_received[3];

void create_token_send_object(void);
void create_token_receive_object(void);
void create_diagnostic_receive_object(void);
void create_diagnostic_send_object(void);

void token_can_send(void);
void token_can_receive(void);
void diagnostic_can_send(uint8_t b1, uint8_t b2, uint8_t b3);
void diagnostic_can_receive(void);

#endif /*__SERVAL_CAN_H__*/
