/*! @file ConfigException.h
 * @author Sascha Heimfarth
 * @brief Hier befinden sich alle Exeptions die durch das Config Objekt geworfen werden können.
 */

#ifndef ConfigExceptions_H
#define ConfigExceptions_H

/*! @brief Die Standard Exceptions für die Config library
*/
enum ConfigException {
  ReadError,
  WriteError,
  FormatError
};
#endif
