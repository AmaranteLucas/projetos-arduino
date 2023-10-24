int led=7,led2=9, botao=8,botao2=6,val,val2,inc=0,inc2=0;

void setup(){
  
pinMode(led,OUTPUT);
pinMode(botao,INPUT);
pinMode(led2,OUTPUT);
pinMode(botao2,INPUT);

Serial.begin(9600);

}

void loop(){
  
  

  val=digitalRead(botao);
  val2=digitalRead(botao2);
  
  if(val==HIGH){

  inc=inc+1;
  
  Serial.println(inc);
  }
  
  
  if(inc%2!=0){
  
    digitalWrite(led,HIGH);
    
  }
  else{
    digitalWrite(led,LOW);
  }
  
// ################ Bloco para o segundo botão e Led ############
 
  if(val2==HIGH){

  inc2=inc2+1;
  
  Serial.println(inc2);
  }
  
  
  if(inc2%2!=0){
    
    digitalWrite(led2,HIGH);
    
  }
  else{
    digitalWrite(led2,LOW);
  }
  
  delay(150);
}
