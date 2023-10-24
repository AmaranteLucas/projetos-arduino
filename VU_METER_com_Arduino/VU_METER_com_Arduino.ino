
int tempo=50;

void setup()
{
  for(int i=2;i<=11;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop()
{

  
 int val=analogRead(A0);
  
  int i=map(val,0,1023,2,11);
  
  digitalWrite(i,HIGH);
  digitalWrite(i+1,LOW);
  
  
}


  

    
    
