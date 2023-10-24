
int botao=A0;
int val[]={0,0};
int tentativa=0;
int teste[]={0,0,0,0,0};

void setup(){
  
 Serial.begin(9600);
 pinMode(botao,INPUT);
 
}

void loop(){
  
    while(tentativa<3){
  
     LerBotao(val[0],1);
  
     LerBotao(val[1],2);
  
     compara(0,860,940);
     compara(1,960,986);
     
     for(int i=0,i<2;i++){
       if(teste[i]==0)
     
 
 Serial.println("Senha Correta");
 
else{
  tentativa=tentativa+1;
  Serial.println("Senha incorreta");
  Serial.println("Voce tem apenas");
  Serial.println(3-tentativa);
  Serial.println("tentativas");
}
}
Serial.println("#######################################");
Serial.println("Voce esgotou o numero de tentativas");
Serial.println("O Arduino foi bloqueado");
Serial.println("#######################################");
delay(1000*100);
}

// #################### FUNÇÕES ########################  

void LerBotao( int bt, int i){
 
  Serial.print("Pressione o botao");
  Serial.println(i);
  
    bt=analogRead(botao);
    
  while(bt<=40){
     bt=analogRead(botao);
     delay(250);
  }
  
  Serial.println(bt);
  
}  

void compara(int j, int rg1, int rg2){
  
  if((val[j]>=rg1)&&(val[j]<=rg2)){
    teste[0]=1;
  }
  
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
