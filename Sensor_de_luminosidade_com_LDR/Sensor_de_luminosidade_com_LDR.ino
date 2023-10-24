int led=9,led_2=6, ldr=A0,val,var;

void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(ldr,INPUT);
}

void loop(){
  
  digitalWrite(led,HIGH);
  
  val=analogRead(ldr);
  
  Serial.println(val);
  
  var=map(val,0,280,0,255);
  
  analogWrite(led_2,var);
  
  delay(550);
  
  
}
