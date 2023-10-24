include <liquidcrystal_i2c .h>

#include <wire .h>
int pinoSensor = 0; //pino que está ligado o terminal central do LM35 (porta analogica 0)
int valorLido = 0; //valor lido na entrada analogica
float temperatura = 0;
int pinoTensao = 1; 
int valorTensao = 0; //valor lido na entrada analogica
float tensao = 0;
byte detecta = 2;
int contador = 0;
LiquidCrystal_I2C lcd(0x38,16,2);
void setup()
{
lcd.init();
lcd.backlight();
lcd.print("CONTA GIROS DNL");
pinMode(detecta,INPUT);
digitalWrite(detecta,HIGH);
contador = 0;
attachInterrupt(0, DETECTA, FALLING);
noInterrupts();

delay (10000);

}

void loop()
{
  unsigned long tempo = millis();
  
  while(tempo +300 > millis())
  {
    interrupts(); 
  }
  
  contador = contador * 100 ;
  
  //Leitura da temperatura
  valorLido = analogRead(pinoSensor);
  temperatura = (valorLido * 0.00488); // 5V / 1023 = 0.00488 (precisão do A/D)
  temperatura = temperatura * 100;
  
  //Leitura de tensão da bateria
  valorTensao = analogRead(pinoTensao);
  tensao = valorTensao * 0.00488 ;
  tensao = tensao * 4 ;
  
  lcd.setCursor(0, 0);
  lcd.print("V:"); 
  lcd.print(tensao); 
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperatura);
  lcd.print(" ");
  lcd.setCursor(8, 1);
  lcd.print("RPM:");
  lcd.print(contador);
  lcd.print(" ");
  contador = 0;
}

void DETECTA()
{
  contador ++;
}

