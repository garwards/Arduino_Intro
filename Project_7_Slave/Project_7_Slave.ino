#include <Wire.h>

const int I2C_ADDRESS = 1;   // Set your slave address here

const int OUT_A = 2;
const int OUT_B = 3;
const int OUT_C = 4;
const int OUT_D = 5;
const int OUT_E = 6;
const int OUT_F = 7;
const int OUT_G = 8;

const int POT_IN = A0;

// This is our setting to send to the master
int setting = 0;

int digit_segments[10][7] = {
   {1, 1, 1, 1, 1, 1, 0},		// This is digit 0, as per the table
   {0, 1, 1, 0, 0, 0, 0},		// Digit 1
   {1, 1, 0, 1, 1, 0, 1},
   {1, 1, 1, 1, 0, 0, 1},
   {0, 1, 1, 0, 0, 1, 1},
   {1, 0, 1, 1, 0, 1, 1},
   {1, 0, 1, 1, 1, 1, 1},
   {1, 1, 1, 0, 0, 0, 0},
   {1, 1, 1, 1, 1, 1, 1},
   {1, 1, 1, 1, 0, 1, 1}		// Digit 9
};

void setup()
{
   pinMode(OUT_A, OUTPUT);
   pinMode(OUT_B, OUTPUT);
   pinMode(OUT_C, OUTPUT);
   pinMode(OUT_D, OUTPUT);
   pinMode(OUT_E, OUTPUT);
   pinMode(OUT_F, OUTPUT);
   pinMode(OUT_G, OUTPUT);

   // Configure for I2C communications
   Wire.begin(I2C_ADDRESS);
   Wire.onRequest(requestHandler);
}

void loop()
{
   int sensorValue = analogRead(POT_IN);
   setting = map(sensorValue, 0, 1023, 0, 9);
   writeDigit(setting);
   delay(50);
}


void requestHandler()
{
   Wire.write((byte)setting);
}


void writeDigit(int digit)
{
   int startPin = 2;
   for (int i = 0; i < 7; i++)
   {
      digitalWrite(startPin + i, digit_segments[digit][i]);
   }
}


