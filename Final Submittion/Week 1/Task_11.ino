/*
    Write a program that will generate a random number 
    under 300 for ten times and if the generated number 
    is between 0-100 print A, if the generate number is 
    101-200 print Band if the generated number is 201-300 
    print C in the serial monitor. 
    (Use if else if statements and for loop)
*/

void setup()
{
    Serial.begin(9600); //Initialise serial communication

    int randomNumber; // Initialise random number

    for (int i = 0; i < 10; i++) // Begin loop, iterates 10 times
    {
        randomNumber = random(301); // Set a random number

        //Checks for the right message depending on the random number
        if (randomNumber < 101)
        {
            Serial.println("A");
        }
        else if (randomNumber < 201)
        {
            Serial.println("B");
        }
        else
        {
            Serial.println("C");
        }
    }
}

// Loop must be defined
void loop()
{
}
