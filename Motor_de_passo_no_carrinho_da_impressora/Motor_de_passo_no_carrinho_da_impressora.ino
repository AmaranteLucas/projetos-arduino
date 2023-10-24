
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
                                     // for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);       

int led=7;
int red=4,yellow=5,green=6;
int val=0;

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  
  pinMode(led,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
   Serial.println("clockwise");
   
   
   digitalWrite(red,HIGH);
  
  
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  
  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
  
  digitalWrite(yellow,LOW);
  pisca(20,green);
  
  
  pisca(50,7);
  delay(500);
  
  digitalWrite(green,HIGH);
 
  
   // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  
  digitalWrite(green,LOW);
  digitalWrite(yellow,HIGH);
  
  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
 
 digitalWrite(yellow,LOW);
 pisca(20,red);
 
  pisca(50,7);
  delay(500); 
  
  val=val+1;
  
  if(val==2){
    pisca_2(led,red,yellow,green,200);
    pisca_2(led,red,yellow,green,200);
    pisca_2(led,red,yellow,green,200);
    val=0;
  }
  
 
}

void pisca(int tempo, int pin){
  digitalWrite(pin,HIGH);
  delay(tempo);
  digitalWrite(pin,LOW);
  delay(tempo);
}

void pisca_2(int p1, int p2, int p3, int p4, int tempo){
  
  digitalWrite(p1,HIGH);
  digitalWrite(p2,HIGH);
  digitalWrite(p3,HIGH);
  digitalWrite(p4,HIGH);
  delay(tempo);
  
  digitalWrite(p1,LOW);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  digitalWrite(p4,LOW);
  delay(tempo);
  
}
  
