
// Declaração das Bibliotecas utilizadas.

#include <IRremote.h>

#include<LiquidCrystal.h>

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


//#####################################

// Declaração das Variáveis utilizadas.

LiquidCrystal lcd(8,9,10,11,12,13);

int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

int val=0,pin,dal=0;

int led_receive= 4,led=5,led2=6;

//#####################################

void setup()
{
  lcd.begin(16,2);
  irrecv.enableIRIn(); // Start the receiver
  lcd.setCursor(3,0);
  lcd.print("Bem Vindo");
  pinMode(led_receive,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    
    digitalWrite(led_receive,HIGH);
    delay(5);
    digitalWrite(led_receive,LOW);
    
  switch(results.value){
    
    case 16724175 : // Tecla 1 do controle.
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Opcoes de Led 1");
      pin=2;
      break;
      
    case 16718055 : // Tecla 2 do controle.
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Opcoes de Led 2");
      delay(1000);
      pin=3;
      break;
      
    case 16738455 : // Tecla 0 do controle.
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Bem Vindo");
      pin=0;
      break;
    //################### codigo para aumentar ###########
    case 16769565 :
    if(pin==2){
      val=val+1;
      if(val>10){val=10;}
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Opcoes de Led 1");
      lcd.setCursor(0,1);
      lcd.print("-");
      lcd.setCursor(7,1);
      lcd.print(val);
      lcd.setCursor(15,1);
      lcd.print("+");
      analogWrite(led,map(val,0,10,0,255));
    }else{
    if(pin==3){
       dal=dal+1;
       if(dal>10){dal=10;}
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Opcoes de Led 2");
      lcd.setCursor(0,1);
      lcd.print("-");
      lcd.setCursor(7,1);
      lcd.print(dal);
      lcd.setCursor(15,1);
      lcd.print("+");
      analogWrite(led2,map(dal,0,10,0,255));
    }
    }
    break;
    
 //####################### codigo para abaixar ##############   
    
    case 16753245 :
    if(pin==2){
      val=val-1;
      if(val<0){val=0;}
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Opcoes de Led 1");
      lcd.setCursor(0,1);
      lcd.print("-");
      lcd.setCursor(7,1);
      lcd.print(val);
      lcd.setCursor(15,1);
      lcd.print("+");
      analogWrite(led,map(val,0,10,0,255));
    }else{
    if(pin==3){
      dal=dal-1;
      if(dal<0){dal=0;}
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Opcoes de Led 2");
      lcd.setCursor(0,1);
      lcd.print("-");
      lcd.setCursor(7,1);
      lcd.print(dal);
      lcd.setCursor(15,1);
      lcd.print("+");
      analogWrite(led2,map(dal,0,10,0,255));
    }
    }
    break;
  }
   irrecv.resume(); // Receive the next value
  }
 
  delay(100);
}
