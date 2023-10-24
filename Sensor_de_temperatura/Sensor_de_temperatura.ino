int valor;
int lm35 = 0;
int valorLido = 0;
float temperatura = 0;
void setup(){
pinMode(13,OUTPUT); 
Serial.begin(9600);
}
void loop(){
valorLido = analogRead(lm35);
temperatura = (valorLido * 0.00488);
temperatura = temperatura *100;

Serial.println(temperatura);
delay(1000);
if(Serial.available()>0){
valor = Serial.read();
}
if (valor == '1'){
digitalWrite(13,HIGH); 
}
else if (valor == '2'){
digitalWrite(13,LOW); 
}
else if (valor == '3'){
pisca();
}

}

void pisca(){
digitalWrite(13,HIGH); 
delay(200);
digitalWrite(13,LOW);
delay(200); 

}
