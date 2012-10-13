const int LED = 9;  // The pin our LED is attached to
void setup()
{
   pinMode(LED, OUTPUT);  // Tells it pin 9 will be used for output
}

void loop()
{
   int loopCounter;  // Counts how many times we’ve been through our loop

   for (loopCounter = 0; loopCounter < 25; loopCounter++)
   {
      analogWrite(LED, loopCounter*10);
      delay(50);
   }
   
   for (/* No initialization */; loopCounter >= 0; loopCounter--)
   {
      analogWrite(LED, loopCounter*10);
      delay(50);
   }
   
}

