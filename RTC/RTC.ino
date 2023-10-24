// Modificated by SoBraL - mr.sobral@hotmail.com
// Font: http://arduino.cc/forum/index.php/topic,8833.0.html
// Before you need to install the library DS1307: http://bricofoy.free.fr/forums/arduino/DS1307.zip
#include <WProgram.h> //é um recurso para referenciar a biblioteca Wiring
#include <Wire.h> //inclui a biblioteca Wire necessaria para comunicaçao i2c
#include <DS1307.h> //inclui a biblioteca de comandos do DS1307 utilizada neste programa. Necessário baixá-la no link acima
int rtc[7];
int rele = 10;
int led = 13;
void setup()
{
Serial.begin(9600);
pinMode(rele, OUTPUT); //define o pino 10 como saída
pinMode(led, OUTPUT); //define o led (pino 13) do arduino como como saída
digitalWrite (rele, LOW); //desliga relé
digitalWrite(led, LOW); //desliga led

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
/*
Comando utilizado apenas pra ficar enviando via USB a hora atual
para que possam monitorar no "serial monitor" do simulador Arduino
e ver se esta tudo funcionando de acordo 
*/


Serial.print(rtc[2]);
Serial.print(":");
Serial.print(rtc[1]);
Serial.print(":");
Serial.print(rtc[0]);
Serial.println();
/*
O codigo abaixo significa que, quando o RTC estiver no segundo 22,
ele irá acionar o relé e o led. Para utilizar o minuto como referencia,
alterar rtc[0] para rtc[1], e assim sussecivamente
*/
if (rtc[0] == 22) { 
digitalWrite(rele, HIGH);
digitalWrite(led, HIGH);
}
delay(1000);
}
