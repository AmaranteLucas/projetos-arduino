#include<Servo.h>

int botao=6,val,inc=0,i,j;

Servo servo;

void setup(){
  
  pinMode(botao,INPUT);
  servo.attach(9);

}

void loop(){
  
val=digitalRead(botao);

 if(val==HIGH){
   
   inc=inc+1;
 
 if(inc%2!=0){
   
   servo.write(0);
 }
 else{
   servo.write(180);
 }
 }
 
 delay(150);
 
}
   
   
   
   
   
   
   
   
   
   
   
