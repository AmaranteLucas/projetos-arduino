int motor_sobe= 8;
int motor_desce=9;
int led1=10;
int led2=11;
int n;
int T=1000;

void setup(){
  
  pinMode( motor_sobe, OUTPUT);
  pinMode(motor_desce, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  
}

void loop(){
  
  
  
   
  digitalWrite(motor_sobe, HIGH);
  digitalWrite(motor_desce, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  
 delay(T);
  
  
  
  
    
  digitalWrite( motor_desce, HIGH);
  digitalWrite(motor_sobe, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  
  delay(T);
  
  
 
}

  
  
