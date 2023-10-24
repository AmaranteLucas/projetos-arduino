

#include <Servo.h> 
 
Servo servo1,servo2,servo3;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
 int t=1000;
 
void setup() 
{ 
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  servo2.attach(10);
  servo3.attach(11);
} 
 
 
void loop(){
  
  servo1.write(0);
  delay(500);
  servo1.write(180);
  delay(t);
  
  servo2.write(0);
  delay(500);
  servo2.write(180);
  delay(t);
  
  servo3.write(0);
  delay(500);
  servo3.write(180);
  delay(t);
} 
