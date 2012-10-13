const int LED = 13;  // The pin our LED is attached to
void setup()
{
   pinMode(LED, OUTPUT);  // Tells it pin 13 will be used for output
}

void loop()
{
   digitalWrite(LED, HIGH);
   delay(1000);
   digitalWrite(LED, LOW);
   delay(1000);
}

