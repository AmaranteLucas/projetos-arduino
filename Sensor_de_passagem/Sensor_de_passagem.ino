int pushButton = 8;
int valor = 0;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(pushButton, INPUT);
}


void loop() {
  // read the input pin:
  digitalRead(pushButton);
  
  if(pushButton == HIGH ){
    valor= valor+1;
  }
  
  Serial.println(valor);
  delay(1);        // delay in between reads for stability
}



