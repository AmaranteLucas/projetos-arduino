#include<TVout.h>
#include<video_gen.h>

TVout TV;
 
void setup()  {
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
TV.begin(PAL,128,96);
delay(1000);
TV.draw_rect(0,0,71,55,WHITE,BLACK);
TV.draw_line(0,0,10,10,WHITE);
TV.draw_circle(36,28,10,WHITE);
TV.set_pixel(36,28,WHITE);
delay(15000);
}
 
void loop() {
TV.shift(1,UP);
delay(1000);
}
