/*
    Connect the 4-digit seven segment LED display, 
    write code to display “11:59”.
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
    {1, 1, 1, 1, 0, 1, 1}, //Nice
};

void setup()
{
    for (int i = 1; i < 14; i++) // Initialise pins 1 to 13
    {
        pinMode(i, OUTPUT);   // Set pin to OUTPUT
        digitalWrite(i, LOW); // Set pin to low
    }
    digitalWrite(A0, HIGH); //turn on colon
}

void loop()
{
    writeMessage(1, 1, 5, 9); // Display message on seven segment display
}

// Set the 4 digits into the requested values
void writeMessage(int firstDigit, int secondDigit, int thirdDigit, int forthDigit)
{
    // Store all digits in an array for easier iteration
    int message[4] = {firstDigit, secondDigit, thirdDigit, forthDigit};

    for (int i = 0; i < 4; i++) // Iterate through the digits and write the appropriate value
    {
        writeToDigit(i);           // Enable writing on the digit
        displayNumber(message[i]); // Write message
        resetWritePins();          // Reset all pins
    }
}

void writeToDigit(int digit) //Turn on appropriate digit for writing
{
    for (int i = 10; i < 14; i++) // Turn off all pins
    {
        digitalWrite(i, HIGH);
    }

    digitalWrite(10 + digit, LOW); // Turn on corrent pin
    delay(1);                      // Delay to ensure changes have taken place
}

void displayNumber(int number) // Set the appropriate pins to on for the digits to display
{
    for (int i = 0; i < 7; i++) //Iterate through all the pins and set them according to the array
    {
        digitalWrite(i + 2, numbers[number][i]);
    }
    delay(1); //Delay 1ms to ensure changes have taken place
}

void resetWritePins() // Set all pins to low
{
    for (int i = 1; i < 14; i++)
    {
        digitalWrite(i, LOW);
    }
    turnOffAllDigits(); // Reset all write enable pins
}

void turnOffAllDigits() // Reset all write enable pins
{
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
}