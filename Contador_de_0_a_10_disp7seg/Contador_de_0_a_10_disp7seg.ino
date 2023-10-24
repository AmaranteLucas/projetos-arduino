
void setup(){
  
  for(int i=2;i<=9;i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  
  //NUMERO 0
  escreve(1,1,1,1,1,1,0,0);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  //NUMERO 1
  escreve(0,1,1,0,0,0,0,0);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  //NUMERO 2
  escreve(1,1,0,1,1,0,1,0);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  //NUMERO 3
  escreve(1,1,1,1,0,0,1,0);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  //NUMERO 4
  escreve(0,1,1,0,0,1,1,0);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  //NUMERO 5
  escreve(1,0,1,1,0,1,1,0);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  //NUMERO 6
  escreve(1,0,1,1,1,1,1,0);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  //NUMERO 7
  escreve(1,1,1,0,0,0,0,0);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  //NUMERO 8
  escreve(1,1,1,1,1,1,1,1);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  //NUMERO 9
  escreve(1,1,1,1,0,1,1,0);
  delay(1000);
  escreve(0,0,0,0,0,0,0,0);
  delay(10);
  
  
  
  
  
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
  

