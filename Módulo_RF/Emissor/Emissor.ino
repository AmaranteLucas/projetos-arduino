#include <RCSwitch.h>
//Thiago Teixeira
//Instacia a Biblioteca 
RCSwitch mySwitch = RCSwitch();

void setup() {
  
  //Inicia a Serial
  Serial.begin(9600);
  
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  
  // Seta como habititado para enviar o pino 10  
  mySwitch.enableTransmit(10);
  delay(500);
  
}
void loop() {

  //envia o comando desejado desejado
  
  if(digitalRead(7)==1)
  {
    mySwitch.send('a',24);
  }
   if(digitalRead(8)==1)
  {
    mySwitch.send('b',24);
  }

 delay(5);
  
}
