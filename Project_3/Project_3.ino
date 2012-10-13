const int POT_INPUT = A0;
int value = 0;
void setup()
{
   Serial.begin(9600);  // Sets up serial communication and sets the rate
}
void loopa()
{
   value = analogRead(POT_INPUT);
   Serial.println(value);
   delay(50);
}

void loop()
{
   value = analogRead(POT_INPUT);
   float voltage = 5.0 * ((float)value / 1024);
   Serial.print("value: ");
   Serial.print(value);
   Serial.print(",  voltage: ");
   Serial.println(voltage);
   delay(50);
}

