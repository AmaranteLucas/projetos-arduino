
#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

//################## Controle Remoto ###########################
int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

int flash=6;

//#############################################################

//#################### Sensor de Temperatura ##################

int lm35=A0;

float temperatura;

//###############################################################

//######################## Dispositivos #########################

int disp_1=2;
int disp_2=3;
int disp_3=4;
int disp_4=5;

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
  
  irrecv.enableIRIn(); // Start the receiver
  
  lcd.begin(16,2);
  lcd.setCursor(3,0);
  lcd.print("Bem Vindo");
  
  for(int i=2;i<=6;i++){
    pinMode(i,OUTPUT);
  }
  
  lcd.createChar(1,(uint8_t*)tmp); //Cria icone da teperatura
  lcd.createChar(2,(uint8_t*)cel);  // cria icone do Graus
  
}

void loop(){
  
  temperatura=analogRead(lm35)*0.488758553;
  
  
  if(irrecv.decode(&results)){
    
    flash_ir();
    
    switch(results.value){
      
      //############ Mostra Temperatura #################
      
      case 16738455: //Tecla 0
      
      escreve_temp();
      
      break;
      
      // ################### Dispositivo 1 ##############
      
      case 16724175: //Tecla 1
      
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Dispositivo 1");
      act=1;
      
      break;
      
      // ################### Dispositivo 2 ##############
      
      case 16718055:// Tecla 2
      
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Dispositivo 2");
      act=2;
           
      break;
      
      // ################### Dispositivo 3 ##############
      
      case 16743045:// Tecla 3
      
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Dispositivo 3");    
      act=3;
      
      break;
      
      // ################### Dispositivo 4 ##############
      
      case 16716015:// Tecla 4
      
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Dispositivo 4");
      act=4;
      
      break;
      
      // Liga o dispositivo selecionado anteriormente
      
      case 16754775: //Tecla de Vol + (Usada para ligar os dispositivos)
      
      switch(act){
        
        case 1:
        
        lcd.setCursor(3,1);
        lcd.print("Ligado");
        digitalWrite(disp_1,HIGH);
        
        break;
        
        case 2:
        
        lcd.setCursor(3,1);
        lcd.print("Ligado");
        digitalWrite(disp_2,HIGH);
        
        break;
        
        case 3:
        
        lcd.setCursor(3,1);
        lcd.print("Ligado");
        digitalWrite(disp_3,HIGH);
        
        break;
        
        case 4:
        
        lcd.setCursor(3,1);
        lcd.print("Ligado");
        digitalWrite(disp_4,HIGH);
        
        break;
        
      }
      break;
      
      // Desliga o dispositivo selecionado anteriormente
      
      case 16769055: //Tecla de Vol - (Usada para desligar os dispositivos)
      
      switch(act){
        
        case 1:
        
        lcd.setCursor(3,1);
        lcd.print("Desligado");
        digitalWrite(disp_1,LOW);
        
        break;
        
        case 2:
        
        lcd.setCursor(3,1);
        lcd.print("Desligado");
        digitalWrite(disp_2,LOW);
        
        break;
        
        case 3:
        
        lcd.setCursor(3,1);
        lcd.print("Desligado");
        digitalWrite(disp_3,LOW);
        
        break;
        
        case 4:
        
        lcd.setCursor(3,1);
        lcd.print("Desligado");
        digitalWrite(disp_4,LOW);
        
        break;
        
      }
      break;
      
    }
    
    irrecv.resume(); // Receive the next value

  }
  delay(100);
  
}

void flash_ir(){
  
  digitalWrite(flash,HIGH);
  delay(5);
  digitalWrite(flash,LOW);
  
}

void escreve_temp(){
  
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
  
  
  
