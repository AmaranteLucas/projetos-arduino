//Thiago Teixeira
#include <RCSwitch.h>

//Instacia a Biblioteca 
RCSwitch mySwitch = RCSwitch();
 
void setup() {
  Serial.begin(9600);
  // delay para estabilizacao do Sinal
  delay(500);
  pinMode(9,OUTPUT);
  
  //Seta como Receptor/ O “0″ é para não interromper, deixar continuo
  //O Pino padrão é o 2
  mySwitch.enableReceive(0);  

}
 
void loop() {
  //Quado estiver sinal disponivel
  if (mySwitch.available()) {
 
    //recebe na variavel value o Status
    int value = mySwitch.getReceivedValue();
    
    //Se o value for Zero
    if (value == 0) 
    {
      Serial.println("Codigo desconhecido");
    } 
    else 
    {
      //Valor Recebido
       float val = mySwitch.getReceivedValue();
      Serial.println(val);
    }
    
    //reseta “limpa” a instacia
    mySwitch.resetAvailable();
        
  }
  delay(5);
}


