#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

int botao_1=2, botao_3=3,tmin,indice,indice_2;


void setup(){
  
  lcd.begin(16,2);
}

void loop(){
  
  if(digitalRead(botao_1)){
       indice=1;
     }
     if(digitalRead(botao_3)){
       indice=2;
     }

switch(indice){
  
  case 1:
   
     if(digitalRead(botao_1)){
       indice_2=1;
     }
     if(digitalRead(botao_3)){
       indice_2=2;
     }
     
     switch(indice_2){
       
        case 1: 
          
          tmin=tmin-1;
          
          lcd.setCursor(0,1);
          lcd.print(tmin);
          
          break;
     }
     
     break;
}
        
}        
        
        
        
        
