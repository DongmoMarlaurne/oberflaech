/*! @file Convert2K.h
 * @author Sascha Heimfarth
 * @brief Beinhält Funktionen um binäre Werte in bzw aus der 2K Darstellung zu konvertieren.
 */

#ifndef Convert2K_H
#define Convert2K_H

#include <cstdint>

/*!
 * @brief ConvertTo2K (Float to 2K)
 * @details Mit dieser Funktion kann man eine Vorzeichenbehafteten Float in eine
 * 16 Bit - 2K Darstellung konvertieren
 * @param value     Wert zum convertieren
 * @param max_value Maximalwert für die scalieren
 * @return 2K-Wert (0 --> FFFF) vom Float-Übergabewert (-max_value --> max_value)
*/
uint16_t ConvertTo2K(float value, float max_value);
/*!
 * @brief ConvertFrom2K (2K to Float)
 * @details Mit dieser Funktion kann man eine 16 Bit - 2K Wert in in einen
 * Vorzeichenbehafteten Float konvertieren
 * @param value     Wert zum konvertieren
 * @param max_value Maximalwert für die scalieren
 * @return Floatwert (-max_value --> max_value) vom 2K-Übergabewert (0 --> FFFF)
*/
float ConvertFrom2K(uint16_t value, float max_value);
#endif
