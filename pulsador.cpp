#include <arduino.h>
#include "pulsador.h"

pulsador::pulsador(int pin, mode pulsador_mode)
{
    this->pin = pin;
    this->pulsador_mode = pulsador_mode;
    this->inicio = 0;

    switch (this->pulsador_mode)
    {
        case PULLUP:
        pinMode (this->pin, INPUT_PULLUP);
        break;

        case PULLDOWN:
        pinMode (this->pin, INPUT);
        break;
    }
}

bool pulsador::Read()
{
    if (millis() - this->inicio >= 150)
    {
        this->inicio = millis();
        return digitalRead(this->pin);
    }
    switch (this->pulsador_mode)
    {
        case PULLUP:
        return 1;
        break;

        case PULLDOWN:
        return 0;
        break;
    }
}