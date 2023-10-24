#include <IRremote.h>
#include<Servo.h>

int RECV_PIN = 7; //Pino do receptor IR.

int val;

Servo myservo;

IRrecv irrecv(RECV_PIN);

decode_results results;

//Rotina de configurações iniciais do Arduino.

void setup(){
 
  myservo.attach(9);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  
  if (irrecv.decode(&results)) {
   
   long int decCode = results.value;
   
   switch(decCode){
     
     case 16754775: // Caso pressione a tecla "vol +" ...
     
       for( val=0;val<80;val++){
       myservo.write(val);
       delay(5);
       }
       break;
       
     case 16769055: // Caso pressione a tecla "vol -"...
       
       for( val=90;val>=0;val--){
       myservo.write(val);
       delay(5);
       }
       break;
   }
    irrecv.resume(); // Recebe o próximo valor.
  }
  delay(100);
}
