
#include<Servo.h>

Servo s1,s2,s3;

int val,i;


void setup(){
  
  s1.attach(9);
  s2.attach(10);
  s3.attach(11);
  
  s1.write(85);
  s2.write(0);
  s3.write(180);
  
  Serial.begin(9600);
  
}

void loop(){
  
    val=Serial.read();
      
    
      if((val==65)||(val==97)){//letra a
      
          s1.write(85);
          for(i=0;i<180;i++){
          s3.write(i);
          s2.write(180-i);
          delay(5);
          }
      }
      
       if((val==66)||(val==98)){ // letra b
        
           
           for(i=180;i>0;i--){
             s2.write(180-i);
             s3.write(i); 
             delay(5);
          }
          s1.write(0);
      }
 
      delay(100);
}
