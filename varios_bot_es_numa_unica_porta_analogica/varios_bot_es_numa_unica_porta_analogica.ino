int botao=A0,val;

void setup(){

  Serial.begin(9600);
  pinMode(botao,INPUT);

}

void loop(){
  
  val= analogRead(botao);
  
  Serial.println(val);
  
  delay(500);
  
}
