/*******************************************************************
****************** LED RGB COM TECLADO E DYSPLAY LCD ***************
********************************************************************
******************* Exemplo criado para o Arduino UNO *************
********************************************************************
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(19, 18, 17, 16, 15, 14);

//Variáveis que armazenam o valor PWM que será passado aos pinos analógicos.

int val_r = 0;
int val_g = 0;
int val_b = 0;



void setup()
{
  
    lcd.begin(16, 2);
    
    //Inicializa os pinos dos botões como entradas
    for(int i=1;i<=7;i=i+1)
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
  if(digitalRead(1) == 1)
  {
    val_r = val_r +10;
    if(val_r > 255)
    {
      val_r=255;
    }
  }
  
  if(digitalRead(2) == 1)
  {
    val_r = val_r - 10;
    if(val_r < 0)
    {
      val_r=0;
    }
  }
  
 //***************************************************************
 
  //*************** CONTROLA O VALOR DE GREEN ********************
  
  if(digitalRead(3) == 1)
  {
    val_g = val_g +10;
    if(val_g > 255)
    {
      val_g=255;
    }
  }
  
  if(digitalRead(4) == 1)
  {
    val_g = val_g - 10;
    if(val_g < 0)
    {
      val_g=0;
    }
  }
  
  //************************************************************************
  
  //*************** CONTROLA O VALOR DE BLUE **********************
   if(digitalRead(5) == 1)
  {
    val_b = val_b +10;
    if(val_b > 255)
    {
      val_b=255;
    }
  }
  
  if(digitalRead(6) == 1)
  {
    val_b = val_b - 10;
    if(val_b < 0)
    {
      val_b=0;
    }
  }
  
  //************************************************************************
  
  //************************* RESETA OS VALORES **********************
  if(digitalRead(7) == 1)
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
  analogWrite(9,pwm_1);
  analogWrite(10,pwm_2);
  analogWrite(11,pwm_3);
}


