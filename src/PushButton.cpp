#include "PushButton.hpp"

PushButton::PushButton(uint8_t pin, uint8_t mode)
{
    this->pin = pin;
    this->mode = (mode == PULLUP) || (mode == INPUT_PULLUP);
    pinMode(pin, (mode == INPUT_PULLUP) ? INPUT_PULLUP : INPUT);
}

void PushButton::begin(void(*ISR)())
{
    attachInterrupt(digitalPinToInterrupt(pin), ISR, CHANGE);
}

void PushButton::checkState()
{
    if ((millis() - last_release < debounceTIME))
        return;
    if (is_pressed && ((bool)digitalRead(pin) == mode))
    {
        is_pressed = false;
        just_pressed = false;
        just_released = true;
        last_release = millis();
    }
    else if (!is_pressed && ((bool)digitalRead(pin) != mode))
    {
        is_pressed = true;
        just_pressed = true;
        just_released = false;
    }
}

bool PushButton::Read()
{
    debounced_read = ((bool)digitalRead(pin) != mode) && (millis() - last_pressed >= debounceTIME);
    last_pressed = millis() * debounced_read + last_pressed * !debounced_read;
    return debounced_read != mode;
}

bool PushButton::justPressed()
{
    if (!just_pressed)
        return false;
    just_pressed = false;
    return true;
}

bool PushButton::isPressed()
{
    return ((bool)digitalRead(pin) != mode) && (millis() - last_release >= debounceTIME);
}

bool PushButton::justReleased()
{
    if (!just_released)
        return false;
    just_released = false;
    return true;
}