#include <Arduino.h>
#include <input_FSM.h>



input A,B,C,D,E,F,G;
void setup() {

  A.setInput(2);
  B.setInput(3);
  C.setInput(4);
  D.setInput(5);
  E.setInput(6);
  F.setInput(7);
  G.setInput(8);



}

void loop() {








  int a,b,c,d,e,f,g;
  a=A.getInput();
  b=B.getInput();
  c=C.getInput();
  d=D.getInput();
  e=E.getInput();
  f=F.getInput();
  g=G.getInput();

  Serial.println("hola");
}

