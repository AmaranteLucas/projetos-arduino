int mf1= 8;
int mt1=9;
int mf2 =10;
int mt2=11;
int n;

void setup(){
  
  pinMode(mf1, OUTPUT);
  pinMode(mt1, OUTPUT);
  pinMode(mf2, OUTPUT);
  pinMode(mt2, OUTPUT);
  Serial.begin(9600);
  
}

void loop(){
  
  if(Serial.available()>0){
   
   n=Serial.read();
  
  if(n == 119 || n == 87){ 
   
  digitalWrite(mf1, HIGH);
  digitalWrite(mf2, HIGH);
  digitalWrite(mt1, LOW);
  digitalWrite(mt2, LOW);
  
  Serial.println("Frente");
  
  }
  
  if( n == 115 || n == 83){
    
  digitalWrite( mt1, HIGH);
  digitalWrite(mt2, HIGH);
  digitalWrite(mf1, LOW);
  digitalWrite(mf2, LOW);
  
  Serial.println("Atras");
  
  }
  
  if( n == 100 || n == 68){
  
  digitalWrite(mf2, HIGH);
  digitalWrite(mf1, LOW);
  digitalWrite(mt1, LOW);
  digitalWrite(mt2, LOW);
  
  Serial.println("Esquerda");
  
  }
  
  if( n == 97 || n == 65){
  
  digitalWrite(mf1, HIGH);
  digitalWrite(mf2, LOW);
  digitalWrite(mt1, LOW);
  digitalWrite(mt2, LOW);
  
  Serial.println("Direita");
  
  }
  if( n == 112 || n == 80){
  
  digitalWrite(mf1, LOW);
  digitalWrite(mf2, LOW);
  digitalWrite(mt1, LOW);
  digitalWrite(mt2, LOW);
  
  Serial.println("Parado");
  
  }
  
  
}

}
  
  
