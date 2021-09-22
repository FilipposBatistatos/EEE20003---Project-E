/*
    Write a simple program to blink the LED every 5 second 
    using timer interrupts (Do not use delay, millis, micros )
*/

void setup()
{
    pinMode(7, OUTPUT);

    cli(); //stop all interupts

    //set timer1 interupt at 1Hz
    TCCR1A = 0; //Set entire TCCR1A register to 0
    TCCR1B = 0; //Same for TCCR1B
    TCNT1 = 0;  //Initialise counter value to 0
    //Set compare match register to 1Hz increments
    OCR1A = 65535; // = (16*10^6) / (5*1024) - 1(must be <65536)
    //Turn on CTC mode
    TCCR1B |= (1 << WGM12);
    //Set CS12 and CS10 bit for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);
    //Enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);

    sei(); //allow interrupts
}

ISR(TIMER1_COMPA_vect)
{
    digitalWrite(7, HIGH);
    delay(50);
    digitalWrite(7, LOW);
}

void loop()
{
}

void blink()
{
    digitalWrite(7, HIGH);
    delay(50);
    digitalWrite(7, LOW);
}