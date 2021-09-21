/*
    Write a program that displays the correct reading of 
    the temperature in the immediate surrounding of the temperature 
    sensor in Celsius and Fahrenheit using appropriate calibration 
    steps on the serial monitor.
*/

const float BETA = 3950; // Constant to normalise the output

void setup()
{
    Serial.begin(9600); // Initialise serial output
}

void loop()
{
    int analogValue = analogRead(A0); // Read the analog value from the temperature sensor
    // Convert analog value to celsius
    float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
    float fahrenheit = (celsius * 1.8) + 32; // Convert celsius to Fahrenheit
    // Print temperature
    Serial.print("Temperature: ");
    Serial.print(celsius);
    Serial.print(" ℃, ");
    Serial.print(fahrenheit);
    Serial.println(" F");

    delay(1000); // Delay 1 second for performance
}