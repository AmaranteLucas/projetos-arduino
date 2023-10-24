/***************************************
*  Informação sobre o programa:                                                                       *
*  Pinos usados:                                                                                      *
*    8 -> RS do LCD                                                                                   *
*    9 -> EN do LCD                                                                                   *
*    10 -> D4 do LCD                                                                                  *
*    11 -> D5 do LCD                                                                                  *
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

//Rotina de configurações iniciais do programa
void setup() {
  
  lcd.begin(16, 2);//Inicializa a biblioteca para trabalhar com display de 16 caracteres por 2 linhas (16x2)
 }

// the loop routine runs over and over again forever:
void loop() {
  
  escreve("Lucas",0,0);
  delay(2000);
  
  escreve("Bastos",5,1);
  delay(2000);
  
  
}

 void escreve(String tex,int col, int lin){
   lcd.setCursor(col,lin);
   lcd.print(tex);
 }

