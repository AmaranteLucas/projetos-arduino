
int buzzer = 9;

void setup()
{
  pinMode(buzzer,OUTPUT);
  
  for(int i=2;i<=8;i++)
  {
    pinMode(i,INPUT);
  }
}

void loop()
{
  
  int tempo=100;
  
  if(!digitalRead(2)) //Lá
  {
    tone(buzzer,440,tempo);
  }
  
  if(!digitalRead(3)) //Si
  {
    tone(buzzer,495,tempo);
  }
  
  if(!digitalRead(4)) //Dó
  {
    tone(buzzer,528,tempo);
  }
  
  if(!digitalRead(5)) //Ré
  {
    tone(buzzer,594,tempo);
  }
  
  if(!digitalRead(6)) //Mi
  {
    tone(buzzer,660,tempo);
  }
  
  if(!digitalRead(7)) //Fá
  {
    tone(buzzer,698,tempo);
  }
  
  if(!digitalRead(8)) // Sol
  {
    tone(buzzer,783,tempo);
  }
  
}
  
