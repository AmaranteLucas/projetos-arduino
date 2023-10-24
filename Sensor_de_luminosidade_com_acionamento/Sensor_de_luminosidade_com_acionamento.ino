
int rele = 13;
int sensor_lum;

void setup()
{
  Serial.begin(9600);
  pinMode(rele,OUTPUT);
}

void loop()
{
  
  sensor_lum = analogRead(A0);
  
  Serial.println(sensor_lum);
  if(sensor_lum < 530)
  {
    digitalWrite(rele,HIGH);
  }
  else
  {
    digitalWrite(rele,LOW);
  }
  delay(10);
}
