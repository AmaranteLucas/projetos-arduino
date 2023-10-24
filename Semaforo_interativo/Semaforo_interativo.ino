int carroVermelho = 12;
int carroAmarelo = 11;
int carroVerde = 10;
int pedVermelho = 8;
int pedVerde = 9;
int botao = 2; // pino do interruptor
int tempoTravessia = 5000; // tempo para atravessar a rua


unsigned long changeTime;
void setup()
{
pinMode (carroVermelho, OUTPUT);
pinMode (carroAmarelo, OUTPUT);
pinMode (carroVerde, OUTPUT);
pinMode (pedVermelho, OUTPUT);
pinMode (pedVerde, OUTPUT);
pinMode (botao, INPUT);
// liga a luz verde dos carros e a vermelha para os pedestres
digitalWrite (carroVerde, HIGH);
digitalWrite (pedVermelho, HIGH);
}
void loop()
{
int state = digitalRead (botao);
if (state == HIGH && (millis() - changeTime) > 5000)
{
// Ativa a função para mudar as luzes
changeLights(); // executa o bloco changeLights()
}
}

void changeLights()
{
digitalWrite (carroVerde, LOW); // desliga o verde
digitalWrite (carroAmarelo, HIGH); // liga o amarelo
delay (2000); // espera 2 segundos
digitalWrite (carroAmarelo, LOW); // desliga o amarelo
digitalWrite (carroVermelho, HIGH); // liga o vermelho
delay (1000); // espera 1 segundo
digitalWrite (pedVermelho, LOW); // desliga o vermelho do pedestre
digitalWrite (pedVerde, HIGH); // liga o verde do pedestre
delay (tempoTravessia);
for (int x=0; x<10; x++)
{
digitalWrite (pedVerde, HIGH); // liga o verde do pedestre
delay (250); // espera 250 milisegundos
digitalWrite (pedVerde, LOW); // desliga o verde do pedestre
delay (250); // espera 250 milisegundos
}
digitalWrite (pedVermelho, HIGH); // liga o sinal vermelho do pedestre
delay (500); // espera 500 milisegundos
digitalWrite (carroAmarelo, HIGH); // liga o vermelho
digitalWrite (carroVermelho, LOW); // desliga o vermelho
delay (1000); // espera 1 segundo
digitalWrite (carroVerde, HIGH); // liga o verde
digitalWrite (carroAmarelo, LOW); // desliga o amarelo
changeTime = millis(); // registra o tempo desde a última alteração de luzes

}

