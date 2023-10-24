

#include <IRremote.h>

#include<LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);


int RECV_PIN = 7,led=6;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  lcd.begin(16,2);
  pinMode(led,OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  lcd.setCursor(0,0);
  lcd.print("Led com controle");
}

void loop() {
  if (irrecv.decode(&results)) {
    
  switch(results.value){
    case 16753245:
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("LED Aceso");
      digitalWrite(led,HIGH);
      break;
    case 16736925:
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("LED Apagado");
      digitalWrite(led,LOW);
      break;
  }
   irrecv.resume(); // Receive the next value
  }
  delay(100);
}
