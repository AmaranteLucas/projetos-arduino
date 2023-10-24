/* Coloque o buzzer na porta 10 e o programa a baixo no arduino
    By: Othavio Santos Rodrigues  Obrigado*/
 
void setup() {
pinMode(10,OUTPUT); //Pino do buzzer
}
 
void loop()
{
    delay(2000);
    tone(10,262,300); //DO
    delay(400);
    tone(10,262,300); //DO
    delay(400);
    tone(10,294,500); //RE
    delay(400);
    tone(10,262,300); //DO
    delay(400);
    tone(10,349,300); //FA
    delay(400);
    tone(10,330,500); //MI
    delay(400);
    tone(10,262,300); //DO
    delay(400);
    tone(10,262,300); //DO
    delay(400);
    tone(10,294,500); //RE
    delay(400);
    tone(10,262,300); //DO
    delay(400);
    tone(10,392,300); //SOL
    delay(400);
    tone(10,349,300); //FA
    delay(400);
    tone(10,349,500); //FA
    delay(400);
    tone(10,294,300); //RE
    delay(400);  
    tone(10,294,300); //RE
    delay(400);   
    tone(10,528,500); //DO a oitava
    delay(400);
    tone(10,440,300); //LA
    delay(400);
    tone(10,349,300); //FA
    delay(400);
    tone(10,330,300); //MI
    delay(400);
    tone(10,294,500); //RE
    delay(400);
    tone(10,466,300); // SI bemol
    delay(400);
    tone(10,466,300); // SI bemol
    delay(400);
    tone(10,440,500); //LA
    delay(400);
    tone(10,349,300); //FA
    delay(400);
    tone(10,392,300); //SOL
    delay(400);
    tone(10,349,300); //FA
    delay(400);
    tone(10,349,500); //FA
    delay(400);
  }

