int led=9, botao_1=3,botao_2=4, val=0;

void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(botao_1,INPUT);
  pinMode(botao_2,INPUT);

}

void loop(){

  
  
  if(digitalRead(botao_1)== HIGH){
  val=val+51;
  if(val>255){
    val=255;
  }
  Serial.println(val);
  }
  if(digitalRead(botao_2)== HIGH){
    val=val-51;
    if(val<0){
      val=0;
    }
    Serial.println(val);
  }
  analogWrite(led,val);
  
  delay(250);
}
