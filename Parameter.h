/*! @file Parameter.h
 * @author Sascha Heimfarth
 * @brief Hier befindet sich das Parameter Objekt welches alle wichtigen Variablen für denn Autosampler bereitstellt.
 */


#ifndef Parameter_H
#define Parameter_H

#include <cstdint>

#include "Config.h"

class Parameter
{
private:
  Config conf;
  /*! @brief Template welches es ermöglicht einen Wert sofern er in der Registry steht in eine übergebene Variable zu schreiben.
  * Wenn sie nicht vorhanden ist, wird der Standard wert belassen.
  */
  template<typename T>
  void LoadValue(const std::string &key, T &target)
  {
    //Prüft ob Wert exisitiert, wenn nein, dann überschreibt er denn Akuellen Wert nicht
    // z.b. ein Default-Wert
    if (this->conf.Exists(key))
    {
      //Wenn er exisitiert, wird er überschrieben
      target = this->conf.Get<T>(key);
    }
  }
  /*! @brief Template welches es ermöglicht einen Wert in die Registry zu speichern.
  */
  template<typename T>
  void StoreValue(const std::string &key, T &target)
  {
    this->conf.Set<T>(key, target);
  }
public:

  // Variabeln für Autosampler

  /// Bit für das Readysignal der Inizialsierung
  uint8_t readyPort = 0;

  /// Adresse der X-Achse
  uint8_t addrXAxis = 255;
  /// Adresse der Y-Achse
  uint8_t addrYAxis = 255;
  /// Adresse der Z-Achse
  uint8_t addrZAxis = 255;

  /// Bit für das Readysignal der X-Achse
  uint8_t readyXAxis = 255;
  /// Bit für das Readysignal der Y-Achse
  uint8_t readyYAxis = 255;
  /// Bit für das Readysignal der Z-Achse
  uint8_t readyZAxis = 255;

  // 1 = Vollschritt, 2 = Halb schritt, ... (1/n-Schritt)

  /// Gangart des X-Achsen Stepper
  uint8_t modeXAxis = 255;
  /// Gangart des Y-Achsen Stepper
  uint8_t modeYAxis = 255;
  /// Gangart des Z-Achsen Stepper
  uint8_t modeZAxis = 255;

  /// Geschwindigkeit des X-Achsen Motors in Schritten/s
  int xSpeed = 32000;
  /// Geschwindigkeit des Y-Achsen Motors in Schritten/s
  int ySpeed = 32000;
  /// Geschwindigkeit des Z-Achsen Motors in Schritten/s
  int zSpeed = 32000;

  /// Geschwindigkeit des X-Achsen Motors in Schritten/s für die Referenzfahrt
  int xRefSpeed = 32000;
  /// Geschwindigkeit des Y-Achsen Motors in Schritten/s für die Referenzfahrt
  int yRefSpeed = 32000;
  /// Geschwindigkeit des Z-Achsen Motors in Schritten/s für die Referenzfahrt
  int zRefSpeed = 32000;

  // Ermittlung der Position der Pipettenspitze

  /// X-Achsen Geschwindigkeit im Vollschritt
  int tipCalXSpeed = 32000;
  /// Y-Achsen Geschwindigkeit im Vollschritt
  int tipCalZSpeed = 32000;

  // Alle Geschwindigkeiten in mm

  /// Postion seitlich der Lichtschranke
  double tipCalXStart = 123.4;
  /// Postion "in" der Lichtschranke
  double tipCalZStart = 123.4;

  /// in Vollschritten
  int tipCalXWeg = 32000;
  /// ZWeg > XWeg !!! im Vollschritt
  int tipCalZWeg = 32000;

  /// Kanal des AD-Wandlers
  int tipCalAD = 32000;

  /// min. Intensitätsunterschied an der Lichtschranke  (mit und ohne Pipettenspitze)
  double tipCalibInt = 123.4;

  // Umrechnungsfaktor für Weg (Anzahl der Schritte pro mm)

  /// Umrechnungsfaktor X-Achse
  double xFaktor = 1.0;
  /// Umrechnungsfaktor Y-Achse
  double yFaktor = 1.0;
  /// Umrechnungsfaktor Z-Achse
  double zFaktor = 1.0;

  // Maximal Weg längen der einzelenen Achsen (in mm)

  /// X-Achsen länge (mm)
  double maxXAxis = 43210.0;
  /// Y-Achsen länge (mm)
  double maxYAxis = 43210.0;
  /// Z-Achsen länge (mm)
  double maxZAxis = 43210.0;
  /*! @brief Diese Funktion dient dazu die Parameter aus der Registry zu lesen
  * und in diesem Objekt zu speichern.
  */
  void Load();
  /*! @brief Diese Funktion dient dazu die Parameter aus diesem Objekt in die Registry
  * zuspeichern.
  */
  void Store();
  Parameter()
  {}
};

#endif
