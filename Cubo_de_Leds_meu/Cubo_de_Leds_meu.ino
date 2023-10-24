

void setup()
{
  for(int i=2;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  
quadrado();

percorre();

apaga(); 

outra();

outra_2();

anda();

  
}

void percorre()
{
  for(int i=13;i>=11;i--){
    digitalWrite(i,HIGH);
    
    for(int j=2;j<=10;j++){
      digitalWrite(j,HIGH);
      delay(100);
      digitalWrite(j,LOW);
    }
    delay(100);
    digitalWrite(i,LOW);
  }
}


void quadrado(){
  
  for(int i=13;i>=11;i--){
    digitalWrite(i,HIGH);
    
    for(int j=2;j<=10;j++){
      digitalWrite(j,HIGH);
       if(j==6){
        digitalWrite(j,LOW);
      }
    }
    
    delay(200);
    digitalWrite(i,LOW); 
  }
}

void apaga(){
   
  for(int i=13;i>=11;i--){
    digitalWrite(i,HIGH);
    
    for(int j=2;j<=10;j++){
      digitalWrite(j,HIGH);
      delay(100);
      }
      delay(100);
      
      for(int j=2;j<=10;j++){
      digitalWrite(j,LOW);
      delay(100);
      }
      
      digitalWrite(i,LOW);
      
  }
}

void outra(){
   
  for(int i=13;i>=11;i--){
    digitalWrite(i,HIGH);
  
  for(int j=2;j<=10;j++){
    if(j%2==0){
    digitalWrite(j,HIGH);
    }
    else{
      digitalWrite(j,LOW);
    }
  }
  delay(200);
 
  }  
  
}

void outra_2(){
   
  for(int i=13;i>=11;i--){
    digitalWrite(i,HIGH);
  
  for(int j=2;j<=10;j++){
    if(j%2==0){
    digitalWrite(j,LOW);
    }
    else{
      digitalWrite(j,HIGH);
    }
  }
  delay(200);

  } 
}

void anda(){
 
  int t=100;
  
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  
  digitalWrite(6,HIGH);
  
  for(int i=2;i<=4;i++){
  digitalWrite(i,HIGH);
  delay(t);
  digitalWrite(i,LOW);
  }
  
  digitalWrite(7,HIGH);
  delay(t);
  digitalWrite(7,LOW);
  
  digitalWrite(10,HIGH);
  delay(t);
  digitalWrite(10,LOW);
  
  digitalWrite(9,HIGH);
  delay(t);
  digitalWrite(9,LOW);
  
  digitalWrite(8,HIGH);
  delay(t);
  digitalWrite(8,LOW);
  
  digitalWrite(5,HIGH);
  delay(t);
  digitalWrite(5,LOW);
  
  digitalWrite(6,LOW);
  
  }

  
  

      
  
