#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

#define botao 7

int led_state=LOW;
int led=6;
int buzzer=5;

void setup()
{
  lcd.begin(16,2);
  pinMode(botao,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Estado do LED");
  
  if(digitalRead(botao)==0)
  {
    led_state=!led_state;
    digitalWrite(buzzer,HIGH);
    delay(20);
    digitalWrite(buzzer,LOW);
    delay(20);
  }
  
  digitalWrite(6,led_state);
  
  if(led_state==LOW)
  {
    lcd.setCursor(5,1);
    lcd.print("Desligado");
  }
  else
  {
    lcd.setCursor(5,1);
    lcd.print("Ligado");
  }
  
   delay(200);
}


