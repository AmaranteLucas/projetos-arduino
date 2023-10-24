/*                                                                               *
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
#include <IRremote.h>

//Para informações sobre a Biblioteca LiquidCrystal.h, vá na guia Help/Reference/Libraries/LiquidCrystal
#include <LiquidCrystal.h> //Incluindo a biblioteca para acionamento do LCD 16x2

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//Configurando os pinos que estão conectados ao LCD

//Declaração de variáveis usadas no programa

int val=0;

int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

//Rotina de configurações iniciais do programa
void setup() {
  
  irrecv.enableIRIn(); // Start the receiver
  lcd.begin(16, 2);//Inicializa a biblioteca para trabalhar com display de 16 caracteres por 2 linhas (16x2)
  
  escreve("Bem Vindo",0,3);
  escreve2("Inicializando",1,1);
  delay(1000);
 }

// the loop routine runs over and over again forever:
void loop() {

escreve("Temperatura:",0,3);
lcd.setCursor(1,3);
lcd.print(val);
lcd.setCursor(1,5);
lcd.print("ºC");

delay(1000);

escreve("Umidade",0,3);
lcd.setCursor(1,3);
lcd.print(val);

delay(1000);

 if (irrecv.decode(&results)) {
    
  switch(results.value){
    
    case 16753245:
    
       escreve("Lampada 1",0,2);
       escreve("Acesa",1,2);
       delay(500);
       
      
      break;
    case 16736925:
     
      break;
  }
   irrecv.resume(); // Receive the next value
  }
  delay(100);




  
}

// #################### Escreve no LCD ###########################

 void escreve(String tex, int lin, int col){
  lcd.clear();
  lcd.setCursor(lin,col);
  lcd.print(tex);
}

 void escreve2(String tex, int lin, int col){
  lcd.setCursor(lin,col);
  lcd.print(tex);
}


