/*
  Esse código faz o Led conectado a porta 8 do arduino piscar de acordo 
  com o valor de T que é obtido através da leitura do potenciometro conectado 
  a porta analogica A0.
  
 */
 

int led1 = 3;
int led2=4;
int led3=5;
int led4=6;
int led5=7;

int potled = A0, T;


void setup() {   
  
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
   Serial.begin(9600);  
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  T=analogRead(potled);
  digitalWrite(led1, HIGH);   
  digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    delay(T);  

  
  digitalWrite(led1, LOW);   
  digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  
  delay(T);      
   
}
