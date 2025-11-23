/*! @file Log.h
 * @author Sascha Heimfarth
 * @brief Dient dazu mithilfe des Log Objektes und des LOG Makros logs zu erstellen
 */

#ifndef iolog_h
#define iolog_h

#include <ctime>
#include <iostream>
#include <fstream>

/*! @brief Die Log Klasse dient dazu ein Log Objekt (verknüpft mit einem Logfile) bereit zustellen
*/
class Log
{
private:
  // Pfad des Logfiles
  std::string filename;
public:
  /*! @brief Die log Funktion des Logfiles, dient dazu eine Log-Nachricht zu schreiben
  * @param msg Die eigentliche Nachricht
  * @param file Der Name des Files in dem der Aufruf passiert
  * @param line Zeile in der der Aufruf passiert
  */
  void log(const std::string msg, const std::string &file, unsigned long line);
  /*! @brief Dient dazu das Logfile zu clearen
  */
  void clear();
  Log(std::string file): filename(file)
  {}
};

/*! @brief Dient dazu Logmeldungen mit automatischem Filename und Zeilennummer zu erstellen
* @param obj Das Log-Objekt
* @param msg Die Log Nachricht
*/
#define LOG(obj, msg) obj.log(msg, __FILE__, __LINE__);

#endif
