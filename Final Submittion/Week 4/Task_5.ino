/*
    Write a program that displays the correct voltage 
    reading from the potentiometer as you dial it on the serial monitor.
*/

const float voltage = 3.3; // Change to 5 if connected to the 5V

void setup()
{
    Serial.begin(9600); // Initialise serial communication
}

void loop()
{
    float analogInput = analogRead(A0) * (voltage / 1023); // Read analog input and convert to voltage
    Serial.print(analogInput);                             // Print voltage reading
    Serial.println("V");

    delay(1000); // Delay 1 second for performance and readability
}