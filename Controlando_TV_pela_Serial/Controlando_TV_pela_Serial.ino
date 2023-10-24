// Ligar o led no pino 3 do Arduino


#include <IRremote.h>

IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  
  char c=Serial.read();
  
  if (c=='c') {
    
      Serial.println("Ligando Conversor");
      irsend.sendNEC(0xFE00FF,32); // O primeiro é o código que o 
      // controle envia e o segundo o numero de bits
    
}

  if (c=='t') {
    
      Serial.println("Ligando TV");
      irsend.sendRC5(0x80C,12); // O primeiro é o código que o 
      // controle envia e o segundo o numero de bits
    
}

 if (c=='a') {
    
      Serial.println("Canal +");
      irsend.sendNEC(0xFE58A7,32); // O primeiro é o código que o 
      // controle envia e o segundo o numero de bits
    
}

if (c=='b') {
    
      Serial.println("Canal -");
      irsend.sendNEC(0xFED827,32); // O primeiro é o código que o 
      // controle envia e o segundo o numero de bits
    
}

if (c=='d') {
    
      Serial.println("Vol +");
      irsend.sendNEC(0xFEB04F,32); // O primeiro é o código que o 
      // controle envia e o segundo o numero de bits
    
}

if (c=='e') {
    
      Serial.println("Vol -");
      irsend.sendNEC(0xFE8877,32); // O primeiro é o código que o 
      // controle envia e o segundo o numero de bits
    
}


}

