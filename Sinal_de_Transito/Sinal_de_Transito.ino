int led1=7; // LUZ VERMELHA DO PEDESTRE
int led2=6; // lUZ VERDE DO PEDESTRE
int led3=10; // LUZ VERMELHA DOS VEÍCULOS
int led4=9; // LUZ AMARELA DOS VEÍCULOS
int led5=8; // LUZ VERDE DOS PEDESTRES

void setup(){
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
 
  
}

void loop(){
       
    digitalWrite(led1, HIGH);
    digitalWrite(led5,HIGH );
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led2, LOW);
    delay(7000);
      
    digitalWrite(led4, HIGH);
    digitalWrite(led5,LOW );
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(2000); 
    
    digitalWrite(led3, HIGH);
    digitalWrite(led5,LOW );
    digitalWrite(led4, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(5000); 
 
  }
  
 
