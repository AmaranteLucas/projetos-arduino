
int val;
int count=0;
int botao_desliga = 7;

void setup()
{
  Serial.begin(9600);
  
  pinMode(botao_desliga,INPUT);
  pinMode(8,INPUT);
  
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop()
{

  val = digitalRead(8);

  if(val == 1)
  {
    count=count+1;
  }
  
  if(count >= 15)
  {
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
  }
  
  if(digitalRead(botao_desliga) == 1)
  {
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    count=0;
  }
  
  Serial.println(val);
  
  Serial.println(count);
  delay(100);
}
