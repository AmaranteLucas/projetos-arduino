int led1=3;
int led2=4;
int led3=5;
int led4=6;
int led5=7;
int n;

void setup(){
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  Serial.begin(9600);
  
}

void loop(){
  
  if(Serial.available()>0){
    
    n=Serial.read();
    
    if(n== 97){
      
    digitalWrite(led1, HIGH);

  }
  if(n== 98){
      
    digitalWrite(led2, HIGH);

  }
  if(n== 99){
      
    digitalWrite(led3, HIGH);

  }
  if(n== 100){
      
    digitalWrite(led4, HIGH);

  }
  if(n== 101){
      
    digitalWrite(led5, HIGH);

  }
  
  
 if(n== 102){
      
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);

  }
  
  }
  }
  
 
