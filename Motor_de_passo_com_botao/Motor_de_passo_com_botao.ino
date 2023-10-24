
#include <Stepper.h>

const int stepsPerRevolution = 300;  // change this to fit the number of steps per revolution
                                     // for your motor
int botao=2,botao_2=4;

int val=0;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
}

void loop() {
  // step one revolution  in one direction:
  
  if((digitalRead(botao)==HIGH)&&(digitalRead(botao_2)==LOW)){
  
  val=1;
  
  }
  
  if((digitalRead(botao_2)==HIGH)&&(digitalRead(botao)==LOW)){
  
  val=0;
  
  }
 
  if(val==1){
  myStepper.step(stepsPerRevolution);
  }
  if(val==0){
  myStepper.step(-stepsPerRevolution);
  }
  
  
}

