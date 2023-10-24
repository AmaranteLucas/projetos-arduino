int tempo=80;

void setup()
{
  for(int i=2;i<=9;i++)
  {
    pinMode(i,OUTPUT);
  }
}


void loop()
{
 //func_1();
 //func_2();
 //func_3();
 func_4();
 

 
 
 

}

void func_1(void)
{
    for(int i=2;i<=5;i++)
  {
    digitalWrite(i,HIGH);
    for(int j=6;j<=9;j++)
    {
      digitalWrite(j,HIGH);
      delay(tempo);
      digitalWrite(j,LOW);
      delay(tempo);
    }
    digitalWrite(i,LOW);
  }
}

void func_2(void)
{
    //liga as linhas
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);

//liga colunas 1 e 4
digitalWrite(2,HIGH);
digitalWrite(5,HIGH);
delay(tempo);

//desliga colunas 1 e 4
digitalWrite(2,LOW);
digitalWrite(5,LOW);
delay(tempo);

//liga colunas 2 e 3
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
delay(tempo);

//desliga colunas 2 e 3
digitalWrite(3,LOW);
digitalWrite(4,LOW);
delay(tempo);
}

void func_3(void)
{
  //liga as colunas
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);

//Liga e desliga as linhas alternadamente
for(int i=6;i<=9;i++)
{
  digitalWrite(i,HIGH);
  delay(tempo);
  digitalWrite(i,LOW);
  delay(tempo);
}
}

void func_4(void)
{
  //liga as colunas
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);

digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);

delay(100);

//Liga e desliga as linhas alternadamente
for(int i=6;i<=9;i++)
{
  digitalWrite(i,LOW);
  delay(tempo);
}
}

void func_5()
{
   //##############################
 digitalWrite(3,HIGH);
 digitalWrite(4,HIGH);
 
 digitalWrite(7,HIGH);
 digitalWrite(8,HIGH);
 
 delay(300);
 
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
 
 delay(300);
 //##############################
 
 //##############################
 digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);

digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);

delay(300);

 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
 digitalWrite(9,LOW);
 
 delay(300);
 //##############################
}
