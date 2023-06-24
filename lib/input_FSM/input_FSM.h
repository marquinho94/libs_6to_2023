#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__)

// definicion de puines disponibles para pull up ?? 
 
#elif defined(__ARDUINO_ESP8266_NODEMCU_ESP12E__)

// definicion de puines disponibles para pull up ?? 


#else 

#warning "Unsupported board, check pins declarations"


#endif



#ifndef INPUT_FSM_H
#define INPUT_FSM_H

class input {
    public:
    enum types{digital, pullup, analog};
    types type;

    int pin;
    int hold_ms_1, hold_ms_2;

    input();
    void setInput(int pinNumber, types type, int hold1, int hold2);
    int getInput();
};





#endif

