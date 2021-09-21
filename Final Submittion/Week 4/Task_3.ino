/*
    Write a program that displays the correct binary 
    representation of a user defined decimal integer 
    between 0 and 255 on the serial monitor.
*/

void decToBinary(int number) /// Print the number in binary
{
    int binaryNumber[7]; // Stores number in binary
    int i = 0;           // Iterate through the number
    while (number > 0)   // repeat until the number is smaller than zero
    {
        binaryNumber[i] = number % 2; // put a one or a zero in the array
        number = number / 2;          // Divide the number by two
        i++;                          // Increment i
    }                                 // repeat

    for (int j = i - 1; j >= 0; j--) // Print all of the array backwards
        Serial.print(binaryNumber[j]);
}

void setup()
{
    Serial.begin(9600); // Initialise serial communication
}

void loop()
{
    Serial.println("Enter a number between 1 and 255");

    int parse; // Store user input to convert to binary

    do
    {
        parse = Serial.parseInt();
    } while (!parse); // Wait for user input

    Serial.print("Your number in binary is: ");
    decToBinary(parse); // Print the binary number
}
