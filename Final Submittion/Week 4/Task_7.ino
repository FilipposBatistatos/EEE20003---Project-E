/*
    Write a program that randomly takes an integer from {0,1,2,3} 
    where each randomly taken integer corresponds to an index within 
    the array of LED pins {9,10,11,12}: num “0”corresponds to LED pin 9, 
    num “1”corresponds to LED pin 10 and so on. You are required to 
    generate a specific tune with a single pitch and turn on the right 
    LED if the potentiometer is dialled in the correct quadrant that 
    corresponds to the randomly taken integer value: num “0” also 
    corresponds to a reading between 0% and 25% of the maximum potential, 
    um “1” also corresponds to a reading between 25% and 50% of the
    maximum potential, and so on. If your dialling on the potentiometer 
    is incorrect, then no LED is lit, and you are required to design a 
    tune of your choice consisting of varying pitches and send it out. 
    Make sure that every tune only lasts for a few seconds and that the 
    outcome of whether you have correctly dialled the potentiometer is 
    displayed on the serial monitor. The game will then be paused for 3 
    seconds, and a new round will begin.
*/

#define SPEAKER 8        // Connect speaker to pin 8
#define POTENTIOMETER A0 // Connect potentiometer to pin A0

int ledPins[4] = {9, 10, 11, 12}; // Store all the LED pins

void gameLoop() // Game logic and control
{
    int led = random(0, 4); // Generate random number between 0 and 3
    int input;              // Store user input

    while (true) // Repeat for ever
    {
        input = analogRead(POTENTIOMETER); // Read potentiometer value

        // Check whether in which quadrant the potentiometer is in
        if ((input >= 0) and (input <= 0.25 * 1023))
        {
            input = 0;
        }
        else if ((input > 0.25 * 1023) and (input <= 0.5 * 1023))
        {
            input = 1;
        }
        else if ((input > 0.5 * 1023) and (input <= 0.75 * 1023))
        {
            input = 2;
        }
        else
        {
            input = 3;
        }

        if (input == led) // If the value matches the random number
        {
            Serial.println("Corrent number picked"); // Print a message
            digitalWrite(ledPins[led], HIGH);        // Turn on the appropriate LED
            //play song
            tone(SPEAKER, 262, 250);
            delay(250);
            tone(SPEAKER, 200, 400);
            delay(400);
            tone(SPEAKER, 300, 250);
            delay(250);
            tone(SPEAKER, 420, 500);
            delay(1000);
            break; // Stop the game loop
        }
    }
}

void setup()
{
    Serial.begin(9600);            // Initialise serial communication
    pinMode(SPEAKER, OUTPUT);      // Set up speaker pin
    pinMode(POTENTIOMETER, INPUT); // Set up potentiometer pin
}

void loop()
{
    for (int i = 0; i < 4; i++) // Set all the pins to low
    {
        digitalWrite(ledPins[i], LOW);
    }

    Serial.println("Game has started"); // Notify that game has begun
    gameLoop();
    delay(3000); // Wait for the game to finish and restart
}