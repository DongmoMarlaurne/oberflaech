/*! @file ConfigWin.h
 * @author Sascha Heimfarth
 * @brief Windows Header für die Konfiguration
 */

#ifndef ConfigWin_H
#define ConfigWin_H

/*
Windows speizifischer Header, wird nur includiert wenn das Target System Windows ist.
Seine ABI ist identisch mit der des Linux headers, damit kann man denn selben Code,
einfach für das andere System compilen.
*/

#include <iostream>
#include <windows.h>

#include "Registry.hpp"

#include "ConfigExceptions.h"

/*! @brief Das Windows Config interface mit einer einheitlichen ABI
* Diese Klasse dient der Abstraktion um Config's zu schreiben und zu lesen,
* genauso wie zu prüfen ob sie bereits existieren z.b. zur Initialisierung
*/
class Config
{
private:
  ///Variable des Windows Spezifischen Registry wrappers aus "Registry.h"
  Registry reg;
public:
  /*! @brief Diese Funktion dient dazu aus der z.b. Registry einen Wert am Key auszulesen
  * @param key der Key aus dem gelesen werden soll
  */
  template <typename T=std::string>
  T Get(const std::string key)
  {
    //Versucht aus der Registry zu lesen
    try {
      //Liest aus der Registry, bei erfolg, gibt des denn Wert zurück
      return this->reg.Read<T>(key);
    }
    catch(int)
    {
      //wenn Nein wird der einhetliche ConfigException::ReadError geworfen
      throw ConfigException::ReadError;
    }
  }
  /*! @brief Diese Funktion dient dazu in z.b. der Registry einen Wert am Key rein zuschreiben
  * @param key Der Key in denn geschrieben werden soll
  * @param value Der Wert der geschrieben werden soll (z.b. int, double, std::string oder const char*)
  */
  template <typename T>
  void Set(const std::string key, T value)
  {
    //Prüft ob das lesen Erfolgreich war, wenn nein, wird eine Exception geworfen
    if (!this->reg.Write<T>(key, value))
    {
      //Hier wird die einheitliche ConfigException::WriteError geworfen
      throw ConfigException::WriteError;
    }
  }
  /*! @brief Mit dieser Funktion kann geprüft werden ob ein Key bereits existiert
  * @param key Der Key der geprüft werden soll
  */
  bool Exists(const std::string key)
  {
    return this->reg.Exists(key);
  }
  /*! @brief Inizialisiert das Config objekt mit dem Pfad an dem die Datengespeichert werden sollen
  */
  Config(): reg(HKEY_CURRENT_USER, "Software\\THM\\SPR-DEVICE-CONFIG")
  {}
};
#endif
