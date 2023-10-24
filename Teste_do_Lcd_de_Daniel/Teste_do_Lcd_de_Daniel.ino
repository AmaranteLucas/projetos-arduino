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
int tempo=10;
boolean val=true;
//Rotina de configurações iniciais do programa
void setup() {
  
  lcd.begin(20, 4);//Inicializa a biblioteca para trabalhar com display de 16 caracteres por 2 linhas (16x2)
 }

// the loop routine runs over and over again forever:
void loop() {
  
  val=true;
  tempo=10;
  
  lcd.clear();
  lcd.setCursor(4, 0);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("TESTE DO LCD");//Escreve a mensagem no LCD
  lcd.setCursor(6, 1);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("DE DANIEL");//Escreve a mensagem no LCD

  lcd.setCursor(6, 3);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("#ARDUINO");//Escreve a mensagem no LCD
  delay(3000);
  
  while(val){
  
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("DETONACAO DA BOMBA");
    lcd.setCursor(9,1);
    lcd.print("EM");
    lcd.setCursor(9,3);
    lcd.print(tempo);
    tempo=tempo-1;
    delay(1000);
    if(tempo==0){
      val=false;
    }
  }
  
  lcd.clear();
  lcd.setCursor(6, 0);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("PEGADINHA");//Escreve a mensagem no LCD
  lcd.setCursor(9, 1);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("DO");//Escreve a mensagem no LCD
  lcd.setCursor(5, 2);//Coloca o display na Primeira linha e Segundo caracter (Começa a contar em zero)
  lcd.print("MALANDRO!!!");//Escreve a mensagem no LCD
  delay(2000);
  
  lcd.clear();
  lcd.print("By LUCAS BASTOS");
  
  for (int positionCounter = 0; positionCounter < 18; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(300);
  }
  
  
  
}
