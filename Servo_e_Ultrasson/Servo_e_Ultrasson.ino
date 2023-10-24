#include <Servo.h>

Servo myservo;

int val;

#define echoPin 6 //Pino 6 recebe o pulso do echo  
#define trigPin 5 //Pino 5 envia o pulso para gerar o echo  
  
void setup(){  
  
   myservo.attach(9);
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

val=map(distancia,30,5,0,180);

myservo.write(val);


delay(200); 

}  
