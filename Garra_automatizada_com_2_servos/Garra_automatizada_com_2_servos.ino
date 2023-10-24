#include<Servo.h>

Servo myservo;
Servo myservo2;
int i,j,val,t=5,G=85; // G graus, t tempo.

void setup(){

 
  myservo.attach(9);
  myservo2.attach(10);
  
} 

void loop(){

  for(i=0; i<=G; i++){
  
    
   myservo.write(i);
   myservo2.write(G-i);
   val=myservo2.read();
   
   Serial.println(val);
   
   
   delay(t);
  
  }
  
  delay(1000);
  
  for(j=0; j<=G; j++){
  
  myservo.write(G-j);
  myservo2.write(j);
  
  delay(t);
  
  }
  
  delay(1000);
  
  
}
