
/* 
 Stepper Motor Control - one revolution
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.  
 
  
 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe
 
 */

#include <Stepper.h>

const int stepsPerRevolution = 300;  // change this to fit the number of steps per revolution
int  rele=3;                                  // for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11); 
Stepper myStepper2(stepsPerRevolution, 4,5,6,7);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  myStepper2.setSpeed(60);
  pinMode(rele, OUTPUT);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
   Serial.println("clockwise");
  myStepper.step(stepsPerRevolution); 
  myStepper2.step(stepsPerRevolution);
  
  digitalWrite(rele,HIGH);
  delay(100);
  digitalWrite(rele,LOW);
  delay(500); 
  
  myStepper.step(stepsPerRevolution); 
  myStepper2.step(stepsPerRevolution);
  
  digitalWrite(rele,HIGH);
  delay(100);
  digitalWrite(rele,LOW);
  delay(500); 
  
  myStepper.step(stepsPerRevolution);
  myStepper2.step(stepsPerRevolution);
  
  delay(100);
  
  digitalWrite(rele,HIGH);
  delay(100);
  digitalWrite(rele,LOW);
  delay(500); 
  
   // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);  
  myStepper2.step(-stepsPerRevolution);
  
  digitalWrite(rele,HIGH);
  delay(100);
  digitalWrite(rele,LOW);
  delay(500); 
  
  myStepper.step(-stepsPerRevolution);   
  myStepper2.step(-stepsPerRevolution);
  
  digitalWrite(rele,HIGH);
  delay(100);
  digitalWrite(rele,LOW);
  delay(500); 
  
  myStepper.step(-stepsPerRevolution);   
  myStepper2.step(-stepsPerRevolution);
  
  delay(100); 
  
  digitalWrite(rele,HIGH);
  delay(100);
  digitalWrite(rele,LOW);
  delay(500);  
  
  
}

