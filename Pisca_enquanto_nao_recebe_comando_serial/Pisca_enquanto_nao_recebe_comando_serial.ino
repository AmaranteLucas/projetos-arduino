 int led1 = 3;
int val=0;

void setup(){
Serial.begin(9600); // Velocidade de transmissão
pinMode(led1,OUTPUT); 
}

void loop(){

  if(Serial.available()>0)
  {
    val=1;
  }
  
  if(val==0)
  {
    digitalWrite(3,HIGH);
    delay(100);
    digitalWrite(3,LOW);
    delay(100);
  }
  
}
