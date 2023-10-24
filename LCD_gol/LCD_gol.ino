#include <LiquidCrystal.h> 

LiquidCrystal lcd(8,9,10,11,12,13);

float temp, temp_2;

void setup()
{
  lcd.begin(16,2);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Iniciando...");
  delay(2000);
}

void loop()
{
  temp=analogRead(A0);
  temp=temp*0.488758553;
  
  temp_2=analogRead(A1);
  temp_2=temp_2*0.488758553;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura");
  lcd.setCursor(0,1);
  lcd.print("Interior:");
  lcd.setCursor(10,1);
  lcd.print(temp);
  delay(3000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura");
  lcd.setCursor(0,1);
  lcd.print("no motor:");
  lcd.setCursor(10,1);
  lcd.print(temp_2);
  delay(3000);
  
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Salve os");
  lcd.setCursor(8,1);
  lcd.print("Golzera!!!");
  delay(3000);
  
}
