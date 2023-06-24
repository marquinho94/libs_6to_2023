// input_FSM.h

#ifndef INPUT_FSM_H
#define INPUT_FSM_H

#include <Arduino.h>

class input {
public:
    input();
    enum types { digital, pullup, analog };
    enum states { reading, delay, reRead };
    types type;
    states state;
    uint8_t pin;
    uint16_t hold_ms_1, hold_ms_2;
    int baseState;
    void setInput(uint8_t pinNumber, types inputType = digital, uint16_t hold1 = 200, uint16_t hold2 = 1000);
    void changeBaseState(int base = HIGH);
    uint16_t getInput();
};

#endif