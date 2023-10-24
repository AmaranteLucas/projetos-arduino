
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

int val,val2,pot=A0;                                    // for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

void setup() {
  // set the speed at 60 rpm:
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  
  val=analogRead(pot);
  
  val2=map(val,0,1023,60,100);
  
   myStepper.setSpeed(val2);
  
  // step one revolution  in one direction:
   Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  delay(500);
  
   // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  delay(500); 
}

