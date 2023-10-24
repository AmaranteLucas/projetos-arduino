int rele= 8, n;


void setup()
{
  pinMode(rele,OUTPUT);
 Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0)
  {
    n = Serial.read();
    


    if(n==113)  // tecla q (minusculo)
    {
    digitalWrite(rele,HIGH);
    Serial.print("Voce digitou o comando para ligar o motor \n");
    }
    if(n==119)  // tecla W (minusculo)
    {
    digitalWrite(rele,LOW);
    Serial.print("Voce digitou o comando para desligar o motor \n");
    }
    
}
}
