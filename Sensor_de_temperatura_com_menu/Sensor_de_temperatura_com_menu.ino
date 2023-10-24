#include <LiquidCrystal.h> //Incluindo a biblioteca para LCD

LiquidCrystal lcd(8,9,10,11,12,13); // Definindo os pinos a serem usados pelo LCD


int botao_1=2, botao_2=3,botao_3=4; // Definindo os pinos dos botoes
int sensor=5; //Definindo o pino do sensor Lm35
float temp_min=18.00, temp_max=25.00; //Definindo as temperaturas de comparacao

float temperatura; // Declarando a variável temperatura

void setup(){
  
  lcd.begin(16,2); // Definindo o LCD que sera utilizado
  
  for(int i=2;i<=4;i++){ // Configurando os pinos dos botoes como entradas
   pinMode(i,INPUT);
  }
}

void loop(){
  
// ############### Menu #######################

if(digitalRead(botao_2)){
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ajuste");
  lcd.setCursor(0,1);
  lcd.print("Temperatura");
  
  if(digitalRead(botao_1)){
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp. min.");
    
    lcd.setCursor(0,1);
    lcd.print(temp_mim);
    
    
    
  }
  
}


  
  
  temperatura=((analogRead(sensor)*500)/1023);
  
  if(temperatura<temp_min){
    //Acende Led verde
  }
  
  if((temp_min<temperatura)&&(temperatura<temp_max)){
    //Acende Led Amarelo
  }
  
  if(temperatura>temp_max){
    //Acende Led vermelho
  }
  
  
  
}
}

