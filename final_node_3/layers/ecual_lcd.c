/*****************************************************************
 * Module Name: ecual_lcd
 * Author: Mustafa Ismail
 * Purpose: Enables the lcd and writes commands and data
 *****************************************************************/

#include "ecual_lcd.h"

bool data8Bit = 0;

/*****************************************************************
 * Function Name: lcdEnable
 * Inputs: void
 * Outputs: void
 * Description:Enables the lcd
 *****************************************************************/
void lcdEnable(void) { /*Enables the lcd */
    GPIOPinWrite(LCD_GPIO_CTL_BASE, E_PIN, E_PIN);
    delay_us(5);
    GPIOPinWrite(LCD_GPIO_CTL_BASE, E_PIN, ~E_PIN);
    delay_us(5);
}

/*****************************************************************
 * Function Name: lcdWriteData
 * Inputs: uint8_t
 * Outputs: void
 * Description:writes data to the lcd
 *****************************************************************/
void lcdWriteData(uint8_t ui8Data) { /*writes data to the lcd */
    if (data8Bit) {
        GPIOPinWrite(LCD_GPIO_DATA_BASE, DATA_PINS, ui8Data);
        lcdEnable();
    }
    else {
        GPIOPinWrite(LCD_GPIO_DATA_BASE, DATA_PINS, ui8Data & 0xF0); //send the rest 4-bits
        lcdEnable();
        GPIOPinWrite(LCD_GPIO_DATA_BASE, DATA_PINS, (ui8Data & 0x0F) << 4); //send first 4-bits
        lcdEnable();
    }
}

/*****************************************************************
 * Function Name: lcdWriteCommand
 * Inputs: uint8_t
 * Outputs: void
 * Description: writes command to the lcd
 *****************************************************************/
void lcdWriteCommand(uint8_t ui8Com) { /*writes command to the lcd */
    GPIOPinWrite(LCD_GPIO_CTL_BASE, E_PIN, ~E_PIN);
    //GPIOPinWrite(LCD_GPIO_CTL_BASE, RW_PIN, ~RW_PIN);
    GPIOPinWrite(LCD_GPIO_CTL_BASE, RS_PIN, ~RS_PIN);
    lcdWriteData(ui8Com);
    delay_msec(5);
}

/*****************************************************************
 * Function Name:lcdInit
 * Inputs: uint8_t, uint8_t,uint8_t
 * Outputs: void
 * Description: Initialize lcd at GPIO port A
 *****************************************************************/
void lcdInit(uint8_t ui8FunctionSetOptions, uint8_t ui8EntryModeSetOptions, uint8_t ui8DisplayOptions) { /*Initialize lcd */

    SysCtlPeripheralEnable(LCD_GPIO_DATA_PERIPH);
    SysCtlPeripheralEnable(LCD_GPIO_CTL_PERIPH);

    HWREG(LCD_GPIO_DATA_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(LCD_GPIO_DATA_BASE + GPIO_O_CR) |= 0x80;

    GPIOPinTypeGPIOOutput(LCD_GPIO_DATA_BASE, DATA_PINS);
    GPIOPinTypeGPIOOutput(LCD_GPIO_CTL_BASE, E_PIN | RS_PIN);

    data8Bit = (ui8FunctionSetOptions & FUNCTION_SET_8_BIT) > 0;

    delay_msec(20);

    lcdWriteCommand(0x30);
    delay_msec(20);
    lcdWriteCommand(0x30);
    delay_msec(20);
    lcdWriteCommand(0x30);
    delay_msec(20);

    if (!data8Bit) {
        lcdWriteCommand(0x20);
        delay_msec(20);
    }

    lcdWriteCommand(FUNCTION_SET_BASE | ui8FunctionSetOptions);
    lcdWriteCommand(ENTRY_MODE_SET_BASE | ui8EntryModeSetOptions);
    lcdWriteCommand(DISPLAY_BASE | ui8DisplayOptions);
    lcdWriteCommand(CLEAR_DISPLAY);
}
