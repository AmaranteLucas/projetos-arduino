#include <Servo.h>

Servo servo, servo_2;

#define echoPin 13 //Pino 13 recebe o pulso do echo  
#define trigPin 12 //Pino 12 envia o pulso para gerar o echo  
  
int LDR=A0;
int led_dir=7;
int led_esq=6;

void setup()  
{  
   Serial.begin(9600); //inicia a porta serial  
   pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)  
   pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)  
   
   servo.attach(9);
   servo_2.attach(10);
   
   pinMode(led_dir,OUTPUT);
   pinMode(led_esq,OUTPUT);
}  
  
void loop()  
{  
  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0  
    digitalWrite(trigPin, LOW);  
  // delay de 2 microssegundos  
    delayMicroseconds(2);  
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1  
    digitalWrite(trigPin, HIGH);  
  //delay de 10 microssegundos  
    delayMicroseconds(10);  
  //seta o pino 12 com pulso baixo novamente  
    digitalWrite(trigPin, LOW);  
  //pulseInt lê o tempo entre a chamada e o pino entrar em high  
    long duration = pulseIn(echoPin,HIGH);  
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado  
  //porque é o tempo de ida e volta do ultrassom  
    long distancia = duration /29 / 2 ;  
  
Serial.print("Distancia em CM: ");  
Serial.println(distancia);  

frente();

if(distancia<=20)
{
para();
vira();
para();
}

int sensor = analogRead(LDR);
  
  Serial.print("Valor LDR: ");
  Serial.println(sensor);
  
  if(sensor<=250)
  {
    digitalWrite(led_dir,HIGH);
    digitalWrite(led_esq,HIGH);
  }
  else
  {
    digitalWrite(led_dir,LOW);
    digitalWrite(led_esq,LOW);
  }

delay(200); //espera 1 segundo para fazer a leitura novamente  
}  

void frente()
{
  servo.attach(9);
  servo.write(180);
  servo_2.attach(10);
  servo_2.write(0);
}


void tras()
{
  servo.attach(9);
  servo.write(0);
  servo_2.attach(10);
  servo_2.write(180);
}

void para()
{
  servo.detach();
  servo_2.detach();
}

void vira()
{
  servo.attach(9);
  servo.write(0);
  delay(785);
}
