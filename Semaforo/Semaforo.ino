int car_verde = 5;
int car_amarelo = 6;
int car_vermelho = 7;

int ped_verde = 8;
int ped_vermelho = 9;

void setup()
{
  for(int i=5; i<=9; i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  digitalWrite(car_vermelho,LOW);
  digitalWrite(car_verde,HIGH);
  digitalWrite(ped_vermelho,HIGH);
  digitalWrite(ped_verde,LOW);
  delay(3000);
  
  digitalWrite(car_verde,LOW);
  digitalWrite(car_amarelo,HIGH);
  
  for(int i=0; i<=3; i++)
  {
    digitalWrite(ped_vermelho,HIGH);
    digitalWrite(ped_verde,HIGH);
    delay(250);
    digitalWrite(ped_vermelho,LOW);
    digitalWrite(ped_verde,LOW);
    delay(250);
  }
  
  digitalWrite(car_vermelho,HIGH);
  digitalWrite(car_amarelo,LOW);
  digitalWrite(ped_vermelho,LOW);
  digitalWrite(ped_verde,HIGH);
  delay(3000);
  
}
