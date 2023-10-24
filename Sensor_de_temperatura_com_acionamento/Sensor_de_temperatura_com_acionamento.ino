// Lendo temperaturas com LM35DZ e Arduino

#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

float temp;
int leitura;
int exaustor=7;

//Desenho icone temperatura.
char tmp[8] = {
0b00100,
0b01010,
0b01010,
0b01110,
0b01110,
0b11111,
0b11111,
0b01110 };

// Desenho icone de Graus .
char cel[8] = {
0b01100,
0b10010,
0b10010,
0b01100,
0b00000,
0b00000,
0b00000,
0b00000 };

void setup(){
  
  lcd.begin(16,2);
  
  lcd.createChar(1,(uint8_t*)tmp); //Cria icone da teperatura
  lcd.createChar(2,(uint8_t*)cel);  // cria icone do Graus
  
  Serial.begin(9600);
  
  pinMode(exaustor,OUTPUT);
}


void loop(){
  
   temp=analogRead(A0);
   
   Serial.println(temp);
  
  temp=temp*0.488758553;
  
  Serial.println(temp);
  
  lcd.clear();
  
  // Escreve a palavra Temperatura
  lcd.setCursor(2,0);
  lcd.print("Temperatura");
  
  //Escreve o icone de termometro
  lcd.setCursor(1,1);
  lcd.write(1);
  
  // Escreve o valor de temperatura lido
  lcd.setCursor(5,1);
  lcd.print(temp);
  
  // Escreve o simbolo de graus
  lcd.setCursor(11,1);
  lcd.write(2);
  
  // Escreve a letra C
  lcd.setCursor(12,1);
  lcd.print("C");
  
  if(temp>=30){ 
    digitalWrite(exaustor,HIGH);
  }
  else{
    digitalWrite(exaustor,LOW);
  }
  
  delay(1000);
  
}
