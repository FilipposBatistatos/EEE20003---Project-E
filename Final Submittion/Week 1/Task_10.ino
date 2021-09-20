/*
    Write a program that will print your name and the student ID
    three times in the serial monitor (Use for loop)
*/

void setup()
{
    Serial.begin(9600); // Initalise serial communication
    for (int i = 0; i < 3; i++)
    {                                                      // Use for loop to iterate through the print loop
        Serial.println("Filippos Batistatos - 102450186"); // Print the message
    }
}

// Loop must be defined
void loop()
{
}