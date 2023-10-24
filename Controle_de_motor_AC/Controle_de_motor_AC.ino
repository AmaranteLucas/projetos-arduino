
#define rele 8


void setup()
{
  Serial.begin(9600);
  pinMode(rele,OUTPUT);
  Serial.println("*************Instrucoes****************");
  Serial.println("Digite (a) para ligar o motor");
  Serial.println("E (b) para desliga-lo");
  Serial.println("***************************************");
}

void loop()
{
  if(Serial.available()>0)
  {
    char c=Serial.read();
    
    if(c=='a')
    {
      Serial.println("Motor ligado");
      digitalWrite(rele,HIGH);
    }
    
    if(c=='b')
    {
      Serial.println("Motor desligado");
      digitalWrite(rele,LOW);
      Serial.println("Espere 30 segundos para liga-lo novamente");
      delay(30000);
      Serial.println("Tempo limite finalizado");
      Serial.println("******************************************");
    }
  }
  delay(100);
}
