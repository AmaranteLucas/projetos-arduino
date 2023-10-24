#include <TVout.h>
#include <fontALL.h>
TVout TV;
 
void setup()
{
  TV.begin(_PAL); // for PAL system
  TV.clear_screen();
}
 
void loop()
{
  
  TV.clear_screen();  
 
  TV.select_font(font8x8);
  TV.set_cursor(25,0);
  TV.println("Lucas Bastos");
  
  TV.select_font(font6x8);
  TV.set_cursor(25,40);
  TV.println("Projetos Arduino");
  delay(6000);
  
  
  TV.clear_screen();  
 
  TV.select_font(font8x8);
  TV.set_cursor(20,40);
  TV.println("Arduino TVout");
  delay(6000);
  
  
}
