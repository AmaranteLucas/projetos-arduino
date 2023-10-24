
int botao=A0;
int val[]={0,0};
int senha[]={932,982};
int tentativa=0;

void setup(){
  
 Serial.begin(9600);
 pinMode(botao,INPUT);
 
}

void loop(){
  
  while(tentativa<3){
  
  Serial.println("Pressione o botao 1");
  
    val[0]=analogRead(botao);
    
  while(val[0]<=40){
     val[0]=analogRead(botao);
     delay(250);
  }
  
  Serial.println(val[0]);
  
 // #####################################################
 
  Serial.println("Pressione o botao 2");
 
 val[1]=analogRead(botao);
    
  while(val[1]<=40){
     val[1]=analogRead(botao);
     delay(250);
  }
  
  Serial.println(val[1]);
  
  delay(500);
  
 
    
if(((val[0]>=860)&&(val[0]<=940))&&((val[1]>=960)&&(val[1]<=986))){
  Serial.println("Senha Correta");
}  
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
  
