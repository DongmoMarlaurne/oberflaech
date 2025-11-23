/**
 * @file Conf.cpp
 * @author Sascha Heimfarth
 * @brief Beispiel um direkt mit dem Config Objekt zu interagieren
 * @details Damit können auch vom Parameter Objekt unabhängig Werte in der Konfiguration hinterlegt,
 * geprüft oder gelesen werden.
 * Man könnte damit z.b. Pfade oder sonnstige Einstellungen hinterlegen, die nichts mit dem
 * Autosampler zutun haben.
 */
 
#include "../libconfig/Config.h"
int main()
{
  Config conf;
  try
  {
    conf.Set("test", 42);
  }
  catch (ConfigException)
  {
    std::cout << "write error...\n" << std::endl;
  }
  try
  {
    if (conf.Exists("test"))
    {
      std::cout << conf.Get<int>("test") << std::endl;
    }
  }
  catch (ConfigException)
  {
    std::cout << "read error...\n" << std::endl;
  }
}
