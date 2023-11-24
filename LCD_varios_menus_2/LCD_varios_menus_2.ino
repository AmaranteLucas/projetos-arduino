/****************************************************************
*                       ARDUINO HOME CONTROL                    *
*****************************************************************
* Código para controlar 4 dispositivos com controle remoto IR e
* ter informações de temperatura e luminosidade em um display
* LCD 16x2.
* 
* Versão: 1.01
* Criador: Lucas Bastos 
* Data: 04/11/2013
*
* Comando controle NEC(pode ser adaptado para outro controle IR):
*
* Tecla numérica 0: Exibe temperatura
* Tecla 200+: Exibe luminosidade
* Tecla EQ: Exibe tela inicial
* Teclas numériacas 1 à 4: Seleciona os dispositivos 1 à 4.
* Tecla Vol+: Aciona o dispositivo selecionado
* Tecla Vol-: Desliga o dispositivo selecionado
*
*/

#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

//################## Controle Remoto ###########################
#define RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

#define flash=6;

//#############################################################

//#################### Sensor de Temperatura ##################

#define lm35=A0;

float temperatura;

//###############################################################

//#################### Sensor de Luminosidade ##################

#define ldr=A1;

float luminosidade;

//###############################################################

//######################## Dispositivos #########################

#define disp_1=2;
#define disp_2=3;
#define disp_3=4;
#define disp_4=5;

int act=0; // Variável que controla qual dispositivo foi selecionado
// no menu.

//###############################################################

//####################### Caracteres Especiais ##################

//Desenho icone temperatura.
char tmp[8] = {
0b00100,
0b01010,
0b01010,
0b01110,
0b01110,
0b11111,
0b11111,
0b01110 };

// Desenho icone de Graus .
char cel[8] = {
0b01100,
0b10010,
0b10010,
0b01100,
0b00000,
0b00000,
0b00000,
0b00000 };

//###############################################################


void setup(){
  
  irrecv.enableIRIn(); // Inicia o receptor IR
  
  lcd.begin(16,2); //Inicia o display 16x2
  
  lcd.clear(); //Limpa o display
  lcd.setCursor(4,0);
  lcd.print("Arduino");
  lcd.setCursor(2,1);
  lcd.print("Home Control");
  
  for(int i=2;i<=6;i++){
    pinMode(i,OUTPUT);
  }
  
  lcd.createChar(1,(uint8_t*)tmp); //Cria icone da teperatura
  lcd.createChar(2,(uint8_t*)cel);  //Cria icone do Graus
  
}

void loop(){
  
  if(irrecv.decode(&results)){
    
    flash_ir();
    
    switch(results.value){
      
      //############ Mostra Temperatura #################
      
      case 16738455: //Tecla 0
      
      escreve_temp();
      act=0;
      
      break;
      
      //############ Mostra Luminosidade #################
      
      case 16756815: //Tecla 200+
      
      luminosidade=map(analogRead(ldr),0,1023,0,100);
      
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Luminosidade");
      lcd.setCursor(6,1);
      lcd.print(luminosidade);
      act=0;
      
      break;
      
      
      // ################### Dispositivo 1 ##############
      
      case 16724175: //Tecla 1
      
      escreve_disp("Dispositivo 1");
      act=1;
      
      break;
      
      // ################### Dispositivo 2 ##############
      
      case 16718055:// Tecla 2
      
      escreve_disp("Dispositivo 2");
      act=2;
           
      break;
      
      // ################### Dispositivo 3 ##############
      
      case 16743045:// Tecla 3
      
      escreve_disp("Dispositivo 3");  
      act=3;
      
      break;
      
      // ################### Dispositivo 4 ##############
      
      case 16716015:// Tecla 4
      
      escreve_disp("Dispositivo 4");
      act=4;
      
      break;
      
      // Liga o dispositivo selecionado anteriormente
      
      case 16754775: //Tecla de Vol + (Usada para ligar os dispositivos)
      
      switch(act){
        
        case 1:
        
        escreve_disp("Dispositivo 1");
        escreve_estado("Ligado",disp_1,1);
        
        break;
        
        case 2:
        
        escreve_disp("Dispositivo 2");
        escreve_estado("Ligado",disp_2,1);
        
        break;
        
        case 3:
        
        escreve_disp("Dispositivo 3");
        escreve_estado("Ligado",disp_3,1);
        
        break;
        
        case 4:
        
        escreve_disp("Dispositivo 4");
        escreve_estado("Ligado",disp_4,1);
        
        break;
        
      }
      break;
      
      // Desliga o dispositivo selecionado anteriormente
      
      case 16769055: //Tecla de Vol - (Usada para desligar os dispositivos)
      
      switch(act){
        
        case 1:
        
        escreve_estado("Desligado",disp_1,0);
        
        break;
        
        case 2:
        
        escreve_estado("Desligado",disp_2,0);
        
        break;
        
        case 3:
        
        escreve_estado("Desligado",disp_3,0);
        
        break;
        
        case 4:
        
        escreve_estado("Desligado",disp_4,0);
        
        break;
        
      }
      break;
      
      case 16748655: //Tecla EQ
      
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Arduino");
      lcd.setCursor(2,1);
      lcd.print("Home Control");
      act=0;
      
      break;
      
    }
    
    irrecv.resume(); // Receive the next value

  }
  delay(100);
  
}

void flash_ir(){ //Função para piscar o led
  
  digitalWrite(flash,HIGH);
  delay(5);
  digitalWrite(flash,LOW);
  
}

void escreve_temp(){ //Função para escrever no LCD a temperatura
  
  temperatura = analogRead(lm35)*0.488758553;
  
  lcd.clear();
  
  // Escreve a palavra Temperatura
  lcd.setCursor(2,0);
  lcd.print("Temperatura");
  
  //Escreve o icone de termometro
  lcd.setCursor(1,1);
  lcd.write(1);
  
  // Escreve o valor de temperatura lido
  lcd.setCursor(5,1);
  lcd.print(temperatura);
  
  // Escreve o simbolo de graus
  lcd.setCursor(11,1);
  lcd.write(2);
  
  // Escreve a letra C
  lcd.setCursor(12,1);
  lcd.print("C");
  
}

void escreve_disp(String c){//função que escreve na coluna 2 linha 0
  
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print(c); 
      
}

//Função para Escrever no LCD o status de um dos dispositivos
//Parametros: Status,o número do pino dispositivo a ser controlado,
// O nível lógicodo pino 1 ligado ou 0 desligado.
void escreve_estado(String c,int disp,int state){ 
  
  lcd.setCursor(3,1);
  lcd.print(c);
  digitalWrite(disp,state);  
}




  
  
  
