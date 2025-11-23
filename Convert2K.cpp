/*! @file Convert2K.cpp
 * @author Sascha Heimfarth
 */

#include <iostream>

#include "Convert2K.h"

uint16_t ConvertTo2K(float value, float max_value)
{
    //Initialisiere Rückgabewert
    uint16_t ret = 0;
    //Prüfe ob Übergabewert die limits überschreitet
    if (std::abs(value) > max_value)
    {
        //Wenn ja, setzte Wert auf Vorzeichenabhängigen Maximalwert
        value = value < 0 ? -max_value : max_value;
    }
    // 3 Satz, teile Wert durch Maximal Wert (ohne Vorzeichen) und Multipliziere es mit höchsten Wert
    //(nur 15 Bit, weil ohne Vorzeichen)
    ret = std::abs(value / max_value) * 0x7FFF;
    //Wenn Wert eine negative Zahl ist
    if (value < 0)
    {
        //Invertiere Wert, weil
        // (weil        0 - 7FFF:   0V --> 10V) [Für Positivezahlen]
        //  und dann 8000 - FFFF: -10V --> -0V [Gegenläufig für Negativezahlen]
        //Invertierung setzt 16. Bit auch auf 1 (für Negativ)
        ret = ~ret;
    }
    return ret;
}

float ConvertFrom2K(uint16_t value, float max_value)
{
    //Initialisiere Rückgabewert
    float ret = 0;
    //Prüft ob das 16. Bit gesetzt ist (negativ)
    bool negativ = (value & (1 << 15)) >> 15;
    //wenn Negativ, invertiere Wert (weil für Negativezahlen Rückwerts gezählt wird)
    if (negativ)
    {
        value = ~value;
    }
    //3 Satz, Teile Wert (ohne Vorzeichen, untere 15 Bits) durch Maximalwert von 15 Bit
    //und speichere das Ergebnis in denn Rückgabe wert
    ret = (float) (value & ~(1 << 15)) / 0x7FFF;
    //Multipliziere denn Wert <=1 mit dem maximalen Wert
    ret *= max_value;
    //Wenn negativ, ändere Vorzeichen auf negativ
    if (negativ)
    {
        ret *= -1;
    }
    return ret;
}
