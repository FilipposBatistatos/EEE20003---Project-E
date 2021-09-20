/*
    Connect DS1307 RTC and LED Matrix with “chain” attribute is 5 to 
    Arduino Mega. Write a code to display the current time from DS1307 
    RTC to LED Matrix with the speed value is 10, pause value is 100, 
    and text alignment is PA_CENTER.
*/

#include <MD_Parola.h>  // Library to control the matrix display
#include <MD_MAX72xx.h> // Library to control the matrix display
#include <SPI.h>        // Assistant library for the matrix display
#include <Wire.h>       // Assistant library for the matrix display
#include <RTClib.h>     // Clock library

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 5  // Define the number of displays connected
#define CLK_PIN 52     // CLK or SCK
#define DATA_PIN 51    // DATA or MOSI
#define CS_PIN 53      // CS or SS
#define SPEED_TIME 10  // Speed of the transition
#define PAUSE_TIME 100 // Time between animations
#define MAX_MESG 20    // Maximum length for message

RTC_DS1307 rtc; // Initiliase clock object

// Global variables
uint8_t hours, minutes, seconds;

//char szTime[9];    // mm:ss\0
char szMesg[MAX_MESG + 1] = "";

// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void getDS1307() // Read time from the clock
{
    DateTime now = rtc.now(); // Load current time
    minutes = now.minute();   // Store minutes
    hours = now.hour();       // Store hours
}

// Code for reading clock time
void getTime(char *psz, bool f = true)
{
    sprintf(psz, "%02d%c%02d", hours, (f ? ':' : ' '), minutes);
}

void setup()
{
    rtc.begin(); // Begin clock object

    P.begin(); // Begin matrix display

    // Matrix display settings
    P.setInvert(false);
    P.setZone(0, MAX_DEVICES - 4, MAX_DEVICES - 1);
    P.displayZoneText(0, szMesg, PA_CENTER, SPEED_TIME, 0, PA_PRINT, PA_NO_EFFECT);
}

void loop()
{
    static uint32_t lastTime = 0; // Memory (ms)
    static bool flasher = false;  // Seconds passing flasher

    getDS1307(); // update time

    P.displayAnimate(); // Animate the display

    if (P.getZoneStatus(0)) // Check if the zone is ready to be written to
    {
        P.setTextEffect(0, PA_NO_EFFECT, PA_NO_EFFECT); // Set no effects on the text
        P.setPause(0, 0);                               // No pause of display length

        if ((millis() - lastTime) >= 1000) // Check if a second has passed to update the flashing ":"
        {
            lastTime = millis();
            getTime(szMesg, flasher);
            flasher = !flasher;
        }

        P.displayReset(0); // Rest zone zero
    }
}