#include <U8glib.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  

int breathy = 0;
int* breathyptr = &breathy;

void setup() {}

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_fur20);
  
  if (millis() < 25000) {
     //waiting for sensor to warm up
     u8g.drawStr(0, 25, "Warming"); 
     u8g.drawStr(0, 50, "up...");
     return;
  }
   
  char c[3];
  itoa(breathy, c, 10);
    
  u8g.drawStr( 0, 25, c);
  if (breathy > 250) {
      u8g.drawStr( 0, 60, "Drunk!");
  }
}

void loop(void) {
  breathy = analogRead(0);

  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );

  // rebuild the picture after some delay
  delay(500);
  
}
