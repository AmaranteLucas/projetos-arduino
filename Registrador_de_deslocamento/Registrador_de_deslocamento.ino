
int latch=8;
int data=9;
int clock=10;

void setup()
{
  pinMode(latch,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(clock,OUTPUT);
}

void loop()
{
  
  digitalWrite(data,HIGH);
  
  for(int i=0;i<16;i++)
  { 
    digitalWrite(clock,HIGH);
    delay(5);
    digitalWrite(clock,LOW);
    delay(5);
 
  
    digitalWrite(latch,HIGH);
    delay(25);
    digitalWrite(latch,LOW);
    delay(25);
  
    digitalWrite(data,LOW);
  
  }
   
}


