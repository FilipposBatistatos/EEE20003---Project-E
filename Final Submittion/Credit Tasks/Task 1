#include "U8glib.h"
#include <RTClib.h>

//Analog clock constants
#define MINUTEHAND 25
#define HOURHAND 15
#define XCENTER 64
#define YCENTER 31

//Pins
#define BUTTON 2

U8GLIB_SSD1306_128X64 u8g; //Initialising the display
RTC_DS1307 rtc;            //Initialising the RTC

bool mode = true; // true is analog, false is digital

String digitalClock = "10:00";

float hrRad;
float mnRad;

// Arduino map returns an integer, this is a modification that returns a float
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setTime()
{
    DateTime now = rtc.now();
    int hr = now.hour();
    int mn = now.minute();

    //preparing digital clock variabes
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

    //preparing analog clock varibles
    if (hr == 12)
    {
        hr = 0;
    }
    if (mn == 60)
    {
        mn = 0;
    }
    hrRad = mapFloat(hr, 0, 12, 0, 2 * PI);
    mnRad = mapFloat(mn, 0, 60, 0, 2 * PI);
}

void toggleMode()
{
    mode = !mode;
    //Serial.println(mode);
}

void setup()
{
    //Serial.begin(9600);
    rtc.begin();

    u8g.setFont(u8g_font_7x13);

    attachInterrupt(digitalPinToInterrupt(BUTTON), toggleMode, CHANGE);
}

void loop()
{
    setTime();
    //=============== START OF DRAW ===================
    u8g.firstPage();
    do
    {
        u8g.setColorIndex(1); //set colour to white
        if (mode)
        {
            //================= Analog Clock Draw Start =====================
            //drawCircle(x, y, radius)
            u8g.drawCircle(XCENTER, YCENTER, 30); // Analog clock rim
            u8g.drawCircle(XCENTER, YCENTER, 3);

            //drawLine(xStart, yStart, xFinish, yFinish)
            u8g.drawLine(XCENTER, YCENTER, XCENTER + HOURHAND * sin(hrRad), YCENTER - HOURHAND * cos(hrRad));     //minutes hand
            u8g.drawLine(XCENTER, YCENTER, XCENTER + MINUTEHAND * sin(mnRad), YCENTER - MINUTEHAND * cos(mnRad)); //minutes hand
            //================= Analog Clock Draw End =======================
        }
        else
        {
            //Digital Clock
            u8g.setScale2x2();
            u8g.setPrintPos(15, 20);
            u8g.print(digitalClock);
            u8g.undoScale();
        }
    } while (u8g.nextPage());
    //=================== END OF DRAW ===========================
}
