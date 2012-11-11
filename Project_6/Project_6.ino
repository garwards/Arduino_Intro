const int OUT_A = 2;
const int OUT_B = 3;
const int OUT_C = 4;
const int OUT_D = 5;
const int OUT_E = 6;
const int OUT_F = 7;
const int OUT_G = 8;

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
}

void loop()
{
   writeDigit(0);
   delay(1000);
   writeDigit(1);
   delay(1000);
   writeDigit(2);
   delay(1000);
   writeDigit(3);
   delay(1000);
   writeDigit(4);
   delay(1000);
   writeDigit(5);
   delay(1000);
   writeDigit(6);
   delay(1000);
   writeDigit(7);
   delay(1000);
   writeDigit(8);
   delay(1000);
   writeDigit(9);
   delay(1000);
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
