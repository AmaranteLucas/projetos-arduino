int val;

void setup(){
  
  Serial.begin(9600);
  
}

void loop(){
  
  if(Serial.available()>0){
    
    val=Serial.read();
    
    if(val=='1'){
    
    Serial.println("Ola");
    }
    if((val=='a')||(val=='A')){
      Serial.println("SHOW");
}
}
}
