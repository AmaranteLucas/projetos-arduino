#include<LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

byte detecta = 2;
int contador = 0;

int shift_light = 7;

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("CONTA GIROS");
  
  //Acionando PULL-UP interno no pino 2
  pinMode(detecta,INPUT);
  digitalWrite(detecta,HIGH);
  
  pinMode(shift_light,OUTPUT);
  
  contador = 0;
  
  //Criando interrupção utilizando o pino 2
  attachInterrupt(0, DETECTA, FALLING);
  noInterrupts();
  
  delay (10000);
}

void loop()
{
  unsigned long tempo = millis();
  
  while(tempo + 300 > millis())
  {
    interrupts(); 
  }
  
  contador = contador * 100 ;
  
  /*
  lcd.setCursor(0, 0);
  lcd.print("V:"); 
  lcd.print(tensao); 
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperatura);
  lcd.print(" ");
  */
  lcd.setCursor(8, 1);
  lcd.print("RPM:");
  lcd.print(contador);
  lcd.print(" ");
  
  if(contador >= 3000)
  {
    digitalWrite(shift_light,HIGH);
  }
  else
  {
    digitalWrite(shift_light,LOW);
  }
  
  contador = 0;
}

void DETECTA()
{
  contador ++;
}

