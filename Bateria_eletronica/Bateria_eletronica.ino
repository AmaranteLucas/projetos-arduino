/* 
 Keyboard Button test
 
 For the Arduino Leonardo and Micro.
 
 Sends a text string when a button is pressed.
 
 The circuit:
 * pushbutton attached from pin 2 to +5V
 * 10-kilohm resistor attached from pin 4 to ground
 
 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/KeyboardButton
 */

const int buttonPin = 4;          
int previousButtonState = HIGH;   

const int buttonPin_3 = 5;          
int previousButtonState_3 = HIGH; 

const int buttonPin_4 = 6;          
int previousButtonState_4 = HIGH; 

const int buttonPin_2 = 7;          
int previousButtonState_2 = HIGH;  

void setup() {

  pinMode(buttonPin, INPUT);
  pinMode(buttonPin_2, INPUT);
  pinMode(buttonPin_3, INPUT);
  pinMode(buttonPin_4, INPUT);
  Keyboard.begin();
}

void loop() {

  int buttonState = digitalRead(buttonPin);
  int buttonState_2 = digitalRead(buttonPin_2);
  int buttonState_3 = digitalRead(buttonPin_3);
  int buttonState_4 = digitalRead(buttonPin_4);
 
  //#######################################################################################
  if ((buttonState != previousButtonState)&& (buttonState == HIGH)) 
  {
    Keyboard.print("s");
  }
  previousButtonState = buttonState; 
  
  //#######################################################################################
  if ((buttonState_2 != previousButtonState_2)&& (buttonState_2 == HIGH)) 
  {
    Keyboard.print("c");
  }
  
  previousButtonState_2 = buttonState_2; 
  //#######################################################################################
 
 //#######################################################################################
  if ((buttonState_3 != previousButtonState_3)&& (buttonState_3 == HIGH)) 
  {
    Keyboard.print("b");
  }
  
  previousButtonState_3 = buttonState_3; 
  //####################################################################################### 

  //#######################################################################################
  if ((buttonState_4 != previousButtonState_4)&& (buttonState_4 == HIGH)) 
  {
    Keyboard.print("e");
  }
  
  previousButtonState_4 = buttonState_4; 
  //#######################################################################################
  delay(3);

}

