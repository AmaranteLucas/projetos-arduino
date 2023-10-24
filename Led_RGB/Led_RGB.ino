
void setup()
{
}

void loop()
{
  
  analogWrite(9,255);
  analogWrite(10,255);
  analogWrite(11,255);
  delay(500);
  
  analogWrite(9,255);
  analogWrite(10,0);
  analogWrite(11,0);
  delay(500);
  
  analogWrite(9,0);
  analogWrite(10,255);
  analogWrite(11,0);
  delay(500);
  
  analogWrite(9,0);
  analogWrite(10,0);
  analogWrite(11,255);
  delay(500); 
  
  analogWrite(9,255);
  analogWrite(10,255);
  analogWrite(11,255);
  delay(500);
  
  analogWrite(9,255);
  analogWrite(10,0);
  analogWrite(11,255);
  delay(500);
  
  analogWrite(9,0);
  analogWrite(10,255);
  analogWrite(11,255);
  delay(500);
  
  analogWrite(9,255);
  analogWrite(10,255);
  analogWrite(11,0);
  delay(500); 
  
  for(int i=0; i<=255; i++)
  {
    analogWrite(9,i);
    analogWrite(10,255-i);
    analogWrite(11,0);
    delay(20);
  }
  
   for(int i=0; i<=255; i++)
  {
    analogWrite(9,0);
    analogWrite(10,i);
    analogWrite(11,255-i);
    delay(20);
  }
  
   for(int i=0; i<=255; i++)
  {
    analogWrite(9,i);
    analogWrite(10,0);
    analogWrite(11,255-i);
    delay(20);
  }
  
   for(int i=0; i<=255; i++)
  {
    analogWrite(9,i);
    analogWrite(10,i);
    analogWrite(11,255-i);
    delay(20);
  }
  
   for(int i=0; i<=255; i++)
  {
    analogWrite(9,i);
    analogWrite(10,i);
    analogWrite(11,i);
    delay(20);
  }
  
    for(int i=0; i<=255; i++)
  {
    analogWrite(9,255-i);
    analogWrite(10,255-i);
    analogWrite(11,255-i);
    delay(20);
  }
  
  
}
