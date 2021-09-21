/*
    Write a program that measures the temperature using a 
    temperature sensor every 5 seconds while simultaneously 
    generating a tune with varying pitches every 2 seconds 
    from the speaker. You are required to display values of 
    temperature at each time of measurement and the text “Speaker is on!” 
    right before a tune is generated and the text “Speaker if off!” 
    right after the tune is turned off. Hint: Use millis() function and 
    a “current time” versus “previous time” structure.
*/

#define SPEAKER 8      // Connect speaker to pin 8
#define TEMPERATURE A0 // Connect temperature to pin A0

//Buzzer timer variables
int previousBuzzerTime;
int currentBuzzerTime;

// Temperature sensor timer
int previousTempTime;
int currentTempTime;

const float BETA = 3950; // Constant for temperature convertion

void setup()
{
    Serial.begin(9600); // Initialise serial communication

    pinMode(SPEAKER, OUTPUT);    // Set up speaker pin
    pinMode(TEMPERATURE, INPUT); // Set up temperature sensor pin

    previousBuzzerTime = millis();         // Store current time
    previousTempTime = previousBuzzerTime; // Store current time in both timers
}

void loop()
{
    currentBuzzerTime = millis(); // Store current time in both timers
    currentTempTime = millis();

    // Check buzzer timer
    if (currentBuzzerTime - 2000 > previousBuzzerTime)
    {
        previousBuzzerTime = currentBuzzerTime;
        //play song
        Serial.println("Speaker is on!");
        tone(SPEAKER, 262, 250);
        delay(250);
        Serial.println("Speaker is off!");
    }

    // Check temperature timer
    if (currentTempTime - 5000 > previousTempTime)
    {
        previousTempTime = currentTempTime;
        //print temp
        int analogValue = analogRead(TEMPERATURE);
        float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
        Serial.print("Temperature: ");
        Serial.print(celsius);
        Serial.println(" ℃");
    }
}