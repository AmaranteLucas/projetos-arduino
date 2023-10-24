//##################### Teclado Matricial 4x3 ####################
// Devem ser usados resistores de pull-down nos pinos das colunas
//################################################################


int lin_1 = 2;
int lin_2 = 3;
int lin_3 = 4;
int lin_4 = 5;

int col_1 = 6;
int col_2 = 7;
int col_3 = 8;

void setup()
{
  Serial.begin(9600);
  
  for(int i=2;i<=5;i++)
  {
    pinMode(i,OUTPUT);
  }
  
  for(int i=6;i<=8;i++)
  {
    pinMode(i,INPUT);
  }
}

void loop()
{
  
  //LÊ A LINHA 1
  digitalWrite(lin_1,HIGH);
  digitalWrite(lin_2,LOW);
  digitalWrite(lin_3,LOW);
  digitalWrite(lin_4,LOW);
  
  if( digitalRead(col_1)==HIGH)
  {
    Serial.println("1");
  }
  
  if( digitalRead(col_2)==HIGH)
  {
    Serial.println("2");
  }
  
  if( digitalRead(col_3)==HIGH)
  {
    Serial.println("3");
  }
  
  //LÊ A LINHA 2
  digitalWrite(lin_1,LOW);
  digitalWrite(lin_2,HIGH);
  digitalWrite(lin_3,LOW);
  digitalWrite(lin_4,LOW);
  
  if( digitalRead(col_1)==HIGH)
  {
    Serial.println("4");
  }
  
  if( digitalRead(col_2)==HIGH)
  {
    Serial.println("5");
  }
  
  if( digitalRead(col_3)==HIGH)
  {
    Serial.println("6");
  }
  
  //LÊ A LINHA 3
  digitalWrite(lin_1,LOW);
  digitalWrite(lin_2,LOW);
  digitalWrite(lin_3,HIGH);
  digitalWrite(lin_4,LOW);
  
  if( digitalRead(col_1)==HIGH)
  {
    Serial.println("7");
  }
  
  if( digitalRead(col_2)==HIGH)
  {
    Serial.println("8");
  }
  
  if( digitalRead(col_3)==HIGH)
  {
    Serial.println("9");
  }
  
  //LÊ A LINHA 4
  digitalWrite(lin_1,LOW);
  digitalWrite(lin_2,LOW);
  digitalWrite(lin_3,LOW);
  digitalWrite(lin_4,HIGH);
  
  if( digitalRead(col_1)==HIGH)
  {
    Serial.println("*");
  }
  
  if( digitalRead(col_2)==HIGH)
  {
    Serial.println("0");
  }
  
  if( digitalRead(col_3)==HIGH)
  {
    Serial.println("#");
  }
 
 delay(10);  
}
