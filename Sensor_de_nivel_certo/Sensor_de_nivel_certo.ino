#include <LiquidCrystal.h> //Incluindo a biblioteca para acionamento do LCD 16x2

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//Configurando os pinos que estão conectados ao LCD

char msg_1[]={'B','E','M',' ','V','I','N','D','O'};
char msg_2[]={'S','E','N','S','O','R',' ','D','E',' ','N','I','V','E','L'};

// Definindo as variáveis usadas do programa.

int pin1=2,sensor_cheio;
int pin2=3,sensor_medio;
int pin3=4,sensor_vazio;

int bomba=7;

int botao_act=0;
int botao_on=5;
int botao_off=6;

int indice=0;

void setup(){
  
  lcd.begin(16, 2);//Inicializa a biblioteca para trabalhar com display de 16 caracteres por 2 linhas (16x2)
  
  // Configurando os pinos dos sensores como entradas.
  pinMode(pin1,INPUT);
  pinMode(pin2,INPUT);
  pinMode(pin3,INPUT);
  
  // Configurando os pinos dos botões como entradas.
  pinMode(botao_on,INPUT);
  pinMode(botao_off,INPUT);
  
  // Configurando o pino de acionamento da bomba como saída.
  pinMode(bomba,OUTPUT);
  
  for(int i=0;i<=8;i++)
  {
    lcd.setCursor(i+3,0);
    lcd.print(msg_1[i]);
    delay(250);
  }
  
  for(int i=0;i<=14;i++)
  {
    lcd.setCursor(i+1,1);
    lcd.print(msg_2[i]);
    delay(250);
  }
  
  lcd.clear();
  delay(500);
 
}

void loop(){
  
  // Fazendo a leitura dos pinos dos sensores.
  sensor_cheio=digitalRead(pin1);
  sensor_medio=digitalRead(pin2);
  sensor_vazio=digitalRead(pin3);
  
  if(!digitalRead(botao_on)){
    
    indice=5;
    botao_act=1;
  }
  if(!digitalRead(botao_off)){
    indice=6;
    botao_act=1;
  }
  if((!digitalRead(botao_on))&&(!digitalRead(botao_off))){
    botao_act=0;
  }
  
  
  if(botao_act==0)
  {
  
    if((sensor_cheio==1)&&(sensor_medio==1)&&(sensor_vazio==1))
    {
      indice=1;
    }
  
    if((sensor_cheio==0)&&(sensor_medio==1)&&(sensor_vazio==1))
    {
      indice=2;
    }
  
    if((sensor_cheio==0)&&(sensor_medio==0)&&(sensor_vazio==1))
    {
      indice=3;
    }
    
    if((sensor_cheio==0)&&(sensor_medio==0)&&(sensor_vazio==0))
    {
      indice=4;
    }
    
  }

 switch(indice)
 {
   
   case 1:
   
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 2 linha 0.
    lcd.print("RESERVATORIO");
    lcd.setCursor(6,1);
    lcd.print("CHEIO");
    digitalWrite(bomba,LOW);
    break;
    
    case 2:
    
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 2 linha 0.
    lcd.print("RESERVATORIO");
    lcd.setCursor(3,1);
    lcd.print("ESTA A 50%");
    break;
    
    case 3:
    
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 2 linha 0.
    lcd.print("RESERVATORIO");
    lcd.setCursor(2,1);
    lcd.print("ABAIXO DE 50%");
    break;
    
    case 4:
    
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 2 linha 0.
    lcd.print("RESERVATORIO");
    lcd.setCursor(6,1);
    lcd.print("VAZIO");
    digitalWrite(bomba,HIGH);
    break;
    
    case 5:
    
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 5 linha 0.
    lcd.print("MODO MANUAL");
    lcd.setCursor(2,1);
    lcd.print("Bomba Ligada");
    digitalWrite(bomba,HIGH);
    break;
    
    case 6:
    
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 5 linha 0.
    lcd.print("MODO MANUAL");
    lcd.setCursor(2,1);
    lcd.print("Bomba Deslig.");
    digitalWrite(bomba,LOW);
    break;
    
 }
 
 delay(100);
 
 }
    
    
    
    
    
    
    
    
    
    
    
    
  
  
  
  
  
