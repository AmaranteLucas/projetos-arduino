#include <Wire.h>
#include <DS1307.h> // written by  mattt on the Arduino forum and modified by D. Sjunnesson

//rtc[0] imprime os segundos 
//rtc[2] imprime os minutos 
//rtc[3] imprime as horas
//rtc[4] imprime o dia da semana entre 1(domingo) e 6 (sábado)
//rtc[5] imprime o dia 
//rtc[6] imprime o mes 
//rtc[7] imprime o ano

int rtc[7];

void setup()
{
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  
  //Esta sequencia de comandos deve ser escrita apenas uma vez, para 
//configurar a hora do Shield RTC 1307. Troque os numeros pela hora atual

/*RTC.stop();
RTC.set(DS1307_SEC,1); //define o segundo
RTC.set(DS1307_MIN,57); //define o minuto
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
 
 
 // Imprime  Horas:Minutos:Segundos
 
 Serial.print(rtc[2]); //rtc[2] imprime horas
 Serial.print(":");
 Serial.print(rtc[1]); //rtc[1] imprime minutos
 Serial.print(":");
 Serial.println(rtc[0]); //rtc[0] imprime segundos 
 
 
 //Liga o pino 8 quando estiver em qualquer hora, minuto e segundo 30.
 if(rtc[0]>=30)
 {
   digitalWrite(8,HIGH);
 }
 
 //Desliga o pino 8 quando estiver em qualquer hora, minuto e segundo 59.
 if(rtc[0]>=59)
 {
   digitalWrite(8,LOW);
 }

  delay(1000);

}


