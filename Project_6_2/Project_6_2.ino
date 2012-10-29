
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
}

void loop()
{
   int sensorValue = analogRead(POT_IN);
   int scaled = map(sensorValue, 0, 1023, 0, 9);
   writeDigit(scaled);
   scaled = map(sensorValue, 0, 1023, 0, 768);
   Wheel(scaled);
   analogWrite(RED, r);
   analogWrite(GREEN, g);
   analogWrite(BLUE, b);
   delay(50);
}


void writeDigit(int digit)
{
   int startPin = 2;
   for (int i = 0; i < 7; i++)
   {
      digitalWrite(startPin + i, digit_segments[digit][i]);
   }
}


void figure8()
{
  int delayTime = 30;
  
   activateSegment(OUT_A);
   delay(delayTime);
   activateSegment(OUT_F);
   delay(delayTime);
   activateSegment(OUT_G);
   delay(delayTime);
   activateSegment(OUT_C);
   delay(delayTime);
   activateSegment(OUT_D);
   delay(delayTime);
   activateSegment(OUT_E);
   delay(delayTime);
   activateSegment(OUT_G);
   delay(delayTime);
   activateSegment(OUT_B);
   delay(delayTime);
}

void flash8()
{
   for (int i = 1; i <= 7; i++)
   {
      digitalWrite(i, true);
   }
   delay(300);
   for (int i = 1; i <= 7; i++)
   {
      digitalWrite(i, false);
   }
   delay(300);
   
}


void cycle()
{
   for (int i = 1; i <= 6; i++)
   {
      activateSegment(i);
      delay(100);
   }
}

void activateSegment(int i)
{
   for (int j = 1; j <= 7; j++)
   {
      if (i == j)
      {
         digitalWrite(j, true);
      }
      else
      {
         digitalWrite(j, false);
      }
   }
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


