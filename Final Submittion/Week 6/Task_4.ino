/*
    Write a simple program to blink the inbuilt LED 
    every 500 milliseconds. Connect two buttons to the Arduino 
    (Button A & Button B) When A is pressed millis value should 
    be printed in the serial monitor and when the B is pressed 
    micros value should be printed in the serial monitor. 
    (Use hardware interrupts)
*/

int millisButton = 2;  // Connect button to trigger milliseconds
int microsButton = 20; // Connect button to trigger microseconds

void setup()
{
    Serial.begin(9600);

    //Attach interrupt events
    attachInterrupt(digitalPinToInterrupt(microsButton), printMicros, FALLING);
    attachInterrupt(digitalPinToInterrupt(millisButton), printMillis, FALLING);
}

void loop()
{
}

void printMillis()
{
    // Print message for milliseconds
    Serial.print("Milliseconds : ");
    Serial.println(millis());
}

void printMicros()
{
    // Print message for microseconds
    Serial.print("Microseconds : ");
    Serial.println(micros());
}