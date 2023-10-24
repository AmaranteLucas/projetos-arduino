
int Sensor = 3;
int buzzer=8;

void setup()
{
  Serial.begin(9600);
  pinMode(Sensor,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  
  int LeituraSensor = digitalRead(Sensor);
  
  if(LeituraSensor == 1)
  {
    digitalWrite(buzzer,HIGH);
  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
  
  Serial.println(digitalRead(Sensor));
  delay(1);
}
