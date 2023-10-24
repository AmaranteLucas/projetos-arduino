#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

String nome[]= {"L","U","C","A","S"};

long row,col;

void setup(){
  
  lcd.begin(16,2);
  
}

void loop(){
  
  row=random(0,2);
  col=random(9,16);
  
  
  lcd.clear();
  lcd.setCursor(col,row);
  lcd.write(0B01111111);

  delay(500);
  
}

