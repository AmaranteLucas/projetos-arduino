//##################### Teclado Matricial 4x3 ####################
// Devem ser usados resistores de pull-down nos pinos das colunas
//################################################################

#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13); 

int lin_1 = 2;
int lin_2 = 3;
int lin_3 = 4;
int lin_4 = 5;

int col_1 = 6;
int col_2 = 7;
int col_3 = 8;

void setup()
{
  lcd.begin(16,2);
  
  for(int i=2;i<=5;i++)
  {
    pinMode(i,OUTPUT);
  }
  
  for(int i=6;i<=8;i++)
  {
    pinMode(i,INPUT);
  }
}

void loop()
{
  
  //LÊ A LINHA 1
  digitalWrite(lin_1,HIGH);
  digitalWrite(lin_2,LOW);
  digitalWrite(lin_3,LOW);
  digitalWrite(lin_4,LOW);
  
  if( digitalRead(col_1)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("1");
  }
  
  if( digitalRead(col_2)==HIGH)
  {
   lcd.clear();
   lcd.setCursor(8,1);
   lcd.print("2");
  }
  
  if( digitalRead(col_3)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("3");
  }
  
  //LÊ A LINHA 2
  digitalWrite(lin_1,LOW);
  digitalWrite(lin_2,HIGH);
  digitalWrite(lin_3,LOW);
  digitalWrite(lin_4,LOW);
  
  if( digitalRead(col_1)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("4");
  }
  
  if( digitalRead(col_2)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("5");
  }
  
  if( digitalRead(col_3)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("6");
  }
  
  //LÊ A LINHA 3
  digitalWrite(lin_1,LOW);
  digitalWrite(lin_2,LOW);
  digitalWrite(lin_3,HIGH);
  digitalWrite(lin_4,LOW);
  
  if( digitalRead(col_1)==HIGH)
  {
   lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("7");
  }
  
  if( digitalRead(col_2)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("8");
  }
  
  if( digitalRead(col_3)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("9");
  }
  
  //LÊ A LINHA 4
  digitalWrite(lin_1,LOW);
  digitalWrite(lin_2,LOW);
  digitalWrite(lin_3,LOW);
  digitalWrite(lin_4,HIGH);
  
  if( digitalRead(col_1)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("*");
  }
  
  if( digitalRead(col_2)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("0");
  }
  
  if( digitalRead(col_3)==HIGH)
  {
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("#");
  }
 
 delay(10);  
}
