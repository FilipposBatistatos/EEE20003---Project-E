/*
    Connect 3NeoPixelRings to Arduino Mega. 
    Write code to develop an analog clock display with 
    each NeoPixel Rings presents hour, minute and second.
*/

#include <FastLED.h> // Library to control the LED rings

#define SECONDS 5 // Seconds ring led pin
#define MINUTES 6 // Minutes ring led pin
#define HOURS 7   // Hours ring led pin

CRGB seconds[60]; // Seconds led array
CRGB minutes[60]; // Minutes led array
CRGB hours[12];   // Hours led array

unsigned int time;
int timeNow = millis(); // capture time

void setup()
{
    Serial.begin(9600);                                         // Initialise serial communication
    Serial.println("Please enter the current time in seconds"); // Print message on Serial monitor

    do
    {
        unsigned int input = Serial.parseInt();
        if (input != 0)
            time = input;
        time = time % 43200;
    } while (!time); // Obtain appropriate time from serial monitor

    Serial.println(time);                            // print time in seconds
    FastLED.addLeds<NEOPIXEL, SECONDS>(seconds, 60); // Initialise seconds led ring
    FastLED.addLeds<NEOPIXEL, MINUTES>(minutes, 60); // Initialise minutes led ring
    FastLED.addLeds<NEOPIXEL, HOURS>(hours, 12);     // Initialise hours led ring
}

void loop()
{
    FastLED.clear(); // Clear all the LEDs
    setHours();      // Prepare the hours led ring
    setMinutes();    // Prepare the minutes led ring
    setSeconds();    // Prepare the seconds led ring
    FastLED.show();  // Load previiously prepared configuration on the led rings

    int currentTime = millis();         // Store current time
    if ((currentTime - 1000) > timeNow) // Check if a second has ellapsed
    {
        time++;                //Increment time
        time = time % 43200;   // Circle around for 12 hours
        timeNow = currentTime; // Update time to current time
    }
}

void setHours() // Set the array for hours to the correct values
{
    int hand = ((time / 60) / 60) % 13;
    for (int i = 0; i <= hand; i++)
    {
        hours[i] = CRGB::Aqua;
    }
}

void setMinutes() // Set the array for minutes to the correct values
{
    int hand = (time / 60) % 60;
    for (int i = 0; i <= hand; i++)
    {
        minutes[i] = CRGB::Aqua;
    }
}

void setSeconds() // Set the array for seconds to the correct values
{
    int hand = time % 60;
    for (int i = 0; i <= hand; i++)
    {
        seconds[i] = CRGB::Aqua;
    }
}