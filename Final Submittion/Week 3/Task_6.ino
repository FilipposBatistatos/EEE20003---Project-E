/*
    Connect NeoPixel Rings and DS1307 RTC to Arduino Mega. 
    Write a code to create a simple timer using DS1307 RTC and 
    NeoPixel Rings as visualization. In the setup(), write code 
    to take input from serial monitor to set up the hour, minute 
    and second for the timer.
*/

#include <FastLED.h> // Library to control LED ring
#include <RTClib.h>  // LIbrary to control clock

CRGB indicator[60]; // Initialise LED array

RTC_DS1307 rtc; // Initialise clock object

int countDownSeconds; // Stores dount down in seconds
int maximum;          // stores the maximum time

int input() // Obtain input from the user
{
    int parse;
    int count = 0;
    do
    {
        parse = Serial.parseInt();
        Serial.println(parse);
        count++;
    } while ((!parse) and (count < 10));
    return parse;
}

void setCountDown(int hours, int minutes, int seconds) // Turn hour, minutes and seconds into seconds to make it easier to count down
{
    DateTime now = rtc.now(); // Get current time

    seconds += minutes * 60;
    seconds += hours * 60 * 60;
    countDownSeconds = seconds;

    maximum = countDownSeconds; // Set the maximum count down

    countDownSeconds += now.second();
    countDownSeconds += now.minute() * 60;
    countDownSeconds += now.hour() * 60 * 60;
}

void setVisualiser() // Write to the led ring
{
    DateTime now = rtc.now();                                                     // Get the current time
    int currentSeconds = now.second() + now.minute() * 60 + now.hour() * 60 * 60; // Turn the current time into seconds
    int visualiser;                                                               // Stores the visualiser value

    visualiser = countDownSeconds - currentSeconds;

    if (visualiser > 0) // Set the visualiser to the appropriate amount
    {
        visualiser = map(visualiser, 0, maximum, 0, 59);
        for (int i = 0; i < visualiser; i++)
        {
            indicator[i] = CRGB::DodgerBlue;
        }
    }
    else // Set to red if the time has elapsed
    {
        for (int i = 0; i < 60; i++)
        {
            indicator[i] = CRGB::Red;
        }
    }
}

void setup()
{
    int second, minute, hour; // Store user inputs for hour, minute and seconds
    char msg[10] = "";        // Store the message to display to the user

    rtc.begin(); // Begin clock

    Serial.begin(9600);
    Serial.println("Enter the number of hours"); // Get the number of hours
    hour = input();

    Serial.println("Enter the number of minutes"); // Get the number of minutes
    minute = input();

    Serial.println("Enter the number of seconds"); // Get the number of seconds
    second = input();

    sprintf(msg, "%02d:%02d:%02d", hour, minute, second); // Set the message to the appropriate values
    Serial.println(msg);

    setCountDown(hour, minute, second); // Set the count down to the right values

    pinMode(4, OUTPUT);

    FastLED.addLeds<NEOPIXEL, 4>(indicator, 60); // Initialise led ring
}

void loop()
{
    FastLED.clear();
    setVisualiser();
    FastLED.show();
    delay(100);
}