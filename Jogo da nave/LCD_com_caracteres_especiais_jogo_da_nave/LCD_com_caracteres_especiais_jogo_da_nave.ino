#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

String nome[]= {"L","U","C","A","S"};

void setup(){
  
  lcd.begin(16,2);
  
}

void loop(){
  
  for(int i=1;i<16;i++){
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(0B01111110);
  
  lcd.setCursor(i,0);
  lcd.write(0B10100101);
  delay(500);
  }
  

  lcd.setCursor(15,0);
  lcd.write(0B00101010);
  delay(500);
  
}
