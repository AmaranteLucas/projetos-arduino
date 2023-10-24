void setup()
{
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
}

void loop()
{
  
  if(digitalRead(8)==HIGH)
  {
  Serial.print("a");
  }
  
  if(digitalRead(9)==HIGH)
  {
  Serial.print("c");
  }
  delay(1);
}
  
