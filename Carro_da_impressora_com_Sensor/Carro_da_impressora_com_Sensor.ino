#include <Stepper.h>
const int stepsPerRevolution = 300; 
Stepper myStepper(stepsPerRevolution, 8,9,10,11);

#define echoPin 6 //Pino 6 recebe o pulso do echo  
#define trigPin 5 //Pino 5 envia o pulso para gerar o echo  
  
void setup(){  
  
  myStepper.setSpeed(60);
   Serial.begin(9600); //inicia a porta serial  
   pinMode(echoPin, INPUT); 
   pinMode(trigPin, OUTPUT); 
}  
  
void loop(){  
 
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);   
    digitalWrite(trigPin, LOW);  
    long duration = pulseIn(echoPin,HIGH);  
    long distancia = duration /29 / 2 ;  
  
Serial.print("Distancia em CM: ");  
Serial.println(distancia);  


if((distancia>=3)&&(distancia<=22)){
myStepper.step(-100);
}
if(distancia>22){
  myStepper.step(900);
}

delay(200); 

}  
