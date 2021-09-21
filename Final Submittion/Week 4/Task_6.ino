/*
    Write a program that controls the volume of a noise from 
    the speaker using input from the potentiometer.
*/

#define SPEAKER       // Connect speaker to pin 10
#define POTENTIOMETER // Connect potentiometer to pin A0

void setup()
{
    pinMode(SPEAKER, OUTPUT);      // Set up speaker pin
    pinMode(POTENTIOMETER, INPUT); // Set up potentiometer poin
    Serial.begin(9600);            // Initialise serial communication
}

void loop()
{
    int analogValue = analogRead(POTENTIOMETER);      // Read potentiometer value
    analogWrite(SPEAKER, (analogValue / 1023) * 254); // Convert potentiometer reading to frequency
    delay(10);                                        // Delay for performance
}