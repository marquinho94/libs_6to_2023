#include <Arduino.h>
#include <input_FSM.h>

input::input (){
    type = digital; //verificar los parámtros por defecto 
    hold_ms_1=200;
    hold_ms_2=1000;
    #warning " verificar los valores por defecto "
}

void input::setInput(int pinNumber, types type = digital, int hold1=200, int hold2=200){
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

    case analog:
        pinMode(pin,analog);
        break;


    
    default:
        pinMode(pin,INPUT);
        #warning "input not defined" 
        break;
    }
}


