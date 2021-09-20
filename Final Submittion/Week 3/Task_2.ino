/*
    Connect OLED display to Arduino Mega. 
    Write code to draw Olympic Rings symbol at center of the OLED display
*/

#include "U8glib.h" // Using U8glib to control the OLED display

U8GLIB_SSD1306_128X64 u8g; // Initialising a OLED display object

void setup()
{
    u8g.setFont(u8g_font_7x13); // Setting font for display
}

void loop()
{
    u8g.firstPage(); // marks the beginning of the draw loop
    do
    {
        u8g.setColorIndex(1); //set colour to white
        //middle circle
        u8g.drawCircle(64, 30, 12);
        //left top circle
        u8g.drawCircle(37, 30, 12);
        //right top circle
        u8g.drawCircle(89, 30, 12);
        //left bottom circle
        u8g.drawCircle(51, 42, 12);
        //right bottom circle
        u8g.drawCircle(77, 42, 12);
    } while (u8g.nextPage()); // End of printing on screen
}