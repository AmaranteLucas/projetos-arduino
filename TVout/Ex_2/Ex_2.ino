#include <TVout.h>
#include <fontALL.h>
TVout TV;
 
int d=10; // for delay purposes
char c='X';
 
void setup()
{
  TV.begin(_PAL); // for PAL system
  TV.clear_screen();
}
 
void loop()
{
  TV.select_font(font4x6);
  for (int a=0; a<6; a++)
  {
    for (int b=0; b<128; b++)
    {
      TV.print_char(b,a*6,c);
      delay(d);
      TV.clear_screen();
    }
  }
  delay(1000);
  TV.clear_screen();  
 
  TV.select_font(font6x8);
  for (int a=0; a<6; a++)
  {
    for (int b=0; b<128; b++)
    {
      TV.print_char(b,a*8,c);
      delay(d);  
      TV.clear_screen();
    }
  }
  delay(1000);
  TV.clear_screen();  
 
  TV.select_font(font8x8);
  for (int a=0; a<6; a++)
  {
    for (int b=0; b<128; b++)
    {
      TV.print_char(b,a*8,c);
      delay(d);  
      TV.clear_screen();
    }
  }
  delay(1000);
  TV.clear_screen();  
}
