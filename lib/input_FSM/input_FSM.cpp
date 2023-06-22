#include <Arduino.h>
#include <input_FSM.h>

input::input (){
    type = digital;
    hold_ms_1=200;
    hold_ms_2=1000;
}

void input::setInput(int pinNumber, types type, int hold1, int hold2){
    pin=pinNumber;
    type=type;
    hold_ms_1=hold1;
    hold_ms_2=hold2;
    switch (type)
    {
    case digital:
        pinMode(pin,INPUT);
        break;

    case pullup:
            pinMode(pin,INPUT);
            digitalWrite(pin, 1);//configura la resistencia de pullup - ver hoja de datos
            
        break;


    
    default:
        break;
    }
}

