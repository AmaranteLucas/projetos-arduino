
#include <LiquidCrystal.h> //Incluindo a biblioteca para acionamento do LCD 16x2

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//Configurando os pinos que estão conectados ao LCD

/******************************************************************************************************
*  Informação sobre o programa:                                                                       *
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


int sensor_cheio=2;
int sensor_medio=3;
int sensor_vazio=4;
int bomba=5;

void setup(){
  
  lcd.begin(16, 2);//Inicializa a biblioteca para trabalhar com display de 16 caracteres por 2 linhas (16x2)
  
  pinMode(sensor_cheio,INPUT);
  pinMode(sensor_medio,INPUT);
  pinMode(sensor_vazio,INPUT);
  pinMode(bomba,OUTPUT);
 
}

void loop(){
  
  sensor_cheio=digitalRead(sensor_cheio);
  sensor_medio=digitalRead(sensor_medio);
  sensor_vazio=digitalRead(sensor_vazio);
  
  if(sensor_vazio==0){
    digitalWrite(bomba,HIGH);
  }
  if(sensor_cheio==1){
    digitalWrite(bomba,LOW);
  
  lcd.clear();
  lcd.setCursor(1, 0);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("O reservatorio");//Escreve a mensagem no LCD
  lcd.setCursor(1,1);
  lcd.print("esta cheio");
   
  }
  if((sensor_cheio==0)&&(sensor_medio==1)){
   
  lcd.clear();  
  lcd.setCursor(1, 0);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("Nivel acima de ");//Escreve a mensagem no LCD
  lcd.setCursor(6,1);
  lcd.print("50%"); 
  }
  else{
     if(sensor_medio==0){
       
       lcd.clear();  
       lcd.setCursor(1, 0);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
       lcd.print("Nivel abaixo de ");//Escreve a mensagem no LCD
       lcd.setCursor(6,1);
       lcd.print("50%"); 
      //escrever no LCD que o nível está abaixo de 50%
     }
  }
  
  
}
