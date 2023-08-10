#include <PushButton.hpp>

/*
https://wokwi.com/projects/372717884958772225
*/

PushButton p1 (2, INPUT_PULLUP);

int last = 0;
int counter = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (!p1.Read()) ++counter;
    if (last != counter)
    {
        Serial.print("Counter: ");
        Serial.println(counter);
        last = counter;
    }
}