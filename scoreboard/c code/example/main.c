#include <wiringPi.h>
#include <lcd.h>

#define LCD_RS  25
#define LCD_E   24
#define LCD_D4  23
#define LCD_D5  22
#define LCD_D6  21
#define LCD_D7  14


int main()
{
    int lcd;
    wiringPiSetup();
    lcd = lcdInit(2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);

    lcdPosition(lcd,6,0);
    lcdPuts(lcd, "15");

    lcdPosition(lcd,8,0);
    lcdPuts(lcd, ":");

    lcdPosition(lcd,9,0);
    lcdPuts(lcd, "00");

    lcdPosition(lcd,0,1);
    lcdPuts(lcd, "H: 00");
    
    lcdPosition(lcd,8,1);
    lcdPuts(lcd, "4");

    lcdPosition(lcd,11,1);
    lcdPuts(lcd, "G: 00");

    return 0;


}
