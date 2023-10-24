// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo, servo_2;  // create servo object to control a servo 
 
int potpin = A0;  // analog pin used to connect the potentiometer
int val,val_2;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  servo_2.attach(6);
} 
 
void loop() 
{ 
  val = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023) 
  val_2 = analogRead(A1);    
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  val_2 = map(val_2, 0, 1023, 0, 179);
  myservo.write(val);                  // sets the servo position according to the scaled value 
  servo_2.write(179-val);
  delay(15);                           // waits for the servo to get there 
} 
