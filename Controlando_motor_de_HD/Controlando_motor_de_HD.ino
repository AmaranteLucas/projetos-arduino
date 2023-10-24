
int pinA = 2;
int pinB = 3;
int pinC = 4;
int steppingDelay = 250;

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);

  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);   
}

void loop() {

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    delay(steppingDelay);
    
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    delay(steppingDelay);
    
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    delay(steppingDelay);
    
    if( steppingDelay>50){
    steppingDelay= steppingDelay-50;
    }
    
}

