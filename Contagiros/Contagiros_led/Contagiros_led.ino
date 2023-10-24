//******* Pinos utilizados ************
byte detecta = 2;
int shift_light = 13;
//* OBS.: São utilizados também os pinos de 3 à 13 e o pino A0. ******

//*************************************

//******************** Variáveis de controle *********************
int contador = 0;
int ctr_shift = 500;
int max_rpm;
//****************************************************************

void setup()
{
  //Acionando PULL-UP interno no pino 2
  pinMode(detecta,INPUT);
  digitalWrite(detecta,HIGH);
  
  //** Setando os pinos de 3 à 13 como saídas digitais ********
  for(int i=3;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  
  //** Setando o pino do shift light como saída digital
  pinMode(shift_light,OUTPUT);
  
  contador = 0;
  
  //Criando interrupção utilizando o pino 2
  attachInterrupt(0, DETECTA, FALLING);
  noInterrupts();
  
  //***** Acende todos os leds em sequencia **********
  for(int j=3; j<=12; j++)
  {
    digitalWrite(j,HIGH);
    delay(4000);
  }
  //***** Desliga todos os leds em sequencia *********
  for(int j=12; j>=3; j--)
  {
    digitalWrite(j,LOW);
    delay(4000);
  }
  
  delay (5000);
}

void loop()
{
  unsigned long tempo = millis();
  
  while(tempo + 100 > millis())
  {
    interrupts(); 
  }
  
  contador = contador * 300 ;
  
  turn_led(ctr_shift,3);
  turn_led(2*ctr_shift,4);
  turn_led(3*ctr_shift,5);
  turn_led(4*ctr_shift,6);
  turn_led(5*ctr_shift,7);
  turn_led(6*ctr_shift,8);
  turn_led(7*ctr_shift,9);
  turn_led(8*ctr_shift,10);
  turn_led(9*ctr_shift,11);
  turn_led(10*ctr_shift,12);
  
  //** Lê o potenciômetro que controla em qual rotação o ShiftLight
  //** acenderá.
  max_rpm = map(analogRead(A0),0,1023,1000,5000);
  
  //** Liga o ShiftLight de acordo com a rotação selecionada no Pot.
  turn_led(max_rpm,shift_light);
  
  contador = 0;
}

//*********************** Subrotinas *********************************

void DETECTA()
{
  contador ++;
}

void turn_led(int compara, int led)
{
  if(contador >= compara)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}
//*********************************************************************
