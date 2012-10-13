const int LED = 9;  // The pin our LED is attached to
const int POT_INPUT = A0;
int value = 0;
int ledBrightness = 0;

void setup()
{
   pinMode(LED, OUTPUT);  // Tells it pin 9 will be used for output
}

void loop()
{
   value = analogRead(POT_INPUT);
   ledBrightness = map(value, 0, 1023, 0, 255);
   analogWrite(LED, ledBrightness);
   delay(10);
}

