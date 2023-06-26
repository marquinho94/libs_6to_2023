#include <Arduino.h>
#include <input_FSM.h>
#include <display_FSM.h>


input A;

void setup() {
    Serial.begin(9600);
    A.setInput(8);
    displaySet(16,2);




}

void loop() {
    int a;
    while (true)
    {
        a=A.getInput();
        Serial.println(a);
        delay(200);
    }

}

