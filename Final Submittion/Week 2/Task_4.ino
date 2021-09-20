/*
    Write code to toggle the LED when the button is pressed.
*/

int led_pin = 7;    // Stores the pin for the LED anode
int button_pin = 6; // Stores the pin for the button
bool output = true; // Stores the current LED state, Bool takes up the least amount of space

void setup()
{
    pinMode(button_pin, INPUT); // Set button to INPUT
    pinMode(led_pin, OUTPUT);   // Set led pin to OUTPUT

    digitalWrite(led_pin, LOW); // Set led pin to LOW
}

void loop()
{
    if (digitalRead(button_pin)) // Trigger on button press
    {
        do // Wait for button to be released
        {
            delay(10); // Delay 10ms for performance
        } while (digitalRead(button_pin) == HIGH);

        output = !output;              // Toggle bool, most efficiect way to toggle LED
        digitalWrite(led_pin, output); // Set LED to output
        delay(50);                     // delay 50ms for performance between button presses, longer for debouncing
    }
}