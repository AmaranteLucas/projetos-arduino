
#include <Servo.h>

Servo myservo;

int leitura;
int controle=0;
int val=0;

void setup()
{
  myservo.attach(9);
  myservo.write(controle);
}

void loop()
{
  leitura=analogRead(A0);
  
  if((leitura<=200)&&(val==0))
  {
    
    myservo.write(controle);
    controle++;
    
    if(controle==180)
    {
      val=1;
    }
  }
  
  
  if((leitura<=200)&&(val==1))
  {
    myservo.write(controle);
    controle--;
    
    if(controle==0)
    {
      val=0;
    }
  }
  
  delay(5);
 
}
    
