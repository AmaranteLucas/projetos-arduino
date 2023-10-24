#include<Servo.h>

Servo myservo;

int val,red=2,green=3,blue=4;

void setup(){
  
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  
  Serial.begin(9600);
  myservo.attach(10);
  
}

void loop(){

  val=Serial.read();
  
  if(val==65||val==97){ // Se for enviado pela serial a letra A ou a 
                        // o servo vai para 0 grau.
    myservo.write(0); 
    
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    
    Serial.println("O servo esta a 0 grau");

  }
  
  if(val==68||val==100){ // Se for enviado pela serial a letra D ou d
                         // o servo vai para 90 graus.
    myservo.write(90);
    
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
    
    Serial.println("O servo esta a 90 graus");
  
  }
  
  if(val==71||val==103){ // E se for enviado pela serial a letra G ou g
                         // o servo vai para 180 graus.
    myservo.write(180);
    
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
    
    Serial.println("O servo esta a 180 graus");
    
  }
  

}
