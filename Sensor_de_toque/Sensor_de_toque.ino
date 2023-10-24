int sensor=8;
int rele=7;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(rele,OUTPUT);
}

void loop()
{
  if(digitalRead(8)==1)
  {
    Serial.println("Encostou");
    digitalWrite(rele,HIGH);
    delay(5000);
    digitalWrite(rele,LOW);
  }
  delay(10);  
}
