/*Código para a intensidade de um led através do controle remoto
e exibe em um display LCD 16x2 o caracter ">" conforme o brilho
do led aumenta ou diminui.

Desenvolvido por: Lucas Bastos de L. Amarante
Data: 24/03/2013

*/

#include <IRremote.h>

#include<LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13); //Pinos utilizados para conectar o LCD.
                                   

int RECV_PIN = 7; //Pino do receptor IR.

int led=6,val=0,cont=0; // "val" controla o brilho do led
 // "cont" serve para contar os caracteres ">" que serão exibidos.

IRrecv irrecv(RECV_PIN);

decode_results results;

//Rotina de configurações iniciais do Arduino.

void setup()
{
  pinMode(led,OUTPUT);
  lcd.begin(16,2);
   lcd.setCursor(0,0);
   lcd.print("Controle do Led");
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  
  if (irrecv.decode(&results)) {
   
   long int decCode = results.value;
   
   switch(decCode){
     
     case 16754775: // Caso pressione a tecla "vol +" ...
       val=val+15;
       if(val>255){
         val=255;
         cont=16;
       }
       analogWrite(led,val);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Controle do Led");
       cont=cont+1;
       for(int i=0;i<cont;i++){
       lcd.setCursor(i,1);
       lcd.print(">");
       }
       break;
       
     case 16769055: // Caso pressione a tecla "vol -"...
       val=val-15;
       if(val<0){
         val=0;
         cont=0;
       }
       analogWrite(led,val);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Controle do Led");
         cont=cont-1;
       for(int i=0;i<cont;i++){
       lcd.setCursor(i,1);
       lcd.print(">");
       }
       break;
   }
    irrecv.resume(); // Recebe o próximo valor.
  }
  delay(100);
}
