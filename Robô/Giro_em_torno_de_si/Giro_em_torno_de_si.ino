#include <Servo.h>

Servo servo, servo_2;
 
int LDR=A0;
int led_dir=7;
int led_esq=6;

void setup()  
{  
   Serial.begin(9600); //inicia a porta serial  
   
   servo.attach(9);
   servo_2.attach(10);
   
   pinMode(led_dir,OUTPUT);
   pinMode(led_esq,OUTPUT);
}  
  
void loop()  
{  
   digitalWrite(led_dir,HIGH);
    digitalWrite(led_esq,HIGH);
  
    servo.write(180);
    servo_2.write(180);
    delay(3000);
    
    digitalWrite(led_dir,LOW);
    digitalWrite(led_esq,LOW); 
    
    servo.write(0);
    servo_2.write(0);
    delay(3000);
    
     
}  
 
    

