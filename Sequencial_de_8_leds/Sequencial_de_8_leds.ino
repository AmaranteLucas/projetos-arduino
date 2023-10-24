/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

int tempo = 50;
  int i = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);     
  pinMode(4, OUTPUT);     
  pinMode(5, OUTPUT);     
  pinMode(6, OUTPUT);     
  pinMode(7, OUTPUT);     
  pinMode(8, OUTPUT);     
  pinMode(9, OUTPUT);     
  
}

// the loop routine runs over and over again forever:
void loop() 
{  
  pisca(2, tempo);
  pisca(3, tempo);
  pisca(4, tempo);
  pisca(5, tempo);
  pisca(6, tempo);
  pisca(7, tempo);
  pisca(8, tempo);
  pisca(9, tempo);
  
  for(int j=0; j<=i; j++)
  {
  pisca_tudo(100);
  }
  
  i=i+1;
  if( i == 10)
  {
    i=0;
  }
  
  pisca_cores(2,6,tempo);
  pisca_cores(3,7,tempo);
  pisca_cores(4,8,tempo);
  pisca_cores(5,9,tempo);
}

void pisca(int led, int tempo)
{
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(tempo);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(tempo);       // wait for a second
}

void pisca_tudo(int tempo)
{
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  delay(tempo);
  
  digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(3, LOW);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(4, LOW);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(5, LOW);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(6, LOW);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(7, LOW);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)              // wait for a second
  delay(tempo);
}

void pisca_cores(int led_1, int led_2, int tempo)
{
  digitalWrite(led_1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led_2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(tempo);   

  digitalWrite(led_1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led_2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(tempo);   
}
