/*
  Esse código faz o Led conectado a porta 8 do arduino piscar de acordo 
  com o valor de T que é obtido através da leitura do potenciometro conectado 
  a porta analogica A0.
  
 */
 

int led = 8;
int potled = A0, T;


void setup() {   
   Serial.begin(9600);  
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  T=analogRead(potled);
  digitalWrite(led, HIGH);   
  delay(T);               
  digitalWrite(led, LOW);    
  delay(T);               
}
