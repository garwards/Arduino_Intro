
const int LED = 9;
const int BUTTON = 2;

void setup()
{
   pinMode(2, INPUT);
   pinMode(9, OUTPUT);
}

void loop()
{
   digitalWrite(9, digitalRead(2));
}


