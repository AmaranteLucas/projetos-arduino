

float temp;

void setup(){
  
  Serial.begin(9600);
  
}

void loop(){
  
  temp=analogRead(A0);
  
  Serial.println(temp);
  
  temp=temp*0.488758553;
  
  Serial.println(temp);
  
  delay(500);
  
}
