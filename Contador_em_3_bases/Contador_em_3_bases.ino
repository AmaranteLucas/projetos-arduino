#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

void setup()
{
  lcd.begin(16,2);
}

void loop()
{
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("DEC:");
  
  lcd.setCursor(9,0);
  lcd.print("HEX:");
  
  lcd.setCursor(0,1);
  lcd.print("BIN:");
  
  
  for(int i=0;i<=256;i++)
  {
  lcd.setCursor(5,0);
  lcd.print(i,DEC);
  
  lcd.setCursor(13,0);
  lcd.print(i,HEX);
  
  lcd.setCursor(6,1);
  lcd.print(i,BIN);
  delay(500);
  }
}
