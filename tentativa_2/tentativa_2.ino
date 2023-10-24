
int senha[]={49,50,51},i;
int comp_senha[]={0,0,0};
boolean teste=true;

void setup(){
  
  Serial.begin(9600);
  
}

void loop(){
  
  Serial.println("Digite o primeiro numero");
  
  comp_senha[0]=Serial.read();
  
  while(comp_senha[0]<=0){
    comp_senha[0]=Serial.read();
  }
 
  
  Serial.println("Digite o segundo numero");
  
  comp_senha[1]=Serial.read();
  
  while(comp_senha[1]<=0){
    comp_senha[1]=Serial.read();
  }
  
  
    
  Serial.println("Digite o terceiro numero");
  
  comp_senha[2]=Serial.read();
  
  while(comp_senha[1]<=0){
    comp_senha[2]=Serial.read();
  }
  
  
  for(i=0;i<3;i++){
    if(comp_senha[i]!=senha[i]){
      teste=false;
    }
  }
  
  if(teste==true){
    Serial.println("Senha correta");
  }
  
}
