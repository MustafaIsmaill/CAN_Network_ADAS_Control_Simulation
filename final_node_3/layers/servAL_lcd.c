#include "servAL_lcd.h"

void
lcdStartup(void)
{
    lcdWriteString("     MCT411");
    lcdGoToXY((uint8_t)0, (uint8_t)1);
    lcdWriteString(" start-up state ");
}

void
lcdWriteChar(char cChar)
{
    GPIOPinWrite(LCD_GPIO_CTL_BASE, E_PIN, ~E_PIN);
    //GPIOPinWrite(LCD_GPIO_CTL_BASE, RW_PIN, ~RW_PIN);
    GPIOPinWrite(LCD_GPIO_CTL_BASE, RS_PIN, RS_PIN);
    lcdWriteData(cChar);
    delay_us(100);
}

void
lcdWriteString(char * s)
{
    while (*s) {
        lcdWriteChar(*s);
        s ++;
    }
}

void
lcdWriteDistance(uint8_t num)
{
    char buf[3] = {0,0,0};
    itoa(num, buf, (uint8_t)10);

    lcdGoToXY((uint8_t)0, (uint8_t)0);
    lcdWriteString("Distance: ");
    lcdWriteString(buf);
}

void
lcdWriteCmd(char* cmd)
{
    lcdGoToXY((uint8_t)0, (uint8_t)1);
    lcdWriteString(cmd);
}

void
lcdClear(void)
{
    lcdWriteCommand(CLEAR_DISPLAY);
}

void
lcdGoToXY(uint8_t ui8X, uint8_t ui8Y)
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