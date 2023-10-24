

void setup(){
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
}


void loop(){
 
  pisca_led(8,5,25);
  
  pisca_led(9,5,25);
  
   pisca_led(9,5,25);
   
   pisca_led(8,5,25);
   
  
 
  
}

//################Funcoes######################

void pisca_led(int led, int n, int t){
  
  int i=0;
  
  for(i=0;i<n;i++){
    digitalWrite(led,HIGH);
    delay(t);
    digitalWrite(led,LOW);
    delay(t);
  }

}

/*###########################################################*/



