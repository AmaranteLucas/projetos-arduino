#include <IRremote.h> // Inclui a Biblioteca do receptor IR.
#include <Stepper.h>  // Inclui a Biblioteca do Motor de Passo.

const int stepsPerRevolution = 300; /* Declaração do número de 
passos por revolução. */

int RECV_PIN = 11; // Pino do receptor IR.

int green=3,red=2,blue=8; // Declaração dos Leds.

int rele=12; // Declaração do Relê. 

IRrecv irrecv(RECV_PIN); // Função para o funcionamento do IR.

decode_results results; // Função para o funcionamento do IR.

//Configura o número de passos e os pinos que vão controlar o motor.
Stepper myStepper(stepsPerRevolution, 4,5,6,7); 

void setup()
{
  irrecv.enableIRIn(); // Inicia o receptor.
   myStepper.setSpeed(60); //Inicia a velocidade do motor de passo.
   
   //Inicia os Leds e o Rele como saídas.
   pinMode(green,OUTPUT);
   pinMode(red,OUTPUT);
   pinMode(blue,OUTPUT);
   pinMode(rele,OUTPUT);
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
    
      motorahr(600); // Função para girar o motor de passo
                     // no sentido horário.
      break;
      
    case 16712445: //Caso o botão pressionado seja o PREV
    
      motorhr(600); // Função para girar o motor de passo 
                    // no sentido anti-horário.  
      break;
      
     case 16724175: // Caso o botão 1 seja pressionado.
      
         motorahr(300);
         motorhr(300);
         motorahr(500);
         motorhr(500);
      
      break;
        
      case 16754775: // Caso o botão Vol + seja pressionado.
      
       digitalWrite(rele,HIGH); // Liga o Relê.
       
      break;
      
      case 16769055: // Caso o botão Vol - seja pressionado.
      
         digitalWrite(rele,LOW); // Desliga o Relê.
       
      break;
      
      case 16738455: // Caso o botao 0 seja pressionado.
        
        digitalWrite(rele,HIGH);
        motorahr(300);
        motorhr(300);
        digitalWrite(rele,LOW);
        motorahr(300);
        digitalWrite(rele,HIGH);
        motorhr(300);
        digitalWrite(rele,LOW);
      
      break;
      
  }
   irrecv.resume(); // Recebe o próximo valor do IR.
  }
  
  delay(100); // Espera 100 milissegundos.
}

//#####################FUNÇÕES#################################

void motorahr(int steps){
  
  digitalWrite(red,HIGH); // Liga o Led vermelho.
  digitalWrite(green,LOW);// Desliga o Verde.
       
   myStepper.step(-steps);// O Motor dá "steps" passos no sentido 
                          // anti-horário.
                          
   digitalWrite(red,LOW);// Desliga o Led vermelho.
   
}

void motorhr(int steps){
  
  digitalWrite(green,HIGH); // Liga o Led verde.
  digitalWrite(red,LOW); // Desliag o Led Vermelho.
    
  myStepper.step(steps);// O Motor dá "steps" passos no sentido
                       // horário.    
                       
  digitalWrite(green,LOW); // Desliga o Led verde.

}

//###############################################################
