char val;

void setup()
{
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop()
{
  if(Serial.available()>0)
  {
     val = Serial.read();
    
    Serial.println(val);
    
    if(val == 'a')
    {
      digitalWrite(9,HIGH);
    }
    if(val == 'b')
    {
      digitalWrite(8,HIGH);
    }
   
  }
    else
    {
      digitalWrite(9,LOW);
      digitalWrite(8,LOW);
    }
    
    delay(105);
}
