#include "button.hpp"

button::button(byte pin, byte mode)
{
    this->pin = pin;
    this->mode = mode;

    switch (this->mode)
    {
    case PULLUP:
        pinMode (this->pin, INPUT_PULLUP);
        break;

    default:
        pinMode (this->pin, INPUT);
        break;
    }
}

bool button::Read()
{
    if (millis() - start >= 150)
    {
        start = millis();
        return digitalRead(pin);
    }
    switch (mode)
    {
    case PULLDOWN:
        return 0;
        break;
        
    default:
        return 1;
        break;
    }
}