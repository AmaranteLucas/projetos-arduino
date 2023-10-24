/*
  Projeto: TimeInsideArduinoBR
  Versao : 0.1 beta

  Codigo abaixo simula o funcionamento de um relogio
  O mesmo foi criado para apresentar o conceito basico
  Ele retornar os valores utilizando o Serial Monitor da IDE do Arduino.
  
  E recomendado utilizar junto com o Arduino um RTC ( Real Time Clock )
  Onde o mesmo consegue armazenar a hora, mesmo desligado.

  by Antonio Thomacelli Gomes
  tonnytg@gmail.com
  @tonnytg
*/

// Variaveis
int HORA = 0;
int MINUTO = 0;
int SEGUNDO = 0;

// Declaracao inicial
void setup()
{
  Serial.begin(9600);
}

// Repeticao infinita
void loop()
{
  delay(1000);
  SEGUNDO = SEGUNDO + 1;

  if ( SEGUNDO == 60 )
  {
    MINUTO = MINUTO + 1;
    SEGUNDO = 0;
  }
  if ( MINUTO == 60 )
  {
    HORA = HORA + 1;
    MINUTO = 0;
  }
  if ( HORA == 24 )
  {
    HORA = 0;
  }
  // Impressao dos valores
  Serial.print( HORA );
  Serial.print(":");
  Serial.print( MINUTO );
  Serial.print(":");
  Serial.println( SEGUNDO );
}
