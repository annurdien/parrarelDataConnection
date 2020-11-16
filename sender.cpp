#include <Arduino.h>

#define size 8
#define syncPin 10

void sendData(char x) {

Serial.println(x);

for( int i = 7; i >= 0; i-- ) {
  ( x >> i ) & 1 ? digitalWrite(9-i, 0x1) : digitalWrite(9-i, 0x0) ;
}

}

void setup() {

  Serial.begin(9600);
  for (int x = 0; x < size; x++)
  {
    pinMode(x + 2, OUTPUT);
  }
}

void loop() {

  digitalWrite(syncPin, 0x0);
  sendData('A');
  digitalWrite(syncPin, 0x1);
  delay(500);
  digitalWrite(syncPin, 0x0);
  
}
