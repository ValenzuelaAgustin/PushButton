#ifndef PULSADOR_H
#define PULSADOR_H

typedef enum {PULLDOWN, PULLUP} mode;

class pulsador
{
    private:
    int pin;
    mode pulsador_mode;
    unsigned int inicio;

    public:
    pulsador(int pin, mode pulsador_mode);
    bool Read();
};
#endif