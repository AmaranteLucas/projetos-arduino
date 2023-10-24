/* Nível de Reservatório com 3 sensores e Display LCD.

 Desenvolvido por Lucas Bastos.

/* Data: 29/07/2013


/******************************************************************************************************
*  Informação sobre a pinagem do LCD:                                                                       *
*  Pinos usados:                                                                                      *
*    8 -> RS do LCD                                                                                   *
*    9 -> EN do LCD                                                                                   *
*    10 -> D4 do LCD                                                                                   *
*    11 -> D5 do LCD                                                                                   *
*    12 -> D6 do LCD                                                                                  *
*    13 -> D7 do LCD                                                                                  *
*    Você deve alimentar o LCD                                                                        *
*    Ligar um Potenciômetro/trimpot ao pino VO do LCD para controlar o contraste                      *
*    Ligar o R/W do LCD ao GND                                                                        *
*    Ligar os pinos D0, D1, D2, D3 do LCD ao GND                                                      *
*******************************************************************************************************/

//Para informações sobre a Biblioteca LiquidCrystal.h, vá na guia Help/Reference/Libraries/LiquidCrystal
#include <LiquidCrystal.h> //Incluindo a biblioteca para acionamento do LCD 16x2

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//Configurando os pinos que estão conectados ao LCD

// Definindo as variáveis usadas do programa.

int pin1=2,sensor_cheio;
int pin2=3,sensor_medio;
int pin3=4,sensor_vazio;
int bomba=5;
int botao_act=0;
int botao_on=6;
int botao_off=7;
int t=2000;
int teste;

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
 
}

void loop(){
  
  // Fazendo a leitura dos pinos dos sensores.
  sensor_cheio=digitalRead(pin1);
  sensor_medio=digitalRead(pin2);
  sensor_vazio=digitalRead(pin3);
  
  
  // Leitura e testes dos Botões.
  
  if(digitalRead(botao_on)==1){
    teste=1;
    botao_act=1;
  }
  if(digitalRead(botao_off)==1){
    teste=0;
    botao_act=1;
  }
  if((digitalRead(botao_on)==1)&&(digitalRead(botao_off)==1)){
    botao_act=0;
  }
  
  
  
  if(botao_act==0){
  
  // Teste dos níveis lógicos dos pinos dos sensores.
  
  lcd.clear();
  lcd.setCursor(5,0); // Seta o cursor para coluna 5 linha 0.
  lcd.print("NIVEL");
  lcd.setCursor(2,1);
  lcd.print("RESERVATORIO");
  
  delay(t);
  
  if((sensor_cheio==1)&&(sensor_medio==1)&&(sensor_vazio==1)){
    
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 2 linha 0.
    lcd.print("RESERVATORIO");
    lcd.setCursor(6,1);
    lcd.print("CHEIO");
    delay(t);
    
    teste=0;
  }
  
  if((sensor_cheio==0)&&(sensor_medio==1)&&(sensor_vazio==1)){
   
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 2 linha 0.
    lcd.print("RESERVATORIO");
    lcd.setCursor(3,1);
    lcd.print("ESTA A 50%");
    delay(t);
  }
  
  if((sensor_cheio==0)&&(sensor_medio==0)&&(sensor_vazio==1)){
      
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 2 linha 0.
    lcd.print("RESERVATORIO");
    lcd.setCursor(2,1);
    lcd.print("ABAIXO DE 50%");
    delay(t);
  }
  
  if((sensor_cheio==0)&&(sensor_medio==0)&&(sensor_vazio==0)){
   
    lcd.clear();
    lcd.setCursor(2,0); // Seta o cursor para coluna 2 linha 0.
    lcd.print("RESERVATORIO");
    lcd.setCursor(6,1);
    lcd.print("VAZIO");
    delay(t);
   
    teste=1;
  }
  }
  else{
    lcd.clear();
  lcd.setCursor(6,0); // Seta o cursor para coluna 5 linha 0.
  lcd.print("MODO");
  lcd.setCursor(5,1);
  lcd.print("MANUAL");
  
  delay(t);
  }
  
  if(teste==1){
  lcd.clear();
  
    digitalWrite(bomba,HIGH);//Liga a Bomba.
     
    lcd.setCursor(5,0); // Seta o cursor para coluna 5 linha 0.
    lcd.print("BOMBA");
    lcd.setCursor(5,1);
    lcd.print("LIGADA");
    delay(t);
  }
  else{
    digitalWrite(bomba,LOW); // Desliga a Bomba.
    
    lcd.clear();
    lcd.setCursor(5,0); // Seta o cursor para coluna 5 linha 0.
    lcd.print("BOMBA");
    lcd.setCursor(3,1);
    lcd.print("DESLIGADA");
    delay(t);
  }
  
  
  
  
}
