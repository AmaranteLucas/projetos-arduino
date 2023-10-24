int val=1;
void setup()
{
  
  Serial.begin(9600);
  
  for(int i=2; i<=7; i++)
  {
    pinMode(i, OUTPUT);
  }
  
  pinMode(9,INPUT);
  pinMode(8,INPUT);
}

void loop()
{
  if(digitalRead(9)==1)
  {
    val=val+1;
    if(val>7){val=7;}
    digitalWrite(val,HIGH);
    Serial.println(val);
  }
  
  if(digitalRead(8)==1)
  {
    val=val-1;
    if(val<2){val=1;}
    digitalWrite(val+1,LOW);
    Serial.println(val);
  }
  
  delay(150);
  
}
