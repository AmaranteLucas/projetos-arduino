/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5, led5 = 6, led6 = 7, led7 = 8,t=0;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);  
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(t);               // wait for a second
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);    // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(t);   
  digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led3, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second  
  digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second  
  digitalWrite(led5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led5, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second  
  digitalWrite(led6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(t);  
  digitalWrite(led6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(t); 
   digitalWrite(led5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led5, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(t);   
  digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(t);     
  digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led3, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(t);     
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);    // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(t);    
   digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(t);   
   digitalWrite(led7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(led7, LOW);    // turn the LED off by making the voltage LOW
  delay(t);   
  
  t=t+10;
  
  if(t==100){
    t=0;
  }
  
}

