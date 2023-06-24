// input_FSM.h

#ifndef INPUT_FSM_H
#define INPUT_FSM_H

#include <Arduino.h>

class input {
<<<<<<< HEAD
    public:
    enum types{digital, pullup, analog};
    types type;

    int pin;
    int hold_ms_1, hold_ms_2;

=======
public:
    enum types { digital, pullup, analog };
    enum states { reading, delay, reRead };
    types type;
    states state;
    uint8_t pin;
    uint16_t hold_ms_1, hold_ms_2;
>>>>>>> 27f23ccd5fd7b0d5c1b21c6208ccfcc3d5fd229b
    input();
    void setInput(uint8_t pinNumber, types inputType = digital, uint16_t hold1 = 200, uint16_t hold2 = 1000);
    uint16_t getInput();
};

#endif