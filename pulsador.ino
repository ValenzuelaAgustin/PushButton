#include <LiquidCrystal.h>
#include "pulsador.h"

LiquidCrystal lcd (12, 11 ,10, 9, 8, 7);
pulsador p1 (2, PULLUP);

int contador = 0;

void setup()
{
    lcd.begin (16,2);
}

void loop()
{
    if (p1.Read()) contador++;
    lcd.setCursor(0,0);
    lcd.print (contador);
}