#include <Arduino.h>
#include "input_FSM.h"

input::input()
{
    /* type = digital;
    hold_ms_1 = 200;
    hold_ms_2 = 1000;
    #warning "verificar los valores por defecto"
     */
}

<<<<<<< HEAD
void input::setInput(int pinNumber, types type = digital, int hold1=200, int hold2=200){
    pin=pinNumber;
    type=type;
    hold_ms_1=hold1;
    hold_ms_2=hold2;
=======
void input::setInput(uint8_t pinNumber, types inputType, uint16_t hold1, uint16_t hold2)
{
    type = inputType;
    hold_ms_1 = hold1;
    hold_ms_2 = hold2;
    state = reading;

>>>>>>> 27f23ccd5fd7b0d5c1b21c6208ccfcc3d5fd229b
    switch (type)
    {
    case digital:
        pinMode(pin, INPUT);
        break;

    case pullup:
        pinMode(pin, INPUT);
        digitalWrite(pin, HIGH); // configura la resistencia de pullup - ver hoja de datos
        break;

    case analog:
        pinMode(pin, INPUT);
        break;

    default:
        pinMode(pin, INPUT);
        
        break;
    }
}

<<<<<<< HEAD

=======
uint16_t input::getInput()
{
    static uint8_t count = 0;
    static uint32_t holder1 = 0;
    static uint32_t holder2 = 0;
    static bool hold_1_flag = true;

    if (millis() >= holder1 + hold_ms_1)
    {
        hold_1_flag = true;
    };

    switch (state)
    {
    case reading:

        break;

    default:
        break;
    };
}
>>>>>>> 27f23ccd5fd7b0d5c1b21c6208ccfcc3d5fd229b
