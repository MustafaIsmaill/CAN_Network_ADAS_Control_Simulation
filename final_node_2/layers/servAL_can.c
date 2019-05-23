#include "servAL_can.h"

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
    ui32MsgDistance_sent = (uint32_t)dist;
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)4, &sCANDistance_sent, MSG_OBJ_TYPE_TX);
}

void
command_can_send(uint8_t cmd)
{
    ui32MsgCommand_sent = (uint32_t)cmd;
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)5, &sCANCommand_sent, MSG_OBJ_TYPE_TX);
}

void
diagnostic_can_receive(void)
{
    CANMessageGet((uint32_t)CAN0_BASE, (uint32_t)6, &sCANDiagnostic_received, (uint8_t)0);
    UARTprintf("%X\n", pui8MsgDiagnostic_received[0]);
    UARTprintf("%X\n", pui8MsgDiagnostic_received[1]);
    UARTprintf("%X\n", pui8MsgDiagnostic_received[2]);
}

void
create_diagnostic_receive_object(void)
{
    sCANDiagnostic_received.ui32MsgID = (uint32_t)6;
    sCANDiagnostic_received.ui32MsgIDMask = (uint32_t)0xFFFFFFFFU;
    sCANDiagnostic_received.ui32Flags = (uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER;
    sCANDiagnostic_received.ui32MsgLen = (uint32_t)3;
    sCANDiagnostic_received.pui8MsgData = pui8MsgDiagnostic_received;

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)6, &sCANDiagnostic_received, MSG_OBJ_TYPE_RX);
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
create_command_send_object(void)
{
    pui8MsgCommand_sent = (uint8_t *)&ui32MsgCommand_sent;

    ui32MsgCommand_sent = (uint32_t)0;
    sCANCommand_sent.ui32MsgID = (uint32_t)5;
    sCANCommand_sent.ui32MsgIDMask = (uint32_t)0;
    sCANCommand_sent.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;
    sCANCommand_sent.ui32MsgLen = (uint32_t)1;
    sCANCommand_sent.pui8MsgData = pui8MsgCommand_sent;
}
