#include <IRremote.h> // Inclui a Biblioteca do receptor IR.
#include <Stepper.h>  // Inclui a Biblioteca do Motor de Passo.

const int stepsPerRevolution = 300; /* Declaração do número de 
passos por revolução. */

int RECV_PIN = 11; // Pino do receptor IR.

int green=3,red=2,blue=8;// Declaração dos Leds.

IRrecv irrecv(RECV_PIN); // Função para o funcionamento do IR.

decode_results results; // Função para o funcionamento do IR.

//Configura o número de passos e os pinos que vão controlar o motor.
Stepper myStepper(stepsPerRevolution, 4,5,6,7); 

void setup()
{
  irrecv.enableIRIn(); // Inicia o receptor.
   myStepper.setSpeed(60); //Inicia a velocidade do motor de passo.
   
   //Inicia os Leds
   pinMode(green,OUTPUT);
   pinMode(red,OUTPUT);
   pinMode(blue,OUTPUT);
}

void loop() {
  
  if (irrecv.decode(&results)){ // Caso receba algum valor no IR
  // executa o código abaixo.
    
//##Faz o led azul piscar quando recebe um sinal do controle IR##
    digitalWrite(blue,HIGH);
    delay(5);
    digitalWrite(blue,LOW);
//###############################################################

  switch(results.value){ // Testa os valores recebidos.
    
    case 16720605: //Caso o botão pressionado seja o NEXT.
    
      digitalWrite(red,HIGH); // Liga o Led vermelho.
      digitalWrite(green,LOW);// Desliga o Verde.
       
      myStepper.step(600);// O Motor dá 600 passos no sentido 
                          // horário.
      
      digitalWrite(red,LOW);// Desliga o Led vermelho.
      
      break;
      
    case 16712445: //Caso o botão pressionado seja o PREV
    
       digitalWrite(green,HIGH); // Liga o Led verde.
       digitalWrite(red,LOW); // Desliag o Led Vermelho.
    
       myStepper.step(-600);// O Motor dá 600 passos no sentido
                            // anti-horário.
                            
       digitalWrite(green,LOW); // Desliga o Led verde.
       
      break;
      
  }
   irrecv.resume(); // Recebe o próximo valor do IR.
  }
  
  delay(100); // Espera 100 milissegundos.
}


