// Lendo temperaturas com LM35DZ e Arduino

#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

float temp;
int leitura;

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
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
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
  
  delay(5000);
  
  if(temp<=20){ 
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Frio/Agradavel");
  }
  
  if(temp>20&&temp<=29){
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Clima ameno");
  }
  
  if(temp>29){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Muito Quente");
  }
   
  delay(1000);
   
}
