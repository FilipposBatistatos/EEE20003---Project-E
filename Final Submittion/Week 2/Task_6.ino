/*
    Write code to change the volume of the piezo buzzer 
    based on input from Serial monitor (Use PWM).
*/

int buzzer_pin = 2; // Stores buzzer pin number
int input;          // Stores user input

void setup()
{
    Serial.begin(9600);          // Initialise serial communication
    pinMode(buzzer_pin, OUTPUT); // Set buzzer pin to output
    // Print message in Serial monitor
    Serial.println("Enter a number between 1 and 255 to control the buzzer volume");
}

void loop()
{
    input = Serial.parseInt();        // Get input from serial monitor
    if ((input > 0) && (input < 256)) // Ensure the value is within the boundry
    {
        Serial.print("Volume changed to "); // Print message
        Serial.println(input);
        analogWrite(buzzer_pin, input); // Set buzzer pin to the input frequency
    }
    delay(10); // Delay 10ms for performance
}