int motor_sobe= 8;
int motor_desce=9;
int led1=10;
int led2=11;
int n;

void setup(){
  
  pinMode( motor_sobe, OUTPUT);
  pinMode(motor_desce, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  
}

void loop(){
  
  if(Serial.available()>0){
   
   n=Serial.read();
  
  if(n == 115 || n == 83){ //A tecla "s" faz o motor subir.
   
  digitalWrite(motor_sobe, HIGH);
  digitalWrite(motor_desce, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  
  Serial.println("O Motor esta subindo");
  
  }
  
  if( n == 100 || n == 68){ //A tecla "d" faz o motor descer.
    
  digitalWrite( motor_desce, HIGH);
  digitalWrite(motor_sobe, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  
  Serial.println("O Motor esta descendo");
  
  }
  
  if( n == 101 || n == 69){//A tecla "e" faz o motor parar.
  
  digitalWrite( motor_desce, LOW);
  digitalWrite(motor_sobe, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  
  Serial.println("O Motor esta parado");
  
  }
  
}

}
  
  
