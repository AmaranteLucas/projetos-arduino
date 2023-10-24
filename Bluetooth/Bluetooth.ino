
int disp_1 = 8;
int disp_2 = 9;
int disp_3 = 10;
int disp_4 = 11;

void setup()
{
  Serial.begin(9600);
  
  pinMode(disp_1,OUTPUT);
  pinMode(disp_2,OUTPUT);
  pinMode(disp_3,OUTPUT);
  pinMode(disp_4,OUTPUT);
}

void loop()
{
  if(Serial.available()>0)
  {
    char val=Serial.read();
    
    switch(val)
    {
      case 'a':
      digitalWrite(disp_1,HIGH);
      break;
      
      case 'b':
      digitalWrite(disp_1,LOW);
      break;
      
      case 'c':
      digitalWrite(disp_2,HIGH);
      break;
      
      case 'd':
      digitalWrite(disp_2,LOW);
      break;
      
      case 'e':
      digitalWrite(disp_3,HIGH);
      break;
      
      case 'f':
      digitalWrite(disp_3,LOW);
      break;
      
      case 'g':
      digitalWrite(disp_4,HIGH);
      break;
      
      case 'h':
      digitalWrite(disp_4,LOW);
      break;
    }
  }
}
