#include <Wire.h>
#include <DS1307.h> // written by  mattt on the Arduino forum and modified by D. Sjunnesson
#include<LiquidCrystal.h>

//rtc[0] imprime os segundos 
//rtc[2] imprime os minutos 
//rtc[3] imprime as horas
//rtc[4] imprime o dia da semana entre 1(domingo) e 6 (sábado)
//rtc[5] imprime o dia 
//rtc[6] imprime o mes 
//rtc[7] imprime o ano

LiquidCrystal lcd(8,9,10,11,12,13);

int rtc[7];
int pump = 7;
int ctrPump;
int A,B,C,D;

void setup()
{
  Serial.begin(9600);
  pinMode(pump,OUTPUT);
  
  lcd.begin(16,2);
  
  //Esta sequencia de comandos deve ser escrita apenas uma vez, para 
//configurar a hora do Shield RTC 1307. Troque os numeros pela hora atual

/*RTC.stop();
RTC.set(DS1307_SEC,1); //define o segundo
RTC.set(DS1307_MIN,41); //define o minuto
RTC.set(DS1307_HR,10); //define a hora
RTC.set(DS1307_DOW,1); //define o dia da semana
RTC.set(DS1307_DATE,22); //define o dia
RTC.set(DS1307_MTH,12); //define o mes
RTC.set(DS1307_YR,13); //define o ano
RTC.start();
*/

}

void loop()
{

 RTC.get(rtc,true);
 
 //*********************** Escrita no LCD ************************
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Hora:");
 
 lcd.setCursor(6,0);
 lcd.print(rtc[2]);
 
 lcd.setCursor(8,0);
 lcd.print(":");
 
 lcd.setCursor(9,0);
 lcd.print(rtc[1]);
 
 lcd.setCursor(11,0);
 lcd.print(":");
 
 lcd.setCursor(12,0);
 lcd.print(rtc[0]);
 
 lcd.setCursor(0,1);
 if(ctrPump == 1)
 {
   lcd.print("Irrigacao Ligada");
 }
 else
 {
   lcd.print("Irrigacao Desligada");
 }
 //**************** Fim escrita LCD ******************************
 
 
 // Imprime  Horas:Minutos:Segundos
 
 Serial.print(rtc[2]); //rtc[2] imprime horas
 Serial.print(":");
 Serial.print(rtc[1]); //rtc[1] imprime minutos
 Serial.print(":");
 Serial.println(rtc[0]); //rtc[0] imprime segundos 
 
 /* Neste exemplo, ligamos a bomba na mesma hora em minutos diferentes
 e também a desligamos assim.*/
 
 if(rtc[1]%2 == 0)
 {
   
   A = 10; //Liga
   B = 30; //Desliga 
   
   C = 40; //Liga novamente
   D = 50; //Desliga 
   
   //Para minutos rtc[1] e para segundos rtc[0];
   
   /*Primeiro a bomba é ligada no intervalo entre A e B minutos 
   e depois é ligada  novamente no intervalo entre C e D minutos.
   */
               //A                B                C               D
   if((rtc[0] >= A && rtc[0] <= B) || (rtc[0] >= C && rtc[0] <= D))
   {
     digitalWrite(pump,HIGH);
     ctrPump = 1;
   }
   /*Depois a bomba é desligada no intervalo entre B e C minutos,
    quando é novamente ligada, e desligada novamente em D minutos*/
   if((rtc[0] > B && rtc[0]< C)||(rtc[0] > D))
   {
     digitalWrite(pump,LOW);
     ctrPump = 0;
   }
 }
 
  delay(1000);

}


