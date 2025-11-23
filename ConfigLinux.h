/*! @file ConfigLinux.h
 * @author Sascha Heimfarth
 * @brief Der Linux spezifische Header für die Konfiguration
 */

#ifndef ConfigLinux_H
#define ConfigLinux_H

/*
Linux speizifischer Header, wird nur includiert wenn das Target System Linux ist.
Seine ABI ist identisch mit der des Windows headers, damit kann man denn selben Code,
einfach für das andere System compilen.
*/

#include <iostream>
#include <fstream>

#include "ConfigExceptions.h"
#include "json.hpp"


//Vereinfacht denn namespace zu Json
using Json = nlohmann::json;

/*! @brief Das Linux Config interface mit einer einheitlichen ABI
* Diese Klasse dient der Abstraktion um Config's zu schreiben und zu lesen,
* genauso wie zu prüfen ob sie bereits existieren z.b. zur Initialisierung
*/
class Config
{
private:
  /// @brief Pfad an dem die Config-Datei abgelegt ist
  const std::string FILEPATH;
  /// @brief Wird benötigt um relative pfade zu erweitern, z.b. von ~/ zu /home/<user>/
  std::string expandPath(const std::string &path);
public:
  /*! @brief Diese Funktion dient dazu aus der Config einen Wert am Key auszulesen
  * @param key der Key aus dem gelesen werden soll
  */
  template <typename T=std::string>
  T Get(const std::string key)
  {
    //Prüft ob der Key existiert, wenn nein, wird der ConfigException::ReadError geworfen
    if(!this->Exists(key))
    {
      throw ConfigException::ReadError;
    }
    //Öffnet das Config file (read)
    std::ifstream ifile(this->expandPath(Config::FILEPATH));
    //Erzeugt ein neues Json object
    Json data;
    //Prüft ob die Config-Datei existiert
    if (!ifile)
    {
      //Wenn Nein, wird ein ConfigException::ReadError geworfen
      throw ConfigException::ReadError;
    }
    try
    {
      //Versucht denn Inhalt der Datei in Json umzuwandeln.
      ifile >> data;
    }
    catch (const Json::parse_error& e)
    {
      //Wenn nein, wird das file geworfen, und der ConfigException::FormatError geworfen
      ifile.close();
      throw ConfigException::FormatError;
    }
    //Liest denn Key aus
    T ret = data[key];
    //Schließt die Datei
    ifile.close();
    //gibt denn gelesen Wert zurück
    return ret;
  }
  /*! @brief Diese Funktion dient dazu in die Config einen Wert am Key rein zuschreiben
  * @param key Der Key in denn geschrieben werden soll
  * @param value Der Wert der geschrieben werden soll (z.b. int, double, std::string oder const char*)
  */
  template <typename T=const std::string&>
  void Set(const std::string key, T value)
  {
    //Öffnet das File (lesenend)
    std::ifstream ifile(this->expandPath(Config::FILEPATH));
    //Erzeugt ein neues Json objekt
    Json data;
    //Prüft ob das file existiert, wenn nein, gibt es einen ConfigException::ReadError
    if (!ifile)
    {
      throw ConfigException::ReadError;
    }
    try
    {
      //Prüft die Datei als Json zu parsen
      ifile >> data;
    }
    catch (const Json::parse_error& e)
    {
      //Wenn nein, wird das File geschlossen und ein ConfigException::FormatError geworfen
      //z.b. wenn die Festplatte bzw. die config im Betrieb gelöscht wurde beschädigt ist.
      ifile.close();
      throw ConfigException::FormatError;
    }
    //Schreibt denn Wert in das Json-Objekt.
    data[key] = value;

    //Schließt das Config-File
    ifile.close();

    //Öffnet das Config-File (schreibend)
    std::ofstream ofile(this->expandPath(Config::FILEPATH));

    //Wenn nicht erfolgreich geöffnet, wird ein ConfigException::WriteError, geworfen
    if (!ofile)
    {
      throw ConfigException::WriteError;
    }
    //Schreibt denn Inhalt des Json Objects als Prettyprint in das Config file (override)
    ofile << data.dump(4);
    //schließt die Datei
    ofile.close();
  }
  /*! @brief Mit dieser Funktion kann geprüft werden ob ein Key bereits existiert
  * @param key Der Key der geprüft werden soll
  */
  bool Exists(const std::string key);
  /*! @brief Standard Konstruktor, dient der Initialisierung des Config objects
  */
  Config();
};

#endif
