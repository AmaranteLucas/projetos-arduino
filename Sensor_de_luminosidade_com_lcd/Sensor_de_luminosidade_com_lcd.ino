
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

int val=0;

void setup()
{
  lcd.begin(16,2);
}

void loop()
{
  
  val=analogRead(A0);
  val=map(val,0,1023,100,0);
  
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Luminosidade");
  lcd.setCursor(6,1);
  lcd.print(val);
  lcd.setCursor(9,1);
  lcd.print("%"); 
  delay(200);
}
