/*
    Use the built-in utility PROGMEM from the library pgmspace.h 
    to store a string “ARDUINO IS FUN, I WANT TO DO MORE.” and a 
    character array with numbers 6500, 2300, 20, 1, 2, 14, and 5 
    in the flash memory of Arduino DUE instead of RAM. 
    On the serial monitor, please print the string followed by an 
    empty line, and each number form the character array on a separate 
    line only once.
*/

// Save numbers
const PROGMEM uint16_t charSet[] = {6500, 2300, 20, 1, 2, 14, 5};

// Save message
const char signMessage[] PROGMEM = {"ARDUINO IS FUN, I WANT TO DO MORE"};

unsigned int displayInt; // Stores number to display
int k;                   // counter variable
char myChar;

void setup()
{
    Serial.begin(9600); // Initialise serial communication
    while (!Serial)
        ;

    // read back a char
    int len = strlen_P(signMessage); // Store length of message
    for (k = 0; k < len; k++)        // Iterate through all characters and print them
    {
        myChar = pgm_read_byte_near(signMessage + k);
        Serial.print(myChar);
    }

    Serial.print("\n\n"); // Print an empty line

    // read back a 2-byte int
    for (k = 0; k < 7; k++) // Iterate through number array and print every line
    {
        displayInt = pgm_read_word_near(charSet + k);
        Serial.println(displayInt);
    }
    Serial.println();
}

void loop()
{
}