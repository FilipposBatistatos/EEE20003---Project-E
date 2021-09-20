/*
    Write a function to for multiplication, 
    Values needed to multiply be the inputs to the 
    function and function should output the correct value. 
    Using the function multiply 16 x 15 and print the 
    correct value in the serial monitor.
*/

// Multiply the two parameters with each other
int multiplication(int x, int y)
{
    return x * y; // Return the product of x and y
}

void setup()
{
    Serial.begin(9600);                     // Initialise
    Serial.println(multiplication(16, 15)); // Print the return of the function
}

// Loop must be defined
void loop()
{
}