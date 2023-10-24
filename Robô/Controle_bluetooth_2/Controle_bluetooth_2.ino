//Inclui a biblioteca para controlar servo-motores.
#include <Servo.h>

//Declara os objetos servos
Servo servo,servo2;

//Variável que vai aramazenar os caracteres recebidos via bluetooth.
char val;


int farol = 7;
int ctrFarol = LOW;

void setup()
{
  Serial.begin(9600);
  servo.attach(9);
  servo2.attach(10);
  pinMode(farol,OUTPUT);
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

    Serial.print("Caracter recebido: ");
    Serial.println(val);
    Serial.print("Comando: ");
    
     if(val == 'a')
    {
      Serial.println("Frente");
      
      servo.write(180);
      servo2.write(0);
    }
    if(val == 'b')
    {
      Serial.println("Tras");
      
      servo.write(0);
      servo2.write(180);
    }
    if(val == 'c')
    {
      Serial.println("Direita");
      
      servo.write(180);
      servo2.write(180);
    }
    if(val == 'd')
    {
      Serial.println("Esquerda");
      
      servo.write(0);
      servo2.write(0);
    }
     if(val == 'e')
    {
      Serial.println("Liga ou Desl. farol");
      
      ctrFarol = !ctrFarol;
    }
    
    Serial.println("");
  }
    else
    {
      servo.detach();
      servo2.detach();
    }
    
          digitalWrite(farol,ctrFarol);
          
    delay(105);
    
}
