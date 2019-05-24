#include "ecual_lcd.h"

bool data8Bit = 0;

void lcdEnable(void) {
    GPIOPinWrite(LCD_GPIO_CTL_BASE, E_PIN, E_PIN);
    delay_us(5);
    GPIOPinWrite(LCD_GPIO_CTL_BASE, E_PIN, ~E_PIN);
    delay_us(5);
}

void lcdWriteData(uint8_t ui8Data) {
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

void lcdWriteCommand(uint8_t ui8Com) {
    GPIOPinWrite(LCD_GPIO_CTL_BASE, E_PIN, ~E_PIN);
    //GPIOPinWrite(LCD_GPIO_CTL_BASE, RW_PIN, ~RW_PIN);
    GPIOPinWrite(LCD_GPIO_CTL_BASE, RS_PIN, ~RS_PIN);
    lcdWriteData(ui8Com);
    delay_msec(5);
}

void lcdInit(uint8_t ui8FunctionSetOptions, uint8_t ui8EntryModeSetOptions, uint8_t ui8DisplayOptions) {

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
