/******************************************************************************************************
*  Programa exemplo para uso de Display de LCD - MSS Eletrônica                                       *
*  Produto: Para todos os Display´s de LCD 16x2 da MSS Eletrônica                                     *
*  Desenvolvedor: Misael                                                                              *
*  Data: 31/10/2012                                                                                   *
*                                                                                                     *
*  Objetivo: Escrever um texto em um LCD 16x2 com comunicação à 4 bits usando o arduino (UNO)         *
*  Biblioteca: LiquidCrystal.h                                                                        *
*  Referencia para a Biblioteca: http://arduino.cc/en/Reference/LiquidCrystal                         *
*******************************************************************************************************/

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

//Para informações sobre a Biblioteca LiquidCrystal.h, vá na guia Help/Reference/Libraries/LiquidCrystal
#include <LiquidCrystal.h> //Incluindo a biblioteca para acionamento do LCD 16x2

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//Configurando os pinos que estão conectados ao LCD
//2 -> RS do LCD, 4 -> EN do LCD, 7 -> D4 do LCD, 8 -> D5 do LCD, 12 -> D6 do LCD, 13 -> D7 do LCD

//Declaração de variáveis usadas no programa
int botao=7,val=0,teste=0;
int led=6;
//Rotina de configurações iniciais do programa
void setup() {
  
  lcd.begin(16, 2);//Inicializa a biblioteca para trabalhar com display de 16 caracteres por 2 linhas (16x2)
   pinMode(botao,INPUT);
   pinMode(led,OUTPUT);
 }

// the loop routine runs over and over again forever:
void loop() {
  
   val= digitalRead(botao);
   
   if(val==1){
     teste=teste+1;
     digitalWrite(led,HIGH);
     delay(100);
     digitalWrite(led,LOW);
   }
   
   if(teste%2==0){
     lcd.clear();
  //lcd.setCursor(caracter, linha);
  lcd.setCursor(1, 0);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("Bem Vindo");//Escreve a mensagem no LCD
  lcd.setCursor(1, 1);//Coloca o display na Segunda coluna e Segundo caracter
  lcd.print("Lucas Bastos");//Escreve a mensagem no LCD
  
   }
   if(teste%2!=0){
  lcd.clear();
  lcd.setCursor(1, 0);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("Botao");//Escreve a mensagem no LCD
  lcd.setCursor(1, 1);//Coloca o display na Segunda coluna e Segundo caracter
  lcd.print("no LCD");//Escreve a mensagem no LCD
   }
   
   delay(300);
  
}
