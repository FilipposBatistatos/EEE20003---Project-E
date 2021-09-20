/*
    Connect LED Matrix with “chain” attribute is 1 and 4 buttons 
    with suitable resistors to Arduino Mega. Write a code to control 
    a dot/LED move up, down, left, and right using 4 buttons. 
    At the beginning, the dot location will be (0,0). 
    Only one dot/LED is displayed at once and this dot/LED can only 
    display within the 8x8 range.
*/

#include <MD_MAX72xx.h> // Library to control the matrix display
#include <SPI.h>        // Required for MD_MAX library to work properly

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW // Define type of hardware
#define MAX_DEVICES 1                       // Number of matrixes connected together
#define CLK_PIN 52                          // Clock pin
#define DATA_PIN 51                         // Data pin
#define CS_PIN 53                           // CS pin

// Button pins
#define RIGHT_BUTTON 4
#define LEFT_BUTTON 7
#define UP_BUTTON 5
#define DOWN_BUTTON 6

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES); // Initialise dot matrix object

int x = 0; // horizontal position of the dot
int y = 0; // vertical position of the dot

void checkInput()
{
    if (digitalRead(RIGHT_BUTTON) == LOW) // Check if right button is pressed
    {
        mx.setPoint(y, x, false);
        x--;
    }
    else if (digitalRead(UP_BUTTON) == LOW) // Check if up button is pressed
    {
        mx.setPoint(y, x, false);
        y--;
    }
    else if (digitalRead(DOWN_BUTTON) == LOW) // Check if down button is pressed
    {
        mx.setPoint(y, x, false);
        y++;
    }
    else if (digitalRead(LEFT_BUTTON) == LOW) // Check if left button is pressed
    {
        mx.setPoint(y, x, false);
        x++;
    }

    x = rollOver(x); // Check if horizontal position is beyond the display and reposition
    y = rollOver(y); // Check if vertical position is beyond the display and reposition

    mx.setPoint(y, x, true); // Draw the point on the matrix display
    delay(100);              // delay for performance
}

int rollOver(int number) // Check if the position of the dot is beyond the matrix and reposition at a valid location
{
    if (number > 7)
    {
        return 0;
    }
    else if (number < 0)
    {
        return 7;
    }
    else
    {
        return number;
    }
}

void setup()
{
    //Set up pins for button inputs
    pinMode(RIGHT_BUTTON, INPUT_PULLUP);
    pinMode(DOWN_BUTTON, INPUT_PULLUP);
    pinMode(LEFT_BUTTON, INPUT_PULLUP);
    pinMode(UP_BUTTON, INPUT_PULLUP);

    mx.begin();                                           // Begin metrix object
    mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY / 2); // Initialise matrix display parameters
    mx.clear();                                           // Clear matrix display

    mx.setPoint(y, x, true); // Draw initial point
}

void loop()
{
    checkInput(); // Check for user input
    mx.update();  // Update display output
}