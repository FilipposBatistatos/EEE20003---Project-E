// Link to the simulation https://wokwi.com/arduino/projects/309683284460175938

// To toggle between temperature, double click the button
// To change to analog/digital press the button once
// To set up an alarm, press and hold the button, upon release the alarm will come up

#include <OneButton.h> //Allows for different types of presses out of one button
#include "U8glib.h"    //Controls the OLED display
#include <RTClib.h>    //Reads the RTC clock

//================= Analog clock constants=====================
#define MINUTEHAND 24 //Length of minute hand
#define HOURHAND 12   //Length of hour hand
#define SECONDHAND 26 //Length of second hand
#define XCENTER 54    //Horizontal center of analog clock
#define YCENTER 31    //Vertical center of analog clock

//========================= Pins ===============================
#define BUTTON A1 //Pin for button
#define BUZZER 8  //Pin for buzzer
#define TEMP A0   //Pin for temperature sensor

//====================== Constants =============================
const float BETA = 3950; //Constant for analog to temperature convertion

//================== Object initialisation =====================
U8GLIB_SSD1306_128X64 u8g;      //Initialising the display
RTC_DS1307 rtc;                 //Initialising the RTC
OneButton button(BUTTON, true); //attach a button

//===================== Mode variables =========================
bool analog = true; // true is analog, false is digital
bool temp = true;   //true is temperature presented, false is not

// ===================== Clock variables =======================
String digitalClock; //Digital clock value

float hrRad;  //Hour in radians
float mnRad;  //minutes in radians
float secRad; //minutes in radians

//==================== Other Global variables =================
int alarmMinute = ""; //Alarm clock minute
int alarmHour = "";   //Alarm clock hour

float celsius; //Temperature in celsius

// ========================= Functions =========================
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//======================== Clock functions =======================
void toggleAnalog()
{
    analog = !analog;
}

void setTime()
{
    DateTime now = rtc.now();
    int hr = now.hour();
    int mn = now.minute();
    int sec = now.second();

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
    digitalClock += ":";
    if (sec < 10)
    {
        digitalClock += 0;
    }
    digitalClock += sec;

    checkAlarm(hr, mn);

    //preparing analog clock varibles
    if (hr == 12)
    {
        hr = 0;
    }
    if (mn == 60)
    {
        mn = 0;
    }
    if (sec == 60)
    {
        sec = 0;
    }
    hrRad = mapFloat(hr, 0, 12, 0, 2 * PI);
    mnRad = mapFloat(mn, 0, 60, 0, 2 * PI);
    secRad = mapFloat(sec, 0, 60, 0, 2 * PI);
}

//===================== Temperature functions ================
//toggle between showing and not showing temperature
void toggleTemp()
{
    temp = !temp;
}

//Obtain a reading of the current temperature
void getTemperature()
{
    int analogValue = analogRead(TEMP);
    celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
}

// ====================== Alarm functions ====================
//Set the alarm time
void setAlarm()
{
    int minute;
    int hour;

    //Obtain time to set the alarm through the serial monitor
    Serial.println("Set and alarm, type in the hour (1-12)");
    do
    {
        hour = Serial.parseInt();
    } while (!hour);
    Serial.println("Set the minutes");
    do
    {
        minute = Serial.parseInt();
    } while (!minute);
    Serial.print("Alarm has been set for ");
    Serial.print(hour);
    Serial.print(":");
    Serial.println(minute);

    //Set the variables for the alarm
    alarmMinute = minute;
    alarmHour = hour;
}

//Check the alarm time
void checkAlarm(int hour, int minute)
{
    if ((hour == alarmHour) && (minute == alarmMinute))
    {
        tone(BUZZER, 250, 100);
        delay(250);
        digitalWrite(LED_BUILTIN, HIGH);
        alarmHour = "";
        alarmMinute = "";
    }
}

//====================== Main functions ========================
void setup()
{
    Serial.begin(9600);
    rtc.begin();

    u8g.setFont(u8g_font_7x13);

    button.attachDoubleClick(toggleTemp);
    button.attachClick(toggleAnalog);
    button.attachLongPressStop(setAlarm);

    Serial.println("Instuctions: \n Single press: Toggle between analog and digital \n Double press: Toggle temperature display \n Long press: Set up an alarm \n");
}

