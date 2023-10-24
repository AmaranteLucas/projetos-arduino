
void setup()
{
  Serial.begin(9600);
  
  for(int i=2;i<=8;i++)
  {
    pinMode(i,INPUT);
  }
}

void loop()
{
  if(digitalRead(2)==1)
  {
    Serial.println("Botao 1");
  }
  
  if(digitalRead(3)==1)
  {
    Serial.println("Botao 2");
  }
  
  if(digitalRead(4)==1)
  {
    Serial.println("Botao 3");
  }
  
  if(digitalRead(5)==1)
  {
    Serial.println("Botao 4");
  }
  
  if(digitalRead(6)==1)
  {
    Serial.println("Botao 5");
  }
  
  if(digitalRead(7)==1)
  {
    Serial.println("Botao 6");
  }
  
  if(digitalRead(8)==1)
  {
    Serial.println("Botao 7");
  }
  
  delay(100);
}
