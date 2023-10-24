
//Pratos

int chimbal_aberto =  2;
int chimbal_fechado =  3;
int ataque_1 = 4;
int ataque_2  = 5;
int ataque_3  = 6;
int conducao  = 7;

//Tambores

int bumbo = 8 ;
int caixa = 9;
int ton_1 = 10;
int ton_2 = 11;
int surdo = 12;

void setup()
{
  Serial.begin(9600);
  
  for(int i=2; i<=12; i++)
  {
    pinMode(i,INPUT);
  }
   Keyboard.begin();
}

void loop()
{

  //################## Leitura dos Pratos ########################
  
  if(digitalRead(chimbal_aberto) == HIGH)
  {
    Keyboard.print ("s");
  }
  
  if(digitalRead(chimbal_fechado) == HIGH)
  {
    Keyboard.print("z");
  }
  
  if(digitalRead(ataque_1) == HIGH)
  {
    Keyboard.print("e");
  }
  
  if(digitalRead(ataque_2) == HIGH)
  {
    Keyboard.print("t");
  }
  
  if(digitalRead(ataque_3) == HIGH)
  {
    Keyboard.print("u");
  }
  
  if(digitalRead(conducao) == HIGH)
  {
    Keyboard.print("a");
  }
  
  //#################### Fim leitura dos pratos ##################
  
  
  //################## Leitura dos Tambores ######################
  
  if(digitalRead(bumbo) == HIGH)
  {
    Keyboard.print("b");
  }
  
  if(digitalRead(caixa) == HIGH)
  {
    Keyboard.print("c");
  }
  
  if(digitalRead(ton_1) == HIGH)
  {
    Keyboard.print("f");
  }
  
  if(digitalRead(ton_2) == HIGH)
  {
    Keyboard.print("h");
  }
  
  if(digitalRead(surdo) == HIGH)
  {
    Keyboard.print("k");
  }
  //#################### Fim leitura dos tambores ##################
  
  delay(3);
  
}
