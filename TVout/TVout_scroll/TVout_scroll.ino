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
  
  for(int i=0;i<=128;i++)
  {
    
  TV.clear_screen();  
 
  TV.select_font(font8x8);
  TV.set_cursor(i,0);
  TV.println("Lucas Bastos");
  delay(10);
    }
 
  
}
