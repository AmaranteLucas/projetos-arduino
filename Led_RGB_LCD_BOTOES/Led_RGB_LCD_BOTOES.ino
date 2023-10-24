/*******************************************************************
****************** LED RGB COM TECLADO E DYSPLAY LCD ***************
********************************************************************
******************* Exemplo criado para o Arduino MEGA *************
********************************************************************
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

//Variáveis que armazenam o valor PWM que será passado aos pinos analógicos.

int val_r = 0;
int val_g = 0;
int val_b = 0;



void setup()
{
  
    lcd.begin(16, 2);
    Serial.begin(9600);
    
    //Inicializa os pinos dos botões como entradas
    for(int i=31;i<=43;i=i+2)
    {
      pinMode(i,INPUT);
    }
}

void loop()
{
  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("RED GREEN BLUE");
  

  //*************** CONTROLA O VALOR DE RED************************
  if(digitalRead(43) == 1)
  {
    val_r = val_r +10;
    if(val_r > 255)
    {
      val_r=255;
    }
  }
  
  if(digitalRead(41) == 1)
  {
    val_r = val_r - 10;
    if(val_r < 0)
    {
      val_r=0;
    }
  }
  
 //***************************************************************
 
  //*************** CONTROLA O VALOR DE GREEN ********************
  
  if(digitalRead(39) == 1)
  {
    val_g = val_g +10;
    if(val_g > 255)
    {
      val_g=255;
    }
  }
  
  if(digitalRead(37) == 1)
  {
    val_g = val_g - 10;
    if(val_g < 0)
    {
      val_g=0;
    }
  }
  
  //************************************************************************
  
  //*************** CONTROLA O VALOR DE BLUE **********************
   if(digitalRead(35) == 1)
  {
    val_b = val_b +10;
    if(val_b > 255)
    {
      val_b=255;
    }
  }
  
  if(digitalRead(33) == 1)
  {
    val_b = val_b - 10;
    if(val_b < 0)
    {
      val_b=0;
    }
  }
  
  //************************************************************************
  
  //************************* RESETA OS VALORES **********************
  if(digitalRead(31) == 1)
  {
    val_r = 0;
    val_g = 0;
    val_b = 0;
  }
  
  //****************************************************************
  
  lcd.setCursor(1,1);
  lcd.print(val_r);
  
  lcd.setCursor(6,1);
  lcd.print(val_g);
  
  lcd.setCursor(12,1);
  lcd.print(val_b);
  
  
   RGB(val_r,val_g,val_b);
   delay(100);
}


void RGB(int pwm_1, int pwm_2, int pwm_3)
{
  analogWrite(2,pwm_1);
  analogWrite(3,pwm_2);
  analogWrite(4,pwm_3);
}


