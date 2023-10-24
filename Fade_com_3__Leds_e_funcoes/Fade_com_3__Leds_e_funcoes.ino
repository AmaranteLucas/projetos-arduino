
int led1=9;
int led2=10;
int led3=11;

void setup(){
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  
}

void loop(){
  
  fade_led(led1,5);
  fade_led(led2,5);
  fade_led(led3,5);
  
}

void fade_led(int led ,int tempo){
  
  int i;
  
  for(i=0;i<=255;i++){
    
    analogWrite(led,i);
    delay(tempo);
    
  }
  
   for(i=255;i>=0;i--){
    
    analogWrite(led,i);
    delay(tempo);
  }
}
  
