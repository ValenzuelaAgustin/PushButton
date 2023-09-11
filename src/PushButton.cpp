#include "PushButton.hpp"

PushButton::PushButton(uint8_t pin, uint8_t mode)
{
    this->pin = pin;
    this->mode = (mode == PULLUP) || (mode == INPUT_PULLUP);

    switch (mode)
    {
    case INPUT_PULLUP:
        pinMode(pin, INPUT_PULLUP);
        break;
    default:
        pinMode(pin, INPUT);
        break;
    }
}

bool PushButton::Read()
{
    is_pressed = (digitalRead(pin) != mode) && (millis() - last_pressed >= debounceTIME);
    last_pressed = millis() * is_pressed + last_pressed * !is_pressed;
    return is_pressed != mode;
}