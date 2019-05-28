/*****************************************************************
 * Module Name: servAL_lcd
 * Author: Mustafa Ismail
 * Purpose: Initializations and writing data to the lcd
 *****************************************************************/

#include "servAL_lcd.h"
/*****************************************************************
 * Function Name: lcdStartup
 * Inputs: void
 * Outputs: void
 * Description: Startup function for the lcd
 *****************************************************************/
void
lcdStartup(void) /*Startup function for the lcd */
{
    lcdWriteString("     MCT411");
    lcdGoToXY((uint8_t)0, (uint8_t)1);
    lcdWriteString(" start-up state ");
}

/*****************************************************************
 * Function Name:lcdWriteChar
 * Inputs: char
 * Outputs: void
 * Description: Writes a charachter to the LCD
 *****************************************************************/
void
lcdWriteChar(char cChar) /*Writes a charachter to the LCD */
{
    GPIOPinWrite(LCD_GPIO_CTL_BASE, E_PIN, ~E_PIN);
    //GPIOPinWrite(LCD_GPIO_CTL_BASE, RW_PIN, ~RW_PIN);
    GPIOPinWrite(LCD_GPIO_CTL_BASE, RS_PIN, RS_PIN);
    lcdWriteData(cChar);
    delay_us(100);
}

/*****************************************************************
 * Function Name: lcdWriteString
 * Inputs: char
 * Outputs: void
 * Description: Writes a string to the LCD
 *****************************************************************/
void
lcdWriteString(char * s) /*Writes a string to the LCD */
{
    while (*s) {
        lcdWriteChar(*s);
        s ++;
    }
}

/*****************************************************************
 * Function Name: lcdWriteDistance
 * Inputs: uint8_t
 * Outputs: void
 * Description: Writes the distance to the LCD
 *****************************************************************/
void
lcdWriteDistance(uint8_t num) /*Writes the distance to the LCD */
{
    char buf[3] = {0,0,0};
    itoa(num, buf, (uint8_t)10);

    lcdGoToXY((uint8_t)0, (uint8_t)0);
    lcdWriteString("Distance: ");
    lcdWriteString(buf);
}

/*****************************************************************
 * Function Name: lcdWriteCmd
 * Inputs: char
 * Outputs: void
 * Description: Writes the command to the LCD
 *****************************************************************/
void
lcdWriteCmd(char* cmd) /*Writes the command to the LCD */
{
    lcdGoToXY((uint8_t)0, (uint8_t)1);
    lcdWriteString(cmd);
}

/*****************************************************************
 * Function Name:lcdClear
 * Inputs: void
 * Outputs: void
 * Description: Clears the LCD
 *****************************************************************/
void
lcdClear(void) /*Clears the LCD */
{
    lcdWriteCommand(CLEAR_DISPLAY);
}

/*****************************************************************
 * Function Name:lcdGoToXY
 * Inputs: uint8_t,uint8_t
 * Outputs: void
 * Description: Go to cursor position
 *****************************************************************/
void
lcdGoToXY(uint8_t ui8X, uint8_t ui8Y) /*Go to cursor position */
{
    uint8_t ui8Address;
    // Specify the address
    if (ui8Y == 0) {
        ui8Address = 0x00 + ui8X;
    }
    else {
        ui8Address = 0x40 + ui8X;
    }
    // Set the bit for cursor moving command
    ui8Address |= 0x80;
    lcdWriteCommand(ui8Address);
}