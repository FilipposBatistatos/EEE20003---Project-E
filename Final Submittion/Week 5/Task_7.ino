/*
    Create a program that turns on and off individual LEDs 
    using the middle 8 LEDs from an LED bar graph using the 
    numeric input from the serial monitor. You need to use an 
    array to initialise all digital input pins and create a void 
    function that prints out which LED (from 1 to 8) is being turned 
    on e.g., ‘OUTPUT X ON’, turns up the brightness of the selected 
    LED, and then turns down its brightness for an appropriate duration 
    of time and prints ‘OUTPUT X OFF’. It is recommended that you use 
    the network resistor and LED bar graph for this exercise.
*/

int LEDarray[] = {5, 6, 7, 8, 9, 10, 11, 12}; // Store all LED active pins

int getInput() // Obtain user input
{
    int input;
    do
    {
        input = Serial.parseInt();
    } while (!input);
    return input;
}

void turnOn(int led) // Sequence to on and off LED
{
    // Print out the state of the LED
    Serial.print("OUTPUT ");
    Serial.print(led);
    Serial.println(" ON");

    for (int i = 0; i < 255; i++) // turn on LED slowly
    {
        analogWrite(LEDarray[led - 1], i);
        delay(10); // Delay 10ms for performance
    }

    delay(1000); // Wait 1 second

    for (int i = 255; i >= 0; i--) // Turn off LED slowly
    {
        analogWrite(LEDarray[led - 1], i);
        delay(10); // Delay 10ms for performance
    }

    // Print out the state of the LED
    Serial.print("OUTPUT ");
    Serial.print(led);
    Serial.println(" OFF");
}

void setup()
{
    for (int i = 0; i < 7; i++)
    {
        pinMode(LEDarray[i], OUTPUT); // set all pins to outputs
    }
    Serial.begin(9600); // Initialise serial communication
}

void loop()
{
    Serial.println("Enter a number from 1-7"); // Print message
    int led = getInput();                      // Obtain input from user
    turnOn(led);                               // Turn on appropriate LED
}