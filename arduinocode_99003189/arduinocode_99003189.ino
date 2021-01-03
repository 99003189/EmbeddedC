#include<SPI.h>
volatile boolean received;
volatile uint16_t  Slavereceived;


ISR(SPI_STC_vect)
{
  Slavereceived = SPDR;
  received = true;
}

void setup()
{
  Serial.begin(9600);
  pinMode(MISO, OUTPUT);
  pinMode(10, INPUT);
  digitalWrite(10, LOW);
  SPCR |= _BV(SPE);
  received = false;
  SPI.attachInterrupt();
  Serial.print("ARDUINO LOADING...");
  delay(2000);
  Serial.print("SYSTEM READY");
}


void loop()
{
  if (received)
  {
    if (Slavereceived !=0)
    {
      received = false;
      Serial.print("OBJECT IS IN RANGE\n");
      delay(200);
    }
    else
    {
      received =false;
      Serial.print("OBJECT IS NOT IN RANGE\n");
      delay(200);
    }
  } 
}
