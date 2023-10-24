// Programa : RFID - Controle de acesso / cancela
// Autor : Arduino e Cia - Modificado por Lucas Bastos em 26/02/2015

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h> 
 
Servo microservo9g;

#define SS_PIN 10
#define RST_PIN 9
// Definicoes pino modulo RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); 

// Leds indicadores acesso liberado ou negado
int led_liberado = 5;
int led_negado = 6;
int buzzer = 7;

char st[20];

void setup() 
{
  pinMode(led_liberado, OUTPUT);
  pinMode(led_negado, OUTPUT);
  pinMode(buzzer,OUTPUT);
  // Define que o servo esta ligado a porta digital 3
  microservo9g.attach(3);
  // Move o servo para a posicao inicial (cancela fechada)
  microservo9g.write(90);
  // Inicia a serial
  Serial.begin(9600);
  // Inicia  SPI bus
  SPI.begin();
  // Inicia MFRC522
  mfrc522.PCD_Init(); 
  // Mensagens iniciais no serial monitor
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
}

void loop() 
{
  // Aguarda a aproximacao do cartao
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Seleciona um dos cartoes
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  //Apita o Buzzer
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  
  // Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
  
  // Testa se o cartao1 foi lido
  if (conteudo.substring(1) == "E5 D6 85 28")
  {
    // Levanta a cancela e acende o led verde
    microservo9g.write(-90);
    digitalWrite(led_liberado, HIGH);
    Serial.println("Cartao Valido - Acesso liberado !");
    Serial.println();
    delay(3000);
    microservo9g.write(90);
    digitalWrite(led_liberado, LOW);
    }
    
  // Testa se o cartao2 foi lido
  //if (conteudo.substring(1) == "55 F2 F2 9D")
  else
  {
    Serial.println("Cartao Invalido!!! - Acesso negado !!!");
    Serial.println();
    // Pisca o led vermelho
    for (int i= 1; i<5 ; i++)
    {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led_negado, HIGH);
      delay(200);
      digitalWrite(led_negado, LOW);
      delay(200);
    }
    digitalWrite(buzzer, LOW);
  }
  delay(1000);
}
