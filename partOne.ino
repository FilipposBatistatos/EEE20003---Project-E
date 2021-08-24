#include "U8glib.h"
#include <Keypad.h>

U8GLIB_SSD1306_128X64 u8g; // Create an instant of OLED display
char szMesg;               // Create variable to print when a key is pressed

// Global variable declarations
const uint8_t ROWS = 4;
const uint8_t COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

uint8_t colPins[COLS] = {5, 4, 3, 2}; // Pins connected to C1, C2, C3, C4
uint8_t rowPins[ROWS] = {9, 8, 7, 6}; // Pins connected to R1, R2, R3, R4

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);         //
    u8g.setFont(u8g_font_7x13); // set the font for text
    u8g.setColorIndex(1);       // set the display colour to white - can be done inside or outside the picture loop
}

void loop()
{
    // put your main code here, to run repeatedly:
    char key = keypad.getKey(); // Get keypad input

    // *** START TEST CODE FOR KEYPAD *** //
    // If key is entered, print key in serial monitor
    if (key != NO_KEY)
    {
        Serial.println(key);
        szMesg = key;
    }
    // *** END TEST CODE FOR KEYPAD *** //

    // Start picture loop for GLCD
    u8g.firstPage(); // marks the beginning of the picture loop for the GLCD

    do
    {

        // *** START TEST CODE FOR GLCD DISPLAY *** //
        // NOTE: (X,Y) position is the lower left corner of the first char of the string
        // NOTE: drawing functions below must be inside the picture loop

        u8g.setColorIndex(1); // set the display colour to white - can be done inside or outside the picture loop

        u8g.drawStr(0, 50, "Hello World"); // Y position = 5 < height of text so cannot see the txt fully.

        u8g.drawFrame(0, 10, 128, 20); // draw frame at (0,10) with width = 128, height = 20
        u8g.drawBox(10, 15, 20, 10);   // draw box at (10,15) with with = 20, height = 10
        u8g.drawCircle(110, 50, 10);   // draw circle with centre at (110,50) and radius = 20

        //Print the last key pressed
        u8g.setPrintPos(50, 25); // set the print position on display
        u8g.print(szMesg);       // Use print instead of drawstr for data types other than strings - Why does this only appears for a short time?

        u8g.setColorIndex(0);  // change the colour to black
        u8g.drawPixel(15, 18); // draw a pixel at (15,18) with the colour black

        // *** END TEST CODE FOR GLCD DISPLAY *** //

    } while (u8g.nextPage()); // marks the end of the body of the picture loop
}
