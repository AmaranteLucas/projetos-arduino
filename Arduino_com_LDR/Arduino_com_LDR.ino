int ldr=A0;//Defenir o pino analógico onde será ligado o ldr neste caso pino 0
int val=0; //definir a vareável que vai armazenar os valores obtidos pelo ldr 
void setup(){
  Serial.begin(9600);// linha de código para a comunicação com o pc
}

void loop(){
  val=analogRead(ldr);//  linha de código para o armazenamento dos valores obtidos no ldr numa variável
  Serial.println(val);// fazer um print dos valores obtidos pelo ldr
  delay(100); // intervalo de tempo de 1 segundo
}
