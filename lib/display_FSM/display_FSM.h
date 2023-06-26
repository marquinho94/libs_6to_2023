#ifndef DISPLAY_FSM_H
#define DISPLAY_FSM_H

    #ifndef ARDUINO_H
    #include <Arduino.h>
    #endif
    //HAY QUE INCLUIR ALGUNA LIBRERÍA PARA GESTIONAR EL LCD
    #ifndef LIQUIDCRYSTAL_H
    #include <LiquidCrystal.h>
    #endif 

void displaySet (int cols, int rows ,const int rs = 12,const int en = 11,const int d4 = 5,const int d5 = 4,const int d6 = 3,const int d7 = 2);











#endif