#include <PushButton.hpp>

/*
https://wokwi.com/projects/372717884958772225
*/

PushButton p1 (2, INPUT_PULLUP);
#define p2 19

int counter = 0;
int counter2 = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(p2, INPUT_PULLUP);
}

void loop()
{
    if (!p1.Read())
    {
        Serial.print("Counter: ");
        Serial.println(counter);
        ++counter;
    }
    if (!digitalRead(p2))
    {
        Serial.print("\t\tCounter2: ");
        Serial.println(counter2);
        ++counter2;
    }
}