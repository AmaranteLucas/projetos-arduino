/* ########################### JOGO DA NAVE #######################

Versão 1.0
Criado por Lucas Bastos de L. Amarante
Data 16/10/2013

####################################################################

*/



#include <LiquidCrystal.h> // Incluindo a biblioteca para o LCD

LiquidCrystal lcd(8,9,10,11,12,13); // Declarando pinos do LCD

String nome[]= {"L","U","C","A","S"}; // Array com caracteres do meu nome

int atira=7; // Botao que faz a "nave" atirar
int cima=5; // Move a nave para cima
int baixo=6; //Move a nave para baixo
int dir=0; // Variável que registra a posição da nave no display

void setup(){ // Configurações
  
  lcd.begin(16,2); // Iniciando o LCD 16x2
  
  lcd.clear(); // Limpa a tela do LCD
  
  // Escreve "LUCAS" caracter a caracter
  
  for(int i=0;i<5;i++){ // De i=0 até 5, somando de um em um faça:
    lcd.setCursor(i+5,0); // Posiciona o cursor na coluna i+5 , linha 0
    lcd.print(nome[i]); // Escreve na tela o caracter que está na posição i do array nome
    delay(500); // Espera 500 milissegundos
  }
  
  delay(500); // Espera 500 milissegundos
  
   lcd.clear(); // Limpa o LCD
  
}

void loop(){ // Loop infinito
  
      if(!digitalRead(cima)){ // Se o botao CIMA for precionado...
        dir=0; // Atribui valor zero a variável dir
        lcd.clear(); // Limpa o display
        
      }
      
      if(!digitalRead(baixo)){ // Se o botao BAIXO for precionado...
        dir=1;// Atribui valor um a variável dir
        lcd.clear(); // Limpa o LCD
      }
  
       
       lcd.setCursor(0,dir); // Poe o cursor na coluna 0 linha com o valor atribuido a dir
       lcd.write(0B01111110);// Escreve na tela o Byte correspondente a "nave"
  
  if(!digitalRead(atira)){ // Se o botao atira for precionado...
  
      for(int i=1;i<16;i++){ // De i=1 até 15, somando de 1 em 1
  
       lcd.clear(); // Limpa o LCD
       lcd.setCursor(0,dir); // Posiciona o cursor na coluna 0 linha com o valor de dir
       lcd.write(0B01111110); // Escreve na tela o Byte correspondente a "nave"
  
       lcd.setCursor(i,dir); // Posiciona o cursor na coluna i linha com o valor de dir
       lcd.write(0B10100101); // Escreve na tela o Byte correspondente ao "tiro" (ponto)
       delay(150); // Espera 500 milissegundos
      }
  
   lcd.setCursor(15,dir); // Posiciona o cursor na coluna 15 linha com o valor de dir
   lcd.write(0B00101010); // Escreve na tela o Byte correspondente a explosão
   delay(500); // Espera 500 milissegundos
   
   lcd.clear(); // Limpa o LCD
  
  }
}
