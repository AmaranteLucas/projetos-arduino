#include <TVout.h>
#include <fontALL.h>
TVout TV;
 
float temperatura;
 
void setup()
{
  TV.begin(_PAL); // for PAL system
  TV.clear_screen();
}
 
void loop()
{
  
  temperatura=analogRead(A0);
  
  temperatura=temperatura*0.488758553;
  
  TV.clear_screen();  
 
  TV.select_font(font8x8);
  TV.set_cursor(25,0);
  TV.println("Temperatura:");
  
  TV.select_font(font8x8);
  TV.set_cursor(25,40);
  TV.println(temperatura);
  
  delay(1000);
  
 
   
}
