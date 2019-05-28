/*****************************************************************
 * Module Name: servAL_can.c
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the CAN BUS.
 *****************************************************************/

#include "servAL_can.h"

uint8_t pui8MsgDiagnostic_received[3];

/*****************************************************************
 * Function Name: token_can_send
 * Inputs: void
 * Outputs: void
 * Description: Send a CAN message object with token
 *****************************************************************/

void
token_can_send(void) /*Send a CAN message object with token */
{
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)2, &sCANMessage_sent, MSG_OBJ_TYPE_TX);
}
/*****************************************************************
 * Function Name: token_can_receive
 * Inputs: void
 * Outputs: void
 * Description: Recieves a CAN message object with token
 *****************************************************************/
void
token_can_receive(void) /*Recieves a CAN message object with token */
{
    CANMessageGet((uint32_t)CAN0_BASE, (uint32_t)1, &sCANMessage_received, (uint8_t)0);
}
/*****************************************************************
 * Function Name: diagnostic_can_send
 * Inputs: uint8_t b1, uint8_t b2, uint8_t b3
 * Outputs: void
 * Description: Sends a CAN message with diagnostic
 *****************************************************************/
void
diagnostic_can_send(uint8_t b1, uint8_t b2, uint8_t b3) /* Sends a CAN message with diagnostic */
{
{
    ui32MsgDiagnostic_sent[0] = b1;
    ui32MsgDiagnostic_sent[1] = b2;
    ui32MsgDiagnostic_sent[2] = b3;
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)6, &sCANDiagnostic_sent, MSG_OBJ_TYPE_TX);
}
/*****************************************************************
 * Function Name: diagnostic_can_send
 * Inputs: void
 * Outputs: void
 * Description: Recieves a CAN message with diagnostic
 *****************************************************************/
void
diagnostic_can_receive(void) /* Recieves a CAN message with diagnostic */
{
    CANMessageGet((uint32_t)CAN0_BASE, (uint32_t)7, &sCANDiagnostic_received, (uint8_t)0);
}
/*****************************************************************
 * Function Name: diagnostic_can_send
 * Inputs: void
 * Outputs: void
 * Description: Initialize the message object of the diagnostic 
 *              for the token to be recieved
 *****************************************************************/
void
create_diagnostic_receive_object(void) /* Initialize the message object of the diagnostic for the token to be recieved */
{
    sCANDiagnostic_received.ui32MsgID = (uint32_t)7;
    sCANDiagnostic_received.ui32MsgIDMask = (uint32_t)0xFFFFFFFFU;
    sCANDiagnostic_received.ui32Flags = (uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER;
    sCANDiagnostic_received.ui32MsgLen = (uint32_t)3;
    sCANDiagnostic_received.pui8MsgData = pui8MsgDiagnostic_received;

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)7, &sCANDiagnostic_received, MSG_OBJ_TYPE_RX);
}
/*****************************************************************
 * Function Name: diagnostic_can_send
 * Inputs: void
 * Outputs: void
 * Description: Initialize the message object of the diagnostic 
 *              for the token to be sent
 *****************************************************************/
void
create_diagnostic_send_object(void) /* Initialize the message object of the diagnostic for the token to be sent */
{
    pui8MsgDiagnostic_sent = (uint8_t *)&ui32MsgDiagnostic_sent;

    ui32MsgDiagnostic_sent[0] = 0;
    ui32MsgDiagnostic_sent[1] = 0;
    ui32MsgDiagnostic_sent[2] = 0;
    sCANDiagnostic_sent.ui32MsgID = (uint32_t)6;
    sCANDiagnostic_sent.ui32MsgIDMask = (uint32_t)0;
    sCANDiagnostic_sent.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;
    sCANDiagnostic_sent.ui32MsgLen = (uint32_t)3;
    sCANDiagnostic_sent.pui8MsgData = pui8MsgDiagnostic_sent;
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)6, &sCANDiagnostic_sent, MSG_OBJ_TYPE_TX);
}
/*****************************************************************
 * Function Name: diagnostic_can_send
 * Inputs: void
 * Outputs: void
 * Description: Initialize the message object for the token to be 
 *              recieved
 *****************************************************************/
void
create_token_receive_object(void) /* Initialize the message object for the token to be recieved */
{
    sCANMessage_received.ui32MsgID = (uint32_t)1;
    sCANMessage_received.ui32MsgIDMask = (uint32_t)0xFFFFFFFFU;
    sCANMessage_received.ui32Flags = (uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER;
    sCANMessage_received.ui32MsgLen = (uint32_t)1;
    sCANMessage_received.pui8MsgData = pui8MsgData_received;

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)1, &sCANMessage_received, MSG_OBJ_TYPE_RX);
}
/*****************************************************************
 * Function Name: diagnostic_can_send
 * Inputs: void
 * Outputs: void
 * Description: Initialize the message object for the token to be 
 *              sent
 *****************************************************************/

void
create_token_send_object(void) /* Initialize the message object for the token to be sent */	
{
    pui8MsgData_sent = (uint8_t *)&ui32MsgData_sent;

    ui32MsgData_sent = (uint32_t)0;
    sCANMessage_sent.ui32MsgID = (uint32_t)2;
    sCANMessage_sent.ui32MsgIDMask = (uint32_t)0;
    sCANMessage_sent.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;
    sCANMessage_sent.ui32MsgLen = (uint32_t)1;
    sCANMessage_sent.pui8MsgData = pui8MsgData_sent;
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)2, &sCANMessage_sent, MSG_OBJ_TYPE_TX);
}
