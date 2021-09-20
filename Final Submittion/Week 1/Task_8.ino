/*
    Write a simple program to find out the students mark (x)
    belongs to Higher Distinction, Distinction, Credit, Pass or fail. 
    Add the screenshot for the following marks x= 45,55,60,80 
*/

void setup()
{
    Serial.begin(9600);                    // Setup serial communication
    Serial.println("Enter student score"); // Print a message
}

void loop()
{
    int x; // Stores student mark
    do
    {
        x = Serial.parseInt();
    } while (!x); //Repeat untill a mark has been entered

    // Print user mark
    Serial.print("Score: ");
    Serial.println(x);

    // Place mark in the appropriate mark bracket
    switch (x)
    {
    case 80 ... 100:
        Serial.println("Higher Distinction");
        break;
    case 60 ... 79:
        Serial.println("Distinction");
        break;
    case 55 ... 59:
        Serial.println("Credit");
        break;
    case 45 ... 54:
        Serial.println("Pass");
        break;
    default:
        Serial.println("Fail");
        break;
    }
}