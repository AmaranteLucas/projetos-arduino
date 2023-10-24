//########################## RECEPTOR #############################

#include <RCSwitch.h>
#include <Servo.h>

RCSwitch mySwitch = RCSwitch();

Servo servo_dir, servo_esq;

int farol = 7;
int state_farol=LOW;

int tempo = 0;

void setup()
{
  Serial.begin(9600);
  
  //Habilita a recepção, por padrão no pino 2, o "0" é para receber
  //continuamente.
  mySwitch.enableReceive(0);
  delay(500);
  
  servo_dir.attach(9);
  servo_esq.attach(10);
  
  pinMode(farol,OUTPUT);
}

void loop()
{
  if(mySwitch.available())
  {
    int value = mySwitch.getReceivedValue();
    
    Serial.println(value);

    
    switch(value)
    {
      case 0:
      Serial.println("Codigo desconhecido");
      break;
      
      case 1:
      //Frente
      frente();
      delay(tempo);
      para();
     
      break;
      
      case 2:
      //tras
      tras();
      delay(tempo);
      para();
      break;
      
      case 3:
      //direita
      direita();
      delay(tempo);
      para();
      break;
      
      case 4:
      //esquerda
      esquerda();
      delay(tempo);
      para();
      break;
      
      case 5:
      //farol
      state_farol=!state_farol;
      digitalWrite(farol,state_farol);
      break;
      
    }
    mySwitch.resetAvailable();
  }
  delay(10);
}

void frente()
{
  servo_dir.attach(9);
  servo_dir.write(180);
  servo_esq.attach(10);
  servo_esq.write(0);
}


void tras()
{
  servo_dir.attach(9);
  servo_dir.write(0);
  servo_esq.attach(10);
  servo_esq.write(180);
}

void para()
{
  servo_dir.detach();
  servo_esq.detach();
}

void direita()
{
  servo_dir.attach(9);
  servo_dir.write(180);
}

void esquerda()
{
  servo_esq.attach(10);
  servo_esq.write(0);
}