void loop()
{
    setTime();
    button.tick();
    //=============== START OF DRAW ===================
    u8g.firstPage();
    do
    {
        u8g.setColorIndex(1); //set colour to white
        if (analog)
        {
            //================= Analog Clock Draw Start =====================
            //drawCircle(x, y, radius)
            u8g.drawCircle(XCENTER, YCENTER, 30); // Analog clock rim
            u8g.drawCircle(XCENTER, YCENTER, 3);

            //draw 5 minute markings
            u8g.drawLine(XCENTER, YCENTER - 30, XCENTER, YCENTER - 25);
            u8g.drawLine(XCENTER, YCENTER + 30, XCENTER, YCENTER + 25);
            u8g.drawLine(XCENTER + 30, YCENTER, XCENTER + 25, YCENTER);
            u8g.drawLine(XCENTER - 30, YCENTER, XCENTER - 25, YCENTER);
            u8g.drawLine(XCENTER + 30 * cos(30 * 180 / PI), YCENTER + 30 * sin(30 * 180 / PI), XCENTER + 25 * cos(30 * 180 / PI), YCENTER + 25 * sin(30 * 180 / PI));
            u8g.drawLine(XCENTER - 30 * cos(30 * 180 / PI), YCENTER - 30 * sin(30 * 180 / PI), XCENTER - 25 * cos(30 * 180 / PI), YCENTER - 25 * sin(30 * 180 / PI));
            u8g.drawLine(XCENTER + 30 * cos(30 * 180 / PI), YCENTER - 30 * sin(30 * 180 / PI), XCENTER + 25 * cos(30 * 180 / PI), YCENTER - 25 * sin(30 * 180 / PI));
            u8g.drawLine(XCENTER - 30 * cos(30 * 180 / PI), YCENTER + 30 * sin(30 * 180 / PI), XCENTER - 25 * cos(30 * 180 / PI), YCENTER + 25 * sin(30 * 180 / PI));
            u8g.drawLine(XCENTER + 30 * cos(60 * 180 / PI), YCENTER - 30 * sin(60 * 180 / PI), XCENTER + 25 * cos(60 * 180 / PI), YCENTER - 25 * sin(60 * 180 / PI));
            u8g.drawLine(XCENTER - 30 * cos(60 * 180 / PI), YCENTER - 30 * sin(60 * 180 / PI), XCENTER - 25 * cos(60 * 180 / PI), YCENTER - 25 * sin(60 * 180 / PI));
            u8g.drawLine(XCENTER + 30 * cos(60 * 180 / PI), YCENTER + 30 * sin(60 * 180 / PI), XCENTER + 25 * cos(60 * 180 / PI), YCENTER + 25 * sin(60 * 180 / PI));
            u8g.drawLine(XCENTER - 30 * cos(60 * 180 / PI), YCENTER + 30 * sin(60 * 180 / PI), XCENTER - 25 * cos(60 * 180 / PI), YCENTER + 25 * sin(60 * 180 / PI));

            //drawLine(xStart, yStart, xFinish, yFinish)
            u8g.drawLine(XCENTER, YCENTER, XCENTER + HOURHAND * sin(hrRad), YCENTER - HOURHAND * cos(hrRad));       //hours hand
            u8g.drawLine(XCENTER, YCENTER, XCENTER + MINUTEHAND * sin(mnRad), YCENTER - MINUTEHAND * cos(mnRad));   //minutes hand
            u8g.drawLine(XCENTER, YCENTER, XCENTER + SECONDHAND * sin(secRad), YCENTER - SECONDHAND * cos(secRad)); //minutes hand
                                                                                                                    //================= Analog Clock Draw End =======================
        }
        else
        {
            //Digital Clock
            u8g.setScale2x2();
            u8g.setPrintPos(5, 20);
            u8g.print(digitalClock);
            u8g.undoScale();
        }

        //================== Temperature Display =====================
        if (temp)
        {
            getTemperature();
            u8g.setPrintPos(80, 60);
            u8g.print(celsius);
            u8g.print("C");
        }
        // ============== End of temperature display ================

    } while (u8g.nextPage());
    //=================== END OF DRAW ===========================
}
