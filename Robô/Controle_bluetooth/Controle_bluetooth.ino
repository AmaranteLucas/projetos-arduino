#include <Servo.h>

Servo servo,servo2;

char val;

int farol = 7;
int ctrFarol = LOW;

int luzPosicao = 6;

void setup()
{
  Serial.begin(9600);
  servo.attach(9);
  servo2.attach(10);
  pinMode(farol,OUTPUT);
  pinMode(luzPosicao,OUTPUT);
}

void loop()
{
  if(Serial.available()>0)
  {
     val = Serial.read();
    
    if(val != 'e')
    {
      servo.attach(9);
      servo2.attach(10);
    }

    Serial.println(val);
    
     if(val == 'a')
    {
      servo.write(180);
      servo2.write(0);
    }
    if(val == 'b')
    {
      servo.write(0);
      servo2.write(180);
    }
    if(val == 'c')
     {
      servo.write(180);
      servo2.write(180);
    }
    if(val == 'd')
    {
      servo.write(0);
      servo2.write(0);
    }
     if(val == 'e')
    {
      ctrFarol = !ctrFarol;
    }
  }
    else
    {
      servo.detach();
      servo2.detach();
    }
    
          digitalWrite(farol,ctrFarol);
          
    delay(105);
    
}
