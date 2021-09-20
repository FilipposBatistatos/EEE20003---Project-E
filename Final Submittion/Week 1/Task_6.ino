/*
    Write a program that will turn On the LED for 1 second 
    and off the LED for 2 seconds. Make sure that the LED is 
    connected to pin 7.
*/

void setup()
{
    pinMode(7, OUTPUT); // Setting pin 7 to output
}

void loop()
{
    digitalWrite(7, HIGH); //Turning On the LED
    delay(1000);           // Waiting for one second
    digitalWrite(7, LOW);  //Turning Off the LED
    delay(2000);           // Waiting for two seconds
}