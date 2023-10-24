/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;
int tecla;

IRrecv irrecv(RECV_PIN);

decode_results results;

//Dispositivos

int disp_1 = 2;
int disp_2 = 3;
int disp_3 = 4;
int disp_4 = 5;
int disp_5 = 6;
int disp_6 = 7;
int disp_7 = 8;
int disp_8 = 9;
int disp_9 = 10;

//Status inicial do dispositivo
int disp_1_state = LOW;
int disp_2_state = LOW;
int disp_3_state = LOW;
int disp_4_state = LOW;
int disp_5_state = LOW;
int disp_6_state = LOW;
int disp_7_state = LOW;
int disp_8_state = LOW;
int disp_9_state = LOW;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  irrecv.blink13(true);
  
  for(int i=2; i<=10; i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    
    tecla = results.value;
    
    Serial.println(tecla);
    
    switch(tecla)
    {
      //Tecla 1
      case 16695359:
      disp_1_state = !disp_1_state;
      break;
      
       //Tecla 2
      case 16662719:
      disp_2_state = !disp_2_state;
      break;
      
       //Tecla 3
      case 16679039:
      disp_3_state = !disp_3_state;
      break;
      
       //Tecla 4
      case 16703519:
      disp_4_state = !disp_4_state;
      break;
      
       //Tecla 5
      case 16670879:
      disp_5_state = !disp_5_state;
      break;
      
       //Tecla 6
      case 16687199:
      disp_6_state = !disp_6_state;
      break;
      
       //Tecla 7
      case 16699439:
      disp_7_state = !disp_7_state;
      break;
      
       //Tecla 8
      case 16666799:
      disp_8_state = !disp_8_state;
      break;
      
       //Tecla 9
      case 16683119:
      disp_9_state = !disp_9_state;
      break;
    }
    
    digitalWrite(disp_1,disp_1_state);
    digitalWrite(disp_2,disp_2_state);
    digitalWrite(disp_3,disp_3_state);
    digitalWrite(disp_4,disp_4_state);
    digitalWrite(disp_5,disp_5_state);
    digitalWrite(disp_6,disp_6_state);
    digitalWrite(disp_7,disp_7_state);
    digitalWrite(disp_8,disp_8_state);
    digitalWrite(disp_9,disp_9_state);
    
    irrecv.resume(); // Receive the next value
  }
  
  delay(100);
}
