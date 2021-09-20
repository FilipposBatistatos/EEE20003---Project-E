/*
    Connect the seven segment LED display, 
    write code to display number from 9 to 0 
    (change every 1 second).
*/

bool numbers[10][7] = {
    // Store all the value for all numbers in a 2D array
    //A, B, C, D, E, F, G
    {1, 1, 1, 1, 1, 0, 1}, //Zero
    {0, 1, 1, 0, 0, 0, 0}, //One
    {1, 1, 0, 1, 1, 1, 0}, //Two
    {1, 1, 1, 1, 0, 1, 0}, //Three
    {0, 1, 1, 0, 0, 1, 1}, //Four
    {1, 0, 1, 1, 0, 1, 1}, //Five
    {1, 0, 1, 1, 1, 1, 1}, //Six
    {1, 1, 1, 0, 0, 0, 0}, //Seven
    {1, 1, 1, 1, 1, 1, 1}, //Eight
    {1, 1, 1, 0, 0, 1, 1}, //Nice
};

void setup()
{
    for (int i = 5; i < 12; i++) // Initialise pins 5 to 11
    {
        pinMode(i, OUTPUT);   // Set pin to OUTPUT
        digitalWrite(i, LOW); // Set pin to low
    }
}

void loop()
{
    for (int i = 9; i >= 0; i--) // Count down from 9 to 0
    {
        for (int j = 0; j < 7; j++) // Set the pins to the right value
        {
            digitalWrite(j + 5, numbers[i][j]); // Use array values for appropriate pin state
            // Might require microsecond delay here in actual hardware
        }
        delay(1000); //Delay 1 seconds to display numeral
    }
}