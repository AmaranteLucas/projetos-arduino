//######################## Controle do Robot #####################
//########################### EMISSOR ############################
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

//Declara os botoes do controle
int botao_frente = 2;
int botao_tras = 3;
int botao_dir = 4;
int botao_esq = 5;
int botao_farol = 6;

//Declara o estado inicial dos botoes
int state_botao_frente = 0;
int state_botao_tras = 0;
int state_botao_dir = 0;
int state_botao_esq = 0;
int state_botao_farol = 0;

// Funcao de configuracao
void setup()
{
  //Habilita o pino 10 para ligar no transmissor
  mySwitch.enableTransmit(10);
  
  delay(500); 
  
  for(int i=2;i<=6;i++)
  {
    pinMode(i,INPUT);
  }
}

//Funcao principal (Loop infinito)
void loop()
{
 
 //Leitura do estado dos botoes
 state_botao_frente = digitalRead(botao_frente);
 state_botao_tras = digitalRead(botao_tras);
 state_botao_dir = digitalRead(botao_dir);
 state_botao_esq = digitalRead(botao_esq);
 state_botao_farol = digitalRead(botao_farol);
 
 //Envia os comandos correspondentes aos botoes pressionados
 
 if(state_botao_frente == 0)
 {
   mySwitch.send(1,24);
 }
 
 if(state_botao_tras == 0)
 {
   mySwitch.send(2,24);
 }
 
 if(state_botao_dir == 0)
 {
   mySwitch.send(3,24);
 }
 
 if(state_botao_esq == 0)
 {
   mySwitch.send(4,24);
 }
 
 if(state_botao_farol == 0)
 {
   mySwitch.send(5,24);
 }
 
  delay(100);
}
