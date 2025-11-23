/*! @file Example.cpp
 * @author Sascha Heimfarth
 * @brief Ein kleines Beispiel für Logging mit Fehler behandlung.
 */

#include <iostream>
#include "Log.h"

int main()
{
  Log test("log.txt");
  test.clear();
  Log error("error-logs.txt");
  error.clear();
  LOG(test, "Hallo Welt!");
  try
  {
    throw 5;
    LOG(test, "Complete.");
  }
  catch (int err)
  {
    LOG(error, "Fehler: " + std::to_string(err));
  }
}
