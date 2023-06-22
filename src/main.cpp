#include <Arduino.h>
#include <input_FSM.h>

// put function declarations here:
int myFunction(int, int);

input pulsador1, llaveRotativa;

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}