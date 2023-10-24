
int led1= 2,led2= 3, n;

void setup(){
  
  pinMode( led1, OUTPUT);
  pinMode( led2, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop(){
  
  if(Serial.available()>0){
    
  n= Serial.read();
  
  if(n == 108 || n == 76){ // Para ligar o Led 1 tem que digitar "l ou L".
     
    digitalWrite( led1, HIGH);
    digitalWrite(led2, LOW);
    Serial.print("Led 1 ligado\n");
    
  }
  if( n == 100 || n == 68){ // Para ligar o Led 2 tem que digitar "d ou D".
    
    digitalWrite(led2, HIGH);
    digitalWrite(led1,LOW);
    Serial.print("Led 2 ligado\n");
    
  }
  if( n == 116 || n == 85){ // Para desligar os dois Led's tem que digitar "t ou T".
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    Serial.print(" Os dois Led's estao apagados\n\n");
  
  }
  
  }
}
