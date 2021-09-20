/*
    Connect 5 LEDs (remember to use 270 Ohm resistors). 
    Write code to take input (a single number ranging from 1 to 5) 
    from Serial monitor and light up the corresponding LED. 
    Only one LED lit up at a time.
*/

#define PIN_OFFSET 2

int input;     // Stores user input
int activeLED; // Store the LED that is currently on

void setup()
{
    Serial.begin(9600);         //Initialise serial communication
    for (int i = 2; i < 8; i++) // Set pins 2 to 7 to OUTPUT and set them to low
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
    Serial.println("Enter a number from 1 to 5"); // Print a message on the serial monitor
}

void loop()
{
    input = Serial.parseInt();      // Take input from serial monitor
    if ((input > 0) && (input < 6)) // Check if it's a valid input
    {
        digitalWrite(activeLED, LOW);   // Turn off the previously selected LED
        activeLED = input + PIN_OFFSET; // Store the approprite value in the activeLED variable
        digitalWrite(activeLED, HIGH);  // Turn on the new LED
    }
    delay(10); // Delay 10ms for better performance
}