// Comandos da Serial: abcfhgddddddddafiiiii

#include<Servo.h>

Servo s1,s2,s3;

int val,i;

int R=5,L=7;

void setup(){
  s1.attach(9);
  s2.attach(10);
  s3.attach(11);
  
  pinMode(R,OUTPUT);
  pinMode(L,OUTPUT);
  
  s1.write(85);
  s2.write(85);
  s3.write(85);
  
  Serial.begin(9600);
}

void loop(){
  

    
    val=Serial.read();
      
      if((val==65)||(val==97)){//letra a
          for(i=85;i>0;i--){
          s1.write(i);
          delay(5);
          }
      }
      
       if((val==66)||(val==98)){ // letra b
        
           for(i=85;i<140;i++){
          s2.write(i);
          delay(5);
          }
      }
      
       if((val==67)||(val==99)){ // letra c
        
           for(i=85;i>20;i--){
          s3.write(i);
          delay(5);
          }
        
      }
      
      if((val==77)||(val==109)){ // letra m
        
           for(i=170;i>85;i--){
          s3.write(i);
          delay(10);
          }
        
      }
      
      if((val==68)||(val==100)){//letra d
         
         digitalWrite(R,HIGH);
         delay(500);
         digitalWrite(R,LOW);

         
      }
//########################SOBE#####################  
      
        if((val==70)||(val==102)){//letra f
     
         for(i=0;i<85;i++){
         s1.write(i);
          delay(5);
}
        }
      
        if((val==71)||(val==103)){//letra g
     
         for(i=140;i>85;i--){
         s2.write(i);
          delay(5);
          }
        }
      
         if((val==72)||(val==104)){//letra h
     
         for(i=20;i<85;i++){
         s3.write(i);
          delay(5);
          }
        }
      
      if((val==73)||(val==105)){//letra i
         
         digitalWrite(L,HIGH);
         delay(500);
         digitalWrite(L,LOW);
         
      }
       
      if((val==74)||(val==106)){//letra j
         
         digitalWrite(L,LOW);
         digitalWrite(R,LOW);
         
      }
      
      if((val==76)||(val==108)){//letra l
     
         for(i=85;i<170;i++){
         s3.write(i);
          delay(10);
          }
        }
      
      delay(100);
}
