//####################### Encontro 02 - Arduino ######################

/* ######## Ao escrever um código, preste muita atenção nas pontuações ao
final de algumas funções, lembre-se de fechar chaves, e de que algumas
funções têm letra(s) maiúsculas.
*/


//#### Declaração das variáveis utilizadas em todo o programa #####

int led=10;
int tempo=100;

//###############################################################

//############# Configurando a porta como saída #################

void setup(){
  
  pinMode(led,OUTPUT);
  
}

//###############################################################

//################ Função Principal (Loop Infinito) #############

void loop(){
  
  digitalWrite(led,HIGH);//Coloca o pino associado ao nome led em nivel lógico ALTO(ligado).
  delay(tempo);// Espera "tempo" milissegundos.
  digitalWrite(led,LOW);//Coloca o pino associado ao nome led em nivel lógico BAIXO(Desligado).
  delay(tempo);// Espera "tempo" milissegundos.
  
  tempo=tempo+50;// Incrementa a variável tempo 50ms a cada ciclo(loop).
  
  if(tempo==300){// Condição "Se", testa se o valor de tempo for igual a 300ms,
    tempo=100;     // a variável tempo volta a valer 100, que era seu valor inicial.
  }
  
}

// ############################### FIM ##################################
