/*
    Connect OLED display and HC-SR04 Ultrasonic Distance Sensor 
    to Arduino Mega. Write a code to present the distance value 
    from Ultrasonic sensor as a rectangle (height of the rectangle 
    will be the same while the width of the rectangle will be changed 
    based on the distance value). Display a certain simple text on 
    OLED display based on the distance value: “Safe” when the 
    distance >= 200, “Careful” when 80 <= distance < 200 and 
    “Too Closed” when distance < 80.
*/

#include <U8glib.h> // Library to control OLED display

U8GLIB_SSD1306_128X64 u8g; // Initialise display object

#define PIN_TRIG 3 // Trigger pin for ultrasonic sensor
#define PIN_ECHO 4 // Echo pin for ultrasonic sensor

char szMesg[10] = ""; // Stores currenty displayed message

void setup()
{
    pinMode(PIN_TRIG, OUTPUT);   // Set trigger pin to output
    pinMode(PIN_ECHO, INPUT);    // Set echo pin to input
    u8g.setFont(u8g_font_tpssb); // Set display font
}

void loop()
{
    setMessage();    // Calculate distance and set message to appropriate value
    u8g.firstPage(); // Begin draw loop
    do
    {
        u8g.drawStr(20, 20, szMesg); // Draw the message on the screen
    } while (u8g.nextPage());        // End draw loop
}

void setMessage()
{
    int distance = calcDistance(); // Calculate the distance
    if (distance >= 200)           // Pick the appropriate message to be displayed
    {
        sprintf(szMesg, "Safe"); // Load the message on the variable
    }
    else if (distance < 200 && distance >= 80)
    {
        sprintf(szMesg, "Careful"); // Load the message on the variable
    }
    else
    {
        sprintf(szMesg, "Too close"); // Load the message on the variable
    }
}

int calcDistance() // Calculate the distance from the sensor
{
    digitalWrite(PIN_TRIG, HIGH);           // Turn the trigger pin on
    delayMicroseconds(10);                  // Delay 10 microseconds to ensure the pulse has gone through
    digitalWrite(PIN_TRIG, LOW);            // Turn the trigger pin off
    int duration = pulseIn(PIN_ECHO, HIGH); // Wait until the pulse is detected
    return duration / 58;                   // Convert the distance to centimeters
}