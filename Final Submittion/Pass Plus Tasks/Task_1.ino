/*
    To design digital clock with few features. 
    Connect OLED display to Arduino. Write program to display 
    analog and digital clocks. At the beginning, the clock is 
    set up using serial. A real time clock (RTC) module can be 
    added as well.
*/

#include "U8glib.h" // Include OLED display library
#include <RTClib.h> // Include clock library

#define MINUTEHAND 25 // Magnitude of minute hand
#define HOURHAND 15   // Magnitude of hour hand

U8GLIB_SSD1306_128X64 u8g; //Initialising the display
RTC_DS1307 rtc;            //Initialising the RTC

String digitalClock = "10:00"; // Initial time placeholder

float hrRad; // Angle of the hour hand in radians
float mnRad; // Angle of the minute hand in radians

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    // Custom function based on the map function but returning a float instead of int
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setTime() // Update to the current time
{
    DateTime now = rtc.now(); // Load the current time as a DateTime
    int hr = now.hour();      // Extract the hours
    int mn = now.minute();    // Exctract the minutes

    //==================preparing digital clock variabes==================
    digitalClock = "";
    if (hr < 10)
    {
        digitalClock += "0";
    }
    digitalClock += hr;
    digitalClock += ":";
    if (mn < 10)
    {
        digitalClock += 0;
    }
    digitalClock += mn;

    //===================preparing analog clock varibles==================
    if (hr == 12)
    {
        hr = 0;
    }
    if (mn == 60)
    {
        mn = 0;
    }
    hrRad = mapFloat(hr, 0, 12, 0, 2 * PI); // Map the hour to a circle
    mnRad = mapFloat(mn, 0, 60, 0, 2 * PI); // Map the minutes to a circle
}

void setup()
{
    Serial.begin(9600);         // Initialise serial communication
    rtc.begin();                // Begin clock
    u8g.setFont(u8g_font_7x13); // Set font for OLED display
}

void loop()
{
    setTime();
    //=============== START OF DRAW ===================
    u8g.firstPage();
    do
    {
        u8g.setColorIndex(1); //set colour to white

        //================= Analog Clock Draw Start =====================
        //drawCircle(x, y, radius)
        u8g.drawCircle(32, 31, 30); // Analog clock rim
        u8g.drawCircle(32, 31, 3);

        //drawLine(xStart, yStart, xFinish, yFinish)
        u8g.drawLine(32, 31, 32 + HOURHAND * sin(hrRad), 31 - HOURHAND * cos(hrRad));     //minutes hand
        u8g.drawLine(32, 31, 32 + MINUTEHAND * sin(mnRad), 31 - MINUTEHAND * cos(mnRad)); //minutes hand
        //================= Analog Clock Draw End =======================

        //Digital Clock
        u8g.setPrintPos(70, 35);
        u8g.print(digitalClock);

    } while (u8g.nextPage());
    //=================== END OF DRAW ===========================
}