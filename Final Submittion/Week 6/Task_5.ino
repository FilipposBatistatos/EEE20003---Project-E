/*
   Write a program to display “I love Swinburne” in the LED matrix. 
   When the external button is pressed it should display your name. 
   The text should move from left to right continuously.
   (Use LED Dot Matrix MA7219 and interrupts). 
*/

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <Wire.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4 // Define the number of displays connected
#define CLK_PIN 52    // CLK or SCK
#define DATA_PIN 51   // DATA or MOSI
#define CS_PIN 53     // CS or SS
#define SPEED_TIME 10 // Speed of the transition
#define MAX_MESG 20

//char szTime[9];    // mm:ss\0
char szMesg[MAX_MESG + 1] = "";

int display = 0;

// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup()
{
    P.begin();          // Begin communication with display
    P.setInvert(false); // Set up display parameters
    P.setZone(0, MAX_DEVICES - 4, MAX_DEVICES - 1);
    P.displayZoneText(0, szMesg, PA_CENTER, SPEED_TIME, 0, PA_PRINT, PA_NO_EFFECT);

    attachInterrupt(digitalPinToInterrupt(2), toggle, CHANGE); // Attach interrupt pin to function
}

void loop()
{
    P.displayAnimate(); // Animate display

    if (P.getZoneStatus(0)) // Check is the zone is available for writing
    {
        switch (display) // Check in which state the display is
        {
        case 0: // Print "I love Swinburne"
            sprintf(szMesg, "I love Swinburne");
            break;
        case 1: // Print my name
            sprintf(szMesg, "Philip");
        }

        //Display the text on the display
        P.setTextEffect(0, PA_SCROLL_RIGHT, PA_SCROLL_RIGHT); // set up effects
        P.setPause(0, 0);                                     // remove any pause
        P.setSpeed(0, 20);                                    // set speed of animation

        P.displayReset(0); // Rest zone zero
    }
}

void toggle() // Toggle between display zones
{
    display++;
    display = display % 2;
}