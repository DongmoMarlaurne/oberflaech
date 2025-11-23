/*! @file ConfigLinux.cpp
 * @author Sascha Heimfarth
 */

#include "ConfigLinux.h"

#include "ConfigExceptions.h"

#include <unistd.h>
#include <fstream>
#include "json.hpp"

using Json = nlohmann::json;

std::string Config::expandPath(const std::string &path)
{
  //Prüft ob der pfad mit "~" anfängt
  if (path[0] == '~')
  {
    //wenn ja, versucht er die $HOME Variable zu lesen
    const char* home = std::getenv("HOME");
    if (home)
    {
      //wenn erfolgreich, ersetzt er "~/" durch denn Inhalt von $HOME und gibt ihn zurück
      return std::string(home) + path.substr(1);
    }
    else
    {
      //sonst gibt denn Unveränderten string zurück
      return path;
    }
  }
  //oder gibt sonnst auch denn Unveränderten string zurück
  return path;
}
//Erzeugt das Config-File an angegeben Pfad
Config::Config(): FILEPATH("~/.spr-device.conf")
{
  //Prüft ob das Config-File existiert
  if (access( this->expandPath(Config::FILEPATH).c_str(), 0 ) != 0)
  {
    //Wenn nein, öffnet er ein neues File (schreibend)
    std::ofstream file(this->expandPath(Config::FILEPATH));
    //wenn nicht Erfolgreich, wird ein WriteError geworfen
    if (!file)
    {
      throw ConfigException::WriteError;
    }
    //Schreibt ein leeres Json Objekt in das File
    file << "{}";
    //Schließt das File wieder
    file.close();
  }
}

bool Config::Exists(const std::string key)
{
  //Öffnet das Config file
  std::ifstream file(this->expandPath(Config::FILEPATH));
  //Erzeugt ein Json-Objekt
  Json data;
  //Wenn File nicht erfolgreich geöffnet, wird ein ConfigException::ReadError geworfen
  if (!file)
  {
    throw ConfigException::ReadError;
  }
  //Versucht das File zu parsen.
  try
  {
    file >> data;
  }
  catch (const Json::parse_error& e)
  {
    //Wenn nicht erfolgreich, schließt das File und wirft einen ConfigException::FormatError
    file.close();
    throw ConfigException::FormatError;
  }
  //Prüft ob key in Json-Objekt
  bool ret = data.contains(key);
  //Schließt File.
  file.close();
  //Gibt zurück ob Key existiert
  return ret;
}
