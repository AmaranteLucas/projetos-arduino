#include <LiquidCrystal.h>// Incluindo a biblioteca para o LCD

LiquidCrystal lcd(8,9,10,11,12,13); // Declarando os pinos do LCD

int sensor=A0; //Sensor de passagem no pino analógico A0
int leitura;  // Variável que guarda o valor lido no sensor
int buzzer=2; // Buzzer no pino digital 2
int cont=0;   // Variável que conta o número de pessoas e/ou objetos
int reset=3; // Botao de reset no pino 3

void setup(){ // Funçao de configuração
  
  pinMode(buzzer,OUTPUT); // Configura o pino atribuido a buzzer como saída
  pinMode(reset,INPUT); // Configura o pino atribuido a reset como entrada
  
  lcd.begin(16,2); // Iniciando o lcd 16x2
  
  lcd.clear(); // Limpa o LCD
  lcd.setCursor(2,0); // Coloca o cursor na coluna 2 linha 0
  lcd.print("Contador de"); // Escreve a mensagem na tela
  lcd.setCursor(4,1); // Coloca o cursor na coluna 4 linha 1
  lcd.print("passagem"); // Escreve a mensagem na tela
  delay(3000); // Espera 3 segundos
  lcd.clear(); // Limpa o LCD
  
  
}

void loop(){
  
  leitura=analogRead(sensor); // Atribui o valor lido na porta A0 
                             // a variável leitura
  lcd.setCursor(0,0); // Coloca o cursor na coluna 0 linha 0
  lcd.print("Total de objetos"); // Escreve a mensagem na tela
  lcd.setCursor(7,1); // Coloca o cursor na coluna 7 linha 1
  lcd.print(cont); // Escreve a variável cont na tela
  
  if(leitura<=400){ // Se o valor de leitura for menor que 400
    
    cont=cont+1; // Soma 1 a variável cont
    
    lcd.setCursor(7,1); // Coloca o cursor na coluna 7 linha 1
    lcd.print(cont); // Escreve a variável cont na tela
    
    
    digitalWrite(buzzer,HIGH); // Liga o buzzer
    delay(50); //Espera 50 milissegundos
    digitalWrite(buzzer,LOW); // Desliga o buzzer
    
    
  }
  
  if(!digitalRead(reset)){ // Se o botão estiver em nível logico baixo
    cont=0; // Zera a contagem
    lcd.clear(); // Limpa o LCD
  }
  
  delay(100); // Espera 100 milissegundos
  
}

