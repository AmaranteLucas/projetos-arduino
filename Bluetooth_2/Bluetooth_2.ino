
int disp_1 = 8;
int disp_2 = 9;
int disp_3 = 10;
int disp_4 = 11;

int disp1_state = LOW;
int disp2_state = LOW;
int disp3_state = LOW;
int disp4_state = LOW;

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
    
    Serial.println(val);
    
    switch(val)
    {
      case 'a':
        disp1_state = !disp1_state;
        digitalWrite(disp_1,disp1_state);
      break;
      
      case 'b':
        disp2_state = !disp2_state;
        digitalWrite(disp_2,disp2_state);
      break;
      
      case 'c':
        disp3_state = !disp3_state;
        digitalWrite(disp_3,disp3_state);
      break;
      
      case 'd':
        disp4_state = !disp4_state;
        digitalWrite(disp_4,disp4_state);
      break;
      
      /*
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
      */
    }
  }
}
