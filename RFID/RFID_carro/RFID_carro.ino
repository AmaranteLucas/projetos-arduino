#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(14,15,16,17,18,19);

int teste = 0;
int btn_bloqueio = 5;

#define rele 7


#define SS_PIN 10
#define RST_PIN 9
// Definicoes pino modulo RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); 

int buzzer = 6;

char st[20];

void setup() 
{
  pinMode(buzzer,OUTPUT);
  pinMode(rele,OUTPUT);
  pinMode(btn_bloqueio,INPUT);
  
  digitalWrite(rele,HIGH);
  
  // Inicia a serial
  Serial.begin(9600);
  
  // Inicia  SPI bus
  SPI.begin();
  
  // Inicia MFRC522
  mfrc522.PCD_Init(); 
  // Mensagens iniciais no serial monitor
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sistema OK!");
}

void loop() 
{

   while(teste == 0){
    // Aguarda a aproximacao do cartao
    if ( ! mfrc522.PICC_IsNewCardPresent()) 
    {
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("APROXIME O");
      lcd.setCursor(0,1);
      lcd.print("CARTAO DO LEITOR");
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
    conteudo.toUpperCase();
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(conteudo);
  
    delay(250);
    
    // Testa se o cartao1 foi lido
    if (conteudo.substring(1) == "E5 D6 85 28")
    {
      teste = 1;
    }
    if (conteudo.substring(1) == "20 84 56 CF")
    {
      teste = 2;
    }
    else
    {
      Serial.println("Cartao Invalido!!! - Acesso negado !!!");
    }
  }

  if(digitalRead(btn_bloqueio) == 0)
  {
    teste = 0;
    digitalWrite(rele,HIGH);
  }

  if(teste == 1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ignicao 1");
    lcd.setCursor(0,1);
    lcd.print("liberada");
    digitalWrite(rele,LOW);
  }

  if(teste == 2)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ignicao 2");
    lcd.setCursor(0,1);
    lcd.print("liberada");
  }
  

  delay(100);
}
