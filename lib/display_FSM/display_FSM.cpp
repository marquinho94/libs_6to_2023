#include "display_FSM.h"

void displaySet (int cols, int rows,const int rs = 12,const int en = 11,const int d4 = 5,const int d5 = 4,const int d6 = 3,const int d7 = 2)
{
    LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
    lcd.begin(cols, rows);
    lcd.display();
    lcd.println("init OK");

}

