#include <Arduino.h>

#define size 8
#define syncPin 10

// Reveive data from pin digital
char receiveData()
{
unsigned char result = 0;

for(int i=7; i>=0; i--)
{
    unsigned char temp = 1;
    if (digitalRead(i+2) == 1)
    {
        temp <<= (7-i);
        result |= temp;
    }
}
  return result;
}

void setup()
{
  Serial.begin(9600);
  for (int x = syncPin - size; x <= size + 2 ; x++){
    pinMode(x, INPUT);
  }
}

void loop()
{

  bool ___ready___ = digitalRead(syncPin);

  if (___ready___)
  {
    char z = receiveData();
    Serial.println("");
    Serial.print("Ascii Symbol : ");
    Serial.println(z);
    Serial.println("\n");

  }
  delay(500);
}
