#include <Servo.h>

Servo servo;

char val;

void setup()
{
  Serial.begin(9600);
  servo.attach(9);
}

void loop()
{
  if(Serial.available()>0)
  {
   servo.attach(9);
     val = Serial.read();
    
    Serial.println(val);
    
    if(val == 'a')
    {
      servo.write(0);
    }
    if(val == 'b')
    {
      servo.write(180);
    }
   
  }
    else
    {
      servo.detach();
    }
    
    delay(100);
}
