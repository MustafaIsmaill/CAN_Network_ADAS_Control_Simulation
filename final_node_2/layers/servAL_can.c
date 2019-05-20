#include "servAL_can.h"

#define ZERO    0U

/* TOKEN RECEIVE OBJECT */
tCANMsgObject sCANMessage_received;
uint8_t pui8MsgData_received[1];

/* TOKEN SEND OBJECT */
tCANMsgObject sCANMessage_sent;
uint32_t ui32MsgData_sent;
uint8_t *pui8MsgData_sent;

/* DISTANCE SEND OBJECT */
tCANMsgObject sCANDistance_sent;
uint32_t ui32MsgDistance_sent;
uint8_t *pui8MsgDistance_sent;

void
token_can_receive(void)
{
    CANMessageGet((uint32_t)CAN0_BASE, (uint32_t)1, &sCANMessage_received, ZERO);
}

void
token_can_send(void)
{
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)2, &sCANMessage_sent, MSG_OBJ_TYPE_TX);
}

void
distance_can_send(int8_t dist)
{
    pui8MsgDistance_sent[0] = dist;
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)4, &sCANDistance_sent, MSG_OBJ_TYPE_TX);
}

void
create_distance_send_object(void)
{
    pui8MsgDistance_sent = (uint8_t *)&ui32MsgDistance_sent;

    ui32MsgDistance_sent = (uint32_t)0;
    sCANDistance_sent.ui32MsgID = (uint32_t)4;
    sCANDistance_sent.ui32MsgIDMask = (uint32_t)0;
    sCANDistance_sent.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;
    sCANDistance_sent.ui32MsgLen = (uint32_t)1;
    sCANDistance_sent.pui8MsgData = pui8MsgDistance_sent;
}

void
create_token_receive_object(void)
{
    sCANMessage_received.ui32MsgID = (uint32_t)2;
    sCANMessage_received.ui32MsgIDMask = (uint32_t)0xFFFFFFFFU;
    sCANMessage_received.ui32Flags = (uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER;
    sCANMessage_received.ui32MsgLen = (uint32_t)1;
    sCANMessage_received.pui8MsgData = pui8MsgData_received;

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)1, &sCANMessage_received, MSG_OBJ_TYPE_RX);
}

void
create_token_send_object(void)
{
    pui8MsgData_sent = (uint8_t *)&ui32MsgData_sent;

    ui32MsgData_sent = (uint32_t)0;
    sCANMessage_sent.ui32MsgID = (uint32_t)3;
    sCANMessage_sent.ui32MsgIDMask = (uint32_t)0;
    sCANMessage_sent.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;
    sCANMessage_sent.ui32MsgLen = (uint32_t)1;
    sCANMessage_sent.pui8MsgData = pui8MsgData_sent;
}
