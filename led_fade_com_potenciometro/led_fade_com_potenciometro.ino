int led=3;
int pot=A0;
int lerpot;
void setup(){
  
  pinMode(led,OUTPUT);
  pinMode(pot,INPUT);
  
}

void loop(){
  
  lerpot=analogRead(pot);
  
  analogWrite(led,lerpot);
  
}  
  
