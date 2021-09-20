/*
    Write a simple program that 
    will print the values from 1 to 10 
    in the serial monitor using a while loop.
*/

// Use setup to only execute the program once
void setup()
{
    Serial.begin(9600); // Initialise serial commnication
    int i = 1;          // Initialise iteration value
    while (i < 11)
    {
        Serial.println(i); // Print the number
        i++;               // Increment the number by one
    }
}

// Loop must be defined
void loop()
{
}