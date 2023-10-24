
void setup(){
  
  for(int i=2;i<=8;i++){
    pinMode(i,OUTPUT);
  }
  
  for(int i=9;i<=12;i++){
    pinMode(i,INPUT);
  }
  
}

int indice=0;

void loop(){
  
  
  
  if(digitalRead(9))indice=1;
  if(digitalRead(10)) indice=2;
  if(digitalRead(11))indice=3;
  if(digitalRead(12))indice=4;
  
  switch(indice){
  
  case 1:
  //APAGA
  escreve(0,0,0,0,0,0,0,0);
  break;
  
  
  case 2:
  escreve(0,0,0,0,0,0,0,0);
  //NUMERO 1
  escreve(0,1,1,0,0,0,0,0);
  break;

 
  case 3:
  escreve(0,0,0,0,0,0,0,0);
  //NUMERO 2
  escreve(1,1,0,1,1,0,1,0);
  break;

  case 4:
  escreve(0,0,0,0,0,0,0,0);
  //NUMERO 3
  escreve(1,1,1,1,0,0,1,0);
  break;
  
  }
}


void escreve(int d0,int d1,int d2,int d3,int d4,int d5,int d6,int d7){
  
  digitalWrite(2,d0);
  digitalWrite(3,d1);
  digitalWrite(4,d2);
  digitalWrite(5,d3);
  digitalWrite(6,d4);
  digitalWrite(7,d5);
  digitalWrite(8,d6);
  digitalWrite(9,d7);
  
}
  

