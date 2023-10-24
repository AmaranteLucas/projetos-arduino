

void setup()
{
  Serial.begin(9600);
  
  for(int i=8;i<=12;i++)
  {
  pinMode(i,OUTPUT);
  }
}

void loop()
{
  if(Serial.available()>0)
  {
    int val=Serial.read();
    
    Serial.println(val);
    
    switch(val)
    {
      case 65:
      digitalWrite(8,HIGH);
      break;
      
      case 97:
      digitalWrite(8,LOW);
      break;
      
       case 66:
      digitalWrite(9,HIGH);
      break;
      
      case 98:
      digitalWrite(9,LOW);
      break;
      
       case 67:
      digitalWrite(10,HIGH);
      break;
      
      case 99:
      digitalWrite(10,LOW);
      break;
      
       case 68:
      digitalWrite(11,HIGH);
      break;
      
      case 100:
      digitalWrite(11,LOW);
      break;
      
      case 69:
      digitalWrite(12,HIGH);
      break;
      
      case 101:
      digitalWrite(12,LOW);
      break;
    }
  }
}
