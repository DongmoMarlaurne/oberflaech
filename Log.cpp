/*! @file Log.cpp
 * @author Sascha Heimfarth
 */

#include "Log.h"

#include <ctime>
#include <iostream>
#include <fstream>

void Log::log(const std::string msg, const std::string &file, unsigned long line)
{
  //erzeugt einen neuen Timestamp
  time_t timestamp;
  //inizialisiert denn Timestamp
  time(&timestamp);
  //Öffnet eine neue Logdatei
  std::ofstream log((this->filename), std::ios::app | std::ios::out);
  //Erzeugt einen Buffer für denn Ascii Timestamp
  char buffer[20];
  //schreibt aktuelles Datum und Uhrzeit in denn Buffer
  std::strftime(buffer, 50, "%d.%m.%Y %H:%M:%S", localtime(&timestamp));
  //schreibt das Aktuelle Datum in die Datei
  log << buffer << " @ " << file << ':' << line;
  //schreibt die Nachricht in die Datei
  log << ": " << msg << std::endl;
  //schließt die Datei wieder
  log.close();
}

void Log::clear()
{
  //Überschreibt das File (Leer)
  std::ofstream log((this->filename), std::ios::out);
  //Schließt das File wieder
  log.close();
}


void Msg2Logfile(const std::string &msg, const std::string &file, unsigned long line)
{
  //erzeugt einen neuen Timestamp
  time_t timestamp;
  //inizialisiert denn Timestamp
  time(&timestamp);
  //Öffnet eine neue Logdatei
  std::ofstream log(("modio.log"), std::ios::app | std::ios::out);
  //Erzeugt einen Buffer für denn Ascii Timestamp
  char buffer[20];
  //schreibt aktuelles Datum und Uhrzeit in denn Buffer
  std::strftime(buffer, 50, "%d.%m.%Y %H:%M:%S", localtime(&timestamp));
  //schreibt das Aktuelle Datum in die Datei
  log << buffer << " @ " << file << ':' << line;
  //schreibt die Nachricht in die Datei
  log << ": " << msg << std::endl;
  //schließt die Datei wieder
  log.close();
}
