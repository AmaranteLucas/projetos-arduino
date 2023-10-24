int senha[]={4,5,6},comp_senha[]={0,0,0},i;
boolean teste=true;

void setup(){
  
  Serial.begin(9600);
}

void loop(){
  
  Serial.println("Digite os digitos da senha, um por um, dando Enter");
  
   delay(1000);
    
    Serial.println("Digite o primeiro digito");
    
    while(Serial.read()<0){
    comp_senha[0]= Serial.read();
    
    delay(500);
    }
    
    Serial.println(comp_senha[0]);
    
    Serial.println("Digite o segundo digito");
    
    while(Serial.read()<0){
    comp_senha[1]=Serial.read();
    
    delay(500);
    }
    
    Serial.println("Digite o terceiro digito");
    
    while(Serial.read()<0){
    comp_senha[2]=Serial.read();
    
    delay(500);
    }
  
  for(i=0;i<=3;i++){
    
    if(comp_senha[i]!=senha[i]){
     teste= false;
    }
  }
  if(teste==true){
    Serial.println("Senha correta");
  }
  else{
    Serial.println("Senha incorreta");
  }
}
    
    
