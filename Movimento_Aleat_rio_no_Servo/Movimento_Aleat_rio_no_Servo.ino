#include<Servo.h>

Servo myservo;

long val;

void setup(){
  
  myservo.attach(9);
  
}

void loop(){
  
  val=random(0,179);
  
  myservo.write(val);
  
}
