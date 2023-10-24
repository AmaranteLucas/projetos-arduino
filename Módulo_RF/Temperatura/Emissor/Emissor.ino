#include <RCSwitch.h>
//Thiago Teixeira
//Instacia a Biblioteca 
RCSwitch mySwitch = RCSwitch();
float temp;

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
  
    temp = analogRead(A0);
    
    temp=temp*0.488758553;
    
    mySwitch.send(temp,24);


 delay(50);
  
}
