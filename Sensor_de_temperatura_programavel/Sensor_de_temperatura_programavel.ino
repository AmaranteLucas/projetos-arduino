#include<LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

#define mais 5
#define menu 6
#define menos 7

int val=0;
float temp_max=25;
float temp;

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


void setup()
{
  lcd.begin(16,2);
  
  pinMode(mais,INPUT);
  pinMode(menu,INPUT);
  pinMode(menos,INPUT);
  
  lcd.createChar(1,(uint8_t*)tmp); //Cria icone da teperatura
  lcd.createChar(2,(uint8_t*)cel);  // cria icone do Graus
}

void loop()
{
  temp=analogRead(A0);
  temp=temp*0.488758553;
  
  if((temp>=temp_max-3)&&(temp<=temp_max+3))
  {
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Agradavel");
  
   escreve_temp();
  }
  
  if(temp<temp_max-3)
  {
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Frio!!!");
  
  escreve_temp();
  }
  
  if(temp>temp_max+3)
  {
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Quente!!!");
  
  escreve_temp();
  }
  
  if(digitalRead(menu)==0)
  {
    val=1;
  }
  
  while(val==1)
  {
    
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Temp. maxima");
  lcd.setCursor(6,1);
  lcd.print(temp_max);
    
    if(digitalRead(mais)==0) temp_max=temp_max+0.5;
    if(digitalRead(menos)==0) temp_max=temp_max-0.5;
    delay(200);
    
    if(digitalRead(menu)==0) val=0;
  }
  delay(300);
}

void escreve_temp()
{
  //Escreve o icone de termometro
  lcd.setCursor(1,1);
  lcd.write(1);
  
  // Escreve o valor de temperatura lido
  lcd.setCursor(6,1);
  lcd.print(temp);
  
  // Escreve o simbolo de graus
  lcd.setCursor(12,1);
  lcd.write(2);
  
  // Escreve a letra C
  lcd.setCursor(13,1);
  lcd.print("C");
}
