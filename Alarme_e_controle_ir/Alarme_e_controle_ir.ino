#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

int controle = LOW;

int sensor = 7; 
int status_sensor;
int disparo;

int sirene = 8;
int alarme_acionado = 9;
int alarme_desligado = 10;

void setup()
{
  Serial.begin(9600);
  
  pinMode(sensor,INPUT);
  pinMode(sirene,OUTPUT);
  pinMode(alarme_acionado,OUTPUT);
  pinMode(alarme_desligado,OUTPUT);
  
  irrecv.enableIRIn(); // Start the receiver
  
  irrecv.blink13(true);
}

void loop()
{
  
  status_sensor = digitalRead(sensor);
  
  Serial.println(status_sensor);
  
  
    //********* Leds indicadores do alarme *********************
    digitalWrite(alarme_acionado,!controle);
    digitalWrite(alarme_desligado,controle);
    //**********************************************************
    
    if(status_sensor == 1)
    {
      disparo = 1;
    }
    
    if(controle == HIGH)
    {
      disparo = 0;
    }
  
  if(disparo == 1 && controle == LOW)
  {
    digitalWrite(sirene,HIGH);
    delay(100);
    digitalWrite(sirene,LOW);
    delay(20);
  }
  else
  {
    digitalWrite(sirene,LOW);
  }
  
  //############################## IR ############################
    if (irrecv.decode(&results)) {
    Serial.println(results.value);
    
    if(results.value == 16646399)
    {
      controle = !controle;
    }
    irrecv.resume(); // Receive the next value
  }
  //################################################################
  
  delay(10);
}
  
