#include <Wire.h>

const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;

int r, g, b;

const int OUT_A = 2;
const int OUT_B = 3;
const int OUT_C = 4;
const int OUT_D = 5;
const int OUT_E = 6;
const int OUT_F = 7;
const int OUT_G = 8;

const int POT_IN = A0;

const int NUM_SLAVES = 1;

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

   pinMode(RED, OUTPUT);
   pinMode(GREEN, OUTPUT);
   pinMode(BLUE, OUTPUT);

   // Inisitalise as I2C master
   Wire.begin();
}

void loop()
{
//   writeDigit(scaled);
   // Loop through each slave and request its current data
   for (int slave = 1; slave <= NUM_SLAVES; slave++)
   {
      // Request 1 byte from this slave
      Wire.requestFrom(slave, 1);
      while (Wire.available())
      {
         int data = Wire.read();
         processSlave(slave, data);
      }
   }
   delay(50);
}


void processSlave(int slave, int data)
{
   switch (slave)
   {
      case 1:
         setRGB(data);
         break;
   }
}


void writeDigit(int digit)
{
   int startPin = 2;
   for (int i = 0; i < 7; i++)
   {
      digitalWrite(startPin + i, digit_segments[digit][i]);
   }
}

void setRGB(int data)
{
   int rgb = ((float)((float)data/9) * 768);
   Wheel(rgb);
   analogWrite(RED, r);
   analogWrite(GREEN, g);
   analogWrite(BLUE, b);
}


void Wheel(uint16_t WheelPos)
{
  switch(WheelPos / 256)
  {
    case 0:
      r = 255 - WheelPos % 256;   //Red down
      g = WheelPos % 256;      // Green up
      b = 0;                  //blue off
      break; 
    case 1:
      g = 255 - WheelPos % 256;  //green down
      b = WheelPos % 256;      //blue up
      r = 0;                  //red off
      break; 
    case 2:
      b = 255 - WheelPos % 256;  //blue down 
      r = WheelPos % 256;      //red up
      g = 0;                  //green off
      break; 
  }
}


