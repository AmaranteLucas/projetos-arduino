
int vet[]={1,0,0,1,0,1,0,1,0,0,0,0,1,0,1};

void setup(){
  
  pinMode(3,OUTPUT);
  
}

void loop(){
  
    for(int i=0;i<=sizeof(vet);i++){//A função sizeof retorna
    digitalWrite(3,vet[i]); // o tamanho de um array  ou string.
    delay(500);
    }
  
}
