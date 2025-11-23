/*! @file Registry.hpp
 * @author Sascha Heimfarth
 * @brief Dieser Header (von ConfigWin.h benutzt) dient dazu mithilfe von Templates Typen konvertierungen und das schreiben und lesen in die Windows-Registry durchzuführen.
 */

#ifndef Registry_HPP
#define Registry_HPP

#include <iostream>
#include <windows.h>
#include <string.h>

/*! @brief Mit dieser Funktion werden alle Schreibvorgänge in die Registry ausgeführt
* sie wurde als externe Funktion umgesetzt da hiermit eine template Überladung möglich ist.
* @param baseKey das Ziel z.b. HKEY_CURRENT_USER
* @param subKey Pfad an dem die Daten abgespeichert werden sollen
* @param key der Key unterwelchem die Daten gespeichert werden sollen
* @param value das eigentliche Datenobjekt
*/
template<typename T>
bool WriteRegistryValue(const HKEY &baseKey, const std::string &subKey, const std::string key, T value)
{
  //Variable für denn geöffneten Key
  HKEY hKey;
  //Ist default = false, bedeutet, es war bis jetzt nicht erfolgreich
  bool success = false;
  //Prüft ob der SubKey exist, wenn nein wird er Erzeugt, gibt ERROR_SUCCESS zurück wenn der key benutzt werden kann.
  if(RegCreateKeyEx(baseKey, subKey.c_str(), 0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS)
  {
    //Schreibt Daten in Key im Pfad, wenn erfolgreich gibt ERROR_SUCCESS zurück.
    if (RegSetValueEx(hKey, key.c_str(), 0, REG_BINARY, reinterpret_cast<const BYTE*>(&value), sizeof(value)) == ERROR_SUCCESS)
    {
      //Wenn ja, war es erfolgreich
      success = true;
    }
    //schließt die registry wieder
    RegCloseKey(hKey);
  };
  //gibt zurück ob es erfolgreich war (kein error)
  return success;
}
/*! @brief Einfache Template überladung für integer gleich zur Default Funktion,
* nur anderer Registry-Datentype: REG_DWORD
* @param baseKey das Ziel z.b. HKEY_CURRENT_USER
* @param subKey Pfad an dem die Daten abgespeichert werden sollen
* @param key der Key unterwelchem die Daten gespeichert werden sollen
* @param value das int
*/
template<>
bool WriteRegistryValue<int>(const HKEY &baseKey, const std::string &subKey, const std::string key, int value)
{
  //Variable für denn geöffneten Key
  HKEY hKey;
  //Ist default = false, bedeutet, es war bis jetzt nicht erfolgreich
  bool success = false;
  if(RegCreateKeyEx(baseKey, subKey.c_str(), 0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS)
  {
    if (RegSetValueEx(hKey, key.c_str(), 0, REG_DWORD, reinterpret_cast<const BYTE*>(&value), sizeof(value)) == ERROR_SUCCESS)
    {
      success = true;
    }
    RegCloseKey(hKey);
  };
  return success;
}
/*! @brief Template Überladung für std::string, nutzt als Registry-Datentype: REG_SZ und formt denn std::string in ein const char*.
* @param baseKey das Ziel z.b. HKEY_CURRENT_USER
* @param subKey Pfad an dem die Daten abgespeichert werden sollen
* @param key der Key unterwelchem die Daten gespeichert werden sollen
* @param value das std::string
*/
template<>
bool WriteRegistryValue<std::string>(const HKEY &baseKey, const std::string &subKey, const std::string key, const std::string value)
{
  //Variable für denn geöffneten Key
  HKEY hKey;
  //Ist default = false, bedeutet, es war bis jetzt nicht erfolgreich
  bool success = false;
  if(RegCreateKeyEx(baseKey, subKey.c_str(), 0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS)
  {
    if (RegSetValueEx(hKey, key.c_str(), 0, REG_SZ, reinterpret_cast<const BYTE*>(value.c_str()), static_cast<DWORD>(value.size() + 1)) == ERROR_SUCCESS)
    {
      success = true;
    }
    RegCloseKey(hKey);
  };
  return success;
}
/*! @brief Template Überladung für std::string, nutzt als Registry-Datentype: REG_SZ, nutzt auch REG_SZ,
* aber übergibt value ohne Änderung, ermittelt nur mit strlen die string länge.
* @param baseKey das Ziel z.b. HKEY_CURRENT_USER
* @param subKey Pfad an dem die Daten abgespeichert werden sollen
* @param key der Key unterwelchem die Daten gespeichert werden sollen
* @param value das const char*
*/
template<>
bool WriteRegistryValue<const char*>(const HKEY &baseKey, const std::string &subKey, const std::string key, const char *value)
{
  //Variable für denn geöffneten Key
  HKEY hKey;
  //Ist default = false, bedeutet, es war bis jetzt nicht erfolgreich
  bool success = false;
  if(RegCreateKeyEx(baseKey, subKey.c_str(), 0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS)
  {
    if (RegSetValueEx(hKey, key.c_str(), 0, REG_SZ, reinterpret_cast<const BYTE*>(value), static_cast<DWORD>(strlen(value))) == ERROR_SUCCESS)
    {
      success = true;
    }
    RegCloseKey(hKey);
  };
  return success;
}
/*! @brief Mit dieser Funktion werden alle Lesevorgänge in die Registry ausgeführt
* sie wurde als externe Funktion umgesetzt da hiermit eine template Überladung möglich ist.
* @param baseKey das Ziel z.b. HKEY_CURRENT_USER
* @param subKey Pfad an dem die Daten gelesen werden sollen
* @param key der Key aus dem die Daten gelesen werden sollen
*/
template <typename T>
T ReadRegistryValue(HKEY baseKey, const std::string &subKey, const std::string key)
{
  //Variable für denn geöffneten Key
  HKEY hKey;
  //Es wird erstmal angenommen das es nicht funktioniert um später ggf. einen Fehler zuwerfen
  bool success = false;
  //Rückgabewert
  T value = -1;
  //Wenn der Key geöffnet werden kann, wird der key gelesen
  if (RegOpenKeyEx(baseKey, subKey.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS)
  {
    //Übergabewert für das Lesen, wiegroß der Datentype sein sollte
    DWORD valueSize = sizeof(value);
    //Gibt 1 zurück wenn es erfolgreich war, sonnst 0
    success = RegQueryValueEx(hKey, key.c_str(), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &valueSize) == ERROR_SUCCESS;
    //schließt denn key wieder
    RegCloseKey(hKey);
  }
  //Wenn es nicht erfolgreich war, wrid eine Exception geworfen (hier 0).
  if (!success)
  {
    throw 0;
  }
  //sonnst gibt es denn gelesen Wert zurück
  return value;
}
/*! @brief Diese Funktion ist eine Spezifizierte Templateüberladung für std::string
* sie speichert die Daten aus der Registry in einem 256 byte großen buffer zwischen.
* dannach wird ein neuer std::string zurück gegeben.
* @param baseKey das Ziel z.b. HKEY_CURRENT_USER
* @param subKey Pfad an dem die Daten gelesen werden sollen
* @param key der Key aus dem die Daten gelesen werden sollen
*/
template <>
std::string ReadRegistryValue<std::string>(HKEY baseKey, const std::string &subKey, const std::string key)
{
  //Variable für denn geöffneten Key
  HKEY hKey;
  //Es wird erstmal angenommen das es nicht funktioniert um später ggf. einen Fehler zuwerfen
  bool success = false;
  //Das ist der Buffer für die gelesen Strings
  char buffer[256];
  if (RegOpenKeyEx(baseKey, subKey.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS)
  {
    //Übergabewert für das Lesen, wiegroß ein element des Strings ist (ein char)
    DWORD valueSize = sizeof(buffer);
    //Gibt 1 zurück wenn es erfolgreich war, sonnst 0
    success = RegQueryValueEx(hKey, key.c_str(), NULL, NULL, reinterpret_cast<LPBYTE>(&buffer), &valueSize) == ERROR_SUCCESS;
    //schließt denn key wieder
    RegCloseKey(hKey);
  }
  //Wenn es nicht erfolgreich war, wrid eine Exception geworfen (hier 0).
  if (!success)
  {
    throw 0;
  }
  //sonnst gibt es denn gelesen Wert zurück (wird zu std::string convertiert)
  return std::string(buffer);
}

/**
* Diese Klasse ist ein Windows Registry Wrapper
* um die Registry-Zugriffe zu vereinfachen.
*/

class Registry
{
private:
  /// @brief Konstante des baseKey (in welchem Teil der Registry gearbeitet wird)
  const HKEY baseKey;
  /// @brief Konsante für den Pfad wo die Daten gespeichert werden sollen in der Registry
  const std::string subKey;
public:
  /*! @brief Mit dieser Funktion kann man Prüfen ob ein Key bereits Vorhanden ist
  * @param key string des Keys denn man prüfen möchte
  * @return bool Gibt zurück ob der Key existiert
  */
  bool Exists(const std::string key);
  /*! @brief Das ist eine Template Funktion mit der aufrufe auf die WriteRegistryValue-Funktionen
  * gewrappt werden um Objekt-Orientierung zu ermöglichen.
  * @param key string des Keys denn man schreiben möchte
  * @param value hier wird die zu schreibende Variable übergeben
  * @return bool Gibt zurück ob das schreiben erfolgreich war (=1)
  */
  template <typename T>
  bool Write(std::string key, T value)
  {
    return WriteRegistryValue<T>(this->baseKey, this->subKey, key, value);
  }
  /*! @brief Das ist eine Template Funktion mit der aufrufe auf die ReadRegistryValue-Funktionen
  * gewrappt werden um Objekt-Orientierung zu ermöglichen.
  * @param key string des Keys denn man lesen möchte
  * @return T gibt denn gelesen Wert im Datentype T zurück (muss wie Read<int>("foo") angegeben werden)
  */
  template <typename T>
  T Read(std::string key)
  {
    return ReadRegistryValue<T>(this->baseKey, this->subKey, key);
  }
  /*! @brief Der Konstruktor für denn Registry wrapper
  * @param _BaseKey z.b. HKEY_CURRENT_USER (hier für muss windows.h includiert werden)
  * @param _subKey Pfad an dem die Datengespeichert werden sollen
  */
  Registry(HKEY _BaseKey, std::string _subKey): baseKey(_BaseKey), subKey(_subKey)
  {}
  /*! @brief Konstruktor (Vereinfacht mit HKEY_CURRENT_USER als festes Ziel)
  * Der Konstruktor für denn Registry wrapper
  * @param _subKey Pfad an dem die Datengespeichert werden sollen
  */
  Registry(std::string _subKey): baseKey(HKEY_CURRENT_USER), subKey(_subKey)
  {}
};

bool Registry::Exists(const std::string key)
{
  //Variable für denn geöffneten Key
  HKEY hKey;
  //Versucht denn Pfad zu öffnen
  if (RegOpenKeyEx(this->baseKey, this->subKey.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS)
  {
    //nicht weiter inzialisierter Typ, er muss nur angegeben werden
    DWORD type;
    //länge = 0
    DWORD length = 0;
    //Gibt zurück ob das lesen des Keys erfolgreich war, wenn Ja = 1, sonnst 0
    bool ret = RegQueryValueEx(hKey, key.c_str(), 0, &type, NULL, &length) == ERROR_SUCCESS;
    //schließt denn Pfad wieder
    RegCloseKey(hKey);
    //gibt das Ergebnis zurück
    return ret;
  }
  return false;
}
#endif
