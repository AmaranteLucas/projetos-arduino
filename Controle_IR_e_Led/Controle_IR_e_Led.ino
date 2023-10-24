/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11,led=9;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    
  switch(results.value){
    case 16753245:
      Serial.println("LED Ligado");
      digitalWrite(led,HIGH);
      break;
    case 16736925:
      Serial.println("LED Apagado");
      digitalWrite(led,LOW);
      break;
  }
   irrecv.resume(); // Receive the next value
  }
  delay(100);
}
