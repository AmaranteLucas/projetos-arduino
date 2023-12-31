/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(2,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  for(int i=0;i<=30;i++){
    digitalWrite(2,LOW);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(50);  
  }  // wait for a second
  
  for(int i=0;i<=30;i++){
    digitalWrite(2,HIGH);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(50);  
  }  // wait for a second
}
