/*****************************************************************
 * Module Name: servAL_can.c
 * Author: Mustafa Ismail
 * Purpose: contains service layer components for the CAN BUS.
 *****************************************************************/

#include "servAL_can.h"

uint8_t pui8MsgDiagnostic_received[3];

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
 * Function Name: token_can_send
 * Inputs: void
 * Outputs: void
 * Description: Recieves a CAN message object with token
 *****************************************************************/
void
token_can_send(void) /*Send a CAN message object with token */
{
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)2, &sCANMessage_sent, MSG_OBJ_TYPE_TX);
}

/*****************************************************************
 * Function Name: distance_can_receive
 * Inputs: int8_t
 * Outputs: void
 * Description: 
 *****************************************************************/
int8_t
distance_can_receive(void) 
{
    CANMessageGet((uint32_t)CAN0_BASE, (uint32_t)4, &sCANMessageDistance_received, (uint8_t)0);
    return (int8_t)pui8MsgDistance_received[0];
}

/*****************************************************************
 * Function Name: command_can_receive
 * Inputs: void
 * Outputs: uint8_t
 * Description:Receives a CAN message with commands
 *****************************************************************/
uint8_t
command_can_receive(void) /* Receives a CAN message with commands */
{
    CANMessageGet((uint32_t)CAN0_BASE, (uint32_t)5, &sCANMessageCommand_received, (uint8_t)0);
    return (uint8_t)pui8MsgCommand_received[0];
}

/*****************************************************************
 * Function Name: diagnostic_can_receive
 * Inputs: void
 * Outputs: void
 * Description: Recieves a CAN message with diagnostic
 *****************************************************************/
void
diagnostic_can_receive(void) /* Recieves a CAN message with diagnostic */
{
    CANMessageGet((uint32_t)CAN0_BASE, (uint32_t)6, &sCANDiagnostic_received, (uint8_t)0);
}

/*****************************************************************
 * Function Name: diagnostic_can_send
 * Inputs: uint8_t,uint8_t,uint8_t
 * Outputs: void
 * Description: Sends a CAN message with diagnostic
 *****************************************************************/
void
diagnostic_can_send(uint8_t b1, uint8_t b2, uint8_t b3) /* Sends a CAN message with diagnostic */
{
    ui32MsgDiagnostic_sent[0] = b1;
    ui32MsgDiagnostic_sent[1] = b2;
    ui32MsgDiagnostic_sent[2] = b3;
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)7, &sCANDiagnostic_sent, MSG_OBJ_TYPE_TX);
}

/*****************************************************************
 * Function Name: create_diagnostic_send_object
 * Inputs: void
 * Outputs: void
 * Description: Initialize the message object of the diagnostic for
 *			    the token to be sent
 *****************************************************************/
void
create_diagnostic_send_object(void) /* Initialize the message object of the diagnostic for the token to be sent */	
{
    pui8MsgDiagnostic_sent = (uint8_t *)&ui32MsgDiagnostic_sent;

    ui32MsgDiagnostic_sent[0] = (uint8_t)0;
    ui32MsgDiagnostic_sent[1] = (uint8_t)0;
    ui32MsgDiagnostic_sent[2] = (uint8_t)0;
    sCANDiagnostic_sent.ui32MsgID = (uint32_t)7;
    sCANDiagnostic_sent.ui32MsgIDMask = (uint32_t)0;
    sCANDiagnostic_sent.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;
    sCANDiagnostic_sent.ui32MsgLen = (uint32_t)3;
    sCANDiagnostic_sent.pui8MsgData = pui8MsgDiagnostic_sent;
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)7, &sCANDiagnostic_sent, MSG_OBJ_TYPE_TX);
}

/*****************************************************************
 * Function Name: create_diagnostic_receive_object
 * Inputs: void
 * Outputs: void
 * Description: Initialize the message object of the diagnostic for
 *			    the token to be recieved
 *****************************************************************/
void
create_diagnostic_receive_object(void) /* Initialize the message object of the diagnostic for the token to be recieved */
{
    sCANDiagnostic_received.ui32MsgID = (uint32_t)6;
    sCANDiagnostic_received.ui32MsgIDMask = (uint32_t)0xFFFFFFFFU;
    sCANDiagnostic_received.ui32Flags = (uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER;
    sCANDiagnostic_received.ui32MsgLen = (uint32_t)3;
    sCANDiagnostic_received.pui8MsgData = pui8MsgDiagnostic_received;

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)6, &sCANDiagnostic_received, MSG_OBJ_TYPE_RX);
}

/*****************************************************************
 * Function Name: create_token_send_object
 * Inputs: void
 * Outputs: void
 * Description: Initialize the message object for the token to be 
 *				sent
 *****************************************************************/
void
create_token_send_object(void) /* Initialize the message object for the token to be sent */	
{
    pui8MsgData_sent = (uint8_t *)&ui32MsgData_sent;

    ui32MsgData_sent = (uint32_t)0;
    sCANMessage_sent.ui32MsgID = (uint32_t)1;
    sCANMessage_sent.ui32MsgIDMask = (uint32_t)0;
    sCANMessage_sent.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;
    sCANMessage_sent.ui32MsgLen = (uint32_t)1;
    sCANMessage_sent.pui8MsgData = pui8MsgData_sent;
}

/*****************************************************************
 * Function Name: create_token_receive_object
 * Inputs: void
 * Outputs: void
 * Description:Initialize the message object for the token to be 
 *				recieved
 *****************************************************************/
void
create_token_receive_object(void) /* Initialize the message object for the token to be recieved */	
{
    sCANMessage_received.ui32MsgID = (uint32_t)3;
    sCANMessage_received.ui32MsgIDMask = (uint32_t)0xFFFFFFFFU;
    sCANMessage_received.ui32Flags = (uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER;
    sCANMessage_received.ui32MsgLen = (uint32_t)1;
    sCANMessage_received.pui8MsgData = pui8MsgData_received;

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)1, &sCANMessage_received, MSG_OBJ_TYPE_RX);
}

/*****************************************************************
 * Function Name: create_distance_receive_object
 * Inputs: void
 * Outputs: void
 * Description:Initialize the message object for the distance to be 
 *              recieved
 *****************************************************************/
void
create_distance_receive_object(void) 
{
    sCANMessageDistance_received.ui32MsgID = (uint32_t)4;
    sCANMessageDistance_received.ui32MsgIDMask = (uint32_t)0xFFFFFFFFU;
    sCANMessageDistance_received.ui32Flags = (uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER;
    sCANMessageDistance_received.ui32MsgLen = (uint32_t)1;
    sCANMessageDistance_received.pui8MsgData = pui8MsgDistance_received;

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)4, &sCANMessageDistance_received, MSG_OBJ_TYPE_RX);
}

/*****************************************************************
 * Function Name: create_command_receive_object
 * Inputs: void
 * Outputs: void
 * Description: Initialize the message object for the command to 
 *				be recieved
 *****************************************************************/
void
create_command_receive_object(void) /* Initialize the message object for the command to be recieved */	
{
    sCANMessageCommand_received.ui32MsgID = (uint32_t)5;
    sCANMessageCommand_received.ui32MsgIDMask = (uint32_t)0xFFFFFFFFU;
    sCANMessageCommand_received.ui32Flags = (uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER;
    sCANMessageCommand_received.ui32MsgLen = (uint32_t)1;
    sCANMessageCommand_received.pui8MsgData = pui8MsgCommand_received;

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)5, &sCANMessageCommand_received, MSG_OBJ_TYPE_RX);
}
