
int pinA = 2;
int pinB = 3;
int pinC = 4;
int steppingDelay = 60;

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);

  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);   
}

void loop() {
  stepping(1);
  delay(steppingDelay);
  stepping(2);
  delay(steppingDelay);   
  stepping(3);
  delay(steppingDelay);
  
}

void stepping(int stage)
{
  switch(stage)
  {
  case 1:
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    break;
  case 2:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    break;
  default:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    break;
  }  
}

